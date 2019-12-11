//airport.c

#include <stdio.h>
#include <stdlib.h>
#include "airport.h"

struct _runwayNode;
typedef struct _runwayNode* pRunwayNode;
typedef struct _runwayNode{
    pRunway cur_runway;
    pRunwayNode next_runway;
} runwayNode;
pRunwayNode head=NULL;
/***********************************************************
function name: addRunway

description:
Add a new runway record with given num and type.

parameters:
r_num - Runway number.
r_type - Runway type - DOMESTIC / INTERNATIONAL.

return values:
Result parameter - FAILURE / SUCCESS.
***********************************************************/
Result addRunway(int r_num, FlightType r_type){
    if (r_num<1 || r_num>MAX_ID || (r_type!=DOMESTIC && r_type!=INTERNATIONAL)){
        return FAILURE;
    }
    pRunwayNode curr = head;
    while(curr){
        if (getRunwayNum(curr->cur_runway) ==r_num){
            return FAILURE;
        }
        curr=curr->next_runway;
    }
    pRunway pNewRunway = createRunway(r_num, r_type);
    if (!pNewRunway){
        return FAILURE;
    }
    pRunwayNode new_runway_node = (pRunwayNode)malloc(sizeof(runwayNode));
    if (!new_runway_node){
        return FAILURE;
    }
    new_runway_node->cur_runway=pNewRunway;
    new_runway_node->next_runway =NULL;
    curr = head;
    if(head == NULL) {
        head = new_runway_node;
    }
    else {
        while (curr->next_runway) {
            curr = curr->next_runway;
        }
        curr->next_runway = new_runway_node;
    }
    return SUCCESS;
}
/***********************************************************
function name: removeRunway

description:
The function removes the runway with the given number, and all of its flights.

parameters:
r_num - The ID of the runway to be removed.

return values:
SUCCESS if the runway was removed and FAILURE if an error occurred.
***********************************************************/
Result removeRunway(int r_num){
    if (r_num<1 || r_num>MAX_ID || !head){
        return FAILURE;
    }
    pRunwayNode current = head;
    pRunwayNode *points_to_current = &(head);
    while (current != NULL) {
        if (getRunwayNum(current->cur_runway) == r_num) {
            *points_to_current = current->next_runway;
            destroyRunway(current->cur_runway);
            free(current);
            return SUCCESS;
        }
        points_to_current=&(current->next_runway);
        current = current->next_runway;
    }
    return FAILURE;
}
/***********************************************************
function name: addFlightToAirport

description:
The function adds the given flight to a runway according to the rules specified in the instructions

parameters:
f_num - The ID of the flight to be added.
f_type - Flight type - DOMESTIC / INTERNATIONAL.
dest - Array of 3 capital letters.
emergency - BOOL parameter - TRUE if flight is emergency, FALSE if not.

return values:
SUCCESS if the flight was added and FAILURE if an error occurred.
***********************************************************/
Result addFlightToAirport(int f_num, FlightType f_type, char dest[4], BOOL emergency){
    if (f_num<1 || f_num>MAX_ID) {
        return FAILURE;
    }
    pRunwayNode emptiest_runway=head;
    pRunwayNode curr=head;
    BOOL runway_found=FALSE;
    while (curr){
        if (isFlightExists(curr->cur_runway, f_num)){
            return FAILURE;
        }
        if (getRunwayType(curr->cur_runway)==f_type) {
            runway_found=TRUE;
            if(getRunwayType(emptiest_runway->cur_runway)!=f_type){ //New: Check if the emptiest runway is actually the right type
                emptiest_runway=curr;
            }
            if (getFlightNum(curr->cur_runway) < getFlightNum(emptiest_runway->cur_runway)) {
                emptiest_runway = curr;
            } else if (getFlightNum(curr->cur_runway) == getFlightNum(emptiest_runway->cur_runway)) {
                if (getRunwayNum(curr->cur_runway) < getRunwayNum(emptiest_runway->cur_runway)) {
                    emptiest_runway = curr;
                }
            }

        }
        curr = curr->next_runway;
    }
    if (runway_found){
        pFlight f=createFlight(f_num, f_type, dest, emergency);
        if (addFlight(emptiest_runway->cur_runway, f)){
            return SUCCESS;
        }
    }
    return FAILURE;
}
/***********************************************************
function name: departAirport

description:
remove first flight from a runway chosen according to given priority list:
the runway that contains largest num of emergency flights.
if none exists, the runway with largest number of flights.
the runway with smallest ID.

parameters:
NONE.

return values:
SUCCESS if the flight was removed and FAILURE if an error occurred.
***********************************************************/
Result departAirport(){
    pRunwayNode most_emergency=head;
    pRunwayNode curr=head;
    if(!curr){
        return FAILURE;
    }
    while(curr){
        if (getEmergencyNum(curr->cur_runway)>getEmergencyNum(most_emergency->cur_runway)){
            most_emergency=curr;
        }
        else if(getEmergencyNum(curr->cur_runway)==getEmergencyNum(most_emergency->cur_runway)) {
            if(getFlightNum(curr->cur_runway)>getFlightNum(most_emergency->cur_runway)) {
                most_emergency = curr;
            }
            else if(getRunwayNum(curr->cur_runway)<getRunwayNum((most_emergency->cur_runway))){
                most_emergency = curr;
            }
        }
        curr=curr->next_runway;
    }
    if(depart(most_emergency->cur_runway)){
        return SUCCESS;
    }
    return FAILURE;
}
/***********************************************************
function name: changeDest

description:
search in flight list for given destination and change it to a new value (given).

parameters:
dest - current flight destination, array of 3 capital letters.
new_dest - updated flight destination, array of 3 capital letters.

return values:
SUCCESS if destination was changed and FAILURE if an error occurred.
***********************************************************/
Result changeDest(char dest[4], char new_dest[4]){
    if(!checkDestination(dest) || !checkDestination(new_dest)){
        return FAILURE;
    }
    pRunwayNode curr_runway=head;
    pFlightList curr_flight;
    if(!curr_runway){
        return FAILURE;
    }
    while(curr_runway){
        curr_flight=getFlightList(curr_runway->cur_runway);
        while(curr_flight){
            if(strcmp(getDestination(getFlight(curr_flight)),dest) == 0){
                setDestination(getFlight(curr_flight),new_dest);
            }
            curr_flight=getNextFlight(curr_flight);
        }
        curr_runway=curr_runway->next_runway;
    }
    return SUCCESS;
}
/***********************************************************
function name: delay

description:
move flights with given destination to the end of their runway list.

parameters:
dest - flight destination, array of 3 capital letters.

return values:
SUCCESS if flight was delayed and FAILURE if an error occurred.
***********************************************************/
Result delay(char dest[4]){
    BOOL delayed [MAX_ID];
    int i;
    for( i=1; i<MAX_ID;i++){
        delayed[i]=FALSE;
    }
    for ( i=0; i<3; i++){
        if (dest[i]<'A' || dest[i]>'Z'){
            return FAILURE;
        }
    }
    pRunwayNode curr_runway=head;
    pFlightList curr_flight;
    pFlightList next_flight;
    pFlight f;
    while(curr_runway){
        curr_flight=getFlightList(curr_runway->cur_runway);
        while(curr_flight){
            f=getFlight(curr_flight);
            next_flight=getNextFlight(curr_flight);
            if(strcmp(getDestination(f),dest) == 0 && delayed[getFlightID(f)]!=TRUE){ //Flag added to check if flight was previously delayed
                delayed[getFlightID(f)]=TRUE;
                pFlight delayed_flight=createFlight(getFlightID(f), getFlightType(f), getDestination(f), isEmergency(f));
                Result flight_removed= removeFlight(curr_runway->cur_runway,getFlightID(f));
                if (!delayed_flight || !flight_removed){
                    return  FAILURE;
                }
                if (!addFlight(curr_runway->cur_runway,delayed_flight)){
                    return  FAILURE;
                }
            }
            curr_flight=next_flight;
        }
        curr_runway=curr_runway->next_runway;
    }
    return  SUCCESS;
}
/***********************************************************
function name: printAirport

description:
print all runways and all their associated flights.

parameters:
NONE.

return values:
NONE.
***********************************************************/
void printAirport(){
    pRunwayNode curr_runway=head;
    printf("Airport status:\n");
    while(curr_runway){
        printRunway(curr_runway->cur_runway);
        curr_runway=curr_runway->next_runway;
    }
    printf("\n");
}
/***********************************************************
function name: destroyAirport

description:
free all runways and all their associated flights.

parameters:
NONE.

return values:
NONE.
***********************************************************/
void destroyAirport(){
    pRunwayNode curr_runway=head;
    pRunwayNode next_runway_node;
    while(curr_runway){
        destroyRunway(curr_runway->cur_runway);
        next_runway_node=curr_runway->next_runway;
        free(curr_runway);
        curr_runway=next_runway_node;
    }
}