#ifndef STRUCTURE_H
#define STRUCTURE_H

struct line_t
{
    const char* pointer;
    int length;
};

void Structure(struct line_t* lines, const char* buffer, const size_t length);

#endif /*STRUCTURE_H*/
