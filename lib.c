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
void delete(int id,int f){
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
    if(f){
        printf("error:ID NOT FOUND\n");
    }
}
void print(){
    node* temp=head;
    while(temp!=NULL){
        printf("%d %s %d %s\n",temp->id,temp->name,temp->marks,temp->city);
        temp=temp->next;
    }
}

void process_line(char *line){
    line[strcspn(line,"\n")]='\0';
    int f=1;
    if(strstr(line,"INSERT")!=NULL){
        char* token=strtok(line," ");
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
    if(strstr(line,"DELETE")!=NULL){
        char* token=strtok(line," ");
        token=strtok(NULL," ");
        int id=atoi(token);
        delete(id,f);
    }
    if(strstr(line,"UPDATE")!=NULL){
        char* token=strtok(line," ");
        token=strtok(NULL," ");
        int id=atoi(token);
        node* temp=head;
        while(temp!=NULL){
            if(temp->id==id){
                f=0;
                break;
            }
            temp=temp->next;
        }
        if(f){
            printf("error:ID NOT FOUND\n");
            return;
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
    if(strstr(line,"SELECT")!=NULL){
        char* token=strtok(line," ");
        token=strtok(NULL," ");
        
        if(strcmp(token,"*")==0){
            token=strtok(NULL," ");
            if(token==NULL){
                print();
                return;
            }
            if(strcmp(token,"WHERE")==0){
               token=strtok(NULL," ");
               if(strcmp(token,"id")==0){
                token=strtok(NULL," ");
                if(strcmp(token,"=")==0){
                    token=strtok(NULL," ");
                    int sid=atoi(token);
                    node* temp=head;
                    while(temp!=NULL){
                      if(temp->id==sid){
                        printf("%d %s %d %s\n",temp->id,temp->name,temp->marks,temp->city);
                        f=0;
                        break;
                      }
                      temp=temp->next; 
                    }
                    if(f){
                        printf("error:ID NOT FOUND\n");
                    }
                }
                if(strcmp(token,">")==0){
                    token=strtok(NULL," ");
                    int sid=atoi(token);
                    node* temp=head;
                    while(temp!=NULL){
                        if(temp->id>sid){
                            printf("%d %s %d %s\n",temp->id,temp->name,temp->marks,temp->city);
                            f=0;
                        }
                        temp=temp->next;
                    }   
                    if(f){
                        printf("error:ID NOT FOUND\n");
                    }
                }
                if(strcmp(token,"<")==0){
                    token=strtok(NULL," ");
                    int sid=atoi(token);
                    node* temp=head;
                    while(temp!=NULL){
                        if(temp->id<sid){
                            printf("%d %s %d %s\n",temp->id,temp->name,temp->marks,temp->city);
                            f=0;
                        }
                        temp=temp->next;
                    }
                    if(f){
                        printf("error:ID NOT FOUND\n");
                    }
                }  
            }
            if(strcmp(token,"name")==0){
                token=strtok(NULL," ");
                token=strtok(NULL," ");
                node* temp=head;
                while(temp!=NULL){
                    if(strcmp(temp->name,token)==0){
                        printf("%d %s %d %s\n",temp->id,temp->name,temp->marks,temp->city);
                        f=0;
                    }
                    temp=temp->next;
                }
                if(f){
                    printf("error:NAME NOT FOUND\n");
                }
            }
            if(strcmp(token,"marks")==0){
                token=strtok(NULL," ");
                if(strcmp(token,">")==0){
                    token=strtok(NULL," ");
                    int m=atoi(token);
                    node* temp=head;
                    
                    while(temp!=NULL){
                        if(temp->marks>m){
                            printf("%d %s %d %s\n",temp->id,temp->name,temp->marks,temp->city);
                            f=0;
                        }
                        temp=temp->next;
                    }
                    if(f){
                        printf("error:ID NOT FOUND\n");
                    }
                }
                if(strcmp(token,"<")==0){
                    token=strtok(NULL," ");
                    int m=atoi(token);
                    node* temp=head;
                    while(temp!=NULL){
                        if(temp->marks<m){
                            printf("%d %s %d %s\n",temp->id,temp->name,temp->marks,temp->city);
                            f=0;
                        }
                        temp=temp->next;
                    }
                    if(f){
                        printf("error:ID NOT FOUND\n");
                    }
                }
                if(strcmp(token,"=")==0){
                    token=strtok(NULL," ");
                    int m=atoi(token);
                    node* temp=head;
                    while(temp!=NULL){
                        if(temp->marks==m){
                            printf("%d %s %d %s\n",temp->id,temp->name,temp->marks,temp->city);
                            f=0;
                        }
                        temp=temp->next;
                    }
                    if(f){
                        printf("error:ID NOT FOUND\n");
                    }
                }                                
            }
            if(strcmp(token,"city")==0){
                token=strtok(NULL," ");
                token=strtok(NULL," ");
                node* temp=head;
                while(temp!=NULL){
                    if(strcmp(temp->city,token)==0){
                        printf("%d %s %d %s\n",temp->id,temp->name,temp->marks,temp->city);
                        f=0;
                    }
                    temp=temp->next;
                }
                if(f){
                    printf("error:CITY NOT FOUND\n");
                }
            }
            }
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