#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structure.h"

void Structure(struct line_t* lines, char* buffer, const size_t length, const size_t num_of_lines)
{
    (*lines).pointer = buffer;

    size_t num_of_ends = 1;
    size_t len_of_string = 1;
    for (size_t i = 1; i < length; )                                    // TODO: FIX STRUCTURING THE BUFFER!!!
    {
        len_of_string++;
        if (buffer[i] == '\0')
        {
            while (buffer[i+1] == '\0' && i + 1 < length)
            {
                i++;
                len_of_string++;
            }

            (*(lines + num_of_ends - 1)).length = len_of_string;
            len_of_string = 0;

            if (i + 1 < length)
            {
                (*(lines + num_of_ends)).pointer = buffer + i + 1;
                num_of_ends++;
            }
            i++;
        }
        else
        {
            i++;
        }
    }

    assert(num_of_lines == num_of_ends);

    len_of_string = 0;
    num_of_ends = 0;
}
