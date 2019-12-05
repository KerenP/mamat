//
// Created by Keren on 02/12/2019.
//

#ifndef HW2_RUNWAY_H
#define HW2_RUNWAY_H
#include "ex2.h"
#include "flight.h"
struct  runway;
typedef struct runway* pRunway;
//struct flightList;
//typedef struct flightList* pFlightList;
pRunway createRunway(int r_num, FlightType r_type);
void destroyRunway(pRunway r);
BOOL isFlightExists(pRunway r, int f_num);
int getFlightNum(pRunway r);
int getEmergencyNum(pRunway r);
Result addFlight(pRunway r, pFlight f);
Result removeFlight(pRunway r, int f_num);
Result depart(pRunway r);
void printRunway(pRunway r);
int getRunwayNum(pRunway r);
FlightType getRunwayType(pRunway r);
#endif //HW2_RUNWAY_H
