#ifndef STRUCTURE_H
#define STRUCTURE_H

struct line_t
{
    const char* pointer;
    int length;
};

void Structure(struct line_t* lines, char* buffer, const size_t length, const size_t num_of_lines);

#endif /*STRUCTURE_H*/
