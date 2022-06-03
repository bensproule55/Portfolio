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

/** Function to check if all chars in a string are numeric
 *@return true or false if contains non-num or not
 *@param string to check 
**/
bool containsNonNum(char *number);

/** Function to check validity of phone number
 *@return true or false if the phone fits following formats
 *@param phone number to check 
 * acceptable: xxx-xxx-xxxx, xxxxxxxxxx, xxx xxx xxxx
**/
bool isValidNumber(char *number);

/** Function trim chars off phone number
 *@return phone number stripped of '-' or ' ' chars
 *@param phone number to trim
**/
char * trimNumber(char *number);

/** Function to prompt and get a valid phone number
 *@return a string "number" that is a valid phone number
**/
char * acceptNumber();

/** Function to prompt and get any name
 *@return a string "name" that the user entered 
**/
char * acceptName();

/** Function to prompt and get user input
 *@return a number signifying the user's choice 
**/
int mainMenu();

#endif	