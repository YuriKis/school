#include <stdio.h>
#include <string>
using namespace std;
int quick_pow10(int n) {
    static int pow10[10] = {
        1, 10, 100, 1000, 10000,
        100000, 1000000, 10000000, 100000000, 1000000000
    };
    return pow10[n];
} // о, да!!!-s
int summ_num(int num){
  //if(num)
  int sum = 0, a;
  while(num != 0) {
      a = num % 10;
      num = (num - a) / 10;
      sum = sum + a;
  }
  return sum;
}
int Perevert(int x) {
   int y = 0;
   while(x) {
       y = y*10 + x%10;
       x /= 10;
   }
   return y;
}

void print_palindrom(int n){
  int sum = 1, s = 0;
  int k = (n%2==0)?(n/2):(n/2+1);  //TODO: (n%2==0)?(n/2):(n/2+1) - это криво и не красиво(((
  for(int i = quick_pow10(k-1); i < quick_pow10(k); i++) {// сделать шаг 3
    sum = summ_num(i);
    s = ((n%2==0)?(sum*2):(sum*2-i%10));
    if(s%9 == 0) printf("%d%d ", (i%10 == 0)?i*10:i,(n%2==0)?Perevert(i):Perevert(i/10)); //TODO: проблема с затиранием нолика
  }
}
int main () {
  int n;
  scanf("%d", &n);
  print_palindrom(n);

  return 0;
}
