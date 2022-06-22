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
    TrieNode *node = malloc(sizeof(TrieNode) + sizeof(TrieNode) * alphabetSize);
    node->entryID = -2;
    node->isEnd = false;

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
void insertTrieNode(TrieNode *current, char *toAdd, int entryID, int alphabetSize){
    TrieNode *newNode;
    char *newString = malloc(sizeof(char) * (strlen(toAdd))); // need to make new string to do string copying

    if(strlen(toAdd) == 1){ // end of string
        newNode = createTrieNode(true, entryID, alphabetSize);
        addChild(current, newNode, toAdd[0] - '0');
    }
    else{ // create or traverse node, remove letter, recall
        newNode = createTrieNode(false, -1, alphabetSize);
        addChild(current, newNode, toAdd[0] - '0');
        for(int i = 0; toAdd[i] != '\0'; i++) newString[i] = toAdd[i+1]; //remove first letter from string
        
        insertTrieNode(newNode, newString, entryID, alphabetSize);
    }

    free(newString);
}
