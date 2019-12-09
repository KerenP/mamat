//
// Created by Keren on 02/12/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "runway.h"
#include "ex2.h"
//struct _flightList;
//typedef struct _flightList* pFlightList;
typedef struct _flightList{
    pFlight cur_flight;
    pFlightList next_flight;
} flightList;
struct runway{
    int r_num;
    FlightType r_type;
    pFlightList flight_list;
};
pRunway createRunway(int r_num, FlightType r_type){
    pRunway r;
    if (r_num<1 || r_num>MAX_ID)     //TODO: add additional parameters check
        return NULL;
    r=(pRunway)malloc(sizeof(struct runway));
    if(r == NULL)
        return NULL;
    r->r_num = r_num;
    r->r_type = r_type;
    r->flight_list = NULL;
    return r;
}
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
BOOL isFlightExists(pRunway r, int f_num){
    if (f_num>0 && f_num<MAX_ID && r != NULL)
    {
        pFlightList ptr;
        ptr = r->flight_list;
        while (ptr!=NULL && getFlightID(ptr->cur_flight) != f_num ){
            ptr=ptr->next_flight;
        }
        if (ptr != NULL)
            return TRUE;
    }
    return FALSE;
}
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
Result addFlight(pRunway r, pFlight f){
    if (r!=NULL && f!=NULL){
        if ((!isFlightExists(r,getFlightID(f))) && (getFlightType(f)==r->r_type)){
            pFlight ptr=createFlight(getFlightID(f),getFlightType(f),getDestination(f),isEmergency(f));
            pFlightList new_flight;
            new_flight = (pFlightList)malloc(sizeof(flightList));
            if(!new_flight)
                return FAILURE;
            new_flight->cur_flight=ptr;
            new_flight->next_flight=NULL;
            if(r->flight_list == NULL) {
                r->flight_list = new_flight;
                return SUCCESS;
            }
            if (isEmergency(f)){
                pFlightList curr = r->flight_list;
                if(!isEmergency(curr->cur_flight)){
                    new_flight->next_flight=curr;
                    r->flight_list=new_flight;
                    return SUCCESS;
                }
                while ( curr->next_flight!=NULL && isEmergency((curr->next_flight)->cur_flight)) {
                    curr = curr->next_flight;
                }
                new_flight->next_flight = curr->next_flight;
                curr->next_flight = new_flight;
            }
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
Result removeFlight(pRunway r, int f_num){
        if (r==NULL || r->flight_list==NULL)
            return FAILURE;
        pFlightList current = r->flight_list;
        pFlightList *points_to_current = &(r->flight_list);
        while (current != NULL) {
            if (getFlightID(current->cur_flight) == f_num) {
                *points_to_current = current->next_flight;
                destroyFlight(current->cur_flight);
                free(current);
                return SUCCESS;
            }
            points_to_current=&(current->next_flight);
            current = current->next_flight;
        }
        return FAILURE;
    }
Result depart(pRunway r){
    if(r==NULL || r->flight_list == NULL)
        return FAILURE;
    return removeFlight(r, getFlightID((r->flight_list)->cur_flight));
}
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
int getRunwayNum(pRunway r){
    return r->r_num;
}
FlightType getRunwayType(pRunway r){
    return r->r_type;
}
pFlightList getNextFlight(pFlightList flightNode){
    return flightNode->next_flight;
}
pFlight getFlight(pFlightList flightNode){
    return flightNode->cur_flight;
}
pFlightList getFlightList(pRunway r){
    if(r){
        return r->flight_list;
    }
    return NULL;
}