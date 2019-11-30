//
// Created by Marina on 30/11/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "flight.h"
#include "ex2.h"
int main(){
    int fNum=1;
    FlightType fType=DOMESTIC;
    char* destination="TLV";
    BOOL emergency=TRUE;
    pFlight f;
    f=createFlight(fNum, fType,destination,emergency);
    printFlight(f);
    destroyFlight(f);
}


