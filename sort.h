#ifndef SORT_H
#define SORT_H

struct inform
{
    const char* pointer;
    int lenght;
};

void SortPointers (struct inform * struct_pointer, int height);
void ExchangePointers (struct inform* first_struct_pointer, struct inform* second_struct_pointer);
int ComparePointers (const char* first_string, const char* second_string, int first_length, int second_length);

#endif // SORT_H
