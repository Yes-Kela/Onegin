#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "read.h"

char* ReadText(char* buffer, size_t* length, size_t* height)
{
    assert(buffer);
    assert(length);
    assert(height);

    FILE* file = fopen("evgeniy_onegin.txt", "rb");
    fseek(file, 0L, SEEK_END);
    *length = ftell(file) / sizeof(char);

    buffer = (char*) realloc(buffer, (*length + 1)*sizeof(char));
    for (size_t i = 0; i < *length + 1; i++)
    {
        buffer[i] = 0;
    }

    fseek(file, 0L, SEEK_SET);
    fread(buffer, sizeof(char), *length, file);
    fclose(file);

    (*length)++;
    buffer[*length - 1] = '\n';
    for (size_t i = 0; i < *length; i++)
    {
        if (buffer[i] == '\n')
        {
            (*height)++;
            buffer[i] = '\0';
        }
    }

    return buffer;
}
