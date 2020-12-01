#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define BUFFER_SIZE 100000000

char	**ft_split(char const *s, char c);


int *to_intarr(char **strs)
{
    int i;
    int *arr;

    i = 0;
    arr = malloc(sizeof(int) * 100);
    while (strs[i] != NULL)
    {
        arr[i] = atoi(strs[i]);
        i++;
    }

    return (arr);
}


int main(void)
{
    char *buf;
    int fd;
    int ret;
    char **arr;
    int  *value_arr;

    fd = 0;
    ret = 0;

    fd = open("values.txt", O_RDONLY);

    buf = malloc(BUFFER_SIZE*sizeof(char *));
    ret = read(fd, buf, BUFFER_SIZE);
    arr = ft_split(buf, '\n');
    value_arr = to_intarr(arr);

    int result;
    int i;
    int j;

    i = 0;
    j = 0;
    result = 0;

    int extra_fuel = 0;
    while(i <= 99)
    {
        result += floor(value_arr[i] / 3) - 2;
     	j++;
	extra_fuel = floor(value_arr[i] / 3) - 2;
     while (extra_fuel >= 0)
    {
        extra_fuel = floor(extra_fuel / 3) - 2;
        if (extra_fuel > 0)
        {
         //   printf("Extra Fuel [%i]\n", extra_fuel);
            result += extra_fuel;
            j++;
	}
    }
        i++;
    }
    printf("calculations: [%i]\n", j);
    printf("Result: [%i]\n", result);
    free (buf);
    free(arr);
    free(value_arr);
}
