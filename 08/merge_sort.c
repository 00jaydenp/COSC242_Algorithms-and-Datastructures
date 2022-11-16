#include <stdio.h>
#include <stdlib.h>

/* Determines the max size of the array */
#define ARRAY_MAX 100000

void merge (int *a, int *w, int len){
    int p=0, i=0, j=(len/2);

    while(i< (len/2) && j <len){
        if (a[i] < a[j]){
            *(w+p) = *(a+i);
            i++;
        } else {
            *(w+p) = *(a+j);
            j++;
        }
        p++;
    }
    while (i < (len/2)){
        w[p] = a[i];
        i++;
        p++;
    }
    while(j < len) {
        w[p] = a[j];
        j++;
        p++;
    }
    
}

/** Merge Sort algorithm
 */
void merge_sort(int *a, int *w, int n){
    int i;

    if (n < 2){
        return;
    }
    merge_sort(a,w,(n/2));
    merge_sort(a+(n/2),w,n-(n/2));

    merge(a,w,n);
    for( i = 0; i < n; i++){
        *(a+i) = *(w+i);
    }
}

int main (void){
    int myArray[ARRAY_MAX];
    int *workspace;
    int i, count = 0;

    while(count < ARRAY_MAX && 1 == scanf("%d", &myArray[count])){
        count++;
    }

    workspace = malloc(count*sizeof workspace[0]);
    if(NULL == workspace){
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    merge_sort(myArray, workspace, count);

    for(i =0; i < count; i++){
        printf("%d\n", myArray[i]);
    }
    
    return EXIT_SUCCESS;
}
