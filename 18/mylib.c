#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include <assert.h>
#include <ctype.h>

/**
   Authors: Connor Brown, Dray Ambrose and Jayden Prakash
*/

/**
   This functions reads words from a file one at a time
   
   @param s: the word read in from the file
   @param limit: used to track character counts
   @param stream: the file being read
*/
int getword(char *s, int limit, FILE *stream){
    int c;
    char *w = s;
    assert(limit > 0 && s != NULL &&stream != NULL);

    while(!isalnum(c = getc(stream)) && EOF != c)
        ;
    if(EOF == c){
        return EOF;
    } else if (--limit > 0){
        *w++ = tolower(c);
    }
    while (--limit > 0){
        if (isalnum(c = getc(stream))){
            *w++ = tolower(c);
        } else if ('\'' == c){
            limit++;
        } else {
            break;
        }
    }
    *w = '\0';
    return w - s;
}
/**
   This function tries to allocate memory, and handles any errors
   that arise from the allocation.
   
   @param s: the size of the memory being allocated 
*/
void *emalloc(size_t s){
    void *result = malloc(s);
    if (NULL == result){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
/**
   This function tries to increase the existing allocation of memory
   an object has, and handle any errors that arise.

   @param p: a generic pointer
   @param s: the size of the extra memory being allocated
*/
void *erealloc(void *p, size_t s){
    void *result = realloc(p, s);
    if (NULL == result && s != 0){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_SUCCESS);
    }
    return result;
}
