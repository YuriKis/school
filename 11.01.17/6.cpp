#include <iostream>
using namespace std;
int qsort (int*a, int i, int n){
    int st=i, f=n, piv;
    piv=a[2][(i+n)/2];
    while (st<f){
        while (a[2][st]<piv)
        st++;
        while (a[2][f]>piv)
        f--;
        if (a[2][st]>a[f])
        swap (a[2][st],a[f]);
    }
    if (i<st)
    return (a,i,st);
    if (n>f)
    return (a,f,n);
    return*a;
}
int shedule (int n){
    int a[2][n];
    for (int i=0; i<n; i++)
    cin>>a[1][i]>>a[2][i];
    int b[2][n]=qsort (*a,i,n);
    int k=0, sum=1;
    for (int i=1; i<n; i++){
        if (a[2][k]<a[1][i])
        k=i;
        sum=sum+1;
    }
    return sum;
}
int main(){
    int sum,n;
    cin>>n;
    cout<<shedule (n);
    return 0;
}
