#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "main.h"

void MyPrint(char);
void PrintStruct(struct inform* lines, int height);

int main(void)
{
    FILE* file = fopen("evgeniy.txt", "rb");
    fseek(file, 0L, SEEK_END);
    size_t length = ftell(file) / sizeof(char);
    char* buffer = (char*) calloc(length, sizeof(char));

    fseek(file, 0L, SEEK_SET);
    fread(buffer, sizeof(char), length, file);
    fclose(file);
    /*
    printf("returned_fseek = %d\n", returned_fseek);
    printf("length = %d\n", length);
    printf("buffer address = %p\n", buffer);
    printf("buffer: \n");
    */
    for (size_t i = 0; i < length; i++)
    {
        MyPrint(buffer[i]);
    }
    //printf("\n************************\n");
    // Buffer if okay!


    size_t counter = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (buffer[i] == '\r' || buffer[i] == '\n')
        {
            buffer[i] = '\0';
            counter++;
        }
    }
    size_t height = counter / 2;           // number of the strings
    /*
    printf("counter = %d\n", counter);
    printf("height = %d\n", height);
    printf("buffer address = %p\n", buffer);
    printf("buffer: \n");
    for (size_t i = 0; i < length; i++)
    {
        MyPrint(buffer[i]);
    }
    printf("\n************************\n");
    // Changed buffer ('\r' and '\n' are changed into '\0') is okay!
    */

    struct inform* lines = (struct inform*) calloc(height + 1, sizeof(struct inform));

    lines[0].pointer = buffer;
    /*
    printf("buffer address = %p\n", buffer);
    printf("lines[0].pointer = %p\n", lines[0].pointer);
    */

    size_t num_of_ends = 1;
    size_t len_of_string = 1;

    //printf("  i  i<length-2   buffer[i-1]   buffer[i]   len_of_string   lines[num_of_ends].pointer   lines[num_of_ends-1].length   num_of_ends\n");
    for (size_t i = 1; i < length - 1; i++)
    {
        /*
        printf("%3d     ", i);
        printf("%d          ", (i < length - 2));
        */
        if (i < length - 2)
        {
            //printf("%c           %c               ", buffer[i-1], buffer[i]);

            if (buffer[i] != '\0' || buffer[i - 1] != '\0')
            {
                //printf("%d", len_of_string);

                len_of_string++;
                /*
                printf("(%d)                                                                               ", len_of_string);
                printf("%d", num_of_ends);
                printf("(%d) \n", num_of_ends);
                */
            }
            else
            {
                //printf("%d", len_of_string);

                len_of_string++;
                /*
                printf("(%d)                    ", len_of_string);
                printf("%p", lines[num_of_ends].pointer);
                */
                lines[num_of_ends].pointer = buffer + i + 1;
                /*
                printf("(%p)                      ", lines[num_of_ends].pointer);
                printf("%d", lines[num_of_ends].length);
                */
                lines[num_of_ends - 1].length = len_of_string;

                //printf("(%d)                      ", lines[num_of_ends - 1].length);      // !!!! не заносятся в массив структур!!!

                len_of_string = 0;

                //printf("%d", num_of_ends);

                num_of_ends++;

                //printf("(%d)           \n", num_of_ends);
            }
        }
        else
        {
            len_of_string += 2;
            lines[num_of_ends - 1].length = len_of_string;
            //printf("\n");
        }
    }

    len_of_string = 0;
    num_of_ends = 0;

    PrintStruct(lines, height + 1);

    for (size_t i = 0; i < height; i++)
    {
        printf("%s\n", lines[i].pointer);
    }

    SortPointers (lines, height);

    PrintStruct(lines, height + 1);

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

