#include <stdio.h>
#include <stdlib.h>
#define ARRAY_MAX 30000

void print_array(int *a, int n){
    if (n > 0){
        printf("%d\n", a[0]);
        print_array(a+1, n-1);
    }
}

void selection_sort(int *a, int n) {
    int p, key, small, temp;

    /** takes current element of array and stores it in the small variable **/
    for(p =0; p < n-1; p++){
        small = p;
        /** iterates through the array to check if there is a smaller element than the current small variable. **/
        for(key=p+1; key < n; key++){
            if(a[small] > a[key]){
                small = key;
            }
        }
        /** swaps small with current element **/
        temp = a[small];
        a[small] = a[p];
        a[p] = temp;
    }
}
int main(void) {
    int my_array[ARRAY_MAX];
    int count = 0;
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }


    selection_sort(my_array, count);
 
    print_array(my_array, count);
    return EXIT_SUCCESS;
}
