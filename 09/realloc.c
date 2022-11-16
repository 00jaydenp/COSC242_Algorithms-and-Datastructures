#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
static void array_print(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

void array_sort(int *a, int n) {
    int key, p, left; /** declaring variables used in the loops **/
    /** keeps the current place in the array **/
    for(p = 1; p <n; p++){
        key = a[p];
        left = p-1;

        /** moves every element left from the key right **/
        while(left>=0 && a[left]>key){
            a[left+1] = a[left];
            left--;
        }
        /** puts key in the leftmost position **/
        a[left+1] = key;
    }
     
}



int main(void) {
    int capacity = 2;
    int itemcount = 0;
    int item;
    int *my_array = emalloc(capacity * sizeof my_array[0]);
    if (NULL == my_array) {
        fprintf(stderr, "memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    while (1 == scanf("%d", &item)) {
        if (itemcount == capacity) {
            capacity += capacity;
            my_array = erealloc(my_array, capacity * sizeof my_array[0]);
            if (NULL == my_array) {
                fprintf(stderr, "memory reallocation failed.\n");
                exit(EXIT_FAILURE);
            }
        }
        my_array[itemcount++] = item;
    }
    array_sort(my_array, itemcount);
    array_print(my_array, itemcount);
    free(my_array);
    return EXIT_SUCCESS;
}








