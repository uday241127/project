#include <stdio.h>
typedef struct node{
    char name[64];
    int marks;
    int id;
    struct node* prev;
    struct node* next;
}node;

node* createnode(char *name,int marks,int id);
void insertend(char *name,int marks,int id);
void deletebeg();
void deletend();
void delete(int id);
void print();
void process_line(char *line);
void write(FILE* f1);