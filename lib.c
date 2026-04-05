#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

node* head=NULL;
node* tail=NULL;

node* createnode(char *name,int marks,int id,char* city){
    node* newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->name,name);
    newnode->marks=marks;
    newnode->id=id;
    strcpy(newnode->city,city);
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}
void insertend(char *name,int marks,int id,char* city){
    node* newnode=createnode(name,marks,id,city);
    if(head==NULL){
        head=tail=newnode;
        return;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}
void deletebeg(){
    if(head==NULL){
        return;
    }
    node* temp=head;
    if(head==tail){
        head=tail=NULL;
    }
    else{
        head=head->next;
        head->prev=NULL;
    }
    free(temp);
}
void deletend(){
    if(head==NULL){
        return;
    }
    node* temp=tail;
    if(head==tail){
        head=tail=NULL;
    }
    else{
        tail=tail->prev;
        tail->next=NULL;
    }
    free(temp);
}
void delete(int id){
    if(head->id==id){
        deletebeg();
        return;
    }
    node* temp=head;
    while(temp!=NULL){
        if(temp->id==id){
            if(temp==tail){
                deletend();
                return;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
        temp=temp->next;
    }
}
void print(){
    node* temp=head;
    while(temp!=NULL){
        printf("%d %s %d\n",temp->id,temp->name,temp->marks);
        temp=temp->next;
    }
}

void process_line(char *line){
    line[strcspn(line,"\n")]='\0';
    char* token=strtok(line," ");
    if(strcmp(token,"INSERT")==0){
        token=strtok(NULL," ");
        int id=atoi(token);
        token=strtok(NULL," ");
        char name[64];
        strcpy(name,token);
        token=strtok(NULL," ");
        int marks=atoi(token);
        token=strtok(NULL," ");
        insertend(name,marks,id,token);
    }
    if(strcmp(token,"DELETE")==0){
        token=strtok(NULL," ");
        int id=atoi(token);
        delete(id);
    }
    if(strcmp(token,"UPDATE")==0){
        token=strtok(NULL," ");
        int id=atoi(token);
        node* temp=head;
        while(temp->id!=id){
            temp=temp->next;
        }
        token=strtok(NULL," ");
        char op[10];
        strcpy(op,token);
        if(strcmp(op,"NAME")==0){
            token=strtok(NULL," ");
            strcpy(temp->name,token);
        }
        if(strcmp(op,"MARKS")==0){
            token=strtok(NULL," ");
            int nm=atoi(token);
            temp->marks=nm;
        }
        if(strcmp(op,"CITY")==0){
            token=strtok(NULL," ");
            strcpy(temp->city,token);
        }
    }
}
void write(FILE *f1){
    node* temp=head;
    while(temp!=NULL){
        fprintf(f1,"%d %s %d %s\n",temp->id,temp->name,temp->marks,temp->city);
        temp=temp->next;
    }
}