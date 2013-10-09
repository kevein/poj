#include <stdio.h>
#define TRUE 1
#define FALSE 0

int bit_test(int number, int bit);
int count_bit_1(int *numbers, int bit, int length);

int main(void)
{
  int m, n;
  scanf("%d %d", &n, &m);
  int numbers[n];
  int i;
  char operation;
  int operator;
  for(i = 0; i < n; i++)
      scanf("%d", &numbers[i]);
  for(i = 0; i < m; i++)
    {
      scanf("%c %d", &operation, &operator);
      if( operation == 'Q')
        printf("%d\n", count_bit_1(numbers, operator, n));
      else if( operation == 'C')
        {
          for(i = 0; i < n; i++)
            {
              numbers[i] += operator;
              if (numbers[i] > 65535)
                numbers[i] = numbers[i] / 65536;
            }
        }
    }
  return 0;
}

int bit_test(int number, int bit)
{
  return number&(1<<bit) ? TRUE : FALSE;
}  

int count_bit_1(int *numbers, int bit, int length)
{
  int i, ret = 0;
  for(i = 0; i < length; i++)
    {
      ret += bit_test(numbers[i], bit);
    }
  return ret;
}

