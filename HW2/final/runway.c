//runway.c

#include <stdio.h>
#include <stdlib.h>
#include "runway.h"
#include "ex2.h"
//Create an inner struct that represents a linked list of flights
typedef struct _flightList{
    pFlight cur_flight;
    pFlightList next_flight;
} flightList;

struct runway{
    int r_num;
    FlightType r_type;
    pFlightList flight_list;
};

/***********************************************************
function name: createRunway

description:
The function  Creates a new instance of a runway struct with given parameters and allocates memory for an  new runway.

parameters:
r_num - Runway number.
r_type - Runway type - DOMESTIC / INTERNATIONAL.

return values:
Pointer to runway struct of type pRunway.
***********************************************************/

pRunway createRunway(int r_num, FlightType r_type){
    pRunway r;
    if (r_num<1 || r_num>MAX_ID || ((r_type!=DOMESTIC) && (r_type!=INTERNATIONAL))) // check if parameters are valid
        return NULL;
    r=(pRunway)malloc(sizeof(struct runway)); // allocate memory for a new runway.
    if(r == NULL)
        return NULL;
    r->r_num = r_num;
    r->r_type = r_type;
    r->flight_list = NULL;
    return r;
}

/***********************************************************
function name: destroyRunway

description:
The function destroys the given runway by removing all the flights in the list and freeing the memory allocated
for the runway.

parameters:
r- a pointer to a runway to destroy.

return values:
No return values.
***********************************************************/

void destroyRunway(pRunway r){
    if(r == NULL)
        return;
    if(r->flight_list != NULL) {
        pFlightList curr = r->flight_list;
        while (curr!=NULL){
            removeFlight(r,getFlightID(curr->cur_flight));
            curr=curr->next_flight;
        }
    }
    free(r);
}

/***********************************************************
function name: isFlightExists

description:
The function checks if a flight with the given number exists in the given runway.

parameters:
r- A pointer to a runway in which we want to search for a flight.
f_num - The ID of the flight to search for in the runway.

return values:
TRUE if the flight exists in the runway and FALSE if it doesn't.
***********************************************************/

BOOL isFlightExists(pRunway r, int f_num){
    if (f_num>0 && f_num<MAX_ID && r != NULL)
    {
        pFlightList ptr;
        ptr = r->flight_list;
        //Go through the flight list until a flight with the desired ID is found
        while (ptr!=NULL && getFlightID(ptr->cur_flight) != f_num ){
            ptr=ptr->next_flight;
        }
        if (ptr != NULL)
            return TRUE;
    }
    return FALSE;
}

/***********************************************************
function name: getFlightNum

description:
The function returns the number of flights in the given runway.

parameters:
r- A pointer to a runway in which we want to count the number of flights


return values:
An integer representing the number of flights in the flight list of the runway.
***********************************************************/

int getFlightNum(pRunway r){
    if(r == NULL)
        return -1;
    pFlightList ptr;
    ptr = r->flight_list;
    int count_flight=0;
    while (ptr!=NULL){
        count_flight++;
        ptr=ptr->next_flight;
    }
    return count_flight;
}

/***********************************************************
function name: getEmergencyNum

description:
The function returns the number of emergency flights in the given runway.

parameters:
r- A pointer to a runway in which we want to count the number of emergency flights


return values:
An integer representing the number of emergency flights in the flight list of the runway.
***********************************************************/

int getEmergencyNum(pRunway r){
    if(r == NULL)
        return -1;
    pFlightList ptr;
    ptr = r->flight_list;
    int count_emergency=0;
    while (ptr!=NULL){
        if (isEmergency((ptr->cur_flight)))
            count_emergency++;
        ptr=ptr->next_flight;
    }
    return count_emergency;
}

/***********************************************************
function name: addFlight

description:
The function adds the given flight to the given runway according to the rules specified in the instructions:
If it's an emergency flight - insert it before the regular flights after all the other emergency flights.
If it's a regular flight insert it to the end of the list.

parameters:
r- A pointer to a runway to which we want to add a flight.
f- A pointer to a flight that we want to add to the runway.

return values:
SUCCESS if the flight was added and FAILURE if an error occurred.
***********************************************************/

