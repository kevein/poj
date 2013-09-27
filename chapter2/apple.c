#include<stdio.h>

int place_apple(int m,int n) 
{
  if(m==0||n==1)  
	return 1;
  if(n>m)
	return place_apple(m,m);
  else
	return place_apple(m,n-1) + place_apple(m-n,n);
}

int main(void)
{
  int T,m,n;
  scanf("%d",&T);
  while(T--)
	{
	  scanf("%d%d", &m, &n);
	  printf("%d\n", place_apple(m,n));
    }
}
