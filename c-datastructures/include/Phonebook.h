#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Represents an entry name & number. This should be made as a list and indexed
typedef struct ent{
    // Phone number. Will always be 10 digits, must not be empty or NULL
    // Note: needs to be size 11 for string terminator
    char phoneNumber[11];
    // Name. Must not be empty or NULL
    char name[];
} Entry;

/** Function to prompt and get user input
 *@return a number signifying the user's choice 
**/
int menu();

#endif	