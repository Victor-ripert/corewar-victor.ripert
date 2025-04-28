/*
** EPITECH PROJECT, 2025
** tiktaktoe
** File description:
** tiktaktoe
*/

#include <stdlib.h>
#include <stdbool.h>

static bool is_delim(char c, const char *delims)
{
    for (int i = 0; delims[i] != '\0'; ++i) {
        if (delims[i] == c || c == '\0') {
            return true;
        }
    }
    return false;
}

int count_words(const char *str, const char *delims)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_delim(str[i - 1], delims) && !is_delim(str[i], delims)) {
            ++count;
        }
    }
    return count;
}

int wordlen(const char *str, const char *delims, int index)
{
    int count = 0;

    for (int i = index; !is_delim(str[i], delims); ++i) {
        ++count;
    }
    return count;
}

char *process_word(const char *str, const char *delims, int index)
{
    char *word = malloc(sizeof(char) * (wordlen(str, delims, index) + 1));
    int j = 0;

    for (int i = index; !is_delim(str[i], delims); ++i) {
        word[j] = str[i];
        j++;
    }
    word[j] = '\0';
    return word;
}

char **my_str_to_word_array(const char *str, const char *delims)
{
    char **array = malloc(sizeof(char *) * (count_words(str, delims) + 1));
    int index = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_delim(str[i - 1], delims) && !is_delim(str[i], delims)) {
            array[index] = process_word(str, delims, i);
            ++index;
        }
    }
    array[index] = NULL;
    return array;
}
