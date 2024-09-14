#include <stdio.h>
const int height = 3;
const int width = 5;

int compare_strings (char* first_string, char* second_string);
int compare_char (char first_char, char second_char);

int main(void)
{
    char table[] =
    {'H', 'e', 'l', 'l', '\0', 'H', 'e', 'l', 'k', '\0', 'H', 'e', 'l', 'a', '\0'};

    // принтфы!!!
    /*
    int b = 6;
    printf("(char*) ((unsigned int)table + (b+i)*sizeof(char))"
           "         *( (char*) ((unsigned int)table + (b+i)*sizeof(char)) )\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%30p", (char*) ((unsigned int)table + (b+i)*sizeof(char)) );
        printf("%60c\n", *( (char*) ((unsigned int)table + (b+i)*sizeof(char)) ) );
    }
    printf("\n\n");
    printf("table + i" "      *(table + i)\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%p", table + i);
        printf("%13s\n", *(table + i));
    }
    */


    /*
    int what_is_bigger = compare_strings();
    printf(" first string: %d\n"
           "second string: %d\n\n",
           );

    if (what_is_bigger == 1)
        printf("first is bigger, compare_int = %d\n", what_is_bigger);
    else
        printf("second is bigger, compare_int = %d\n", what_is_bigger);
    */

    //printf("compare_strings = %d", compare_strings())

    int a = 0, b = 1;
    int what_is_bigger = compare_strings (table + a, table + b*width);
    printf("first string: ");
    for (int i = 0; i < width; i++)
    {
        printf("%c", *(table + a + i));
    }
    printf("\n");

    printf("first string: ");
    for (int i = 0; i < width; i++)
    {
        printf("%c", *(table + b*width + i));
    }
    printf("\n");

    printf("%d string is bigger", what_is_bigger);

    return 0;
}


// создаём функцию, сравнивающую две строки: compare_strings
// внутри себя она вызывает функцию сравнения ascii-кодов двух символов и пользуется её возвращающим значением

int compare_strings (char* first_string, char* second_string)            // передаем указатели на начала строк, т е на char-values
{
    int bigger = 0;

    for (int i = 0; i < width; i++)
    {
        /*
        printf("*(first_string + i) = %c\n", *(first_string + i));
        printf("*(second_string + i) = %c\n\n", *(second_string + i));
        */
        if (compare_char (*(first_string + i), *(second_string + i)) != bigger)
        {
            bigger = compare_char (*(first_string + i), *(second_string + i));
            break;
        }
    }

    return bigger;
}


int compare_char (char first_char, char second_char)
{
    if (first_char > second_char)
        return 1;
    else if (first_char < second_char)
        return 2;
    else
        return 0;
}
