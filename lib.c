#define SIZE 100003
#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int f2 = 0;
node *head = NULL;
node *tail = NULL;

map *table[SIZE] = {NULL};

node2 *head2 = NULL;
node2 *tail2 = NULL;
map2 *table2[SIZE] = {NULL};

int hash(char *s)
{
    int h = 0;
    while (*s)
    {
        h = (h * 31 + *s++) % SIZE;
    }
    return h;
}
void add2(char *key, node2 *ptr)
{
    int a = hash(key);
    map2 *new = malloc(sizeof(map2));
    strcpy(new->key, key);
    new->ptr = ptr;
    new->next = table2[a];
    table2[a] = new;
}

node2 *search2(char *key)
{
    int h = hash(key);
    map2 *temp = table2[h];
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            return temp->ptr;
        }
        temp = temp->next;
    }
    return NULL;
}

node2 *createnode2(char *key, char *val)
{
    node2 *newnode = malloc(sizeof(node2));
    strcpy(newnode->key, key);
    strcpy(newnode->val, val);
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void insert(char *key, char *val)
{
    node2 *newnode = createnode2(key, val);
    if (head2 == NULL)
    {
        head2 = tail2 = newnode;
        add2(key, newnode);
        return;
    }
    tail2->next = newnode;
    newnode->prev = tail2;
    newnode->next = NULL;
    tail2 = newnode;
    add2(key, newnode);
    return;
}

void joincity()
{
    node *temp = head;

    while (temp)
    {
        node2 *m = search2(temp->city);
        if (m == NULL)
        {
            strcpy(temp->val, "NA");
        }
        else
        {
            strcpy(temp->val, m->val);
        }
        temp = temp->next;
    }
    f2 = 1;
}

void joinid()
{
    node *temp = head;
    while (temp)
    {
        char str[32];
        sprintf(str, "%d", temp->id);
        node2 *m = search2(str);
        if (m == NULL)
        {
            strcpy(temp->val, "NA");
        }
        else
        {
            strcpy(temp->val, m->val);
        }
        temp = temp->next;
    }
    f2 = 1;
}

void joinname()
{
    node *temp = head;
    while (temp)
    {
        node2 *m = search2(temp->name);
        if (m == NULL)
        {
            strcpy(temp->val, "NA");
        }
        else
        {
            strcpy(temp->val, m->val);
        }
        temp = temp->next;
    }
    f2 = 1;
}

void joinmarks()
{
    node *temp = head;
    while (temp)
    {
        char str[32];
        sprintf(str, "%d", temp->marks);
        node2 *m = search2(str);
        if (m == NULL)
        {
            strcpy(temp->val, "NA");
        }
        else
        {
            strcpy(temp->val, m->val);
        }
        temp = temp->next;
    }
    f2 = 1;
}

void add(int id, node *ptr)
{
    int a = id % SIZE;
    map *new = malloc(sizeof(map));
    new->id = id;
    new->ptr = ptr;
    new->next = table[a];
    table[a] = new;
}

node *search(int id)
{
    int a = id % SIZE;
    map *temp = table[a];
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return temp->ptr;
        }
        temp = temp->next;
    }
    return NULL;
}

