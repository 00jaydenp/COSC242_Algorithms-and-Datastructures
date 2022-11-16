#ifndef MYLIB_H_
#define MYLIB_H_
/**
   Authors: Connor Brown, Dray Ambrose and Jaydan Prakash
*/

/* Functions to be implemented in mylib.c */
extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern int getword(char *s, int limit, FILE *stream);

#endif
