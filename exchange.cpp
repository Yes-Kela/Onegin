#include <assert.h>
#include <stdlib.h>
#include "exchange.h"

void ExchangePointers (struct line_t* first_struct_pointer, struct line_t* second_struct_pointer)
{
    assert ( first_struct_pointer != NULL);
    assert (second_struct_pointer != NULL);

    struct line_t auxiliary = *first_struct_pointer;
    *first_struct_pointer = *second_struct_pointer;
    *second_struct_pointer = auxiliary;
}
