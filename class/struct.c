#include<stdio.h>
#include<string.h>
#define len_name 10
typedef struct
{
    char name[len_name + 1];
    long long number;
    int on_hand;
} item1;
// 结构体的内存按照最小单位大小的倍数来分配
int main(void)
{
    item1 person1 = {.name = "lyh", .number = 241880324, .on_hand = 2};
    printf("%s\n", person1.name);
    printf("sizeof(item1) = %d\n", sizeof(item1));
    printf("&name = %p, &number = %p, &on_hand = %p", person1.name, &person1.number, &person1.on_hand);
}