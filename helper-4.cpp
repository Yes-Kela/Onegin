#include <stdio.h>
#include <assert.h>

const int height = 2;

int main(void)
{
    char table[] =
    "Param\n"
    "QWERTY\n";

    char* pointers[height] = {table, table};

    printf("i  num_of_ends   table + (i - 1)   *(table + (i - 1))     *(pointers + num_of_ends)      **(pointers + num_of_ends)\n");

    int num_of_ends = 0;
    for (int i = 0; i < 13; i++)
    {
        if (*(table + i) == '\n')
        {
            pointers[num_of_ends] = (table + (i - 1));
            printf("%d       %d           %p          %c                       %p               %c\n",
                    i, num_of_ends, table + (i - 1), *(table + (i - 1)), *(pointers + num_of_ends), **(pointers + num_of_ends) );

            assert (*(pointers + num_of_ends) != NULL);
            assert (num_of_ends <= height);

            num_of_ends ++;
            if (num_of_ends > height)
            {
                printf("WARNING!!! NUM_OF_ENDS OUT OF HEIGHT!!!\n");
            }
        }
        else
        {
        }
    }


}
