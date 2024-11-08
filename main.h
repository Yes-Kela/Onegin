#ifndef MAIN_H
#define MAIN_H

struct line_t
{
    const char* pointer;
    int length;
};

char* ReadText(size_t* length, size_t* num_of_lines);
void Structure(struct line_t* lines, const char* buffer, const size_t length);
void SortPointers (struct line_t* struct_pointer, int num_of_lines,
                   int (*Compare)(const char* first_string, const char* second_string, int first_length, int second_length));
int ComparePointers (const char* first_string, const char* second_string, int first_length, int second_length);
int ComparePointersBack (const char* first_string, const char* second_string, int first_length, int second_length);
void WriteText(const struct line_t* lines, const size_t num_of_lines);

#endif // MAIN_H
