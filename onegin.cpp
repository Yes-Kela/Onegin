#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

#define PRINTFS

const int height = 7;
//const int MAXWIDTH = 38;

struct inform
{
    const char* pointer;
    int lenght;
};

int compare_strings (char* first_string, char* second_string);
int compare_char (char first_char, char second_char);
void exchange_strings (char* start_first_string, char* start_second_string);
void exchange_char (char* first_char, char* second_char);
void bubble_sort (char* start);

void pointers_sort (struct inform* struct_pointer);
void exchange_pointers (struct inform* first_struct_pointer, struct inform* second_struct_pointer);
int compare_pointers (const char* first_string, const char* second_string, int first_length, int second_length);
void skip_non_letters (const char** char_ptr);


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

    /*
    printf("i    lines[i].pointer     *lines[i].pointer        lines[i].lenght\n");
    for (int i = 0; i < height; i++)
    {
        printf("%d       %p               %c                     %d\n", i, lines[i].pointer , *lines[i].pointer, lines[i].lenght);
    }
    printf("\n");
    printf("***********************************************************************");
    printf("\n");
    */

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
    /*
    bubble_sort (table);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", *(table + i*width + j));
        }
        printf("\n");
    }
    */


    pointers_sort (&lines[0]);
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


/*
int compare_strings (char* first_string, char* second_string)
{
    assert ( first_string != NULL);
    assert (second_string != NULL);

    int bigger = 0;
    char*  first_string_cur = (char*) calloc (MAXWIDTH, sizeof(char));
    for (int j = 0, num_alpha = 0; j < MAXWIDTH; j++)
    {
        if ( isalpha (*(first_string + j)) )
        {
            num_alpha++;
            *(first_string_cur + num_alpha) = *(first_string + j);
        }
    }

    char* second_string_cur = (char*) calloc (MAXWIDTH, sizeof(char));
    for (int j = 0, num_alpha = 0; j < MAXWIDTH; j++)
    {
        if ( isalpha (*(second_string + j)) )
        {
            num_alpha++;
            *(second_string_cur + num_alpha) = *(second_string + j);
        }
    }

    for (int i = 0; i < MAXWIDTH; i++)
    {

        // printf("*(first_string + i) = %c\n", *(first_string + i));
        // printf("*(second_string + i) = %c\n\n", *(second_string + i));

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

void exchange_strings (char* start_first_string, char* start_second_string)
{
    assert ( start_first_string != NULL);
    assert (start_second_string != NULL);

    for (int i = 0; i < MAXWIDTH; i++)
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
            char* first_string = start + index * MAXWIDTH;
            char* second_string = start + (index + 1) * MAXWIDTH;
            if (compare_strings (first_string, second_string) == 1)
            {
                exchange_strings (first_string, second_string);
            }
            else { ; }
        }
    }
}
*/



void pointers_sort (struct inform * struct_pointer)
{
    assert (struct_pointer != NULL);
    assert ((*struct_pointer).pointer != NULL);

    for (int active_part = height - 1; active_part > 0; active_part--)
    {
        for (int index = 0; index < active_part; index++)
        {
            const char*  first_string = (*(struct_pointer + index)).pointer;
            const char* second_string = (*(struct_pointer + index + 1)).pointer;
            int first_length = (*(struct_pointer + index)).lenght;
            int second_length = (*(struct_pointer + index + 1)).lenght;

            if (compare_pointers (first_string, second_string, first_length, second_length) < 0)  // если первая больше, то:
            {
                exchange_pointers (struct_pointer + index, struct_pointer + index + 1);
            }

            else { ; }
        }
    }

}

void exchange_pointers (struct inform* first_struct_pointer, struct inform* second_struct_pointer)
{
    assert ( first_struct_pointer != NULL);
    assert (second_struct_pointer != NULL);

    struct inform auxiliary = *first_struct_pointer;
    *first_struct_pointer = *second_struct_pointer;
    *second_struct_pointer = auxiliary;
}

int compare_pointers (const char* first_string, const char* second_string, int first_length, int second_length)
{
    assert ( first_string != NULL);
    assert (second_string != NULL);

    const char* first_char_ptr = first_string;
    const char* second_char_ptr = second_string;

    //printf("first_char_ptr    first_char   second_char_ptr    second_char\n");
    //printf(" %p       %c        %p      %c\n", first_char_ptr, *first_char_ptr, second_char_ptr, *second_char_ptr);


    //printf(" %p       %c        %p      %c\n", first_char_ptr, *first_char_ptr, second_char_ptr, *second_char_ptr);

    for (; first_char_ptr != first_string + first_length &&
         second_char_ptr != second_string + second_length;
         first_char_ptr++, second_char_ptr++)
    {
        skip_non_letters (&first_char_ptr);
        skip_non_letters (&second_char_ptr);

        if (first_char_ptr == first_string + first_length || second_char_ptr == second_string + second_length)
            break;

        if (compare_char (*first_char_ptr, *second_char_ptr) != 0)
        {
            //printf("returned_value: %d\n", compare_char (*first_char_ptr, *second_char_ptr));

            return (compare_char (*first_char_ptr, *second_char_ptr));     // возвращает >0, если вторая больше; <0 - иначе
        }
    }

    if (first_char_ptr == first_string + first_length)
    {
        //printf("returned_value: 1\n");

        return 1;
    }

    //printf("returned_value: -1\n");

    return -1;
}

int compare_char (char first_char, char second_char)
{
    return (toupper(second_char) - toupper(first_char));           // если первая больше, то <0, если вторая больше, то >0
}


void skip_non_letters (const char** ptr_to_char_ptr)
{
    assert (ptr_to_char_ptr != NULL);
    assert (*ptr_to_char_ptr != NULL);

    while (**ptr_to_char_ptr != '\n' && !isalpha (**ptr_to_char_ptr))
    {
        (*ptr_to_char_ptr)++;
    }
}
