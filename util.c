#include "util.h"
#include <string.h>
#include <stdlib.h>

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

char *mallocstr(char str[])
{
    size_t size = 1;

    while (str[size - 1] != '\0')
    {
        size++;
    }

    unsigned char *newmem = malloc(size);
    strcpy(newmem, str);

    return newmem;
}