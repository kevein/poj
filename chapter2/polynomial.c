#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define SUCCESS 0
#define ERROR 1
 
typedef struct term {
  int factor;
  int power;
  struct term *next;
} TERM;
 
int insert(TERM *poly, int factor, int power);
TERM *create_poly(int factor, int power);
int print_poly(TERM *poly);
 
int main(void)
{
  int count;
  scanf("%d\n", &count);
  TERM *poly[count];
  char buf[2][1024];
  int i,j=0;
  char c;
  int tmp_f,tmp_p;
  char c_f[12],c_p[12];
  for(i = 0; i < count; i++)
  {
        poly[i]=create_poly(0, 0);
        for(j=0;j<2;j++)
          {
                fgets(buf[j],1024,stdin);
                char *tmp=buf[j];
                while(sscanf(tmp,"%d %d", &tmp_f,&tmp_p) > 1)
                  {
                        sprintf(c_f,"%d",tmp_f);
                        sprintf(c_p,"%d",tmp_p);
                        insert(poly[i],tmp_f,tmp_p);
                        tmp+=strlen(c_f)+strlen(c_p)+2;
                  }
          }
 }
  for(i = 0;i < count; i++)
  print_poly(poly[i]);
  return 0;
 
}
 
TERM *create_poly(int factor, int power)
{
  if (power < 0){
        printf("power should not be negtive!\n");
        return NULL;
  }
 
  TERM *head = (TERM *)malloc(sizeof(struct term));
  head->factor = 0;
  head->power = -1;
  head->next = NULL;
 
  TERM *node = (TERM *)malloc(sizeof(struct term));
 
  node->factor = factor;
  node->power = power;
  node->next = NULL;
 
  head->next = node;
 
  return head;
 
}
 
int insert(TERM *poly, int factor, int power)
{
  TERM *p = poly;
  TERM *tmp;
  if (p->next == NULL){
        printf("Polynomial is empty!\n");
        return ERROR;  
  }
 
  while(p->next != NULL){
        tmp = p;
        p = p->next;
        if(p->power < power){
          TERM *node = (TERM *)malloc(sizeof(struct term));
          node->factor = factor;
          node->power = power;
          node->next = p;
          tmp->next = node;
          return SUCCESS;
        }
        if(p->power > power){
          if(p->next == NULL){
                TERM *node = (TERM *)malloc(sizeof(struct term));
                node->factor = factor;
                node->power = power;
                node->next = NULL;
                p->next = node;
                return SUCCESS;
          }
          continue;
        }
        if(p->power == power){
          p->factor += factor;
          return SUCCESS;
        }
  }
}
 
int print_poly(TERM *poly)
{
  TERM *p = poly;
  if (p->next == NULL){
        printf("Polynomial is empty!\n");
        return ERROR;  
  }
  while(p->next != NULL){
        p = p->next;
    if(p->factor != 0 && p->power >= 0)
        printf("[ %d %d ] ", p->factor, p->power);
  } 
  printf("\n");
}
