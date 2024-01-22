#include <stdio.h>
#include <stdlib.h>

/*Trabalho Feito por: Wesley e Ronald 
Com as seguintes implementações: Inserir e excluir um elemento, balancear a cada inclusão ou exclusão, a cada inclução ou exclusão visualizar à árvore, imprimir à árvore em ordem, pre-ordem e pos-ordem
*/

// estrututa do nó
typedef struct no {
  int dado;
  struct no *esquerdo, *direito; // nos esquerdo e o direito da árvore
  short altura;
} tArvore;

// estrutura árvore com um ponteiro para um nó
typedef struct {
  tArvore *raiz;
} ArvB;

/*
    Função que cria um novo nó
    
*/
tArvore* novotArvore(int xvalor){
   tArvore *novo = malloc(sizeof(tArvore));

    if(novo){
        novo->dado = xvalor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;  //toda vez que é inserido um novo elemento ele é um nó folha ou seja sem filho
    }
    else
        printf("\nERRO ao alocar nó em novotArvore!\n");
    return novo;
}


   //Descobrir a altura dos nós movimentados, retorna o maior

short maior(short a, short b){
    return (a > b)? a: b;
}


      //Retorna a altura de um nó ou -1 caso ele seja null

short alturaDotArvore(tArvore *no){
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

/*
      Calcula e retorna o fator de balanceamento de um nó se tiver maior que 1 ou menor que -1 ta desbalanceada
*/
short fatorBalance(tArvore *no){
    if(no)
        return (alturaDotArvore(no->esquerdo) - alturaDotArvore(no->direito));
    else
        return 0;
}

/*
    função para a rotação à esquerda
*/
tArvore* rEsquerda(tArvore *r){
   tArvore *y, *f;

    y = r->direito; // y aponta para a subárvore direita da raiz r
    f = y->esquerdo; // f aponta para o filho esquerdo de y

    y->esquerdo = r; // o filho esquerdo de y passa a ser a raiz r
    r->direito = f; // o filho direito de r passa a ser f

    // recalcula a altura dos nós que foram movimentados
    r->altura = maior(alturaDotArvore(r->esquerdo), alturaDotArvore(r->direito)) + 1;
    y->altura = maior(alturaDotArvore(y->esquerdo), alturaDotArvore(y->direito)) + 1;

    return y;
}

/*
      função para a rotação à direita
*/
tArvore* rDireita(tArvore *r){
    tArvore *y, *f;

    y = r->esquerdo;
    f = y->direito;

    y->direito = r;
    r->esquerdo = f;

    r->altura = maior(alturaDotArvore(r->esquerdo), alturaDotArvore(r->direito)) + 1;
    y->altura = maior(alturaDotArvore(y->esquerdo), alturaDotArvore(y->direito)) + 1;

    return y;
}

/*
    Funções para as rotações duplas
*/
tArvore* rEsquerdaDireita(tArvore *r){
    r->esquerdo = rEsquerda(r->esquerdo);
    return rDireita(r);
}

tArvore* rDireitaEsquerda(tArvore *r){
    r->direito = rDireita(r->direito);
    return rEsquerda(r);
}


/*
    Função para realizar o balanceamento da árvore após uma inserção ou remoção*/
   
tArvore* balancear(tArvore *raiz){
    short fb = fatorBalance(raiz);

    // Rotação à esquerda
    if(fb < -1 && fatorBalance(raiz->direito) <= 0)
        raiz = rEsquerda(raiz);

    // Rotação à direita
    else if(fb > 1 && fatorBalance(raiz->esquerdo) >= 0)
        raiz = rDireita(raiz);

    // Rotação dupla à esquerda
    else if(fb > 1 && fatorBalance(raiz->esquerdo) < 0)
        raiz = rEsquerdaDireita(raiz);

    // Rotação dupla à direita
    else if(fb < -1 && fatorBalance(raiz->direito) > 0)
        raiz = rDireitaEsquerda(raiz);

    return raiz;
}

    //Insere um novo nó na árvore
    

tArvore* inserir(tArvore *raiz, int xvalor){
    if(raiz == NULL) // árvore vazia
        return novotArvore(xvalor);
    else{ // inserção será à esquerda ou à direita
        if(xvalor < raiz->dado)
            raiz->esquerdo = inserir(raiz->esquerdo, xvalor);
        else if(xvalor > raiz->dado)
            raiz->direito = inserir(raiz->direito, xvalor);
        else
            printf("\nInsercao nao realizada!\nO elemento %d a existe!\n", xvalor);
    }

    // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaDotArvore(raiz->esquerdo), alturaDotArvore(raiz->direito)) + 1;

    // verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);

    return raiz;
}

/*
    Função para remover um nó da Árvore binária balanceada a raiz é retornada se precisar rebalancear a árvore e a raiz pode ser alterada  
*/
tArvore* remover(tArvore *raiz, int nRemove) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->dado == nRemove) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerdo == NULL && raiz->direito == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", nRemove);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esquerdo != NULL && raiz->direito != NULL){
                    tArvore *auxvalor = raiz->esquerdo;
                    while(auxvalor->direito != NULL)
                        auxvalor = auxvalor->direito;
                    raiz->dado = auxvalor->dado;
                    auxvalor->dado = nRemove;
                    printf("Elemento trocado: %d !\n", nRemove);
                    raiz->esquerdo = remover(raiz->esquerdo, nRemove);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    tArvore *auxvalor;
                    if(raiz->esquerdo != NULL)
                        auxvalor = raiz->esquerdo;
                    else
                        auxvalor = raiz->direito;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", nRemove);
                    return auxvalor;
                }
            }
        } else {
            if(nRemove < raiz->dado)
                raiz->esquerdo = remover(raiz->esquerdo, nRemove);
            else
                raiz->direito = remover(raiz->direito, nRemove);
        }

        // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
        raiz->altura = maior(alturaDotArvore(raiz->esquerdo), alturaDotArvore(raiz->direito)) + 1;

        // verifica a necessidade de rebalancear a árvore
        raiz = balancear(raiz);

        return raiz;
    }
}

