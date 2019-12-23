#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct _Node *pNode;
typedef struct _Node{
    pElement curr_element;
    pNode next_node;
} Node;
typedef struct _Hash{
    pNode *hash_arr;
    int arr_size;
    //function pointers:
    HashFunc hash_func;
    PrintFunc print_func;
    CompareFunc compare_func;
    GetKeyFunc get_key_func;
    DestroyFunc destroy_func;
} Hash;
/*******************************************************************************************
function name: HashFindNode

description:
Given key value, find specific list in Hashtable, then search the list to find node with
an element matching key. return pointer to that node

parameters:
HashTable - pointer to hashtable.
key - pointer to key.

return values:
pNode - pointer to node.
*******************************************************************************************/
pNode HashFindNode(pHash HashTable, pKey key){
    if(!HashTable || !key){
        return NULL;
    }
    pNode curr_search_list=HashTable->hash_arr[HashTable->hash_func(key,HashTable->arr_size)];
    while(curr_search_list){
        if (HashTable->compare_func(HashTable->get_key_func(curr_search_list->curr_element),key)==SAME){
            return curr_search_list;
        }
        curr_search_list=curr_search_list->next_node;
    }
    return NULL;
}
/*******************************************************************************************
function name: HashCreate

description:
Create hash table in given size (arr_size) initialized with hash, print, compare, get key
and destroy functions

parameters:
arrSize - size of hash array.
hashFunc - hush function.
printFunc - print function.
compareFunc - compare function.
getKeyFunc - get key function.
destroyFunc - destroy function.

return values:
pHash - pointer to hash table.
*******************************************************************************************/
pHash HashCreate (int arrSize, HashFunc hashFunc, PrintFunc printFunc, CompareFunc compareFunc, GetKeyFunc getKeyFunc,
                  DestroyFunc destroyFunc){
    if(arrSize<0 || !hashFunc || !printFunc || !compareFunc || !getKeyFunc){
        return  NULL;
    }
    pHash new_Hash = (pHash)malloc(sizeof(Hash));
    if(!new_Hash){
        printf("Error Allocating Memory");
        return NULL;
    }
    new_Hash->hash_func = hashFunc;
    new_Hash->print_func = printFunc;
    new_Hash->compare_func = compareFunc;
    new_Hash->get_key_func = getKeyFunc;
    new_Hash->destroy_func = destroyFunc;
    new_Hash->hash_arr = (pNode *)malloc(sizeof(pNode)*arrSize);
   new_Hash->arr_size = arrSize;
    if(!new_Hash->hash_arr){
        printf("Error Allocating Memory");
        return NULL;
    }
    for (int i=0; i<arrSize; i++){
        new_Hash->hash_arr[i] = NULL;
    }
    return new_Hash;
}
/*******************************************************************************************
function name: HashAdd

description:
Add node with given element to the hash table

parameters:
HashTable - pointer to hashtable.
Elem - pointer to element.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result HashAdd (pHash HashTable, pElement Elem){
    if(!HashTable || !Elem){
        return FAIL;
    }
    if(HashFind(HashTable,HashTable->get_key_func(Elem))){
        return FAIL;
    }
    int array_index=HashTable->hash_func((HashTable->get_key_func(Elem)), HashTable->arr_size);
    pNode new_node=(pNode)malloc(sizeof(Node));
    new_node->next_node=HashTable->hash_arr[array_index];
    new_node->curr_element=Elem;
    HashTable->hash_arr[array_index]=new_node;
    return  SUCCESS;
}
/*******************************************************************************************
function name: HashFind

description:
Use HashFindNode function and return the element matching key

parameters:
HashTable - pointer to hashtable.
key - pointer to key.

return values:
pElement - pointer to element.
*******************************************************************************************/
pElement HashFind (pHash HashTable, pKey key){
    if(!HashTable || !key){
        return NULL;
    }
    pNode found_node = HashFindNode(HashTable, key);
    if (found_node){
        return  found_node->curr_element;
    }
    return NULL;
}
/*******************************************************************************************
function name: HashRemove

description:
Find wanted node using hashFunc and delete it.

parameters:
HashTable - pointer to hashtable.
key - pointer to key.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result HashRemove (pHash HashTable, pKey key){
    if(!HashTable || !key ){
        return FAIL;
    }
    pNode current = HashTable->hash_arr[HashTable->hash_func(key,HashTable->arr_size)];
    pNode *points_to_current = &(HashTable->hash_arr[HashTable->hash_func(key,HashTable->arr_size)]);
    //pointer to the current pointer (the address of curr)
    while (current != NULL) {
        if (HashTable->compare_func(HashTable->get_key_func(current->curr_element),key)==SAME) {
            *points_to_current = current->next_node;
            HashTable->destroy_func(current->curr_element);
            free(current);
            current=NULL;
            return SUCCESS;
        }
        points_to_current=&(current->next_node);
        current = current->next_node;
    }
    return FAIL;
}
/*******************************************************************************************
function name: HashPrint

description:
Print hash table content.

parameters:
HashTable - pointer to hashtable.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result HashPrint (pHash HashTable){
    if(!HashTable){
        return FAIL;
    }
    pNode curr_list;
    for (int i=0; i<HashTable->arr_size; i++){
        curr_list=HashTable->hash_arr[i];
        while(curr_list){
            HashTable->print_func(curr_list->curr_element);
            curr_list=curr_list->next_node;
        }
    }
    return SUCCESS;
}
/*******************************************************************************************
function name: HashDestroy

description:
Delete hash table.

parameters:
HashTable - pointer to hashtable.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result HashDestroy (pHash HashTable){
    if(!HashTable){
        return FAIL;
    }
    pNode curr_list;
    pNode next_list_node;
    for (int i=0; i<HashTable->arr_size; i++){
        curr_list=HashTable->hash_arr[i];
        while(curr_list){
            next_list_node=curr_list->next_node;
            if(!HashRemove(HashTable,HashTable->get_key_func(curr_list->curr_element))){
                return FAIL;
            }
            curr_list=next_list_node;
        }
    }
    free(HashTable->hash_arr);
    HashTable->hash_arr=NULL;
    free(HashTable);
    HashTable=NULL;

    return SUCCESS;
}