void delete_idx(int id)
{
    int a = id % SIZE;
    map *temp1 = table[a];
    map *temp2 = NULL;
    while (temp1 != NULL)
    {
        if (temp1->id == id)
        {
            if (temp2 == NULL)
            {
                table[a] = temp1->next;
            }
            else
            {
                temp2->next = temp1->next;
            }
            free(temp1);
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
}

node *createnode(char *name, int marks, int id, char *city)
{
    node *newnode = (node *)malloc(sizeof(node));
    strcpy(newnode->name, name);
    newnode->marks = marks;
    newnode->id = id;
    strcpy(newnode->city, city);
    strcpy(newnode->val, "NA");
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void insertsorted(char *name, int marks, int id, char *city)
{
    if(search(id)!=NULL){
        printf("error:DUPLICATE ID\n");
        return;
    }
    node *newnode = createnode(name, marks, id, city);
    if (head == NULL)
    {
        head = tail = newnode;
        add(id, newnode);
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->id > id)
        {
            if (temp == head)
            {
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
            }
            else
            {
                node *temp1 = temp->prev;
                temp1->next = newnode;
                newnode->prev = temp1;
                newnode->next = temp;
                temp->prev = newnode;
            }
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    add(id, newnode);
}
void deletebeg()
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
}
void deletend()
{
    if (head == NULL)
    {
        return;
    }
    node *temp = tail;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}
void del(int id)
{
    if(head==NULL){
        printf("error:ID NOT FOUND\n");
        return;
    }
    int found=0;
    if (head->id == id)
    {
        deletebeg();
        delete_idx(id);
        return;
    }
    
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (temp == tail)
            {
                found=1;
                deletend();
                delete_idx(id);
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete_idx(id);
            free(temp);
            return;
        }
        temp = temp->next;
    }
    if (found==0)
    {
        printf("error:ID NOT FOUND\n");
    }
}
void resetval()
{
    node *temp = head;
    while (temp)
    {
        strcpy(temp->val, "NA");
        temp = temp->next;
    }
}
void print()
{
    node *temp = head;
    while (temp != NULL)
    {
        if(f2==1){
        printf("%d %s %d %s %s\n", temp->id, temp->name, temp->marks, temp->city, temp->val);
        }
        else{
            printf("%d %s %d %s\n",temp->id, temp->name, temp->marks, temp->city);
        }
        temp = temp->next;
    }
    f2=0;
}

void process_line(char *line)
{
    line[strcspn(line, "\n")] = '\0';
    int f = 1;
    if (strstr(line, "INSERT") != NULL)
    {
        char *token = strtok(line, " ");
        token = strtok(NULL, " ");
        int id = atoi(token);
        token = strtok(NULL, " ");
        char name[64];
        strcpy(name, token);
        token = strtok(NULL, " ");
        int marks = atoi(token);
        token = strtok(NULL, " ");
        insertsorted(name, marks, id, token);
    }
    if (strstr(line, "DELETE") != NULL)
    {
        char *token = strtok(line, " ");
        token = strtok(NULL, " ");
        int id = atoi(token);
        del(id);
    }
    if (strstr(line, "UPDATE") != NULL)
    {
        char *token = strtok(line, " ");
        token = strtok(NULL, " ");
        int id = atoi(token);
        node *temp;
        temp = search(id);
        if (!temp)
        {
            printf("error:ID NOT FOUND\n");
            return;
        }
        token = strtok(NULL, " ");
        char op[10];
        strcpy(op, token);
        if (strcmp(op, "NAME") == 0)
        {
            token = strtok(NULL, " ");
            strcpy(temp->name, token);
        }
        if (strcmp(op, "MARKS") == 0)
        {
            token = strtok(NULL, " ");
            int nm = atoi(token);
            temp->marks = nm;
        }
        if (strcmp(op, "CITY") == 0)
        {
            token = strtok(NULL, " ");
            strcpy(temp->city, token);
        }
    }
    if (strstr(line, "SELECT") != NULL)
    {
        char *token = strtok(line, " ");
        token = strtok(NULL, " ");

        if (strcmp(token, "*") == 0)
        {
            token = strtok(NULL, " ");
            if (token == NULL)
            {
                print();
                return;
            }
            if (strcmp(token, "WHERE") == 0)
            {
                token = strtok(NULL, " ");
                if (strcmp(token, "id") == 0)
                {
                    token = strtok(NULL, " ");
                    if (strcmp(token, "=") == 0)
                    {
                        token = strtok(NULL, " ");
                        int sid = atoi(token);
                        node *temp = search(sid); 
                        if (!temp)
                        {
                            printf("error:ID NOT FOUND\n");
                        }
                        else{
                        printf("%d %s %d %s\n", temp->id, temp->name, temp->marks, temp->city);
                        }
                       
                    }
                    if (strcmp(token, ">") == 0)
                    {
                        token = strtok(NULL, " ");
                        int sid = atoi(token);
                        node *temp = head;
                        while (temp != NULL)
                        {
                            if (temp->id > sid)
                            {
                                printf("%d %s %d %s\n", temp->id, temp->name, temp->marks, temp->city);
                                f = 0;
                            }
                            temp = temp->next;
                        }
                        if (f)
                        {
                            printf("error:ID NOT FOUND\n");
                        }
                    }
                    if (strcmp(token, "<") == 0)
                    {
                        token = strtok(NULL, " ");
                        int sid = atoi(token);
                        node *temp = head;
                        while (temp != NULL)
                        {
                            if (temp->id < sid)
                            {
                                printf("%d %s %d %s\n", temp->id, temp->name, temp->marks, temp->city);
                                f = 0;
                            }
                            temp = temp->next;
                        }
                        if (f)
                        {
                            printf("error:ID NOT FOUND\n");
                        }
                    }
                }
                if (strcmp(token, "name") == 0)
                {
                    token = strtok(NULL, " ");
                    token = strtok(NULL, " ");
                    node *temp = head;
                    while (temp != NULL)
                    {
                        if (strcmp(temp->name, token) == 0)
                        {
                            printf("%d %s %d %s\n", temp->id, temp->name, temp->marks, temp->city);
                            f = 0;
                        }
                        temp = temp->next;
                    }
                    if (f)
                    {
                        printf("error:NAME NOT FOUND\n");
                    }
                }
                if (strcmp(token, "marks") == 0)
                {
                    token = strtok(NULL, " ");
                    if (strcmp(token, ">") == 0)
                    {
                        token = strtok(NULL, " ");
                        int m = atoi(token);
                        node *temp = head;

                        while (temp != NULL)
                        {
                            if (temp->marks > m)
                            {
                                printf("%d %s %d %s\n", temp->id, temp->name, temp->marks, temp->city);
                                f = 0;
                            }
                            temp = temp->next;
                        }
                        if (f)
                        {
                            printf("error:ID NOT FOUND\n");
                        }
                    }
                    if (strcmp(token, "<") == 0)
                    {
                        token = strtok(NULL, " ");
                        int m = atoi(token);
                        node *temp = head;
                        while (temp != NULL)
                        {
                            if (temp->marks < m)
                            {
                                printf("%d %s %d %s\n", temp->id, temp->name, temp->marks, temp->city);
                                f = 0;
                            }
                            temp = temp->next;
                        }
                        if (f)
                        {
                            printf("error:ID NOT FOUND\n");
                        }
                    }
                    if (strcmp(token, "=") == 0)
                    {
                        token = strtok(NULL, " ");
                        int m = atoi(token);
                        node *temp = head;
                        while (temp != NULL)
                        {
                            if (temp->marks == m)
                            {
                                printf("%d %s %d %s\n", temp->id, temp->name, temp->marks, temp->city);
                                f = 0;
                            }
                            temp = temp->next;
                        }
                        if (f)
                        {
                            printf("error:ID NOT FOUND\n");
                        }
                    }
                }
                if (strcmp(token, "city") == 0)
                {
                    token = strtok(NULL, " ");
                    token = strtok(NULL, " ");
                    node *temp = head;
                    while (temp != NULL)
                    {
                        if (strcmp(temp->city, token) == 0)
                        {
                            printf("%d %s %d %s\n", temp->id, temp->name, temp->marks, temp->city);
                            f = 0;
                        }
                        temp = temp->next;
                    }
                    if (f)
                    {
                        printf("error:CITY NOT FOUND\n");
                    }
                }
            }
            if (strcmp(token, "JOIN") == 0)
            {
                token = strtok(NULL, " ");

                if (strcmp(token, "CITY") == 0)
                {
                    resetval();
                    joincity();
                    print();
                }
                if (strcmp(token, "ID") == 0)
                {
                    resetval();
                    joinid();
                    print();
                }
                if (strcmp(token, "MARKS") == 0)
                {
                    resetval();
                    joinmarks();
                    print();
                }
                if (strcmp(token, "NAME") == 0)
                {
                    resetval();
                    joinname();
                    print();
                }
            }
        }
    }
}
void out(FILE *f1)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (f2 == 1)
        {
            fprintf(f1, "%d %s %d %s %s\n", temp->id, temp->name, temp->marks, temp->city, temp->val);
        }
        else
        {
            fprintf(f1, "%d %s %d %s\n", temp->id, temp->name, temp->marks, temp->city);
        }
        temp = temp->next;
    }
    f2=0;
}