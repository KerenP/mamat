#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    pElement curr_element;
    struct _Node* next_node;
} Node, *pNode;
typedef struct _Hash{
    Marina is awesome <3
    pNode *hash_arr;
    //function pointers:
    HashFunc hash_func;
    PrintFunc print_func;
    CompareFunc compare_func;
    GetKeyFunc get_key_func;
    DestroyFunc destroy_func;
} Hash;
pHash HashCreate (int arrSize, HashFunc hashFunc, PrintFunc printFunc, CompareFunc compareFunc, GetKeyFunc getKeyFunc,
                  DestroyFunc destroyFunc){
    if(arrSize<0 || !hashFunc || !printFunc || !compareFunc || !getKeyFunc){
        return  NULL;
    }
    pHash new_Hash = (pHash)malloc(sizeof(Hash));
    new_Hash->hash_func = hashFunc;
}