#include "iostream"

int binpow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		int b = binpow (a, n/2);
		return b * b;
	}
}
void rot(int n){
  int n;
vector<char> prime (n+1, true);
prime[0] = prime[1] = false;
for (int i=2; i<=n; ++i)
	if (prime[i])
		if (i * 1ll * i <= n)
			for (int j=i*i; j<=n; j+=i)
				prime[j] = false;

}
int phi (int n) {
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

int main(int argc, char const *argv[]) {
  int n = 0;
  std::cin >> n;
  std::cout << "phi( " << n << " )  = " << phi(n) << std::endl;

  return 0;
}
