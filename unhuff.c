/*  ECE368 Project 2: Huffman Compression and Decompression
*   Contributors:
*       Thomas Pollard
*       Trenton Andres
*
*   File: unhuff.c
*
*   Created: 11/12/2011
*
*   Description:
*           This is the main program for the Huffman Decompression algorithm.
*       The program takes one (1) command line argument, which is the file to
*       be decompressed. The algorithm uses Huffman coding to decompress the
*		input file, and stores the decompressed file as 
*		<filename.extension>.unhuff
*
*   Last Modified: 11/12/2011
*
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unhuff.h"

// Debug flags for printing intermediate results
//#define __DEBUGTREE__


// Global variable declarations
FILE * ofhd;
Node * head;

int main(int argc, char * argv[])
{
    /* Ensure the user entered a filename */
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }
    /* Open file as "binary, readonly" */
    FILE * fhd = fopen(argv[1], "rb");
        
    /*Ensure the file can be opened */
    if (fhd == NULL) {
        printf("ERROR: %s was not opened correctly.\n", argv[1]);
        return -1;
    }
    
    head = NULL;
    Node * curpos = NULL;
    //char bit;
    //char byte;
    
    curpos = tree(0, 0, curpos);
    
    
   
    
    #ifdef __DEBUGTREE__
        /* Print tree for debugging */
        printf("Code tree:\n");
        print_tree(head);
        printf("\n");
    #endif
    
    ofhd = fopen("Samples/triv.txt.huff.unhuff", "w");
    curpos = head;
    curpos = tree2(1, curpos);
    
    
    
    
    /* Close the input file */
    fclose(fhd);
    
    return 0;
}
    


