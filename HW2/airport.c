//
// Created by Keren on 05/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "airport.h"
/*struct _flightList;
typedef struct _flightList* pFlightList;*/
struct _runwayNode;
typedef struct _runwayNode* pRunwayNode;
typedef struct _runwayNode{
    pRunway cur_runway;
    pRunwayNode next_runway;
} runwayNode;
pRunwayNode head=NULL; //TODO: Maybe change to global variable
Result addRunway(int r_num, FlightType r_type){
    if (r_num<1 || r_num>MAX_ID || (r_type!=DOMESTIC && r_type!=INTERNATIONAL)){//TODO: check flightype???
        return FAILURE;
    }
    pRunwayNode curr = head;
    while(curr){
        if (getRunwayNum(curr->cur_runway) ==r_num){
            return FAILURE;
        }
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
            if (getFlightNum(curr->cur_runway) < getFlightNum(emptiest_runway->cur_runway)) {
                emptiest_runway = curr;
            } else if (getFlightNum(curr->cur_runway) == getFlightNum(emptiest_runway->cur_runway)) {
                if (getRunwayNum(curr->cur_runway) < getRunwayNum(emptiest_runway->cur_runway)) {
                    emptiest_runway = curr;
                }
            }
            curr = curr->next_runway;
        }
    }
    if (runway_found){
        pFlight f=createFlight(f_num, f_type, dest, emergency);
        if (addFlight(emptiest_runway->cur_runway, f)){
            return SUCCESS;
        }
    }
    return FAILURE;
}
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
Result changeDest(char dest[4], char new_dest[4]){
    for (int i=0; i<3; i++){//TODO: add this to other input checks or make this a function
        if (dest[i]<65 || dest[i]>90 || new_dest[i]<65 || new_dest[i]>90){
            return FAILURE;
        }
    }
    pRunwayNode curr_runway=head;
    pFlightList curr_flight;
    if(!curr_runway){//TODO:what to do if no runway exists?(probably SUCCESS)
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
Result delay(char dest[4]){
    for (int i=0; i<3; i++){
        if (dest[i]<65 || dest[i]>90){
            return FAILURE;
        }
    }
    pRunwayNode curr_runway=head;
    pFlightList curr_flight;
    pFlight f;
    while(curr_runway){
        curr_flight=getFlightList(curr_runway->cur_runway);
        while(curr_flight){
            f=getFlight(curr_flight);
            if(strcmp(getDestination(f),dest) == 0){
                pFlight delayed_flight=createFlight(getFlightID(f), getFlightType(f), getDestination(f), isEmergency(f));
                Result flight_removed= removeFlight(curr_runway->cur_runway,getFlightID(f));
                if (!delayed_flight || !flight_removed){
                    return  FAILURE;
                }
                if (!addFlight(curr_runway->cur_runway,delayed_flight)){
                    return  FAILURE;
                }
            }
            curr_flight=getNextFlight(curr_flight);
        }
        curr_runway=curr_runway->next_runway;
    }
    return  SUCCESS;
}
void printAirport(){
    if(!head){
        return;
    }
    pRunwayNode curr_runway=head;
    printf("Airport status:\n");
    while(curr_runway){
        printRunway(curr_runway->cur_runway);
    }
}
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