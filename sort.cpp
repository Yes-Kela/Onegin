#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void SortPointers (struct line_t * struct_pointer, int num_of_lines,
                   int (*Compare) (const char* first_string, const char* second_string, int first_length, int second_length))
{
    assert (struct_pointer != NULL);
    assert ((*struct_pointer).pointer != NULL);

    for (int active_part = num_of_lines - 1; active_part > 0; active_part--)
    {
        for (int index = 0; index < active_part; index++)
        {
            const char*  first_string = (*(struct_pointer + index)).pointer;
            const char* second_string = (*(struct_pointer + index + 1)).pointer;
            int first_length = (*(struct_pointer + index)).lenght;
            int second_length = (*(struct_pointer + index + 1)).lenght;

            if (Compare(first_string, second_string, first_length, second_length) < 0)
            {
                ExchangePointers (struct_pointer + index, struct_pointer + index + 1);
            }
        }
    }

}
