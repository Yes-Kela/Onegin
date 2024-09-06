#include <stdio.h>
//#include <string.h>
int compare_strings (char first_string[], char second_string[]);
const int MAXLENGHT = 20;

int main(void)
{
    char text[3][20] =
    {
    {'M', 'y', ' ', 'u', 'n', 'c', 'l', 'e', 'Т', 's'},
    {'I', 'f', ' ', 's', 'e', 'r', 'i', 'o', 'u', 's', 'l', 'y'},
    {'H', 'e', ' ', 'h', 'a', 't', 'h', ' ', 'a', 'c', 'q', 'u', 'i', 'r', 'e', 'd'}
    };

    printf("%c\n", text[0][0]);

    printf("%d\n", compare_strings(text[0], text[1]));

    return 0;
}



int compare_strings (char str1[], char str2[])              // передаем указатели на 2 массива
{
    //char str1[20] = {'M', 'y', ' ', 'u', 'n', 'c', 'l', 'e', 'Т', 's'};
    //char str2[20] = {'I', 'f', ' ', 's', 'e', 'r', 'i', 'o', 'u', 's', 'l', 'y'};
    //char str1[MAXLENGHT] = * first_string;
    //char str2[MAXLENGHT] = * second_string;
    for (int i = 0; i < MAXLENGHT; i++)
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
    }
    return 0;
}
