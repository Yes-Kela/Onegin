#include <stdio.h>
const int heigth = 3;
const int width = 4;

int compare_int (int* first, int* second);

int main(void)
{
    int table[heigth][width] =
    {
    {11, 12, 13, 14},
    {21, 22, 23, 24},
    {31, 32, 33, 34},
    };
    int a = 0, b = 2;

    int what_is_bigger = compare_int(((int*)table + a*width), ((int*)table + b*width));
    if (what_is_bigger == 1)
        printf("first is bigger, compare_int = %d\n", what_is_bigger);
    else
        printf("second is bigger, compare_int = %d\n", what_is_bigger);

    return 0;
}

int compare_int (int* first, int* second)
{
    int bigger = 1;
    for (int i = 0; i < width; i++)
    {
        if (*(first + i) < *(second + i))
            bigger = 2;
    }
    return bigger;
}
