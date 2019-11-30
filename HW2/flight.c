//
// Created by Marina on 30/11/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "flight.h"
#include "ex2.h"
struct flight {
    int f_Num;
    FlightType  f_type;
    char* dest;
    BOOL emergency;
};
pFlight createFlight(int f_Num , FlightType f_type, char* dest, BOOL emergency ){
    pFlight f;
    if (f_Num<1 || f_Num>MAX_ID)     //add additional parameters check
        return NULL;
    f=(pFlight)malloc(sizeof(struct flight));
    if(f == NULL)
        return NULL;
    f->f_Num = f_Num;
    f->f_type = f_type;
    f->dest = (char*)mallcoc(4); //add define
    if(f->dest == NULL)
        return NULL;
    f->emergency = emergency;
}

void destroyFlight(pFlight f){
    if(f == NULL)
        return;
    free(f->dest);
    free(f);
}

void printFlight(pFlight f){
    if(f == NULL)
        return;
    printf("Flight %d %c %s %c", f->f_Num, (f->f_type == DOMESTIC ? 'D' : 'I'), f->dest, (f->emergency ? 'E' : 'R'));
}
