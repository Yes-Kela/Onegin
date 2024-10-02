#include <assert.h>
#include <stdlib.h>
#include "sort.h"

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
