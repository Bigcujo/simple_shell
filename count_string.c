#include "string.h"

/**
* count_string: this will count the number of char in a string
* str: this will be string to be inputed 
*/

size_t count_string(const char *str)
{
    size_t count = 0;
    
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}