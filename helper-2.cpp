#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

#define PRINTFS

const int height = 7;
const int width = 17;

int compare_strings (char* first_string, char* second_string);
int compare_char (char first_char, char second_char);
void exchange_strings (char* first_string, char* second_string);
void exchange_char (char* start_first_string, char* start_second_string);
void bubble_sort (char* start);

int main(void)
{
    char table[] =
    {
    'M', 'y', ' ', 'u', 'n', 'c', 'l', 'e',  39, 's', '0', '0', '0', '0', '0', '0', '\0',
    'I', 'f', ' ', 's', 'e', 'r', 'i', 'o', 'u', 's', 'l', 'y', '0', '0', '0', '0', '\0',
    'H', 'e', ' ', 'h', 'a', 't', 'h', ' ', 'a', 'c', 'q', 'u', 'i', 'r', 'e', 'd', '\0',
    'A', 'n', 'd', ' ', 'n', 'o', 't', 'h', 'i', 'n', 'g', '0', '0', '0', '0', '0', '\0',
    'A', ' ', 'p', 'a', 'r', 'a', 'g', 'o', 'n', ' ', 'o', 'f', '0', '0', '0', '0', '\0',
    'A', 'p', 'a', 'r', 'a', 'g', ' ', 'o', 'n', ' ', 'o', 'f', 'f', '0', '0', '0', '\0',
    'A', 'P', 'A', 'r', 'a', 'g', ' ', 'o', 'N', ' ', 'o', 'F', '0', '0', '0', '0', '\0'
    };

    // ןנטםעפû!!!
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



int compare_strings (char* first_string, char* second_string)
{
    assert ( first_string != NULL);
    assert (second_string != NULL);

    int bigger = 0;
    char*  first_string_cur = (char*) calloc (width, sizeof(char));
    for (int j = 0, num_alpha = 0; j < width; j++)
    {
        if ( isalpha (*(first_string + j)) )
        {
            num_alpha++;
            *(first_string_cur + num_alpha) = *(first_string + j);
        }
    }

    char* second_string_cur = (char*) calloc (width, sizeof(char));
    for (int j = 0, num_alpha = 0; j < width; j++)
    {
        if ( isalpha (*(second_string + j)) )
        {
            num_alpha++;
            *(second_string_cur + num_alpha) = *(second_string + j);
        }
    }

    for (int i = 0; i < width; i++)
    {
        /*
        printf("*(first_string + i) = %c\n", *(first_string + i));
        printf("*(second_string + i) = %c\n\n", *(second_string + i));
        */
        if (compare_char (*(first_string_cur + i), *(second_string_cur + i)) != bigger)
        {
            bigger = compare_char (*(first_string_cur + i), *(second_string_cur + i));
            break;
        }
    }

    free ( first_string_cur);
    free (second_string_cur);

    return bigger;
}


int compare_char (char first_char, char second_char)
{
    if (toupper(first_char) > toupper(second_char))
        return 1;
    else if (toupper(first_char) < toupper(second_char))
        return 2;
    else
        return 0;
}


void exchange_strings (char* start_first_string, char* start_second_string)
{
    assert ( start_first_string != NULL);
    assert (start_second_string != NULL);

    for (int i = 0; i < width; i++)
    {
        exchange_char (start_first_string + i, start_second_string + i);
    }
}

void exchange_char (char* first_char, char* second_char)
{
    assert ( first_char != NULL);
    assert (second_char != NULL);

    char   auxiliary = *first_char;
        * first_char = *second_char;
        *second_char =  auxiliary;
}


void bubble_sort (char* start)
{
    assert (start != NULL);

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
