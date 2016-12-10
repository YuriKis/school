#include <iostream>

int s;
void printArr(int arr[], int n) {for(int i=0; i<n; i++) std::cout <<arr[i]<< " "; std::cout << std::endl;}
void brf(int arr[], int n){
  for(int i=0; i<10;i++) {
    arr[s-n] = i;
    printArr(arr, s);
    if(n != 1) brf(arr, n-1);
  }
}

int main (){
  s = 0;

  std::cin >> s;
  int a[s]={0};
  brf(a, s);
}
