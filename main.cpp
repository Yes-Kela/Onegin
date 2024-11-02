#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "main.h"

char* ReadText(char* buffer, size_t* length, size_t* height);
void WriteText(const struct inform* lines, const size_t height);
void MyPrint(char ch);


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


char* ReadText(char* buffer, size_t* length, size_t* height)
{
    assert(buffer);
    assert(length);
    assert(height);
    //printf("ReadText(): buffer = %p\n", buffer);

    FILE* file = fopen("evgeniy_onegin.txt", "rb");
    fseek(file, 0L, SEEK_END);
    *length = ftell(file) / sizeof(char);

    buffer = (char*) realloc(buffer, (*length + 1)*sizeof(char));
    for (size_t i = 0; i < *length + 1; i++)
    {
        buffer[i] = 0;
    }
    //printf("ReadText(): after realloc(): buffer = %p\n", buffer);

    fseek(file, 0L, SEEK_SET);
    fread(buffer, sizeof(char), *length, file);
    fclose(file);
    /*
    for (size_t i = 0; i < *length; i++)
    {
        printf("buffer[%d]: %c\n", i, buffer[i]);
    }
    printf("ReadText(): after realloc(): buffer = %p\n", buffer);
    // OK
    */
    (*length)++;
    buffer[*length - 1] = '\n';
    for (size_t i = 0; i < *length; i++)
    {
        if (buffer[i] == '\n')
        {
            (*height)++;
            buffer[i] = '\0';
        }
    }
    //printf("height = %u\n", *height);
    return buffer;
}

void WriteText(const struct inform* lines, const size_t height)
{
    FILE* dest_file = fopen("new_onegin.txt", "wb");
    for (size_t i = 0; i < height; i++)
    {
        fwrite((*(lines + i)).pointer, sizeof(char), (*(lines + i)).length, dest_file);
    }
    fclose(dest_file);
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
