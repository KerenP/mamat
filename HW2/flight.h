//
// Created by Marina on 30/11/19.
//

#ifndef HW2_FLIGHT_H
#define HW2_FLIGHT_H
#include "ex2.h"
struct flight;
typedef struct flight* pFlight;
pFlight createFlight(int f_Num , FlightType f_type, char dest[4], BOOL emergency );
void destroyFlight(pFlight f);
void printFlight(pFlight f);
int getFlightID(pFlight f);
FlightType getFlightType(pFlight f);
BOOL isEmergency(pFlight f);
char* getDestination(pFlight f);
#endif //HW2_FLIGHT_H
