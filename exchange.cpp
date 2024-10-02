#include <assert.h>
#include <stdlib.h>
#include "exchange.h"

void ExchangePointers (struct inform* first_struct_pointer, struct inform* second_struct_pointer)
{
    assert ( first_struct_pointer != NULL);
    assert (second_struct_pointer != NULL);

    struct inform auxiliary = *first_struct_pointer;
    *first_struct_pointer = *second_struct_pointer;
    *second_struct_pointer = auxiliary;
}
