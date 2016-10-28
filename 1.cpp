#include "iostream"

int binpow (int a, int n) {
	if (n < 0) throw -1;// Жуть)
	if (n == 0) return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		int b = binpow (a, n/2);
		return b * b;
	}
}
double binpowP(int a, int n) {//
	  if(n<0) return 1/double(binpow(a, -n));
    else    return double(binpow(a,n));}
void resch(int SZ){
    int i, j;
   //int SZ = 100;            // предел поиска простых чисел
   for (i = 2; i < SZ; i++) //перебираем числа
   {
      bool y = 1;           // пусть будет простое
      if (i%2 == 0) y = 0;  //делится нацело на 2, значит не простое
      for (j = 3; (j*j <= i) && y; j+=2)
            if (i%j == 0) {y = 0; break;} // делится нацело на какое
                           //нибудь число до корня значит не простое
      if(y) std::cout << i << std::endl;
   }
}
int NOD(int a, int b){
    while(a > 0 && b > 0)
        if(a > b)
            a %= b;
        else
            b %= a;
    return a + b;
}
int NOK(int a, int b) {
	return a*b/NOD(a,b);
}
int phi (int n) {
	if(n <= 0 ) return -1; // 0 - это против правил)
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}
int main(){
    std::cout<<"lol)";
    return 0;
}
