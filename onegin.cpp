#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

#define PRINTFS

const int height = 7;

struct inform
{
    const char* pointer;
    int lenght;
};


void SortPointers (struct inform* struct_pointer);
void ExchangePointers (struct inform* first_struct_pointer, struct inform* second_struct_pointer);
int ComparePointers (const char* first_string, const char* second_string, int first_length, int second_length);
int CompareChar (char first_char, char second_char);
void SkipNonLetters (const char** char_ptr);


int main(void)
{
    struct inform lines[height] = {};

    const char table[] =
    "\"My uncle's goodness is extreme,\n"
    "If seriously he hath disease;\n"
    "He hath acquired the world's esteem\n"
    "And nothing more important sees;\n"
    "A paragon of virtue he!\n"
    "But what a nuisance it will be,\n"
    "Chained to his bedside night and day\n";

    lines[0].pointer = table;
    int num_of_ends = 1;
    int counter = 1;

    for (unsigned int i = 1; *(table + i) != '\0'; i++)
    {
        counter++;
        if (*(table + i) == '\n')
        {
            if (*(table + i + 1) != '\0') {
                lines[num_of_ends].pointer = table + (i + 1);
                assert (num_of_ends < height);
            }

            lines[num_of_ends - 1].lenght = counter;
            counter = 0;

            assert (lines[num_of_ends].pointer != NULL);


            num_of_ends ++;
        }
    }

    SortPointers (&lines[0]);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < lines[i].lenght; j++)
        {
            printf("%c", *((lines[i].pointer) + j));
        }
    }

    printf("\n");

    return 0;
}


void SortPointers (struct inform * struct_pointer)
{
    assert (struct_pointer != NULL);
    assert ((*struct_pointer).pointer != NULL);

    for (int active_part = height - 1; active_part > 0; active_part--)
    {
        for (int index = 0; index < active_part; index++)
        {
            const char*  first_string = (*(struct_pointer + index)).pointer;
            const char* second_string = (*(struct_pointer + index + 1)).pointer;
            int first_length = (*(struct_pointer + index)).lenght;
            int second_length = (*(struct_pointer + index + 1)).lenght;

            if (ComparePointers (first_string, second_string, first_length, second_length) < 0)
            {
                ExchangePointers (struct_pointer + index, struct_pointer + index + 1);
            }

            else { ; }
        }
    }

}

void ExchangePointers (struct inform* first_struct_pointer, struct inform* second_struct_pointer)
{
    assert ( first_struct_pointer != NULL);
    assert (second_struct_pointer != NULL);

    struct inform auxiliary = *first_struct_pointer;
    *first_struct_pointer = *second_struct_pointer;
    *second_struct_pointer = auxiliary;
}

int ComparePointers (const char* first_string, const char* second_string, int first_length, int second_length)
{
    assert ( first_string != NULL);
    assert (second_string != NULL);

    const char* first_char_ptr = first_string;
    const char* second_char_ptr = second_string;

    for (; first_char_ptr != first_string + first_length &&
         second_char_ptr != second_string + second_length;
         first_char_ptr++, second_char_ptr++)
    {
        SkipNonLetters (&first_char_ptr);
        SkipNonLetters (&second_char_ptr);

        if (first_char_ptr == first_string + first_length || second_char_ptr == second_string + second_length)
            break;

        if (CompareChar (*first_char_ptr, *second_char_ptr) != 0)
        {
            return (CompareChar (*first_char_ptr, *second_char_ptr));
        }
    }

    if (first_char_ptr == first_string + first_length)
    {
        return 1;
    }

    return -1;
}

int CompareChar (char first_char, char second_char)
{
    return (toupper(second_char) - toupper(first_char));
}


void SkipNonLetters (const char** ptr_to_char_ptr)
{
    assert (ptr_to_char_ptr != NULL);
    assert (*ptr_to_char_ptr != NULL);

    while (**ptr_to_char_ptr != '\n' && !isalpha (**ptr_to_char_ptr))
    {
        (*ptr_to_char_ptr)++;
    }
}
