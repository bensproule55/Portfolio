# C Phone Book
This program builds a phone book with the C language. The phone book has lookup by name or by phone number. It comes pre-populated with ten custom entries.

## How to build and run
Please ensure that the latest version of [GCC](https://gcc.gnu.org/) is installed on your system. You also need [valgrind](https://valgrind.org/) if you would like to check memory use.

To make the whole project, type:

``make all``

To run the program, type:

``make run``

To run the program with memory assessment, type:

``make memory``

To remove temporary and runtime files, type:

``make clean``

## How to use
Program instructions coming soon.

## Dual TRIE structures

The TRIE structure is a tree where each node is a letter in a string. The last letter in the string will have a property that denotes it is the end of a string. The search and insertion complexity is O(k). The storage required is O(n*k). The reason this structure is good for a phone book is that the search and insertion will stay the same but the storage required will reduce when there are more overlapping keys. Since phone books tend to have heavy overlap (ex. "519-xxx-xxxx" or "Greg Xxxxx"), this will make the structure more space-efficient.

For implementation, this program creates two separate TRIEs to allow for search by number or name. Each end-of-word node will contain an ID to lookup the specific entry in a simple array. The name TRIE will allow for multiple IDs to be assigned, since there can be people in the phone book with the same name but different numbers. Again, this sacrifices space to allow for speed.

For more reading on the TRIE structure, please check out [this article on interviewcake.](https://www.interviewcake.com/concept/java/trie)

## Note on memory use
All structures allocated by this program are correctly freed when the program is exited. This program makes use of [valgrind](https://valgrind.org/) to check memory allocation and freeing. 

