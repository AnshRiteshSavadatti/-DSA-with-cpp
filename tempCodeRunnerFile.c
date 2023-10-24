#include <stdio.h>    
struct student 
{        
    char *c;
};
int main()    
{        
    struct student *s;        
    s->c = "kle";
    printf("%s", s->c);
    return 0;
}