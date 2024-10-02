#ifndef EXCHANGE_H
#define EXCHANGE_H

const int height = 7;

struct inform
{
    const char* pointer;
    int lenght;
};

void ExchangePointers (struct inform* first_struct_pointer, struct inform* second_struct_pointer);

#endif // EXCHANGE_H
