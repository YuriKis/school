#include <iostream>
#include <cmath>
using namespace std;
int f1(int N,int n,int S,int sum){
    while (N!=0){
        n=sqrt (N);
        S=n*n;
        N=N-S;
        sum=sum+1;
    }
    return sum;
}
int migrain_minimization (int N){
    int n,S,sum;
    return f1(N,n,S,sum);
}
int main(){
    int N;
    cin>>N;
    cout<<migrain_minimization (N)*4;
    return 0;
}
