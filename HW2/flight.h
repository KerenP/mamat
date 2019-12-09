//
// Created by Marina on 30/11/19.
//

#ifndef HW2_FLIGHT_H
#define HW2_FLIGHT_H

#include <string.h>
#include "ex2.h"
#define DEST_SIZE (4)
struct flight;
typedef struct flight* pFlight;
pFlight createFlight(int f_Num , FlightType f_type, char dest[4], BOOL emergency );
void destroyFlight(pFlight f);
void printFlight(pFlight f);
int getFlightID(pFlight f);
FlightType getFlightType(pFlight f);
BOOL isEmergency(pFlight f);
char* getDestination(pFlight f);
Result setDestination(pFlight f, char new_dest[4]);
BOOL checkDestination(char dest[4]);
BOOL validFlight(int f_Num , FlightType f_type, char dest[4], BOOL emergency );
#endif //HW2_FLIGHT_H
