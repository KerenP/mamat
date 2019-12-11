//airport.h

#ifndef HW2_AIRPORT_H
#define HW2_AIRPORT_H
#include "ex2.h"
#include "runway.h"

/***********************************************************
function name: addRunway

description:
Add a new runway record with given num and type.

parameters:
r_num - Runway number.
r_type - Runway type - DOMESTIC / INTERNATIONAL.

return values:
Result parameter - FAILURE / SUCCESS.
***********************************************************/
Result addRunway(int r_num, FlightType r_type);
/***********************************************************
function name: removeRunway

description:
The function removes the runway with the given number, and all of its flights.

parameters:
r_num - The ID of the runway to be removed.

return values:
SUCCESS if the runway was removed and FAILURE if an error occurred.
***********************************************************/
Result removeRunway(int r_num);
/***********************************************************
function name: addFlightToAirport

description:
The function adds the given flight to a runway according to the rules specified in the instructions

parameters:
f_num - The ID of the flight to be added.
f_type - Flight type - DOMESTIC / INTERNATIONAL.
dest - Array of 3 capital letters.
emergency - BOOL parameter - TRUE if flight is emergency, FALSE if not.

return values:
SUCCESS if the flight was added and FAILURE if an error occurred.
***********************************************************/
Result addFlightToAirport(int f_num, FlightType f_type, char dest[4], BOOL emergency);
/***********************************************************
function name: departAirport

description:
remove first flight from a runway chosen according to given priority list:
the runway that contains largest num of emergency flights.
if none exists, the runway with largest number of flights.
the runway with smallest ID.

parameters:
NONE.

return values:
SUCCESS if the flight was removed and FAILURE if an error occurred.
***********************************************************/
Result departAirport();
/***********************************************************
function name: changeDest

description:
search in flight list for given destination and change it to a new value (given).

parameters:
dest - current flight destination, array of 3 capital letters.
new_dest - updated flight destination, array of 3 capital letters.

return values:
SUCCESS if destination was changed and FAILURE if an error occurred.
***********************************************************/
Result changeDest(char dest[4], char new_dest[4]);
/***********************************************************
function name: delay

description:
move flights with given destination to the end of their runway list.

parameters:
dest - flight destination, array of 3 capital letters.

return values:
SUCCESS if flight was delayed and FAILURE if an error occurred.
***********************************************************/
Result delay(char dest[4]);
/***********************************************************
function name: printAirport

description:
print all runways and all their associated flights.

parameters:
NONE.

return values:
NONE.
***********************************************************/
void printAirport();
/***********************************************************
function name: destroyAirport

description:
free all runways and all their associated flights.

parameters:
NONE.

return values:
NONE.
***********************************************************/
void destroyAirport();
#endif //HW2_AIRPORT_H
