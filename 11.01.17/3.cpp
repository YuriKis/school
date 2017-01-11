#include <stdio.h>

int incredible_sort(int N, int k) {
  int a[N], arr[k] = {0};
  for(int i = 1; i <= N; i++) {
    scanf("%d", &a[i]); //TODO: искл.
    arr[a[i]-1]++;
  }
  for(int i = k-1; i >0; i--)
  for(int j = 0; j < arr[i]; j++)
  printf("%d ", i+1);
}
int main () {
  int N,k;
  scanf("%d %d", &N, &k);
  incredible_sort(N, k);
  return 0;
}
