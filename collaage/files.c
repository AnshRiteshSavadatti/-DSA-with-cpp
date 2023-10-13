#include<stdio.h>
#include<stdlib.h>

struct ig_reels{
    char cname[20];
    float duration;
    int likes;
};

int main(){
    FILE *fp;
    char fname[] = "a2.txt";
    fp = fopen("a.txt", "w+");
    if(fp == NULL){
        printf("File open error\n");
        return -1;
    }

    struct ig_reels ir[3];
    for(int i =0; i<3; i++){
        scanf("%s%f%d",ir[i].cname, &ir[i].duration, &ir[i].likes);
        fprintf(fp,"%s %f %d\n",ir[i].cname, ir[i].duration, ir[i].likes);
    }

    fclose(fp);

    fp = fopen("a.txt", "r+");
    if(fp == NULL){
        printf("File open error\n");
        return -1;
    }

    struct ig_reels r;
    printf("The file data is \n");
    for(int i =0; i<3; i++){
        fscanf(fp, "%s %f %d\n",r.cname, &r.duration, &r.likes);
        printf("%s %f %d\n",r.cname, r.duration, r.likes);
    }
    fclose(fp);
    return 420;
}