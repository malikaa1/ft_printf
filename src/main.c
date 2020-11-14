/// printf("%d est %c fkfjgf %d");
#include <stdio.h>
int find_index(char *str, char c, int start)
{
    while (str[start++])
    {
        if (str[start] == c)
            return start;
    }
    return 0;
}

void parse_args(char *str, int *buff, int count)
{
    int index;
    int i;
    index = -1;
    i = 0;
    while (count > 0 && i < count)
    {
        index = find_index(str, '%', index);
        buff[i] = index;
        i++;
    }
}



int main()
{
    int count = 4;
    int buff[4];

    char *str = "%sa %d l %c %s";
    parse_args(str, buff, count);
    while (count > 0)
    {
        printf("tab de %d \n", buff[count - 1]);
        count--;
    }
    return 0;
}