/*
     Procedimento para imprimir uma árvore AVL
*/
void imprimir(tArvore *raiz, int nivel){
    int i;
    if(raiz){
        imprimir(raiz->direito, nivel + 1);
        printf("\n\n");

        for(i = 0; i < nivel; i++)
            printf("\t");
            

        printf("%d", raiz->dado);
        imprimir(raiz->esquerdo, nivel + 1);
    }
}

/*  faz a impressão da árvore  em-ordem*/
void imprimir_ord(tArvore *raiz) {
  if (raiz != NULL) {
    imprimir_ord(raiz->esquerdo); // recursividade
    printf(" %d ", raiz->dado);
    imprimir_ord(raiz->direito); // recursividade
  }
}

/*  faz a impressão da árvore  pre-ordem */
void imprimir_pre(tArvore *raiz) {
  if (raiz != NULL) {
    printf(" %d ", raiz->dado);
    imprimir_pre(raiz->esquerdo); // recursividade
    imprimir_pre(raiz->direito);  // recursividade
  }
}

/*  faz a impressão da árvore  pos-ordem */
void imprimir_pos(tArvore *raiz) {
  if (raiz != NULL) {
    imprimir_pos(raiz->esquerdo); // recursividade
    imprimir_pos(raiz->direito);  // recursividade
    printf(" %d  ", raiz->dado);
  }
}


int main() {
  int op, dado, resp;
  tArvore *raiz = NULL;
  resp = 1;
  do {
    printf("\n +**********************************+\n");
    printf(" |***** Programa Arvore Binaria  ***|\n");
    printf(" +**********************************+\n");
    printf(" | Menu:                            |\n");
    printf(" |                                  |\n");
    printf(" | 1. Inserir Elemento              |\n");
    printf(" | 2. Remover Elemento              |\n");
    printf(" | 3. Imprimir Em-Ordem             |\n");
    printf(" | 4. Imprimir Pre-Ordem            |\n");
    printf(" | 5. Imprimir Pos-Ordem            |\n");
    printf(" | 6. Imprimir Arvore Binaria       |\n");
    printf(" | 7. Sair                          |\n");
    printf(" |                                  |\n");
    printf(" +**********************************+\n");
    printf("\n Opcao: ");
    scanf("%d", &op);

    switch (op) {
    case 1: // inserir elemento
      printf("Digite o dado a ser inserido: ");
      scanf("%d", &dado);
      raiz = inserir(raiz, dado);
      printf("\nImpressao arvore binaria:\n");
      imprimir(raiz, 1);
      break;
    case 2: // remover elemento
      printf("Digite o dado a ser deletado: ");
      scanf("%d", &dado);
      raiz = remover(raiz, dado);
      printf("\nImpressao arvore binaria:\n");
      imprimir(raiz, 1);
      break;
    case 3: // imprimir em-ordem
      printf("\nImpressao em-ordem: ");
      imprimir_ord(raiz);
      printf("\n");
      break;
    case 4: // imprimir pre-ordem
      printf("\nImpressao pre-ordem: ");
      imprimir_pre(raiz);
      printf("\n");
      break;
    case 5: // imprimir pos-ordem
      printf("\nImpressao pos-ordem: ");
      imprimir_pos(raiz);
      printf("\n");
      break;
    case 6: // imprimir árvore binária
      printf("\nImpressao arvore binaria:\n");
      imprimir(raiz, 1);
      printf("\n");
      break;
    case 7: // sair
      resp = 0;
      break;
    default:
      printf("\n Opcao Invalida!");
    }
  } while (resp);

  return 0;
}
