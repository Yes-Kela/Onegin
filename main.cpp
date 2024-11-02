#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "main.h"

void MyPrint(char);
void PrintStruct(struct inform* lines, int height);

int main(void)
{
    FILE* file = fopen("evgeniy_onegin.txt", "rb");
    fseek(file, 0L, SEEK_END);
    size_t length = ftell(file) / sizeof(char);                    // length - source length
    char* buffer = (char*) calloc(length + 1, sizeof(char));       // alloc one more byte with \n
    fseek(file, 0L, SEEK_SET);
    fread(buffer, sizeof(char), length, file);
    fclose(file);

    length++;
    buffer[length - 1] = '\n';                                     // write down \n in the last byte
    size_t height = 0;                                             // count number of strings by \n or \r
    for (size_t i = 0; i < length; i++)                            // (consider them equivalent == all they're \n)
    {
        if (buffer[i] == '\n')
        {
            height ++;
            buffer[i] = '\0';                                      // they're all \0 now and the number of strings is number of \0
        }                                                          // and we guarantee that there is \0 at the end
    }
    // TODO count last line without \n in the end
    // TODO rename structure inform

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

    printf("\n\n\n"
    "***************************************************************************************************************"
    "***************************************************************************************************************"
    "Sorted text:"
    "***************************************************************************************************************"
    "***************************************************************************************************************"
    "\n\n\n");

    for (size_t i = 0; i < height; i++)
    {
        printf("%s\n", lines[i].pointer);
    }

    printf("\n");

    free(buffer);
    free(lines);

    return 0;
}

void MyPrint(char ch)
{
    if (ch == '\n')
    {
        printf("\n\\n\n");
    }
    else if (ch == '\r')
    {
        printf("\n\\r\n");
    }
    else if (ch == '\0')
    {
        printf("\n\\0\n");
    }
    else
    {
        printf("%c", ch);
    }
}

void PrintStruct(struct inform* lines, int height)
{
    printf("\nlines.pointer      lines.length\n");
    for (int i = 0; i < height; i++)
    {
        printf("%p         %d\n", lines[i].pointer, lines[i].length);
    }
}
