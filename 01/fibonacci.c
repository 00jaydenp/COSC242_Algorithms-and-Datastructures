#include <stdio.h>
#include <stdlib.h>

int main(void){
    int f = 0;
    int g = 1;
    int l = 1;
    int s = 0;

    for(l =1; l < 41; l++){
        printf("%10d" , g);
        s = g;
        g += f;
        f = s;
        if(l%5== 0){
            printf("\n");
        }
    }
    return EXIT_SUCCESS;
}
