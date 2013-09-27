#include <stdio.h>

int find_largest_asci(char *s);
int insert(char *str, char *substr, char *result);

int main(void)
{
  char c, buf[20];
  char str[11], substr[4], result[16];
  int largest, i;
  while((c= getchar()) != '\n')
	{
	  ungetc(c, stdin);
	  fgets(buf, 14, stdin);
	  sscanf(buf, "%s %s", str, substr);
	  insert(str, substr, result);
	  printf("%s\n", result);
	}
  return 0;
}


int find_largest_asci(char *s)
{
  if(s[0] == '\0' || s[0] == '\n')
	{
	  printf("string is empty!\n");
	  return -1;
	}
  int i = 1, largest = 0;
  while(1)
	{
	  if(s[i] == '\n' || s[i] == '\0')
		break;
	  if(s[i] > s[largest])
		largest = i;
	  i++;
	}
  return largest;
}


int insert(char *str, char *substr, char *result)
{
  int largest, i,j;

  largest = find_largest_asci(str);

  for(i = 0; i <= largest; i++)
	{
	  result[i] = str[i];
	}
  
  j = largest + 1;
  i = 0;
  
  while(substr[i] != '\n' && substr[i] != '\0')
	result[j++] = substr[i++];

  i = largest + 1;
  while(str[i] != '\n' && str[i] != '\0')
	  result[j++] = str[i++];

  result[j] = '\0';

  return 0;
}
