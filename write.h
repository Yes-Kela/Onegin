#ifndef WRITE_H
#define WRITE_H

struct inform
{
    const char* pointer;
    int length;
};

void WriteText(const struct inform* lines, const size_t height);

#endif /*WRITE_H*/
