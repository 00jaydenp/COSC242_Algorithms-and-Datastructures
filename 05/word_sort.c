#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 80
#define ARRAY_MAX 30000

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void selection_sort(char *a[], int n) {
    int p, key, small;
    char *temp;

    /** takes current element of array and stores it in the small variable **/
    for(p =0; p < n-1; p++){
        small = p;
        /** iterates through the array to check if there is a smaller element than the current small variable. **/
        for(key=p+1; key < n; key++){
            if(strcmp(a[small], a[key])>=0){
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
    char word[STRING_LENGTH];
    char *wordlist[ARRAY_MAX];
    int num_words, i;
    while (num_words < ARRAY_MAX && 1 == scanf("%79s", word )) {
        wordlist[num_words] = emalloc((strlen(word) + 1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words],word);
        num_words++;
        
    }

    printf("%d\n", num_words);
    selection_sort(wordlist, num_words);
 
    
    for (i = 0; i < num_words; i++) {
        printf("%s\n", wordlist[i]);
        free(wordlist[i]);
    }
    return EXIT_SUCCESS;
}
