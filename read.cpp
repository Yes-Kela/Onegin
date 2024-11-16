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

    int is_windows = 0;
    for (size_t j = 0; buffer[j] != '\n' && j < *length; j++)
    {
        if (buffer[j] == '\r')
        {
            is_windows = 1;
        }
    }

    *num_of_lines = 0;
    if (is_windows == 0)
    {
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
    }
    else
    {
        (*length)++;
        buffer[*length - 1] = '\r';

        for (size_t i = 0; i < *length; )
        {
            if (buffer[i] == '\r')
            {
                (*num_of_lines)++;
                buffer[i] = '\0';
                while ((buffer[i+1] == '\r' || buffer[i+1] == '\n') && i + 1 < *length)
                {
                    buffer[i+1] = '\0';
                    i++;
                }
            }
            else if (buffer[i] == '\n')
            {
                buffer[i] = '\0';
            }
            i++;
        }
    }

    return buffer;
}
