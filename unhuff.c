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
    //int i, read_result = 0, mybit, mybyte, bits_remaining = 8;
    int read_result;
    unsigned long int inbuff;
    //Node *curpos;
    //char cbuff[256];

    /* Ensure the user entered a filename */
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }
    /* Open file as "binary, readonly" */
    FILE* fhd = fopen(argv[1], "r");
        
    /*Ensure the file can be opened */
    if (fhd == NULL) {
        printf("ERROR: %s was not opened correctly.\n", argv[1]);
        return -1;
    }
    /*  - Read through file turning over bit data, if the bit is true give the next byte as well */
    // Decided to use fgetc, the header should be shorter, fgetc will be easier to handle bit/byte nonsense
    printf("\n*******Tree mapping:\n");
    read_result = fread(&inbuff, 8, 1, fhd);
    print_binary(1,inbuff,64);
//    while(curpos != NULL){
/*    while(i++<64){
	if(bits_remaining == 0){
	    bits_remaining = 8;
	    cchar = fgetc(fhd);
	}
        mybit = (int)((cchar>>--bits_remaining) & 0x01);
        if(mybit) {
	    printf("1 \n Leaf Entry: 0b");
            mybyte = 0;
            cchar = fgetc(fhd);
            mybyte = (int)(mybyte|(cchar>>bits_remaining));
            print_binary_char(mybyte,8);
        }
	else printf("0");
//        curpos = tree(mybit, mybyte, curpos);
    }*/
    printf("\n");
    /*  - Read the file into a buffer of chars, stop when fread no longer returns
     *  	* Go through buffer
     *			-break bytes into bits, turning over true/false to code inside
     */
    /*read_result = fread(cbuff, sizeof(char), 256, fhd);
    while(read_result > 0) {
        i = 0;
        while(i < read_result) {
            
            
            
            i++;
        }
        read_result = fread(cbuff, sizeof(char), 256, fhd);
    }*/
    /* Close the input file */
    fclose(fhd);
    
    return 0;
}
    


