int max1(int a, int b, int c)//三个数字排序，输出组成的最大数字
{
    int max;
    if(a == b)
    {
        if(a >=c )
        {
            max = a * 100 + b * 10 + c;
        }
        else
        {
            max = c * 100 + b * 10 + a;
        }
    }
    else if(a < b)
    {
        if(b < c)
        {
            max = c * 100 + b * 10 + a;
        }
        else if(c < a)
        {
            max = b * 100 + a * 10 + c;
        }
        else
        {
            max = b * 100 + c * 10 + a;
        }
    }
    else if(a > b)
    {
        if(a < c)
        {
            max = c * 100 + a * 10 + b;
        }
        else if(c < b)
        {
            max = a * 100 + b * 10 + c;
        }
        else
        {
            max = a * 100 + c * 10 + b;
        }
    }
    return max;
}

int min1(int a, int b, int c)//三个数字排序，输出组成的最小数字
{
    int min;
    if(a == b)
    {
        if(a >=c )
        {
            min = c * 100 + b * 10 + a;
        }
        else
        {
            min = a * 100 + b * 10 + c;
        }
    }
    else if(a < b)
    {
        if(b < c)
        {
            min = a * 100 + b * 10 + c;
        }
        else if(c < a)
        {
            min = c * 100 + a * 10 + b;
        }
        else
        {
            min = a * 100 + c * 10 + b;
        }
    }
    else if(b < a)
    {
        if(a < c)
        {
            min =b * 100 + a * 10 + c;
        }
        else if(c < b)
        {
            min = c * 100 + b * 10 + a;
        }
        else
        {
            min = b * 100 + c * 10 + a;
        }
    }
    return min;
}

void quicksort(int arr[], int low, int high)
{
    int middle;
    if(low >= high)
    {
        return;
    }
    middle = split(arr, low, high);
    quicksort(arr, low, middle - 1);
    quicksort(arr, middle+1, high);
}

int split(int arr[], int low, int high)
{
    int part_element = arr[low];

    for(;;)
    {
        while(low < high && part_element <= arr[high])
        {
            high--;
        }
        if(low >= high)
        {
            break;
        }
        arr[low++] = arr[high];

        while(low < high && arr[low] <= part_element)
        {
            low++;
        }
        if(low >= high)
        {
            break;
        }
        arr[high--] = arr[low];
    }

    arr[high] = part_element;
    return high;
}