#include <stdio.h>
#include <stdlib.h>
#include "write.h"

void WriteText(const struct line_t* lines, const size_t num_of_lines)
{
    FILE* dest_file = fopen("new_onegin.txt", "wb");
    for (size_t i = 0; i < num_of_lines; i++)
    {
        fwrite((*(lines + i)).pointer, sizeof(char), (*(lines + i)).length, dest_file);
    }
    fclose(dest_file);
}
