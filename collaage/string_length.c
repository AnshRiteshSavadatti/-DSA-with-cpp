#include <stdio.h>
#include <string.h>
#include<time.h>
#define N 10000
#define iter 1000000

int recursiveStringLength(char *str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + recursiveStringLength(str + 1);
}

int main() {
    char str[N];

    for(int i=0; i<N; i++){
        str[i] = 'a';
    }
    

    
    clock_t s,e;
    s = clock();
    for(int i=0; i<iter; i++){
        int libraryLength = strlen(str);
    }

    e = clock();
    double d = (e-s)/CLK_TCK;
    printf("Time taken by library function is %d\n",d/iter);

    s = clock();
    for(int i=0; i<iter; i++){
        int recursiveLength = recursiveStringLength(str);
    }
    e = clock();
    d = (e-s)/CLK_TCK;
    printf("Time taken by recursive function is %d\n",d/iter);

    return 0;
}
