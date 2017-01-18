#include <iostream>
using namespace std;
void outer_points(int n, int m) {
     int *beginning = new int[n];
     int *ending = new int[n];
     for (int i = 0; i < n; i++){
         cin >> beginning[i] >> ending[i];
     }
     for (int i = 0; i < m; i++){
         int dot, number = n;
         cin >> dot;
         for (int j = 0; j < n;j++){
             if (beginning[j]<=dot && ending[j]>=dot){
                number--;
             }
         }
     cout << number << " ";
     }
}
int main(){
    int n, m;
    cin >> n >> m;
    outer_points(n, m);
    return 0;
}
