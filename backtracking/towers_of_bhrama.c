#include <stdio.h>
#include<time.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int numDisks = 3;
    clock_t s,e;
    s = clock();
    towerOfHanoi(numDisks, 'A', 'B', 'C');
    e = clock();
    double d = (s-e) / CLK_TCK;
    printf("%g",d);
    return 0;
}
