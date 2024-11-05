#include<stdio.h>
#define LEN 10
int arr[LEN] = {1, 5, 18, 25, 53, 58, 70, 80, 87, 99};

int main (void)
{
    int index = -1;
    int target = 0;
    scanf("%d", &target);

    int low = 0;
    int high = LEN - 1;
    while(low < high)
    {
        int mid = (low + high) / 2;
        if(target > arr[mid])
        {
            low = mid + 1;
        }
        else if(target < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            index = mid;
            break;
        }
    }
    printf("%d\n", index );

}