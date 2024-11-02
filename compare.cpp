#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include "compare.h"

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
        {
            break;
        }

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

    while (**ptr_to_char_ptr != '\0' && !isalpha (**ptr_to_char_ptr))
    {
        (*ptr_to_char_ptr)++;
    }
}
