#include <stdio.h>
#include "lib.h"
#include <stdlib.h>
#include <string.h>

int main(int args, char *argv[])
{
    // file opening
    if (args < 3)
    {
        printf("incomplete argruments");
        return 1;
    }

    FILE *f3; // queries
    f3 = fopen(argv[args - 1], "r");

    if (f3 == NULL)
    {
        printf("cant open");
        return 1;
    }
    char name[64];
    int id;
    int marks;
    char city[64];

    FILE *f1; // data file
    f1 = fopen(argv[1], "r");
    while (fscanf(f1, "%d %s %d %s", &id, name, &marks, city) == 4)
    {
        insertsorted(name, marks, id, city);
    }
    fclose(f1);

    char key[32];
    char val[32];
    if (args == 4)
    {
        FILE *f2 = fopen(argv[2], "r");
        if (f2 == NULL)
        {
            printf("cant open");
            return 1;
        }

        while (fscanf(f2, "%s %s", key, val) == 2)
        {
            insert(key, val);
        }
        fclose(f2);
    }

    char line[256];
    while (fgets(line, sizeof(line), f3) != NULL)
    {
        process_line(line);
    }

    FILE *f4;
    f4 = fopen("output.txt", "w");
    out(f4);
    fclose(f3);
}