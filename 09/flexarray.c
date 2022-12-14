#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

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




struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};
flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}
void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity) {
        f->capacity += f->capacity;
        f = erealloc(f, f->capacity * sizeof f[0]);
    }
    f->items[f->itemcount++]=num;
}
void flexarray_print(flexarray f) {
    int i;

    for(i=0; i < f->itemcount; i++){
        printf("%d\n", f->items[i]);
    }
}
void flexarray_sort(flexarray f) {
    int *workspace;

    workspace = emalloc(f->itemcount *sizeof f[0]);
    merge_sort(f->items, workspace, f->itemcount);
    free(workspace);
}
void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}
