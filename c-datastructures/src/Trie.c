/*************************************
BENJAMIN SPROULE - ben.sproule55@gmail.com
C Data structures Phone book
Trie.c
This file contains the functions around 
the TRIE data structure.
*************************************/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Trie.h"

// create a new trieNode object
TrieNode *createTrieNode(bool isEnd, int entryID, int alphabetSize){
    TrieNode *node = calloc(alphabetSize + 1, sizeof(TrieNode));
    node->entryID = entryID;
    node->isEnd = isEnd;

    for (int i = 0; i<alphabetSize; i++) node->children[i] = NULL;

    return node;
}

// add child to parent node in set position
void addChild(TrieNode *parentNode, TrieNode *newNode, int index){
    parentNode->children[index] = newNode;
}

// insert trieNode in children of current node based on string
// NOTE: TOADD should be a string of numbers. If using a non numeric alphabet, 
// it should be converted before being passed to this function
// For alphabets larger than 10, the characters will line up with ascii indexes 
// and therefore need to be converted backwards to be readable 
void insertTrieNode(TrieNode *current, char *toAdd, int entryID, int alphabetSize){
    TrieNode *newNode;
    char *newString = malloc(sizeof(char) * (strlen(toAdd))); // need to make new string to do string copying

    if(strlen(toAdd) == 1){ // end of string
        newNode = createTrieNode(true, entryID, alphabetSize);
        addChild(current, newNode, toAdd[0] - '0');
    }
    else{ // create or traverse node, remove letter, recall
        if(current->children[toAdd[0] - '0'] == NULL){ // only add new if child is null
            newNode = createTrieNode(false, -1, alphabetSize);
            addChild(current, newNode, toAdd[0] - '0');
        }
        else newNode = current->children[toAdd[0] - '0'];
        for(int i = 0; toAdd[i] != '\0'; i++) newString[i] = toAdd[i+1]; //remove first letter from string
        
        insertTrieNode(newNode, newString, entryID, alphabetSize);
    }

    free(newString);
}

// print functions for debugging, prints in pre order
void printTriePre(TrieNode *current, int alphabetSize){
    if(current == NULL) return;
    else {
        if(current->entryID == -2) printf("Head node. Children:\n");
        else printf("entryID: %d, isEnd: %d. Children:\n", current->entryID, current->isEnd);
        for(int i = 0; i < alphabetSize; i++){
            if(current->children[i] != NULL){
                printf("\tindex: %d, ", i);
                printTriePre(current->children[i], alphabetSize);
            }
        }
    }
}

// print functions for debugging, prints in post order
void printTriePost(TrieNode *current, int alphabetSize){
    if(current == NULL) return;
    else {  
        for(int i = 0; i < alphabetSize; i++){   
            if(current->children[i] != NULL){
                printf("index: %d, \n", i);
                printTriePost(current->children[i], alphabetSize);
            }
        }
        if(current->entryID == -2) printf("Head node.\n");
        else printf("entryID: %d, isEnd: %d.\n", current->entryID, current->isEnd);
    }
}

// uses post processing to free nodes
void freeTrie(TrieNode *current, int alphabetSize){
    if(current == NULL) return;
    else {  
        for(int i = 0; i < alphabetSize; i++){   
            if(current->children[i] != NULL){
                freeTrie(current->children[i], alphabetSize);
            }
        }
        free(current);
    }
}