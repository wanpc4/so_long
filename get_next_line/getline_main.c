#include "get_next_line.h"

int main()
{
    int fd;
    char *str;

    fd = open("tests/example.txt", O_RDONLY);

    for (int i = 0; i < 4; i++)
    {
        str = get_next_line(fd);
        printf("%d : %s", i, str);
        free(str);
    }
    close(fd);
    return 0;
}