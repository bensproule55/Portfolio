#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Represents a Trie Node 
typedef struct tNode{
    // Signifies completed word. Must not be NULL or empty.
    bool isEnd;

    // ID for lookup in a simple array
    // Set as -1 to indicate no entry. This will only contain a num >= 0 if isEnd is true
    // Set as -2 to indicate head of the TRIE structure
    int entryID;

    // List of children. Size may vary since using different alphabets (a-zA-Z vs. 0-9)
    // Allocate memory based on alphabet size during installation.
    // May be NULL, must not be empty. NULL indicates number not found.
    struct tNode* children[];
} TrieNode;



#endif	