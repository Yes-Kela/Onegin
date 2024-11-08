#ifndef SORT_H
#define SORT_H

struct line_t
{
    const char* pointer;
    int lenght;
};

void SortPointers(struct line_t * struct_pointer, int num_of_lines,
                   int (*Compare)(const char* first_string, const char* second_string, int first_length, int second_length));
void ExchangePointers(struct line_t* first_struct_pointer, struct line_t* second_struct_pointer);
int ComparePointers(const char* first_string, const char* second_string, int first_length, int second_length);
int ComparePointersBack(const char* first_string, const char* second_string, int first_length, int second_length);

#endif // SORT_H
