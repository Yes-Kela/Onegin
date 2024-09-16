#include <stdio.h>
//#include <string.h>
int compare_strings (char first_string[], char second_string[]);

int char_cmp (char first, char second);

const int MAXLENGHT = 20;
const int STR_NUM = 3;

int main(void)
{
    char text[STR_NUM][MAXLENGHT] =
    {
    {"My uncle's"},
    {"If seriously"},
    {"He hath acquired"}
    };

    printf("%c\n", text[0][0]);

    printf("%d\n", compare_strings(text[0], text[1]));
    /*
    for (int i = 0; i < STR_NUM; i++)
    {
        if (compare_strings(text[i], text[i+1]) >)
    }
    */
    return 0;
}



int compare_strings (char str1[], char str2[])              // передаем указатели на 2 массива
{
    //char str1[20] = {'M', 'y', ' ', 'u', 'n', 'c', 'l', 'e', '’', 's'};
    //char str2[20] = {'I', 'f', ' ', 's', 'e', 'r', 'i', 'o', 'u', 's', 'l', 'y'};
    //char str1[MAXLENGHT] = * first_string;
    //char str2[MAXLENGHT] = * second_string;
    int first_bigger = 1;
    for (int i = 0; i < MAXLENGHT; i++)      // по умолчанию считаем, что первая больше
    {
        if (char_cmp(str1[i], str2[i]) == 2)
            first_bigger = 2;
    }
    return first_bigger;
}


int char_cmp (char first, char second)
{
    if (first >= second)
        return 1;
    else
        return 2;
}
