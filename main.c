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

    FILE *f2; // queries
    f2 = fopen(argv[args - 1], "r");

    if (f2 == NULL)
    {
        printf("cant open");
        return 1;
    }
    char name[64];
    int id;
    int marks;
    char city[64];
    for (int i = 0; i < args - 2; i++)
    {
        FILE *f1; // data file
        f1 = fopen(argv[i], "r");
        while (fscanf(f1, "%d %s %d %s", &id, name, &marks, city) == 4)
        {
            insertsorted(name, marks, id, city);
        }
        fclose(f1);
    }
    char line[256];
    while (fgets(line, sizeof(line), f2) != NULL)
    {
        process_line(line);
    }

    fclose(f2);
    FILE *f3;
    f3 = fopen("output.txt", "w");
    write(f3);
    fclose(f3);
}