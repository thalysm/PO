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

void mostrarvet(int vet[])
{
   int i;
 for(i=0;i<tam;i++)
 {
  printf("%i | ", vet[i]);   
 } 
 
 printf ("\n");
}

void BuscaSequencial(int vet[])
{
    int num;
    int flag=0;
    printf("Qual seu numero buscado?\n");
    scanf("%i", &num);
    
    for(int i=0; i<tam; i++)
    {
        if(num==vet[i])
        {
            flag=1;
            break;
        }
                
    }
    switch(flag)
    {
        case 0:
        {
        printf("Não há numero no vetor\n");
        }break;
        case 1:
        {
        printf("Há o numero no vetor\n");  
        }break;
    }
}

void main()
{
    int vet[tam];
    srand(7);
    preevet(vet);
    mostrarvet(vet);
    BuscaSequencial(vet);
} 
