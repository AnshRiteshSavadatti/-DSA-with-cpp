#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 12

struct advertisement {
    char message_sent[30]; // Mobile advertisement to be made
    int time[2];           // Time of broadcast as an array of size two
};

struct stack {
    int top;                                 // The stack top
    int active;                              // Status to indicate if the stack is active
    struct advertisement items[MAX];        // Items tracking advertisements
};

typedef struct stack STACK;

int isEmpty(STACK *s) {
    if (s->top == -1)
        return 1;
    return 0;
}

STACK* insert1(STACK* ptr) {
    ptr->top++;
    ptr->items[ptr->top].time[0] = 8;
    ptr->items[ptr->top].time[1] = 0;
    strcpy(ptr->items[ptr->top].message_sent, "Snacks Time  ");

    ptr->top++;
    ptr->items[ptr->top].time[0] = 9;
    ptr->items[ptr->top].time[1] = 0;
    strcpy(ptr->items[ptr->top].message_sent, "Coffee Day  ");

    // Add more advertisements here

    return ptr;
}

STACK* insert2(STACK* ptr) {
    ptr->top++;
    ptr->items[ptr->top].time[0] = 2;
    ptr->items[ptr->top].time[1] = 0;
    strcpy(ptr->items[ptr->top].message_sent, "Lunch Lounge  ");

    ptr->top++;
    ptr->items[ptr->top].time[0] = 3;
    ptr->items[ptr->top].time[1] = 0;
    strcpy(ptr->items[ptr->top].message_sent, "Movie Hall  ");

    // Add more advertisements here

    return ptr;
}

STACK* pop(STACK* p) {
    p->top--;
    return p;
}

int main() {
    STACK* ptr = (STACK*) malloc(sizeof(STACK));
    ptr->top = -1;
    ptr->active = -1;

    STACK* p = (STACK*) malloc(sizeof(STACK));
    p->top = -1;
    p->active = -1;

    ptr = insert1(ptr);
    p = insert2(p);

    int current_time[2] = {8, 0}; // Initialize current_time to 8:00

    while (1) {
        int ch;

        int temp;
        printf("\nEnter \n1 Display the message being broadcasted \n2 to Update Time \n3 to Print messages left over \n");
        printf("4 to Print All Messages \n5 to Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (current_time[0] >= 8 && current_time[0] < 12 || (current_time[0] == 1 && current_time[1] == 0)) {
                    while (current_time[0] != ptr->items[ptr->top].time[0] || current_time[1] != ptr->items[ptr->top].time[1])
                        ptr = pop(ptr);
                    printf("%s", ptr->items[ptr->top].message_sent);
                } else if (current_time[0] >= 2 && current_time[0] < 7) {
                    while (current_time[0] != p->items[p->top].time[0] || current_time[1] != p->items[p->top].time[1])
                        p = pop(p);
                    printf("%s", p->items[p->top].message_sent);
                } else {
                    printf("Invalid time\n");
                    return -1;
                }
                break;

            case 2:
                ptr->top = 5;
                p->top = 5;

                current_time[1]++;
                if (current_time[1] == 60) {
                    current_time[0]++;
                    current_time[1] = 0;
                }

                if (current_time[0] >= 1 && current_time[0] < 12) {
                    if (current_time[0] == 12) {
                        current_time[0] = 1;
                    }
                } else {
                    current_time[0] = 1;
                }

                if (current_time[0] >= 8 && current_time[0] <= 12 || (current_time[0] == 1 && current_time[1] == 0)) {
                    while (current_time[0] != ptr->items[ptr->top].time[0] || current_time[1] != ptr->items[ptr->top].time[1])
                        ptr = pop(ptr);
                    printf("%s", ptr->items[ptr->top].message_sent);
                } else if (current_time[0] >= 2 && current_time[0] <= 8) {
                    while (current_time[0] != p->items[p->top].time[0] || current_time[1] != p->items[p->top].time[1])
                        p = pop(p);
                    printf("%s", p->items[p->top].message_sent);
                } else {
                    printf("Invalid time\n");
                    return -1;
                }
                break;

            case 3:
                if (current_time[0] >= 8 && current_time[0] < 12 || (current_time[0] == 1 && current_time[1] == 0)) {
                    temp = ptr->top;
                    while (temp != -1) {
                        printf("%s", ptr->items[temp].message_sent);
                        temp--;
                    }
                } else if (current_time[0] >= 2 && current_time[0] < 7) {
                    temp = p->top;
                    while (temp != -1) {
                        printf("%s", p->items[temp].message_sent);
                        temp--;
                    }
                }
                break;

            case 4:
                temp = ptr->top;
                while (temp != -1) {
                    printf("%s", ptr->items[temp].message_sent);
                    temp--;
                }
                temp = p->top;
                while (temp != -1) {
                    printf("%s", p->items[temp].message_sent);
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
