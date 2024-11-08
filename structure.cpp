#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structure.h"

void Structure(struct line_t* lines, const char* buffer, const size_t length)
{
    (*lines).pointer = buffer;
    size_t num_of_ends = 1;
    size_t len_of_string = 1;
    for (size_t i = 1; i < length; i++)
    {
        len_of_string++;
        if (i < length - 1)
        {
            if (buffer[i] == '\0')
            {
                (*(lines + num_of_ends - 1)).length = len_of_string;
                (*(lines + num_of_ends)).pointer = buffer + i + 1;
                len_of_string = 0;
                num_of_ends++;
            }
        }
        else
        {
            (*(lines + num_of_ends - 1)).length = len_of_string;
        }
    }
    len_of_string = 0;
    num_of_ends = 0;
}
