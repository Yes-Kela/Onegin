#ifndef COMPARE_H
#define COMPARE_H

struct line_t
{
    const char* pointer;
    int lenght;
};

int ComparePointers (const char* first_string, const char* second_string, int first_length, int second_length);
int ComparePointersBack (const char* first_string, const char* second_string, int first_length, int second_length);
int CompareChar (char first_char, char second_char);
void SkipNonLetters (const char** char_ptr);

#endif // COMPARE_H
