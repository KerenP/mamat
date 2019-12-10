//runway.h

#ifndef HW2_RUNWAY_H
#define HW2_RUNWAY_H
#include "ex2.h"
#include "flight.h"
struct  runway;
typedef struct runway* pRunway;
struct _flightList;
typedef struct _flightList* pFlightList;
/***********************************************************
function name: createRunway

description:
The function  Creates a new instance of a runway struct with given parameters and allocates memory for an  new runway.

parameters:
r_num - Runway number.
r_type - Runway type - DOMESTIC / INTERNATIONAL.

return values:
Pointer to runway struct of type pRunway.
***********************************************************/
pRunway createRunway(int r_num, FlightType r_type);
/***********************************************************
function name: destroyRunway

description:
The function destroys the given runway by removing all the flights in the list and freeing the memory allocated
for the runway.

parameters:
r- a pointer to a runway to destroy.

return values:
No return values.
***********************************************************/
void destroyRunway(pRunway r);
/***********************************************************
function name: isFlightExists

description:
The function checks if a flight with the given number exists in the given runway.

parameters:
r- A pointer to a runway in which we want to search for a flight.
f_num - The ID of the flight to search for in the runway.

return values:
TRUE if the flight exists in the runway and FALSE if it doesn't.
***********************************************************/
BOOL isFlightExists(pRunway r, int f_num);
/***********************************************************
function name: getFlightNum

description:
The function returns the number of flights in the given runway.

parameters:
r- A pointer to a runway in which we want to count the number of flights


return values:
An integer representing the number of flights in the flight list of the runway.
***********************************************************/
int getFlightNum(pRunway r);
/***********************************************************
function name: getEmergencyNum

description:
The function returns the number of emergency flights in the given runway.

parameters:
r- A pointer to a runway in which we want to count the number of emergency flights


return values:
An integer representing the number of emergency flights in the flight list of the runway.
***********************************************************/
int getEmergencyNum(pRunway r);
/***********************************************************
function name: addFlight

description:
The function adds the given flight to the given runway according to the rules specified in the instructions:
If it's an emergency flight - insert it before the regular flights after all the other emergency flights.
If it's a regular flight insert it to the end of the list.

parameters:
r- A pointer to a runway to which we want to add a flight.
f- A pointer to a flight that we want to add to the runway.

return values:
SUCCESS if the flight was added and FAILURE if an error occurred.
***********************************************************/
Result addFlight(pRunway r, pFlight f);
/***********************************************************
function name: removeFlight

description:
The function removes the flight with the given flight ID from the given runway.

parameters:
r- A pointer to a runway from which we want to remove a flight.
f_num- The ID of the flight to be removed.

return values:
SUCCESS if the flight was removed and FAILURE if an error occurred.
***********************************************************/
Result removeFlight(pRunway r, int f_num);
/***********************************************************
function name: depart

description:
The function removes the first flight in the flight list of the given runway.

parameters:
r- A pointer to a runway from which we want to remove a flight.

return values:
SUCCESS if the flight was removed and FAILURE if an error occurred.
***********************************************************/
Result depart(pRunway r);
/***********************************************************
function name: printRunway

description:
The function prints the details of the runway and the details of all the flights in the flight list.

parameters:
r- A pointer to a runway to be printed.

return values:
No return value.
***********************************************************/
void printRunway(pRunway r);
/***********************************************************
function name: getRunwayNum, getRunwayType, getFlightList

description:
The functions which name begins with get and operate on a runway - return the value/pointer of a
runway field (ID, Type and flight list) , specified in the function name, of the given runway.

parameters:
r - A pointer to a runway from which we want to get information.

return values:
The value/pointer of the field specified in the function name - ID, Type and flight list.
***********************************************************/
int getRunwayNum(pRunway r);
FlightType getRunwayType(pRunway r);
pFlightList getFlightList(pRunway r);
/***********************************************************
function name: getNextFlight, getFlight

description:
The functions which name begins with get and operate on a flight list node return poiners to the fields of the
flight list , specified in the function name, of the given flight list.

parameters:
flightNode - A pointer to a flight list from which we want to get information.

return values:
The pointer of the field specified in the function name - current flight or next node.
***********************************************************/
pFlightList getNextFlight(pFlightList flightNode);
pFlight getFlight(pFlightList flightNode);
#endif //HW2_RUNWAY_H
