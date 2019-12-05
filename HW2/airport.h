//
// Created by Keren on 05/12/2019.
//

#ifndef HW2_AIRPORT_H
#define HW2_AIRPORT_H
#include "ex2.h"
#include "runway.h"

Result addRunway(int r_num, FlightType r_type);
Result removeRunway(int r_num);
Result addFlightToAirport(int f_num, FlightType f_type, char dest[4], BOOL emergency);
Result departAirport();
Result changeDest(char dest[4], char new_dest[4]);
Result delay(char dest[4]);
void printAirport();
void destroyAirport();
#endif //HW2_AIRPORT_H
