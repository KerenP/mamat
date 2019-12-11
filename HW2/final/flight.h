//flight.h

#ifndef HW2_FLIGHT_H
#define HW2_FLIGHT_H

#include <string.h>
#include "ex2.h"
#define DEST_SIZE (4)
struct flight;
typedef struct flight* pFlight;
/***********************************************************
function name: createFlight

description:
the function  Creates a new instance of a flight struct with given parameters.

parameters:
f_Num - Flight number.
f_type - Flight type - DOMESTIC / INTERNATIONAL.
dest - String of constant length 4 containing flight destination.
emergency - Boolean indicating if its an emergency flight.

return values:
Pointer to flight struct of type PFlight.
***********************************************************/
pFlight createFlight(int f_Num , FlightType f_type, char dest[4], BOOL emergency );
/***********************************************************
function name: destroyFlight

description:
The function destroys the given flight by freeing all the allocated memory.

parameters:
f- a pointer to a flight to destroy.

return values:
No return values.
***********************************************************/
void destroyFlight(pFlight f);
/***********************************************************
function name: printFlight

description:
The function prints the flight parameters - ID , Type (DOMESTIC / INTERNATIONAL), Destination & Emergency or Regular.

parameters:
f- a pointer to a flight to destroy.

return values:
No return values.
***********************************************************/
void printFlight(pFlight f);
/***********************************************************
function name: Get Functions

description:
The functions which name begins with get return the value of the field, specified in the function name, of the given
flight.

parameters:
f- A pointer to a flight from which we want to get parameters.

return values:
The value of the field specified in the function name - ID, Flight type, Destination, and if it's an Emergency.
***********************************************************/
int getFlightID(pFlight f);
FlightType getFlightType(pFlight f);
BOOL isEmergency(pFlight f);
char* getDestination(pFlight f);
/***********************************************************
function name: setDestination

description:
The function changes the flights destination to a new destination.

parameters:
f- A pointer to a flight which destination we want to change.

return values:
SUCCESS or FAILURE to change the flight destination
***********************************************************/
Result setDestination(pFlight f, char new_dest[4]);
/***********************************************************
function name: checkDestination

description:
The function checks if the destination consists of three capital letters.

parameters:
dest - String of constant length 4 containing flight destination.

return values:
TRUE if dest is a valid destination and FALSE if not.
***********************************************************/
BOOL checkDestination(char dest[4]);
/***********************************************************
function name: validFlight

description:
The function checks if all the flight parameters are valid

parameters:
f_Num - Flight number.
f_type - Flight type - DOMESTIC / INTERNATIONAL.
dest - String of constant length 4 containing flight destination.
emergency - Boolean indicating if its an emergency flight.

return values:
TRUE if all parameters are valid and False if there is some mistake.
***********************************************************/
BOOL validFlight(int f_Num , FlightType f_type, char dest[4], BOOL emergency );
#endif //HW2_FLIGHT_H
