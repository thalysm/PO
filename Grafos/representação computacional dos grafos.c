#include <stdio.h>
#include <stdlib.h>

struct vertice
{
    int numVertice;
    struct vertice *proximoVertice;
    struct no *listaAdjacencia;
};

struct no
{
    int numVertice;
    struct no *proximo;
};

struct no *criaNo (int numRecebido)
{
    struct no *temp;
    temp = (struct no *) malloc (sizeof (struct no));
    temp->numVertice = numRecebido;
    temp->proximo = NULL;
    return (temp);
}

struct no *inserir (struct no *lista, struct no *novo)
{
    struct no *aux;
    aux = lista;
    
    if (lista == NULL)
    {
        lista = novo;
    }
    else
    {
        while (aux -> proximo != NULL)
        {
            aux = aux->proximo;
        }
        
        aux->proximo = novo;
    }
    
    return (lista);
}

void mostrarLista (struct no *lista)
{
    struct no *aux;
    aux = lista;
    
    while (aux != NULL)
    {
        printf ("%i -> ", aux->numVertice);
        
        aux = aux->proximo;
    }
    
    free (aux);
}

int main()
{
    int v; //Quantidade de vértices
    
    printf ("Insira a quantidade de vertices: ");
    
    scanf ("%i", &v);
    
    struct vertice grafo[v]; //Alocando espaços de memória para os vértices
    
    for (int i = 0; i < v; i++) //Inicialização das listas dos vértices
    {
        grafo[i].numVertice = i + 1;
        //printf ("Vértice %i criado em %p\n", grafo[i].numVertice, grafo[i]);
        grafo[i].listaAdjacencia = NULL;
        //printf ("Lista do vértice: %p\n\n", grafo[i].listaAdjacencia);
    }
    
    printf ("\nVértices criados com sucesso!\n\n");
    
    printf ("*** Para a inserção de elementos nas listas de adjacências, por favor utilize números de %i a %i, ou -1 para interromper a inserção em cada vértice. ***\n\n", 1, v);
    
    for (int j = 0; j < v; j++)
    {
        printf ("Inserindo ligações para o vértice %i:\n", j + 1);
        
        for (int k = 0; k < v; k++)
        {
            int entrada;
            
            scanf ("%i", &entrada);
            
            if (entrada >= 1 && entrada <= v)
            {
                grafo[j].listaAdjacencia = inserir (grafo[j].listaAdjacencia, criaNo(entrada));
            }
            else if (entrada == -1)
            {
                break;
            }
            else if (entrada < 0 || entrada > v)
            {
                printf ("Ligação inválida, por favor insira novamente:");
                k--;
            }
        }
        
        printf ("\n");
    }
    
    for (int l = 0; l < v; l++)
    {
        printf ("Lista do vértice %i:\n", l + 1);
        
        mostrarLista(grafo[l].listaAdjacencia);
        
        printf ("\n\n");
    }
    
    return (0);
}
