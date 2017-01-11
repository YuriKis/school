#include <stdio.h>

int partition(double a[], int w[], int c[], int start, int end) {
   int marker = start;
   for ( int i = start; i <= end; i++ )
   {
       if ( a[i] <= a[end] )
       {
           double temp = a[marker]; // swap
           a[marker] = a[i];
           a[i] = temp;

           //2
          int tmpW= w[marker], tmpc = c[marker];
           w[marker] = w[i]; c[marker] = c[i];
           w[i] = tmpW; c[i] = tmpc;

           marker += 1;
       }
   }
   return marker - 1;
}
void quicksort (double a[],int w[], int c[], int start, int end) {
   if ( start >= end ) return;
   int pivot = partition(a,w,c, start, end);
   quicksort(a,w,c, start, pivot-1);
   quicksort(a,w,c, pivot+1, end);
}

int Continuous_knapsack(int W,int n) {
  int w[n], c[n];
  double p[n];
  for(int i = 0; i <n;i++) {
    scanf("%d %d",&w[i],&c[i]);
    p[i] = (double)c[i]/w[i];
  } // scanf
  quicksort(p,w,c,0,n-1);

  for(int i = 0; i <n;i++) {
  //  printf("%d\t%d\t%lf \n",w[i],c[i],p[i]);
  } // scanf
  int C=0;
  for(int i = n-1; i >= 0; i--) {

    if( !(W - w[i] < 0)  ) {W-=w[i]; C+=c[i];}
    else {
      // дробь...
      C +=p[i]*W;
    //  printf("****%d\t%d\tc = %d\n",i, W, C);
      return C;
    }
  //  printf("++++++%d\t%d\tc = %d\n",i, W, C);
  }
  return 1;
}
int main () {
  int W,n;
  scanf("%d %d", &W, &n);
  printf("%d", Continuous_knapsack(W,n));
  return 0;
}
