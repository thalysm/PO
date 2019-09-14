#include <stdlib.h>
#include <stdio.h>
#define tam 7

void preevet(int vet[])
{
 
 for(int i=0;i<tam;i++)
 {
  vet[i]=i+1;
 }
 
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

void BuscaBinaria (int vet[])
{
     int num,esq = 0,dir = tam-1,meio,cont=0;
     printf("Qual numero procurado?\n");
     scanf("%i", &num);
     
     while (esq <= dir)
     {
          meio = (esq + dir)/2;
          if (num == vet[meio])
          {
              cont++;
          }
          if (num < vet[meio])
          {
               dir = meio-1;
          }
          else
          {
               esq = meio+1;
          }
     }
    if(cont==1)
    {
        printf("\nNumero encontrado");
    }
    else 
    {
      printf("\nnumero não encontrado");  
    }
}

void main()
{
    int vet[tam];
    srand(7);
    preevet(vet);
    mostrarvet(vet);
    BuscaBinaria(vet);
} 

