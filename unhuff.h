/*  ECE368 Project 2: Huffman Compression and Decompression
*   Contributors:
*       Thomas Pollard
*       Trenton Andres
*
*   File: unhuff.h
*
*   Created: 11/12/2011
*
*   Description:
*           This is the header file for the Huffman Decompression algorithm.
*       This header declares the node structure that is used to build the 
*       binary tree, as well as support functions. This header also includes
*       other function prototypes
*
*   Last Modified: 11/12/2011
*
*/

#ifndef __UNHUFFH__
#define __UNHUFFH__

#include "huff.h"
#include <stdio.h>
//    global Node * head;
//    global FILE * fhd;
    
    /* This function builds the binary Huffman Coding tree */
	Node * tree(char bit, char byte, Node * curpos) {
		/* curpos == NULL when tree is finished being built (initially == head)
		 * byte is invalid unless bit == 1
		 */
		 
		 /* When the tree is complete, curpos will point to NULL, so return */
		 if (curpos == NULL) {
		    return NULL;
		 }
		 
		 /* If the bit that was read is a zero, */
		 if (bit == 0) {
		    /* Try to make a new child on the left */
		    if (curpos->left == NULL) {
		        Node * n = node_construct(0,0);
		        curpos->left = n;
		        n->next = curpos;
		        return n;
		    }
		    /* Try to make a new child on the right */
		    else if (curpos->right == NULL) {
		        Node * n = node_construct(0,0);
		        curpos->right = n;
		        n->next = curpos;
		        return n;
		    }
		    /* Travel up one level in the tree and try to add there */
		    else {
		        return tree(bit, byte, curpos->next);
		    }
		}
		
		/* If the bit is zero, add the character to a leaf node */
		if (bit == 1) {
		    /* Try to add leaf on left */
		    if (curpos->left == NULL) {
		        Node * n = node_construct(0, byte);
		        curpos->left = n;
		        n->next = curpos;
		        return curpos;
		    }
		    /* Try to add leaf on the right */
		    else if (curpos->right == NULL) {
		        Node * n = node_construct(0, byte);
		        curpos->right = n;
		        n->next = curpos;
		        return curpos;
		    }
		    /* Travel up one level in the tree and try to add there */
		    else {
		        return tree(bit, byte, curpos->next);
		    }
		}
		 
		 /* Should never reach this statement */
		return NULL;
	} 
	
	
	
	/* This function traverses the binary tree and prints a character in the
	 * output file when it reaches a leaf node
	 */
	Node * tree2(char bit, Node * curpos) {
		
		 
		/* This function will print to file */
		
		return curpos;
	} 

	/* This function takes in a char and prints l bits of it to stdout in binary form */
	void print_binary_char(char d, int l){
		int i;
		char temp = d;
		while(i++ < (sizeof(char)*8-l)) printf(" "); 
		temp = temp << (sizeof(char)*8 - l);
		i = 0;
		while(i < l){
			if(temp & 0x80)	printf("1");
			else printf("0");
			temp = temp<<1;
			i++;	
		}
		//printf("%d ",(int)d);
		printf("\n");
	}

    /* Function to append the '.unhuff' to the end of an arbitrarily named file, returns pointer to string */
    char *unhuff_output_filename(char *filename){
        int i = 0;
        char *newname;
        while(*(filename+i) != '\0') i++;
        newname = malloc(sizeof(char)*(i+8));
        i = 0;
        while(*(filename + i) != '\0') {
          *(newname+i) = *(filename + i);
          i++;
        }
        *(newname+i++) = '.';
        *(newname+i++) = 'u';
        *(newname+i++) = 'n';
        *(newname+i++) = 'h';
        *(newname+i++) = 'u';
        *(newname+i++) = 'f';
        *(newname+i++) = 'f';
        *(newname+i) = '\0';
        return(newname);
    }
#endif
