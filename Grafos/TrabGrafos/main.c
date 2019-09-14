#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct relacionamento{
    int id;
    struct relacionamento *proximorelacionamento;
};

struct user{
    char nome[100];
    int id;
    struct user *proximouser;
    struct relacionamento *proximorelacionamento;
};

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
            printf("Nome usuario: %s | Id usuario: %i\n", aux->nome, aux->id);
            aux=aux->proximouser;
        }
        printf("Nome usuario: %s | Id usuario: %i\n\n", aux->nome, aux->id);
    }
    
}

struct user *addamigo (struct user *ini)
{
    char nome[100];
    int ide;
    struct user* aux;
    aux=ini;
    struct relacionamento* aux1;
    
    
    getchar();
    printf("Digite o seu nome: ");
    fgets(nome,100,stdin);
    
    printf("\n");
    usuario(ini);
    
    printf("\nDigite o id que você quer adicionar: ");
    scanf("%i", &ide);
    
    struct relacionamento *novo;
    novo = (struct relacionamento*) malloc (sizeof (struct relacionamento));
    
    novo->id=ide;
    novo->proximorelacionamento=NULL;
    
    while (strcmp(nome,aux->nome)!=0 && aux->proximouser!=NULL)
    {
        aux=aux->proximouser;
    }
    
    aux1=aux->proximorelacionamento;
    
    
    if (aux1 == NULL)
    {
        aux1 = novo;
    }
    else
    {
        while (aux1 -> proximorelacionamento != NULL)
        {
            aux1 = aux1 -> proximorelacionamento;
        }
        
        aux1 -> proximorelacionamento = novo;
    }
    
    printf("\nid amigo: %i\n", aux1->id);
    
    return (ini);
}




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






void amigos(struct user* ini)
{
    char nome[100];
    
    struct user* aux;
    aux=ini;
    
    struct relacionamento* aux1;
    
    getchar();
    printf("Digite o nome para mostrar os amigos: ");
    fgets(nome,100,stdin);

    
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
            printf("\n\nId amigo: %s\n", aux1->id);
            aux1=aux1->proximorelacionamento;
        }
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
        
        scanf ("%i", &opcao);
       
        switch(opcao){
            
            case 1:
            {
                
                home = adicionar (home);
                
            } break;
            
            case 2:
            {
                home = addamigo(home);
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
 
