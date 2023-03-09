#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void saisir_phrase(char*p)
{
    do
    {
        printf("donner la phrase :");
        scanf("%s",p);
    }
    while(strlen(*p)>200);
}
void remplirtab(char *T)
{
    char *p;
    for(p=T;p<T+10;p++)
    {
       saisir_phrase(p);
    }
}
int main()
{
    char *T;
    T=malloc(10*sizeof(char));
    remplirtab(T);
    return 0;
}
