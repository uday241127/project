#include <stdio.h>
typedef struct node{
    char name[64];
    int marks;
    int id;
    char city[64];
    struct node* prev;
    struct node* next;
}node;

typedef struct map{
    int id;
    node* ptr;
    struct map* next;
}map;

node* createnode(char *name,int marks,int id,char* city);
void insertsorted(char *name,int marks,int id,char* city);
void deletebeg();
void deletend();
void delete(int id,int f);
void print();
void process_line(char *line);
void write(FILE* f1);
void add(int id,node* ptr);
node* search(int id);
void delete_idx(int id);