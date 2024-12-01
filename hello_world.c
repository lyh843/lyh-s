#include <stdio.h>

int reverse(int n) {
int ans = 0;
while (n) 
{  // 翻转数字
    ans = ans * 10 + n % 10;
    n /= 10;
}
return ans;
}
int check(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)  // 如果有因式，直接返回 “非素数”
      return 0;
  return 1;
}
int main(void) {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    if (check(i) && check(reverse(i)))
      ans++;
  }
  printf("%d", ans);
  return 0;
}