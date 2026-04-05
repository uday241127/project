#include <stdio.h>
#include "lib.h"
#include <stdlib.h>
#include <string.h>

int main(int args,char* argv[]){
    //file opening
    if(args!=3){
        printf("incomplete argruments");
        return 1;
    }
    FILE *f1; //data file
    f1=fopen(argv[1],"r");

    FILE *f2; // queries
    f2=fopen(argv[2],"r");

    if(f1==NULL || f2==NULL){
        printf("cant open");
        return 1;
    }
    char name[64];
    int id;
    int marks;
    while(fscanf(f1,"%d %s %d",&id,name,&marks)==3){
        insertend(name,marks,id);
    }
    char line[256];
    while(fgets(line,sizeof(line),f2)!=NULL){
        process_line(line);
    }
    fclose(f1);
    f1=fopen(argv[1],"w");
    write(f1);
    fclose(f1);
    fclose(f2);
}