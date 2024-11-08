#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "read.h"

char* ReadText(size_t* length, size_t* num_of_lines)
{
    assert(length);
    assert(num_of_lines);

    FILE* file = fopen("evgeniy_onegin.txt", "rb");
    fseek(file, 0L, SEEK_END);
    *length = ftell(file) / sizeof(char);
    fseek(file, 0L, SEEK_SET);

    char* buffer = (char*) calloc((*length + 1), sizeof(char));

    fread(buffer, sizeof(char), *length, file);
    fclose(file);

    (*length)++;
    buffer[*length - 1] = '\n';
    for (size_t i = 0; i < *length; i++)
    {
        if (buffer[i] == '\n')
        {
            (*num_of_lines)++;
            buffer[i] = '\0';
        }
    }

    return buffer;
}
