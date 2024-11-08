#ifndef EXCHANGE_H
#define EXCHANGE_H

struct line_t
{
    const char* pointer;
    int lenght;
};

void ExchangePointers (struct line_t* first_struct_pointer, struct line_t* second_struct_pointer);

#endif // EXCHANGE_H
