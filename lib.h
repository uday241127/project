#include <stdio.h>
typedef struct node{
    char name[64];
    int marks;
    int id;
    char city[64];
    struct node* prev;
    struct node* next;
}node;

node* createnode(char *name,int marks,int id,char* city);
void insertend(char *name,int marks,int id,char* city);
void deletebeg();
void deletend();
void delete(int id,int f);
void print();
void process_line(char *line);
void write(FILE* f1);