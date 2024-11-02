#ifndef MAIN_H
#define MAIN_H

struct inform
{
    const char* pointer;
    int length;
};

char* ReadText(char* buffer, size_t* length, size_t* height);
void SortPointers (struct inform* struct_pointer, int height);
void WriteText(const struct inform* lines, const size_t height);

#endif // MAIN_H
