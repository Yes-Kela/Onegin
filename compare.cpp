#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include "compare.h"

int ComparePointers(const char* first_string, const char* second_string, int first_length, int second_length)
{
    assert( first_string != NULL);
    assert(second_string != NULL);

    const char* first_char_ptr = first_string;
    const char* second_char_ptr = second_string;

    for (; first_char_ptr != first_string + first_length &&
         second_char_ptr != second_string + second_length;
         first_char_ptr++, second_char_ptr++)
    {
        SkipNonLetters(&first_char_ptr, first_length);
        SkipNonLetters(&second_char_ptr, second_length);

        if (first_char_ptr == first_string + first_length || second_char_ptr == second_string + second_length)
        {
            break;
        }

        if (CompareChar(*first_char_ptr, *second_char_ptr) != 0)
        {
            return (CompareChar(*first_char_ptr, *second_char_ptr));
        }
    }

    if (first_char_ptr == first_string + first_length)
    {
        return 1;
    }

    return -1;
}

int ComparePointersBack(const char* first_string, const char* second_string, int first_length, int second_length)
{
    assert( first_string != NULL);
    assert(second_string != NULL);

    const char* first_char_ptr = first_string + first_length - 1;
    const char* second_char_ptr = second_string + second_length - 1;

    for (; first_char_ptr >= first_string && second_char_ptr >= second_string;
         first_char_ptr--, second_char_ptr--)
    {
        SkipNonLettersBack(&first_char_ptr, first_length);
        SkipNonLettersBack(&second_char_ptr, second_length);

        if (first_char_ptr == first_string || second_char_ptr == second_string)
        {
            break;
        }

        if (CompareChar(*first_char_ptr, *second_char_ptr) != 0)
        {
            return (CompareChar(*first_char_ptr, *second_char_ptr));
        }
    }

    if (first_char_ptr == first_string)
    {
        return 1;
    }

    return -1;
}

int CompareChar(char first_char, char second_char)
{
    return (toupper(second_char) - toupper(first_char));
}

void SkipNonLetters(const char** ptr_to_char_ptr, int string_length)
{
    assert (ptr_to_char_ptr != NULL);
    assert (*ptr_to_char_ptr != NULL);

    int i = 0;
    while (i < string_length && !isalpha (**ptr_to_char_ptr))
    {
        (*ptr_to_char_ptr)++;
        i++;
    }
}

void SkipNonLettersBack(const char** ptr_to_char_ptr, int string_length)
{
    assert(ptr_to_char_ptr != NULL);
    assert(*ptr_to_char_ptr != NULL);

    int i = string_length - 1;
    while (i >= 0 && !isalpha(**ptr_to_char_ptr))
    {
        (*ptr_to_char_ptr)--;
        i--;
    }
}
