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

void selectionsort(int vet[])
{
    int i, j,min, cont=0;
    for(i=0;i<tam-1;i++)
    {
        min=i;
        for(j=i+1; j<tam; j++)
        {
            if(vet[j]<vet[min])
                min=j;
        }
            if(vet[i]!=vet[min])
            {
                barbixas(vet,i,min);
                cont++;
            }
        
    }
    printf("Quantidade de trocas: %i\n", cont);

}

void main()
{
    int vet[tam];
    srand(7);
    preevet(vet);
    mostrarvet(vet);
    selectionsort(vet);
    mostrarvet(vet);
}
 
