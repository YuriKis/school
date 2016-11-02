#include <iostream> //TODO: snake

void put_snake(int *mt, int n, int m){// 3
  int i=0, j=m-1;
  for(int i=0; i < n*m;i++) *(mt+i)=-1;
int c = 0;
  for(int x = 1; x <= n*m; x++) {
        *(mt+m*i+j) = x;
        std::cout << "x = "<< j << " y = " << i << " c = "<< x << std::endl;
        if(c == 0) if(*(mt+m*i+j-m) == -1) i--; // up
        else                    c++;
        if(c ==1) if(*(mt+m*i+j-1) == -1 && j-1 >= 0) j--; // left
        else                                c++;

        if(c == 2) if(*(mt+m*i+j+m) == -1) i++; // down
        else c++;
        if(c == 3) if(*(mt+m*i+j+1) == -1 && j+1 < m) j++; //right
        else c = 0;

        if(c == 0) if(*(mt+m*i+j-m) == -1) i--; // up
        else  c++;
        //*/
      }
}

int main()
{
  int n = -1, m;
  scanf("%i", &n);
  scanf("%i", &m);
  int mt[n][m];
  put_snake(mt[0],n,m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      printf("%i\t",mt[i][j] );
    printf("\n");
  }
  return 0;
}
