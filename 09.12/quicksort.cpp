#include <iostream> //quicksort

int partition(double a[], int start, int end) {
   int marker = start;
   for ( int i = start; i <= end; i++ )
   {
       if ( a[i] <= a[end] )
       {
           double temp = a[marker]; // swap
           a[marker] = a[i];
           a[i] = temp;
           marker += 1;
       }
   }
   return marker - 1;
}
void quicksort (double a[], int start, int end)
{
  std::cout << "quicksort s= "<<start<<" e= "<< end<<" a[] = ";
  for(int i=0;i<end;i++) std::cout <<a[i]<<" ";
  std::cout << "" << '\n';
   if ( start >= end ) return;
   int pivot = partition(a, start, end);
   quicksort(a, start, pivot-1);
   quicksort(a, pivot+1, end);
}

int main (){
  int n = 0;
  std::cin >> n;
  double m[n] = {-1};
  for(int i = 0; i<n; i++)
    std::cin >> m[i];
  quicksort(m, 0, n-1);
  for(int i=0;i<n;i++) std::cout <<m[i]<<" ";
  return 0;
}
