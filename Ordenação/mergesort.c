#include <stdlib.h>
#include <stdio.h>
#define tam 10


void preenchevet(int vet[])
{
    // preencher vetor de forma aleatoria
    for(int i=0;i<tam;i++)
    {
        vet[i]=rand()%17;
    }
}

void mostrarvet(int vet[])
{
    // mostrar vetor
    for(int i=0;i<tam; i++)
    {
        printf(" %i |", vet[i]);
    }
}

void mergesort (int inicio, int fim, int vet[])
{
    // definir o meio do vetor
    int meio=(fim+inicio)/2;
    
    // verificação se sub-problema nao chegou a 1 
    if(inicio!=fim)
    {
        
    // reduzir o primeiro sub-problema
        mergesort(inicio,meio,vet);
        
    // reduzir o segundo sub-problema    
        mergesort(meio+1,fim,vet);
    
    // definindo k, i e j    
        int k=0, i=inicio,j=meio+1;
        
    // criar vetor auxiliar    
        int aux[fim-inicio+1];
        
    // laço verdadeiro até terminar de ordenar    
        while(1)
        {
      
    // verificando se o segundo sub-problema chegou ao fim        
            if(j==fim+1)
            {
                
    // quando o segundo sub-problema chega ao fim, vetor é preechido pelo primeiro sub-problema            
                while (i<=meio)
                {
                    aux[k]=vet[i];
                    i++;
                    k++;
                }
                break;
            } 
            
    // verificando se o primeiro sub-problema chegou ao fim        
            else if(i==meio+1)
            {
                
    // quando o primeiro sub-problema chega ao fim, vetor é preechido pelo segundo sub-problema            
                while(j<=fim)
                {
                    aux[k]=vet[j];
                    j++;
                    k++;
                }
                break;
            } 
            
     // verificando se o primeiro sub-problema é menor, se for, o vetor auxiliar recebe o primeiro sub-problema   
            else if (vet[i]<=vet[j])
            {
                aux[k]=vet[i];
                k++;
                i++;
            }
            
    // verificando se o segundo sub-problema é menor, se for, o vetor auxiliar recebe o segundo sub-problema
            else if (vet[j]<=vet[i])
            {
                aux[k]=vet[j];
                k++;
                j++;
            }
        }
        
     // preencher o vetor original com os sub-problemas já ordenados   
        for(i=inicio;i<=fim;i++)
        {
            vet[i]=aux[i-inicio];
        }
    }
}

void main()
{
    // criando a seed da aleatoriedade
    srand(tam);
    
    // criar vetor 
    int vet[tam];
    
    // preecher vetor de forma aleatoria
    preenchevet(vet);
    
    // mostrar vetor desordenado
    mostrarvet(vet);
    
    // ordenar vetor com o MergeSort
    mergesort(0,tam-1,vet);
    
    // pular linha
    printf("\n");
    
    // mostrar vetor já ordenado
    mostrarvet(vet);
}
