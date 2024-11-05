#include <stdio.h>

void decimalToBase3(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    
    char base3[20];  // 假设不会超过20位
    int index = 0;

    while (n > 0) {
        base3[index++] = (n % 3) + '0';  // 存储当前位
        n /= 3;  // 除以3，准备下一位
    }

    // 反转字符串输出
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", base3[i]);
    }
}

int main() {
    int decimal;
    printf("请输入一个十进制数: ");
    scanf("%d", &decimal);
    
    printf("十进制 %d 转换为三进制是: ", decimal);
    decimalToBase3(decimal);
    printf("\n");

    return 0;
}
