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

void bubblesort(int vet[])
{
    int aux, cont=0;
    for(int i=tam-1;i>=1;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(vet[j]>vet[j+1])
            {
                barbixas(vet,j,j+1);
                cont++;
            }
        }
    }
    printf("Numero de troca: %i\n", cont);
}

void main()
{
    int vet[tam];
    srand(7);
    preevet(vet);
    mostrarvet(vet);
    bubblesort(vet);
    mostrarvet(vet);
}
