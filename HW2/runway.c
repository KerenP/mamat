//
// Created by Keren on 02/12/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "runway.h"
#include "ex2.h"
struct _flightList;
typedef struct _flightList* pFlightList;
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
    if(r->flight_list != NULL)
        free(r->flight_list);
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
            flightList new_flight;
            new_flight.cur_flight=ptr;
            if (isEmergency(f)){
                new_flight.next_flight=r->flight_list;
                r->flight_list=&new_flight;
            }
            else {
                new_flight.next_flight = NULL;
                pFlightList end = r->flight_list;
                while (end->next_flight) {
                    end = end->next_flight;
                }
                end->next_flight = &new_flight;
            }
            return SUCCESS;
        }
    }
    return FAILURE;
}
