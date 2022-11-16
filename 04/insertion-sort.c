#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_MAX 30000
void insertion_sort(int *a, int n) {
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
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }
    start = clock();
    insertion_sort(my_array, count);
    end = clock();
    
    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
