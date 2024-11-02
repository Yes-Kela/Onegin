#include <stdio.h>
#include <stdlib.h>
#include "write.h"

void WriteText(const struct inform* lines, const size_t height)
{
    FILE* dest_file = fopen("new_onegin.txt", "wb");
    for (size_t i = 0; i < height; i++)
    {
        fwrite((*(lines + i)).pointer, sizeof(char), (*(lines + i)).length, dest_file);
    }
    fclose(dest_file);
}
