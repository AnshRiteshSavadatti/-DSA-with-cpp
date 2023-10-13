#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 12


struct advertisement
{
char message_sent[30];        // Mobile advertisement to be made
int time;                 // Time of broadcast
};


struct stack
{
int top;                                    // The stack top
int active;                                 // Status to indicate if the stack is active
struct advertisement items[MAX];      // Items tracking advertisements
};

typedef struct stack STACK;

int isEmpty(STACK *s){
    if(s->top == - 1)
    return 1;
    return 0;
}


// 8.00 - Snacks Time
// 9.00 – Coffee Day
// 10.00 – Kids Section
// 11.00 – Shopping
// 12.00 – Movie Hall
// 1.00 – Lunch Lounge
// 2.00 – Lunch Lounge
// 3.00 – Movie Hall
// 4. 00 – Shopping
// 5.00 – Kids Section
// 6.00 – Coffee Day
// 7.00 – Snacks Time

STACK* insert1(STACK* ptr){
    ptr->top++;
    ptr->items[ptr->top].time = 1;
    strcpy(ptr->items[ptr->top].message_sent, "Lunch Lounge  ");

    ptr->top++;
    ptr->items[ptr->top].time = 12;
    strcpy(ptr->items[ptr->top].message_sent, "Movie Hall  ");


    ptr->top++;
    ptr->items[ptr->top].time = 11;
    strcpy(ptr->items[ptr->top].message_sent, "Shopping  ");

    ptr->top++;
    ptr->items[ptr->top].time = 10;
    strcpy(ptr->items[ptr->top].message_sent, "Kids Section  ");

    ptr->top++;
    ptr->items[ptr->top].time = 9;
    strcpy(ptr->items[ptr->top].message_sent, "Coffee Day  ");

    ptr->top++;
    ptr->items[ptr->top].time = 8;
    strcpy(ptr->items[ptr->top].message_sent, "Snacks Time  ");
    
    return ptr;
}


STACK* insert2(STACK* ptr){
    ptr->top++;
    ptr->items[ptr->top].time = 2;
    strcpy(ptr->items[ptr->top].message_sent, "Lunch Lounge  ");

    ptr->top++;
    ptr->items[ptr->top].time = 3;
    strcpy(ptr->items[ptr->top].message_sent, "Movie Hall  ");


    ptr->top++;
    ptr->items[ptr->top].time = 4;
    strcpy(ptr->items[ptr->top].message_sent, "Shopping  ");

    ptr->top++;
    ptr->items[ptr->top].time = 5;
    strcpy(ptr->items[ptr->top].message_sent, "Kids Section  ");

    ptr->top++;
    ptr->items[ptr->top].time = 6;
    strcpy(ptr->items[ptr->top].message_sent, "Coffee Day  ");

    ptr->top++;
    ptr->items[ptr->top].time = 7;
    strcpy(ptr->items[ptr->top].message_sent, "Snacks Time  ");
    
    return ptr;
}


// STACK* push(struct a ,STACK* p){
//     p->top++;
//     p->items[p->top] = a;
//     return p;
// }

STACK* pop(STACK *p){
    p->top--;
    return p;
}

int main(){
    STACK* ptr = (STACK*) malloc(sizeof(STACK));
    ptr->top = -1;
    ptr->active = -1;

    STACK* p = (STACK*) malloc(sizeof(STACK));
    p->top = -1;
    p->active = -1;
    
    ptr = insert1(ptr);

    p = insert2(p);
    int t = 8;

    while(1){
        int ch;

        int temp;
        printf("\nEnter \n1 Display the message being broadcasted \n2 to Update Time \n3 to Print messages left over \n" );
        printf("4 to Print All Messages \n5 to Exit\n");
        scanf("%d",&ch);

        
        switch (ch)
        {
        case 1:
            /* code */
            if(t >= 8 && t < 12 || t == 1){
               while(t != ptr->items[ptr->top].time)
                   ptr = pop(ptr);
               printf("%s",ptr->items[ptr->top].message_sent);
            }
            else if(t >= 2 && t < 7){
            while(t != p->items[p->top].time)
                   p = pop(p);
              printf("%s",p->items[p->top].message_sent);
            }
            else{
               printf("Invalid time\n");
              return -1;
            }
            break;
        
        case 2:
            ptr->top = 5;
            p->top = 5;
            // printf("\nEnter the time\n");
            // scanf("%d",&t);
            // if(t == 7){
            //     t = 
            // }
            if(t >= 1 && t < 12){
                t = t+1;
            }
            else{
                t = 1;
            }

            if(t >= 8 && t <= 12 || t == 1){
                while(t != ptr->items[ptr->top].time)
                    ptr = pop(ptr);
                printf("%s",ptr->items[ptr->top].message_sent);
            }
            else if(t >= 2 && t <= 8){
            while(t != p->items[p->top].time)
                   p = pop(p);
               printf("%s",p->items[p->top].message_sent);
            }
            else{
                printf("Invalid time\n");
               return -1;
            }
            break;

        case 3:
            if(t >= 8 && t < 12 || t == 1){
                 temp = ptr->top;
                while(temp != -1){
                    printf("%s",ptr->items[temp].message_sent);
                    temp--;
                }
            }
            else if(t >= 2 && t < 7){
                 temp = p->top;
                while(temp != -1){
                    printf("%s",p->items[temp].message_sent);
                    temp--;
                }
            }
            break;

        case 4:
             temp = ptr->top;
            while(temp != -1){
                    printf("%s",ptr->items[temp].message_sent);
                    temp--;
                }
             temp = p->top;
            while(temp != -1){
                    printf("%s",p->items[temp].message_sent);
                    temp--;
                }
            break;
        default:
            exit(0);
            break;
        }

        ptr->top = 5;
        p->top = 5;
    }
    return 0;
}