Result addFlight(pRunway r, pFlight f){
    if (r!=NULL && f!=NULL){
        //add the flight if it doesn't already exist and if the type of the runway match the flight type.
        if ((!isFlightExists(r,getFlightID(f))) && (getFlightType(f)==r->r_type)){
            pFlight ptr=createFlight(getFlightID(f),getFlightType(f),getDestination(f),isEmergency(f));
            pFlightList new_flight;
            new_flight = (pFlightList)malloc(sizeof(flightList)); //Allocate a flight list node to contain the new flight.
            if(!new_flight)
                return FAILURE;
            new_flight->cur_flight=ptr;
            new_flight->next_flight=NULL;
            //if the flight list is empty insert the node at the top of the list.
            if(r->flight_list == NULL) {
                r->flight_list = new_flight;
                return SUCCESS;
            }
            //Inserting an emergency flight:
            if (isEmergency(f)){
                pFlightList curr = r->flight_list;
                //if there are no emergency flights in the list insert this flight at the top of the list.
                if(!isEmergency(curr->cur_flight)){
                    new_flight->next_flight=curr;
                    r->flight_list=new_flight;
                    return SUCCESS;
                }
                //Reach the last emergency flight in the list to insert the given flight after it.
                while ( curr->next_flight!=NULL && isEmergency((curr->next_flight)->cur_flight)) {
                    curr = curr->next_flight;
                }
                new_flight->next_flight = curr->next_flight;
                curr->next_flight = new_flight;
            }
            //Inserting a regular flight at the end of the list:
            else {
                pFlightList end = r->flight_list;
                while (end->next_flight) {
                    end = end->next_flight;
                }
                end->next_flight = new_flight;
            }
            return SUCCESS;
        }
    }
    return FAILURE;
}

/***********************************************************
function name: removeFlight

description:
The function removes the flight with the given flight ID from the given runway.

parameters:
r- A pointer to a runway from which we want to remove a flight.
f_num- The ID of the flight to be removed.

return values:
SUCCESS if the flight was removed and FAILURE if an error occurred.
***********************************************************/

Result removeFlight(pRunway r, int f_num){
        if (r==NULL || r->flight_list==NULL)
            return FAILURE;
        pFlightList current = r->flight_list;
        pFlightList *points_to_current = &(r->flight_list);//pointer to the current pointer (the address of curr)
        while (current != NULL) {
            if (getFlightID(current->cur_flight) == f_num) {
                //If the flight with the given ID was found make the pinter to the current node point to the next node.
                *points_to_current = current->next_flight;
                destroyFlight(current->cur_flight); //Destroy the flight and free the removed node.
                free(current);
                return SUCCESS;
            }
            points_to_current=&(current->next_flight);
            current = current->next_flight;
        }
        return FAILURE;
    }

/***********************************************************
function name: depart

description:
The function removes the first flight in the flight list of the given runway.

parameters:
r- A pointer to a runway from which we want to remove a flight.

return values:
SUCCESS if the flight was removed and FAILURE if an error occurred.
***********************************************************/

Result depart(pRunway r){
    if(r==NULL || r->flight_list == NULL)
        return FAILURE;
    return removeFlight(r, getFlightID((r->flight_list)->cur_flight));
}

/***********************************************************
function name: printRunway

description:
The function prints the details of the runway and the details of all the flights in the flight list.

parameters:
r- A pointer to a runway to be printed.

return values:
No return value.
***********************************************************/

void printRunway(pRunway r){
    if(r==NULL || getFlightNum(r)==-1){
        return;
    }
    int f=getFlightNum(r);
    printf("Runway %d %s\n%d flights are waiting:\n",r->r_num,(r->r_type == DOMESTIC ? "domestic" : "international"),f);
    pFlightList ptr=r->flight_list;
    while(ptr){
        printFlight(ptr->cur_flight);
        ptr=ptr->next_flight;
    }
}

/***********************************************************
function name: getRunwayNum, getRunwayType, getFlightList

description:
The functions which name begins with get and operate on a runway - return the value/pointer of a
runway field (ID, Type and flight list) , specified in the function name, of the given runway.

parameters:
r - A pointer to a runway from which we want to get information.

return values:
The value/pointer of the field specified in the function name - ID, Type and flight list.
***********************************************************/
int getRunwayNum(pRunway r){
    return r->r_num;
}
FlightType getRunwayType(pRunway r){
    return r->r_type;
}
pFlightList getFlightList(pRunway r){
    if(r){
        return r->flight_list;
    }
    return NULL;
}

/***********************************************************
function name: getNextFlight, getFlight

description:
The functions which name begins with get and operate on a flight list node return poiners to the fields of the
flight list , specified in the function name, of the given flight list.

parameters:
flightNode - A pointer to a flight list from which we want to get information.

return values:
The pointer of the field specified in the function name - current flight or next node.
***********************************************************/

pFlightList getNextFlight(pFlightList flightNode){
    return flightNode->next_flight;
}
pFlight getFlight(pFlightList flightNode){
    return flightNode->cur_flight;
}
