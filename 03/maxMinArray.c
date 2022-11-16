#include <stdio.h>
#include <stdlib.h>

/*
 * finds the maximum and minimum values in an array.
 */
void max_min(int *a, int n, int *max, int*min){
    int i =0;
    *min = a[i];
    for(i =0; i < n; i++){
        if(a[i] > *max){
            *max = a[i];
        }
        if(a[i] < *min){
            *min = a[i];
        }
    }
}

int main(void){
    int my_array[] = {5, 2, 7, 3 ,4}; /* Declared array with a size of 5 */
    int biggest = 1;
    int smallest = 0;
    max_min(my_array, 5, &biggest, &smallest);
    printf("Max value is %d, Min value is %d\n", biggest, smallest);

    return EXIT_SUCCESS;
    
}
