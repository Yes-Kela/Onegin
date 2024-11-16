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
    Structure(lines, buffer, length, num_of_lines);
    /*
    printf("num_of_lines = %d\n", num_of_lines);
    for (size_t i = 0; i < num_of_lines; i++)
    {
        printf("%s %d %p\n", lines[i].pointer, lines[i].length, lines[i].pointer);
    }
    printf("\n\n");
    */
    SortPointers(lines, num_of_lines, &ComparePointersBack);
    /*
    for (size_t i = 0; i < num_of_lines; i++)
    {
        printf("%s %d %p\n", lines[i].pointer, lines[i].length, lines[i].pointer);
    }
    */
    WriteText(lines, num_of_lines);

    free(lines);
    free(buffer);

    return 0;
}
