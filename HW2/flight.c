//flight.c

#include <stdio.h>
#include <stdlib.h>
#include "flight.h"

struct flight {
    int f_Num;
    FlightType  f_type;
    char dest[DEST_SIZE];
    BOOL emergency;
};

/***********************************************************
function name: checkDestination

description:
The function checks if the destination consists of three capital letters.

parameters:
dest - String of constant length 4 containing flight destination.

return values:
TRUE if dest is a valid destination and FALSE if not.
***********************************************************/

BOOL checkDestination(char dest[DEST_SIZE]){
    for (int i=0; i<DEST_SIZE-1; i++) {
        if (dest[i] < 'A' || dest[i] > 'Z') {
            return FALSE;
        }
    }
    return TRUE;
}
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

BOOL validFlight(int f_Num , FlightType f_type, char dest[4], BOOL emergency ){
    BOOL check= ((f_Num>=1 && f_Num<=MAX_ID) && ((f_type==DOMESTIC) || (f_type==INTERNATIONAL)) && checkDestination(dest));
    return (check && (emergency==TRUE || emergency==FALSE));
}
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

pFlight createFlight(int f_Num , FlightType f_type, char dest[4], BOOL emergency ){
    pFlight f;
    if (!validFlight(f_Num,f_type,dest,emergency))
        return NULL;
    f=(pFlight)malloc(sizeof(struct flight));
    if(f == NULL)
        return NULL;
    f->f_Num = f_Num;
    f->f_type = f_type;
    strcpy((char *) f->dest, dest);
    f->emergency = emergency;
    return f;
}
/***********************************************************
function name: destroyFlight

description:
The function destroys the given flight by freeing all the allocated memory.

parameters:
f- a pointer to a flight to destroy.

return values:
No return values.
***********************************************************/
void destroyFlight(pFlight f){
    if(f == NULL)
        return;
    //free(f->dest);
    free(f);
}
/***********************************************************
function name: printFlight

description:
The function prints the flight parameters - ID , Type (DOMESTIC / INTERNATIONAL), Destination & Emergency or Regular.

parameters:
f- a pointer to a flight to destroy.

return values:
No return values.
***********************************************************/
void printFlight(pFlight f){
    if(f == NULL)
        return;
    printf("Flight %d %c %s %c\n", f->f_Num, (f->f_type == DOMESTIC ? 'D' : 'I'), f->dest, (f->emergency ? 'E' : 'R'));
}
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
int getFlightID(pFlight f){
    return f->f_Num;
}
FlightType getFlightType(pFlight f){
    return f->f_type;
}
BOOL isEmergency(pFlight f){
    return f->emergency;
}
char* getDestination(pFlight f){
    return f->dest;//TODO: use strcpy
}//TODO: Check if all the fields are correctly defined

/***********************************************************
function name: setDestination

description:
The function changes the flights destination to a new destination.

parameters:
f- A pointer to a flight which destination we want to change.

return values:
SUCCESS or FAILURE to change the flight destination
***********************************************************/

Result setDestination(pFlight f, char new_dest[4]){
    if(!f || !checkDestination(new_dest)){
        return FAILURE;
    }
    strcpy(f->dest,new_dest);
    return SUCCESS;
}
