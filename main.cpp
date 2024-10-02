#include <stdio.h>
#include <assert.h>
#include "main.h"

int main(void)
{
    struct inform lines[height] = {};

    const char table[] =
    "\"My uncle's goodness is extreme,\n"
    "If seriously he hath disease;\n"
    "He hath acquired the world's esteem\n"
    "And nothing more important sees;\n"
    "A paragon of virtue he!\n"
    "But what a nuisance it will be,\n"
    "Chained to his bedside night and day\n";

    lines[0].pointer = table;
    int num_of_ends = 1;
    int counter = 1;

    for (unsigned int i = 1; *(table + i) != '\0'; i++)
    {
        counter++;
        if (*(table + i) == '\n')
        {
            if (*(table + i + 1) != '\0') {
                lines[num_of_ends].pointer = table + (i + 1);
                assert (num_of_ends < height);
            }

            lines[num_of_ends - 1].lenght = counter;
            counter = 0;

            assert (lines[num_of_ends].pointer != NULL);


            num_of_ends ++;
        }
    }

    SortPointers (&lines[0]);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < lines[i].lenght; j++)
        {
            printf("%c", *((lines[i].pointer) + j));
        }
    }

    printf("\n");

    return 0;
}
