#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct relacionamento{
    int id;
    char nome[100];
    struct relacionamento *proximorelacionamento;
    struct user * endereco;
};

struct user{
    char nome[100];
    int id;
    struct user *proximouser;
    struct relacionamento *proximorelacionamento;
};


struct user *adicionar (struct user *ini)
{
    char name[100];
    int ide;
    
    struct user *aux;
    aux = ini;
    
    struct user *novo;
    novo = (struct user*) malloc (sizeof (struct user));
    
    getchar();
    printf("Digite o nome: ");
    fgets(name,100,stdin);
    strcpy(novo->nome,name);
    
    printf("Digite o id: ");
    scanf("%i", &ide);
    
    novo->id=ide;
    
    novo -> proximouser = NULL;
    
    novo -> proximorelacionamento = NULL;
   
    
    if (ini == NULL)
    {
        ini = novo;
    }
    else
    {
        while (aux -> proximouser != NULL)
        {
            aux = aux -> proximouser;
        }
        
        aux -> proximouser = novo;
    }
    
    return (ini);
};




struct user *amizade (struct user *ini)
{
    char nome1[100];
    char nome2[100];
    
    getchar();
    printf("Digite o primeiro nome a ser linkado: ");
    fgets(nome1,100,stdin);
    
    getchar();
    printf("Digite o segundo nome a ser linkado: ");
    fgets(nome2,100,stdin);
    
    getchar();
    
    struct user* aux;
    aux=ini;
    struct user* aux2;
    aux2=ini;
    
    
    
    while (strcmp(nome1,aux->nome)!=0 && aux->proximouser!=NULL)
    {
        aux=aux->proximouser;
    }
    
    while (strcmp(nome2,aux->nome)!=0 && aux2->proximouser!=NULL)
    {
        aux2=aux2->proximouser;
    }
    
    struct relacionamento* aux3;
    aux3=aux->proximorelacionamento;
    struct relacionamento* aux4;
    aux4=aux2->proximorelacionamento;
    
    struct relacionamento *novo;
    novo = (struct relacionamento*) malloc (sizeof (struct relacionamento));
    
    novo->id=aux2->id;
    strcpy(nome2,novo->nome);
    novo->proximorelacionamento=NULL;
    novo->endereco=aux2;
    
    struct relacionamento *novo2;
    novo = (struct relacionamento*) malloc (sizeof (struct relacionamento));
    
    novo2->id=aux->id;
    strcpy(nome1,novo2->nome);
    novo2->proximorelacionamento=NULL;
    novo2->endereco=aux;
    
    if(aux3==NULL)
    {
        aux3=novo;
    }
    else{
        while(aux3->proximorelacionamento!=NULL)
        {
            aux3=aux3->proximorelacionamento;
        }
        aux3->proximorelacionamento=novo;
    }
    
    if(aux4==NULL)
    {
        aux4=novo2;
    }
    else{
        while(aux4->proximorelacionamento!=NULL)
        {
            aux4=aux4->proximorelacionamento;
        }
        aux4->proximorelacionamento=novo2;
    }
    
    
    return (ini);
};


void amigos(struct user* ini)
{
    char nome[100];
    
    struct user* aux;
    aux=ini;
    
    struct relacionamento* aux1;
    
    getchar();
    printf("Digite o nome para mostrar os amigos: ");
    fgets(nome,100,stdin);
    getchar();
    
    while (strcmp(nome,aux->nome)!=0 && aux->proximouser!=NULL)
    {
        aux=aux->proximouser;
    }
    
    aux1=aux->proximorelacionamento;
    if(aux1==NULL)
    {
        printf("Não tem amigo\n");
        
    }else{
        while(aux1->proximorelacionamento!=NULL)
        {
            printf("\n\nNome amigo: %s\n", aux1->nome);
            aux1=aux1->proximorelacionamento;
        }
    }
    
}

void usuario(struct user* ini)
{    
    struct user* aux;
    aux=ini;

    
    if(aux==NULL)
    {
        printf("Não tem usuarios\n");
    }else{
        while(aux->proximouser!=NULL)
        {
            printf("Nome usuario: %s\n", aux->nome);
            aux=aux->proximouser;
        }
        printf("Nome usuario: %s\n", aux->nome);
    }
    
}


void main ()
{
   int opcao;
   struct user* home;
   home=NULL;
   do{
        printf ("0 - Sair.\n");
        printf ("1 - Adicionar pessoa.\n");
        printf ("2 - Adicionar amigo.\n");
        printf ("3 - Listar os amigos de uma pessoa.\n");
        printf ("4 - Listar os usuarios.\n");
        printf ("5 - Distancia entre duas pessoas.\n");
        
        scanf ("%i", &opcao);
       
        switch(opcao){
            
            case 1:
            {
                
                home = adicionar (home);
                
            } break;
            
            case 2:
            {
                home = amizade(home);
            } break;
            
            case 3:
            {
                amigos(home);
            } break;
            
            case 4:
            {
                usuario(home);
            } break;
        }
        }while (opcao!=0);
}
