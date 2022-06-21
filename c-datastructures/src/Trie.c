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
    TrieNode * node = malloc(sizeof(TrieNode) + sizeof(TrieNode) * alphabetSize);
    node->entryID = -2;
    node->isEnd = false;

    for (int i = 0; i<alphabetSize; i++) node->children[i] = NULL;

    return node;
}

// insert trieNode in children of current node based on string
void insertTrieNode(TrieNode current, char toAdd[], int entryID);
