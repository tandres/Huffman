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



int main(int argc, char * argv[])
{
    int i, read_result = 0, mybit, mybyte, bits_remaining = 8;
    Node *curpos;
    char cbuff[256];
    char cchar, nchar;
    /* Ensure the user entered a filename */
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }
    /* Open file as "binary, readonly" */
    FILE* fhd = fopen(argv[1], "rb");
        
    /*Ensure the file can be opened */
    if (fhd == NULL) {
        printf("ERROR: %s was not opened correctly.\n", argv[1]);
        return -1;
    }
    /*  - Read through file turning over bit data, if the bit is true give the next byte as well */
    // Decided to use fgetc, the header should be shorter, fgetc will be easier to handle bit/byte nonsense
    cchar = fgetc(fhd);
    while(curpos != NULL){
        mybit = () & 0x00000001 
        if(mybit) {
            mybyte = 0;
            mybyte = cchar<<(8-bits_remaining);
            cchar = fgetc(fhd);
            mybyte = mybyte|(cchar>>bits_remaining);
        }
        curpos = tree(mybit, mybyte, curpos);
    }

    /*  - Read the file into a buffer of chars, stop when fread no longer returns
     *  	* Go through buffer
     *			-break bytes into bits, turning over true/false to code inside
     */
    read_result = fread(cbuff, sizeof(char), 256, fhd);
    while(read_result > 0) {
        i = 0;
        while(i < read_result) {
            
            
            
            i++;
        }
        read_result = fread(cbuff, sizeof(char), 256, fhd);
    }
    /* Close the input file */
    fclose(fhd);
    
    return 0;
}
    


