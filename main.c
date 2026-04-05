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
    char city[64];
    while(fscanf(f1,"%d %s %d %s",&id,name,&marks,city)==4){
        insertend(name,marks,id,city);
    }
    char line[256];
    while(fgets(line,sizeof(line),f2)!=NULL){
        process_line(line);
    }
    fclose(f1);
    fclose(f2);
    FILE* f3;
    f3=fopen("output.txt","w");
    write(f3);
    fclose(f3);
    
}