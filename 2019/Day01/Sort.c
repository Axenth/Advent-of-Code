#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define BUFFER_SIZE 100000000

struct s_sort {
    int *arr;
    int arr_amount;
};

char	**ft_split(char const *s, char c);


struct s_sort to_intarr(char **strs)
{
    int i;
    int *arr;
    struct s_sort sort;

    i = 0;
    sort.arr = malloc(sizeof(int) * 205);
    while (strs[i] != NULL)
    {
        sort.arr[i] = atoi(strs[i]);
        i++;
    }
    sort.arr_amount = i - 1;

    return (sort);
}

struct s_sort sort_arr(struct s_sort sort, int j, int start) // 2.233s
{
    int i = start + 5;
    int sign = 0;
    int temp;
    int value;
    int next_value;

    printf("Round: %i\n", j);
    while(i < sort.arr_amount)
    {
        value = sort.arr[i];
        // usleep(100000);
        if (sort.arr[start] > value)
        {
            printf("value %i is less then %i\n", value, sort.arr[start]);
            temp = value;
            sort.arr[i] = sort.arr[start];
            sort.arr[start] = temp;
            value = sort.arr[i];
            sign = 1;
        }

        if (sort.arr[start + 1] > value)
        {
            printf("value %i is less then %i\n", value, sort.arr[start + 1]);
            temp = value;
            sort.arr[i] = sort.arr[start + 1];
            sort.arr[start + 1] = temp;
            value = sort.arr[i];
            sign = 1;
        }

        if (sort.arr[start + 2] > value)
        {
            printf("value %i is less then %i\n", value, sort.arr[start + 2]);
            temp = value;
            sort.arr[i] = sort.arr[start + 2];
            sort.arr[start + 2] = temp;
            value = sort.arr[i];
            sign = 1;
        }

        if (sort.arr[start + 3] > value)
        {
            printf("value %i is less then %i\n", value, sort.arr[start + 3]);
            temp = value;
            sort.arr[i] = sort.arr[start + 3];
            sort.arr[start + 3] = temp;
            value = sort.arr[i];
            sign = 1;
        }

        if (sort.arr[start + 4] > value)
        {
            printf("value %i is less then %i\n", value, sort.arr[start + 4]);
            temp = value;
            sort.arr[i] = sort.arr[start + 4];
            sort.arr[start + 4] = temp;
            value = sort.arr[i];
            sign = 1;
        }

        printf("%i: %i\n", i, sort.arr[i]);
        i++;
    }
    if (sign)
        sort_arr(sort, j + 1, start + 5);
    return (sort);
}

struct s_sort insertion_sort(struct s_sort sort) // 0.265s
{
    int i = 0;
    int temp;
    int j;

    while (i < sort.arr_amount)
    {
        temp = sort.arr[i];
        j = i;
        while (j > 0 && sort.arr[j - 1] > temp)
        {
            sort.arr[j] = sort.arr[j - 1];
            j--;
        }
        sort.arr[j] = temp;
        i++;
    }

    return (sort);
}


struct s_sort select_sort(struct s_sort sort, int j, int start) // 0.291s
{
    int i = start;
    int temp = start;
    int temp_value = sort.arr[start];
    printf("#%i/%i\n", start, sort.arr_amount);
    while(i < sort.arr_amount)
    {

        if(sort.arr[i] < temp_value)
        {
            temp = i;
            temp_value = sort.arr[i];
        }
        i++;
    }
    sort.arr[temp] = sort.arr[start];
    sort.arr[start] = temp_value;
    if(start != sort.arr_amount)
        sort = select_sort(sort, j + 1, start + 1);
    return (sort);
}

int main(void)
{
    char *buf;
    int fd;
    int ret;
    char **arr;
    int  *value_arr;
    struct s_sort sort;

    fd = 0;
    ret = 0;

    fd = open("values.txt", O_RDONLY);

    buf = malloc(BUFFER_SIZE*sizeof(char *));
    ret = read(fd, buf, BUFFER_SIZE);
    arr = ft_split(buf, '\n');
    sort = to_intarr(arr);

    //sort = sort_arr(sort, 0, 0);
    //sort = select_sort(sort, 0 ,0);
    sort = insertion_sort(sort);
    for(int i = 0; i < sort.arr_amount; i++)
        printf("%i: %i\n", i, sort.arr[i]);
}