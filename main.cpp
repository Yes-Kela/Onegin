#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    // TODO count last line without \n in the end       DONE
    // TODO rename structure inform                     DONE
    size_t length = 1, num_of_lines = 0;
    char* buffer = ReadText(&length, &num_of_lines);

    struct line_t* lines = (struct line_t*) calloc(num_of_lines, sizeof(struct line_t));
    Structure(lines, buffer, length);

    SortPointers (lines, num_of_lines, &ComparePointers);

    WriteText(lines, num_of_lines);

    free(buffer);
    free(lines);

    return 0;
}
