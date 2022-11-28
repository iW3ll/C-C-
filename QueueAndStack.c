#include <stdio.h>
#include <stdlib.h>
 
/*Autor: Wesley Luiz,Ronald Olieira.
  Objetivo: Construir um algoritmo que seja capaz de poder adicionar elementos em forma de pilha e fila 
  com base na escolhe do usuario.
  Data de estrega: 29/11/2002.
*/
 
 
 
typedef struct no{
    int valor;
    struct no *proximo;
}No;

No *Aloca()
{
	No *novo=(No *) malloc(sizeof(No));
	 if(!novo){
	  printf("Sem memoria disponivel!\n");
	  exit(1);
	 }else{
	  printf("Novo elemento: "); 
	  scanf("%d", &novo->valor);
	  return novo;
 }
}

void inserir(No **fila){
	
		
    No *novo = Aloca();
    if(novo){
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else{
            No *tpm = *fila;
            while(tpm->proximo != NULL)
               tpm = tpm->proximo;
               tpm->proximo = novo;
        }
    }
    else
        printf("\nErro ao alocar memoria.\n");
}
 
 
No *remover_da_fila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("\tFila vazia\n");
    return remover;
}

No *remover_pilha(No *pilha)
{
		if(pilha==NULL){
		printf("Pilha Vazia\n");
		return NULL;
	}else{
		No *ultimo = pilha->proximo, *penult = pilha;
				while(ultimo->proximo != NULL){
						penult = ultimo;
						ultimo = ultimo->proximo;
				}
				penult->proximo = NULL;
		return ultimo;
	}          
}

void imprimir_fila(No *fila){
    printf("\t------- FILA --------\n\t");
    while(fila){
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n\t------- FIM DA FILA --------\n");
}

void imprimir_pilha(No *pilha){
    printf("\t-------PILHA--------\n\t");
    while(pilha){
        printf("%d ", pilha->valor);
        pilha = pilha->proximo;
    }
    printf("\n\t------- FIM DA PILHA--------\n");
}

void Fila()
{
	 No *fila = NULL;
	 int opcao;
	 
	 
	 
	 do{

      printf("==================FILA==================\n");
	 printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Remover: ");
     scanf("%d", &opcao); 
     switch(opcao){
	 	case 1:
          inserir(&fila);
            break;
 
        case 2:
            imprimir_fila(fila);
            break;
            
        case 3:
          remover_da_fila(&fila);
 			break;                    
 			
        default:
            if(opcao != 0)
                printf("\nOpcao invalida!\n");
       break;
	   }
    }while(opcao != 0);	 
}

void Pilha()
{
	 No *pilha = NULL;
	 int opcao;
	 
	 
	 
	 do{

     printf("==================PILHA==================\n");
	 printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Remover: ");
     scanf("%d", &opcao);  
     switch(opcao){
            case 1:
          inserir(&pilha);
            break;
 
        case 2:
            imprimir_pilha(pilha);
            break;
            
        case 3:
          remover_pilha(pilha);
 			break;                    
 			
        default:
            if(opcao != 0)
                printf("\nOpcao invalida!\n");
      
       }
	 }while(opcao != 0);
	 	       	 
}
int main(){

    int opcao;
 
 printf("===========================INICIO DO PROGRAMA===========================\n\n");
    do{
        printf(" Digite - [1] para ter acesso a estrutura Fila\n ");
        printf(" Digite - [2] para ter acesso a estrutura Pilha\n ");
        printf(" Digite - [0] para sair do programa: \n ");
        scanf("%d", &opcao);                                              
 
        switch(opcao){
        case 1:
         Fila();
            break;
 
        case 2:
          Pilha();
            break;
            
                    	
        default:
            if(opcao != 0)
                printf("\nOpcao invalida!\n");
        }
 
    }while(opcao != 0);
  printf("===========================FINAL DO PROGRAMA===========================\n\n");		
}
