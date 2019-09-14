#include <stdlib.h>
#include <stdio.h>
#define tam 7

void preevet(int vet[])
{
 
 for(int i=0;i<tam;i++)
 {
  vet[i]=rand()%17;   
 }
 
}

void barbixas(int vet[],int j,int k)
{
    int aux=vet[j];
    vet[j]=vet[k];
    vet[k]=aux;
}

void mostrarvet(int vet[])
{
   int i;
 for(i=0;i<tam;i++)
 {
  printf("%i | ", vet[i]);   
 } 
 
 printf ("\n");
}

void insertionsort(int vet[])
{
    int i, j,atual, cont=0;
    for(i=1; i<tam;i++)
    {
        atual=vet[i];
        j=i-1;
    
    while((j>=0) && (atual<vet[j]))
    {
    vet[j+1]=vet[j];
    j=j-1;
    cont++;
    }
    vet[j+1]=atual;
    }
    printf("Quantidade de trocas: %i\n", cont+1);
}

void main()
{
    int vet[tam];
    srand(7);
    preevet(vet);
    mostrarvet(vet);
    insertionsort(vet);
    mostrarvet(vet);
}
 
 
