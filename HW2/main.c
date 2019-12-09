//
// Created by Marina on 06/12/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "airport.h"
#define MAX_LINE_SIZE 256


int main() {
    char szLine[MAX_LINE_SIZE];
    char *delimiters = " \t\n";
    char *pszCommand;
    char *pszRunwayNum;
    char *pszRunwayType;
    char *pszFlightNum;
    char *pszFlightType;
    char *pszDestination;
    char *pszEmergency;
    char *pszNewDestination;
    int RunwayNum;
    int FlightNum;
    int check_type;
    int check_emergency;
    Result check_func;
    while (fgets(szLine, MAX_LINE_SIZE, stdin)) {
        pszCommand = strtok(szLine, delimiters);
        if (strcmp(pszCommand, "Insert") == 0) {
            pszRunwayNum = strtok(NULL, delimiters);
            pszRunwayType = strtok(NULL, delimiters);
            if (!pszRunwayNum || !pszRunwayType) {
                fprintf(stderr, "%s failed: not enough parameters.\n", pszCommand);
                continue;
            }
            RunwayNum = atoi(pszRunwayNum);
            check_type = (strcmp(pszRunwayType, "I") != 0 && strcmp(pszRunwayType, "D") != 0);
            if (RunwayNum < 0 || RunwayNum > MAX_ID || check_type) {
                fprintf(stderr, "%s execution failed.\n", pszCommand);
                continue;
            }
            check_func = addRunway(RunwayNum, ((strcmp(pszRunwayType, "D") == 0) ? DOMESTIC : INTERNATIONAL));
            if (!check_func) {
                fprintf(stderr, "%s execution failed.\n", pszCommand);
                continue;
            }
        }
        else if (strcmp(pszCommand, "Remove") == 0) {
            pszRunwayNum = strtok(NULL, delimiters);
            if (!pszRunwayNum) {
                fprintf(stderr, "%s failed: not enough parameters.\n", pszCommand);
                continue;
            }
            RunwayNum = atoi(pszRunwayNum);
            if (RunwayNum < 0 || RunwayNum > MAX_ID) {
                fprintf(stderr, "%s execution failed.\n", pszCommand);
                continue;
            }
            check_func = removeRunway(RunwayNum);
            if (!check_func) {
                fprintf(stderr, "%s execution failed.\n", pszCommand);
                continue;
            }
        }
        else if (strcmp(pszCommand, "Add") == 0) {
            pszFlightNum = strtok(NULL, delimiters);
            pszFlightType = strtok(NULL, delimiters);
            pszDestination = strtok(NULL, delimiters);
            pszEmergency = strtok(NULL, delimiters);
            if (!pszFlightNum || !pszFlightType || !pszDestination || !pszEmergency) {
                fprintf(stderr, "%s failed: not enough parameters.\n", pszCommand);
                continue;
            }
            FlightNum = atoi(pszFlightNum);
            check_type = (strcmp(pszFlightType, "I") != 0 && strcmp(pszFlightType, "D") != 0);
            check_emergency=(strcmp(pszEmergency, "E") != 0 && strcmp(pszEmergency, "R") != 0);
            if (FlightNum < 0 || FlightNum > MAX_ID || check_type || !checkDestination(pszDestination) || check_emergency){
                fprintf(stderr, "%s execution failed.\n", pszCommand);
                continue;
            }
            FlightType convert_type=((strcmp(pszFlightType, "D") == 0) ? DOMESTIC : INTERNATIONAL);
            BOOL convert_emergency=((strcmp(pszEmergency, "E") == 0) ? TRUE : FALSE);
            check_func = addFlightToAirport( FlightNum, convert_type,  pszDestination,  convert_emergency);
            if (!check_func) {
                fprintf(stderr, "%s execution failed.\n", pszCommand);
                continue;
            }
        }
        else if (strcmp(pszCommand, "Depart") == 0) {
            check_func = departAirport();
            if (!check_func) {
                fprintf(stderr, "%s execution failed.\n", pszCommand);
                continue;
            }
        }
        else if (strcmp(pszCommand, "Change") == 0) {
            pszDestination = strtok(NULL, delimiters);
            pszNewDestination = strtok(NULL, delimiters);
            if (!pszDestination || !pszNewDestination) {
                fprintf(stderr, "%s failed: not enough parameters.\n", pszCommand);
                continue;
            }

            if (!checkDestination(pszDestination) || !checkDestination(pszNewDestination)) {
                fprintf(stderr, "%s execution failed.\n", pszCommand);
                continue;
            }
            check_func = changeDest( pszDestination,  pszNewDestination);
            if (!check_func) {
                fprintf(stderr, "%s execution failed.\n", pszCommand);
                continue;
            }
        }
        else if (strcmp(pszCommand, "Delay") == 0) {
            pszDestination = strtok(NULL, delimiters);
            if (!pszDestination ) {
                fprintf(stderr, "%s failed: not enough parameters.\n", pszCommand);
                continue;
            }
            if (!checkDestination(pszDestination) ) {
                fprintf(stderr, "%s execution failed.\n", pszCommand);
                continue;
            }
            check_func = delay( pszDestination);
            if (!check_func) {
                fprintf(stderr, "%s execution failed.\n", pszCommand);
                continue;
            }
        }
        else if (strcmp(pszCommand, "Print") == 0) {
            printAirport();
        }
        else if (strcmp(pszCommand, "Exit") == 0) {
            destroyAirport();
            return 0;
        }
        else{
            fprintf(stderr,"Command not found.\n");
        }

    }
    destroyAirport();
    return 0;
}




