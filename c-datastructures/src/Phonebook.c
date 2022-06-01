/*************************************
BENJAMIN SPROULE - ben.sproule55@gmail.com
C Data structures Phone book
Phonebook.c
This file contains the functions around 
the storage and implementation of the 
phone book struct.
*************************************/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Trie.h"

// simple menu to select what the user wants to do
int menu(){
    // default choice of exit if bad input
    int choice = 4; 

    // options, make these into enum?
    printf("1. Add new entry\n");
    printf("2. Lookup entry\n");
    printf("3. Update contact\n");
    printf("4. View all entries\n");
    printf("5. Exit program\n");
    printf("Enter your choice: ");

    // ask for choice and then loop until it is valid
    scanf("%d", &choice);
    while(choice > 5 || choice < 0){
        printf("Please enter a number between 1-4: ");
        scanf("%d", &choice);
    }
    return choice;
}