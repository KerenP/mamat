//
// Created by Marina on 04/12/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "runway.h"
#include "ex2.h"
int main(){
    int fNum1=1;
    FlightType fType=DOMESTIC;
    char* destination1="TLV";
    BOOL emergency1=FALSE;
    pFlight f1;
    f1=createFlight(fNum1, fType,destination1,emergency1);
    printFlight(f1);

    int fNum=2;
    char* destination="NAR";
    BOOL emergency=TRUE;
    pFlight f;
    f=createFlight(fNum, fType,destination,emergency);
    printFlight(f);

    int rNum=1;
    FlightType rType=DOMESTIC;
    pRunway r;
    r=createRunway(rNum, rType);
    addFlight(r,f1);
    addFlight(r,f);

    printRunway(r);
    destroyRunway(r);
    destroyFlight(f1);
    destroyFlight(f);
}


