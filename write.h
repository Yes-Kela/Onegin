#ifndef WRITE_H
#define WRITE_H

struct line_t
{
    const char* pointer;
    int length;
};

void WriteText(const struct line_t* lines, const size_t num_of_lines);

#endif /*WRITE_H*/
