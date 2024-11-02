#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    // TODO count last line without \n in the end       DONE
    // TODO rename structure inform                     DONE
    size_t length = 1, height = 0;
    char* buffer = (char*) calloc(length, sizeof(char));

    buffer = ReadText(buffer, &length, &height);

    struct inform* lines = (struct inform*) calloc(height, sizeof(struct inform));
    lines[0].pointer = buffer;
    size_t num_of_ends = 1;
    size_t len_of_string = 1;
    for (size_t i = 1; i < length; i++)
    {
        len_of_string++;
        if (i < length - 1)
        {
            if (buffer[i] == '\0')
            {
                lines[num_of_ends - 1].length = len_of_string;
                lines[num_of_ends].pointer = buffer + i + 1;
                len_of_string = 0;
                num_of_ends++;
            }
        }
        else
        {
            lines[num_of_ends - 1].length = len_of_string;
        }
    }
    len_of_string = 0;
    num_of_ends = 0;

    SortPointers (lines, height);

    WriteText(lines, height);

    free(buffer);
    free(lines);

    return 0;
}
