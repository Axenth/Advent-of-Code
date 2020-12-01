#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define BUFFER_SIZE 100000000

char			**ft_split(char const *s, char c);

int *to_intarr(char **strs)
{
    int i;
    int *arr;

    i = 0;
    arr = malloc(sizeof(int) * 150);
    while (strs[i] != NULL)
    {
        arr[i] = atoi(strs[i]);
        i++;
    }

    return (arr);
}


int  *do_math(int *value_arr)
{
    int i = 0;

    int posx;
    int posy;
    int poss;
    while(i <= 149)
    {
        posx = value_arr[i + 1];
        posy = value_arr[i + 2];
        poss = value_arr[i + 3];
        if (value_arr[i] == 1)
        {
            value_arr[poss] = value_arr[posx] + value_arr[posy];
        }
        else if (value_arr[i] == 2)
        {
            value_arr[poss] = value_arr[posx] * value_arr[posy];
        }
        else if (value_arr[i] == 99)
        {
            break;
        }
        i += 4;
    }

    return (value_arr);
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
    int i = 1;
    int j = 1;
    int k = 0;
    int *result ;
    result = malloc(BUFFER_SIZE * sizeof(int));
         fd = open("values.txt", O_RDONLY);
         buf = malloc(BUFFER_SIZE*sizeof(char *));
         ret = read(fd, buf, BUFFER_SIZE);
         arr = ft_split(buf, ',');

         close(fd);
        free(buf);
         while(i <= 98)
         {
             j = 0;
             while (j <= 98 )
             {
             value_arr = to_intarr(arr);
               value_arr[1] = i;
               value_arr[2] = j; 
                result = do_math(value_arr);
                 j++;
                 k = 0;
                 if(result[0] == 19690720)
                 {
                     printf("%i,%i", result[1], result[2]);
                     k++;
                 }
                
             }
             i++;
         }

    free(result);
}