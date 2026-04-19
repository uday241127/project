#include <stdio.h>
typedef struct node{
    char name[64];
    int marks;
    int id;
    char city[64];
    char val[32];
    struct node* prev;
    struct node* next;
}node;

typedef struct node2{
    char key[32];
    char val[32];
    struct node2* prev;
    struct node2* next;
}node2;

typedef struct map2{
    char key[32];
    node2* ptr;
    struct map2* next;
}map2;

typedef struct map{
    int id;
    node* ptr;
    struct map* next;
}map;

node* createnode(char *name,int marks,int id,char* city);
void insertsorted(char *name,int marks,int id,char* city);
void deletebeg();
void deletend();
void del(int id);
void print();
void process_line(char *line);
void out(FILE* f1);
void add(int id,node* ptr);
node* search(int id);
void delete_idx(int id);
void add2(char*key,node2* ptr);
node2* search2(char*key);
int hash(char*s);
node2* createnode2(char*key,char*val);
void insert(char*key,char*val);
void joincity();
void joinid();
void joinmarks();
void joinname();
void resetval();