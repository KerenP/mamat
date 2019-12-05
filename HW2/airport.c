//
// Created by Keren on 05/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "airport.h"

struct _runwayNode;
typedef struct _runwayNode* pRunwayNode;
typedef struct _runwayNode{
    pRunway cur_runway;
    pRunwayNode next_runway;
} runwayNode;
pRunwayNode head=NULL; //TODO: Maybe change to global variable
Result addRunway(int r_num, FlightType r_type){
    if (r_num<1 || r_num>MAX_ID || (r_type!=DOMESTIC && r_type!=INTERNATIONAL)){//TODO: check flightype???
        return FAILURE;
    }
    pRunwayNode curr = head;
    while(curr){
        if (getRunwayNum(curr->cur_runway) ==r_num){
            return FAILURE;
        }
    }
    pRunway pNewRunway = createRunway(r_num, r_type);
    if (!pNewRunway){
        return FAILURE;
    }
    pRunwayNode new_runway_node = (pRunwayNode)malloc(sizeof(runwayNode));
    if (!new_runway_node){
        return FAILURE;
    }
    new_runway_node->cur_runway=pNewRunway;
    new_runway_node->next_runway =NULL;
    curr = head;
    if(head == NULL) {
        head = new_runway_node;
    }
    else {
        while (curr->next_runway) {
            curr = curr->next_runway;
        }
        curr->next_runway = new_runway_node;
    }
    return SUCCESS;
}
Result removeRunway(int r_num){
    if (r_num<1 || r_num>MAX_ID || !head){
        return FAILURE;
    }
    pRunwayNode curr = head;
    /*while(curr){
        if (getRunwayNum(curr->cur_runway) ==r_num){
            return FAILURE;
        }
    }*/
    pRunwayNode current = head;
    pRunwayNode *points_to_current = &(head);
    while (current != NULL) {
        if (getRunwayNum(current->cur_runway) == r_num) {
            *points_to_current = current->next_runway;
            destroyRunway(current->cur_runway);
            free(current);
            return SUCCESS;
        }
        points_to_current=&(current->next_runway);
        current = current->next_runway;
    }
    return FAILURE;
}