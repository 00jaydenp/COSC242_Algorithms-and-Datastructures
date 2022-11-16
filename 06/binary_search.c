#include <stdio.h>
#include <stdlib.h>
#define ARRAY_MAX 30000


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

int binary_search(int *a, int search, int start, int end){
    int mid = (end+start)/2;
    if (end == start){
        return 0;
    }
    else if(a[mid] == search){
        return 1;
    }
    else if(a[mid] > search){
        return binary_search(a, search, start , mid);
    }
    else if(a[mid] < search){
        return binary_search(a, search, mid+1, end);
    }
}

int main(int argc, char **argv){
    FILE *infile;
    int my_array[ARRAY_MAX];
    int num_items, query, i=0;

    if (NULL == (infile = fopen(argv[1], "r"))) {
        fprintf(stderr, "%s: can’t find file %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }
    num_items = 0;
    
    while (num_items < ARRAY_MAX &&
           1 == fscanf(infile, "%d", &my_array[num_items])) {
        num_items++;
    }

    fclose(infile);

    selection_sort(my_array, num_items);
 
    for (i = 0; i < num_items; i++) {
        printf("%d\n", my_array[i]);
    }

    while(1 == scanf("%d", &query)){
        printf("%s\n", (binary_search(my_array, query, 0, num_items) == 1) ? "+" : "-");
    }
    
    return EXIT_SUCCESS;
}
