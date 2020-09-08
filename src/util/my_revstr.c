/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Write a function that reverses b string
*/

char *my_revstr(char *str)
{
    int first = 0;
    int count = 0;
    char change;

    while (str[count] != '\0') {
        count = count +1;
    }
    count = count - 1;
    while (first != count && first != (count + 1)) {
        change = str[count];
        str[count] = str[first];
        str[first] = change;
        count = count - 1;
        first = first + 1;
    }
    return (str);
}
