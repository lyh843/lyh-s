#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int main(void)
{
    int each_arr1[20] = {1, 0, 1, 2, 0, 0};
    char result[20] = {0};
    int length1 = 4;
    for(int j = 0; j < length1; j++)
    {
        if(each_arr1[j] == 1 || each_arr1[j] == 0)
        {
        }
        else if(each_arr1[j] == 2)
        {
            each_arr1[j] = -1;
            each_arr1[j + 1] += 1;
            if(j + 1 > length1 - 1)
            {
                length1++;
            }
        }
        else if(each_arr1[j] == 3)
        {
            each_arr1[j] = 0;
            length1++;
            each_arr1[j + 1] = 1;
            if(j + 1 > length1 - 1)
            {
                length1++;
            }
        }
    }
    printf("Well");
}