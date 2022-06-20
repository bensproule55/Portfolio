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

/** Function to initialize the trieHead object
 * Allocates enough memory for head object and 10 children (0-9)
 *@return void
**/
void initializeHead();

/** Function to add an entry to entryList
 *@return initialized or reinitialized entryList object
 *@param entryList: array of entries to insert new entry
 *@param tempEntry: initialized entry to add to the list
**/
void addEntry(Entry ***entryList, Entry *tempEntry);

/** Function to print current entryList for debugging or user output
 *@param entryList: array of entries
**/
void printEntryList(Entry ***entryList);

/** Function to remove an entry from entry list by matching entry with existing
 * Note: this will also free the memory but will not shift the list due to having to re-write all the TRIE nodes
 *@param entryList: array of entries 
 *@param tempEntry: entry to remove
**/
void removeEntryByEntry(Entry ***entryList, Entry *tempEntry);

/** Function to remove an entry from entry list by looking for the entry ID
 * Note: this will also free the memory but will not shift the list due to having to re-write all the TRIE nodes
 *@param entryList: array of entries 
 *@param id: id number to remove from the list
**/
void removeEntryByID(Entry ***entryList, int id);

/** Function to remove all entries and free the entryList struct
 *@param entryList: array of entries 
**/
void clearEntryList(Entry ***entryList);

/** Function to add an entry object to the entry list
 *@return retEntry: initialized entry object 
 *@param number: non-empty, initialized string to add to the entry
 *@param name: non-empty, initialized string to add to the entry
**/
Entry *createEntry(char *number, char *name);

/** Function to print entry on newline for debugging
 *@param entryToPrint: entry to print
**/
void printEntry(Entry *entryToPrint);

/** Function to delete an entry struct
 *@param tempEntry: entry to free
**/
void freeEntry(Entry *tempEntry);

/** Function to check if all chars in a string are numeric
 *@return true or false if contains non-num or not
 *@param number: string to check 
**/
bool containsNonNum(char *number);

/** Function to check validity of phone number
 *@return true or false if the phone fits following formats
 *@param number: phone number to check 
 * acceptable: xxx-xxx-xxxx, xxxxxxxxxx, xxx xxx xxxx
**/
bool isValidNumber(char *number);

/** Function trim chars off phone number
 *@return phone number stripped of '-' or ' ' chars
 *@param number: phone number to trim
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