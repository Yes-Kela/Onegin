#include <stdio.h>
#define PRINTFS
const int height = 3;
const int width = 5;

int compare_strings (char* first_string, char* second_string);
int compare_char (char first_char, char second_char);
void exchange_strings (char* first_string, char* second_string);
void exchange_char (char* start_first_string, char* start_second_string);
void bubble_sort (char* start);

int main(void)
{
    char table[] =
    {'H', 'e', 'l', 'l', '\0', 'H', 'e', 'l', 'k', '\0', 'H', 'e', 'l', 'a', '\0'};

    // принтфы!!!
    #ifndef PRINTFS
        int b = 0;
        printf("(char*) ((unsigned int)table + (b+i)*sizeof(char))"
               "         *( (char*) ((unsigned int)table + (b+i)*sizeof(char)) )\n");
        for (int i = 0; i < 5; i++)
        {
            printf("%30p", (char*) ((unsigned int)table + (b+i)*sizeof(char)) );
            printf("%60c\n", *( (char*) ((unsigned int)table + (b+i)*sizeof(char)) ) );
        }
        printf("\n\n");
        printf("table + i" "      *(table + i)\n");
        /*for (int i = 0; i < 3; i++)
        {
            printf("%p", table + i);
            printf("%13s\n", *(table + i));
        }       */
        printf("\n");
        printf("*************************************************************");
        printf("\n\n");


        int a = 0; b = 1;
        int what_is_bigger = compare_strings (table + a, table + b*width);
        printf("first string: ");
        for (int i = 0; i < width; i++)
        {
            printf("%c", *(table + a + i));
        }
        printf("\n");

        printf("second string: ");
        for (int i = 0; i < width; i++)
        {
            printf("%c", *(table + b*width + i));
        }
        printf("\n");

        printf("%d string is bigger", what_is_bigger);
    #endif

    bubble_sort (table);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", *(table + i*width + j));
        }
        printf("\n");
    }
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


void exchange_strings (char* start_first_string, char* start_second_string)
{
    for (int i = 0; i < width; i++)
    {
        exchange_char (start_first_string + i, start_second_string + i);
    }
}

void exchange_char (char* first_char, char* second_char)
{
    char   auxiliary = *first_char;
        * first_char = *second_char;
        *second_char =  auxiliary;
}


void bubble_sort (char* start)
{
    for (int active_part = height - 1; active_part > 0; active_part--)
    {
        for (int index = 0; index < active_part; index++)
        {
            char* first_string = start + index * width;
            char* second_string = start + (index + 1) * width;
            if (compare_strings (first_string, second_string) == 1)
            {
                exchange_strings (first_string, second_string);
            }
            else { ; }
        }
    }
}
