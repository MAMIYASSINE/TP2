#include<stdio.h>
#include<stdlib.h>
struct employe
{
    int code;
    char nm[20];
    char pr[20];
    float sl;
    int cdd;
    int csc;
}typedef employe;
struct departement
{
    int cd;
    char nm1[20];
    char resp[20];
}typedef departement;
void saisir_employe(employe*p)
{
    printf("donner le code :");
    scanf("%d",&(p->code));
    getchar();
    printf("\n donner le nom :");
    gets(p->nm);
    printf("\n donner le prenom :");
    gets(p->pr);
    printf("donner le salaire :");
    scanf("%f",&(p->sl));
    printf("\n donner le code de departement:");
    scanf("%d",&(p->cdd));
    printf("\n donner le code de chef: ");
    scanf("%d",&(p->csc));
}
void remplir_tab(employe*T,int n)
{
    employe*p;
    for(p=T;p<T+n;p++)
    {
        printf("donner l'empoyee n %d: \n",p-T+1);
        saisir_employe(p);
    }
}
void affiche_employee(employe*T,int n,int cd)
{
    employe*p;
    for(p=T;p<T+n;p++)
    {
        if((p->code)==cd)
        {
            printf("code :%d \n nom :%s\n prenom:%s \n salaire:%f \n code departement %d \n ",(p->code),(p->nm),(p->pr),(p->sl),(p->cdd));
        }
    }
}
void employee_nonaffect(employe*T,int n,employe*T_nonaffect)
{
    employe*p;
    employe*p1=T_nonaffect;
    for(p=T;p<T+n;p++)
    {
        if((p->cdd)==0)
            p1=p;
            p1++;
    }
}
/*void codedepartement(departement*dep,int n1,char*ch)
{
    departement*p;
    for(p=dep;p<dep+n1;p++)
    {
        if((p->nm1) == *ch)
        {
            printf("le code : ",(p->cd));
        }
    }
}*/
int nbreemployedep(employe*T,int n,int cd)
{
    int s=0;
    employe*p;
    for(p=T;p<T+n;p++)
    {
        if((p->cdd)==cd)
        {
            s++;
        }
    }
    return s;
}

int main()
{
    int n,cd,s;
    printf("donner le nombre de case:");
    scanf("%d",&n);
    employe*T;
    //employe*T1;
    T=malloc(n*sizeof(employe));
    remplir_tab(T,n);
    printf("donner le code de l'employee:");
    scanf("%d",&cd);
    //affiche_employee(T,n,cd);
    //T1=malloc(n*sizeof(employe));
    //employee_nonaffect(T,n,T1);
    printf("le nombre des employe dans un departement : %d",nbreemployedep(T,n,cd));

    return 0;
}
