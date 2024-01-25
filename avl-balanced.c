#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Trabalho Feito por: Wesley e Ronald
Com as seguintes implementações: Inserir e excluir um elemento, balancear a cada
inclusão ou exclusão, a cada inclução ou exclusão visualizar à árvore, imprimir
à árvore em ordem, pre-ordem e pos-ordem
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
tArvore *novotArvore(int xvalor) {
  tArvore *novo = malloc(sizeof(tArvore));

  if (novo) {
    novo->dado = xvalor;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    novo->altura = 0; // toda vez que é inserido um novo elemento ele é um nó
                      // folha ou seja sem filho
  } else
    printf("\nERRO ao alocar nó em novotArvore!\n");
  return novo;
}

/*
    Abaixo definimos o máximo de caracters da variável
    str terá para a impressão de data, o tipo de dado tm
    e o seu ponteiro *tm e a variavel t para qual a estrutura time_t
    da biblioteca time.h
*/
#define MAX_LENGTH 100

time_t t;
struct tm *tm;
char str[MAX_LENGTH];
// Descobrir a altura dos nós movimentados, retorna o maior

short maior(short a, short b) { return (a > b) ? a : b; }

// Retorna a altura de um nó ou -1 caso ele seja null

short alturaDotArvore(tArvore *no) {
  if (no == NULL)
    return -1;
  else
    return no->altura;
}

/*
      Calcula e retorna o fator de balanceamento de um nó se tiver maior que 1
   ou menor que -1 ta desbalanceada
*/
short fatorBalance(tArvore *no) {
  if (no)
    return (alturaDotArvore(no->esquerdo) - alturaDotArvore(no->direito));
  else
    return 0;
}

/*
    função para a rotação à esquerda
*/
tArvore *rEsquerda(tArvore *r) {
  tArvore *y, *x;

  y = r->direito;  // y aponta para a subárvore direita da raiz r
  x = y->esquerdo; // x aponta para o filho esquerdo de y

  y->esquerdo = r; // o filho esquerdo de y passa a ser a raiz r
  r->direito = x;  // o filho direito de r passa a ser x

  // recalcula a altura dos nós que foram movimentados
  r->altura =
      maior(alturaDotArvore(r->esquerdo), alturaDotArvore(r->direito)) + 1;
  y->altura =
      maior(alturaDotArvore(y->esquerdo), alturaDotArvore(y->direito)) + 1;

  return y;
}

/*
      função para a rotação à direita
*/
tArvore *rDireita(tArvore *r) {
  tArvore *y, *x;

  y = r->esquerdo;
  x = y->direito;

  y->direito = r;
  r->esquerdo = x;

  r->altura =
      maior(alturaDotArvore(r->esquerdo), alturaDotArvore(r->direito)) + 1;
  y->altura =
      maior(alturaDotArvore(y->esquerdo), alturaDotArvore(y->direito)) + 1;

  return y;
}

/*
    Funções para as rotações duplas
*/
tArvore *rEsquerdaDireita(tArvore *r) {
  r->esquerdo = rEsquerda(r->esquerdo);
  return rDireita(r);
}

tArvore *rDireitaEsquerda(tArvore *r) {
  r->direito = rDireita(r->direito);
  return rEsquerda(r);
}

/*
    Função para realizar o balanceamento da árvore após uma inserção ou
   remoção*/

tArvore *balancear(tArvore *raiz) {
  short fb = fatorBalance(raiz);

  // Rotação à esquerda
  if (fb < -1 && fatorBalance(raiz->direito) <= 0)
    raiz = rEsquerda(raiz);

  // Rotação à direita
  else if (fb > 1 && fatorBalance(raiz->esquerdo) >= 0)
    raiz = rDireita(raiz);

  // Rotação dupla à esquerda
  else if (fb > 1 && fatorBalance(raiz->esquerdo) < 0)
    raiz = rEsquerdaDireita(raiz);

  // Rotação dupla à direita
  else if (fb < -1 && fatorBalance(raiz->direito) > 0)
    raiz = rDireitaEsquerda(raiz);

  return raiz;
}

// Insere um novo nó na árvore

tArvore *inserir(tArvore *raiz, int xvalor) {
  if (raiz == NULL) // árvore vazia
    return novotArvore(xvalor);
  else { // inserção será à esquerda ou à direita
    if (xvalor < raiz->dado)
      raiz->esquerdo = inserir(raiz->esquerdo, xvalor);
    else if (xvalor > raiz->dado)
      raiz->direito = inserir(raiz->direito, xvalor);
    else
      printf("\nInsercao nao realizada!\nO elemento %d ja existe!!\n", xvalor);
  }

  // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
  raiz->altura =
      maior(alturaDotArvore(raiz->esquerdo), alturaDotArvore(raiz->direito)) +
      1;

  // verifica a necessidade de rebalancear a árvore
  raiz = balancear(raiz);

  return raiz;
}

/*
    Função para remover um nó da Árvore binária balanceada a raiz é retornada se
   precisar rebalancear a árvore e a raiz pode ser alterada
*/
tArvore *remover(tArvore *raiz, int nRemove) {
  if (raiz == NULL) {
    printf("Valor nao encontrado!\n");
    return NULL;
  } else { // procura o nó a remover
    if (raiz->dado == nRemove) {
      // remove nós folhas (nós sem filhos)
      if (raiz->esquerdo == NULL && raiz->direito == NULL) {
        free(raiz);
        printf("Elemento folha removido: %d !\n", nRemove);
        return NULL;
      } else {
        // remover nós que possuem 2 filhos
        if (raiz->esquerdo != NULL && raiz->direito != NULL) {
          tArvore *auxvalor = raiz->esquerdo;
          while (auxvalor->direito != NULL)
            auxvalor = auxvalor->direito;
          raiz->dado = auxvalor->dado;
          auxvalor->dado = nRemove;
          printf("Elemento trocado: %d !\n", nRemove);
          raiz->esquerdo = remover(raiz->esquerdo, nRemove);
          return raiz;
        } else {
          // remover nós que possuem apenas 1 filho
          tArvore *auxvalor;
          if (raiz->esquerdo != NULL)
            auxvalor = raiz->esquerdo;
          else
            auxvalor = raiz->direito;
          free(raiz);
          printf("Elemento com 1 filho removido: %d !\n", nRemove);
          return auxvalor;
        }
      }
    } else {
      if (nRemove < raiz->dado)
        raiz->esquerdo = remover(raiz->esquerdo, nRemove);
      else
        raiz->direito = remover(raiz->direito, nRemove);
    }

    // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura =
        maior(alturaDotArvore(raiz->esquerdo), alturaDotArvore(raiz->direito)) +
        1;

    // verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);

    return raiz;
  }
}

/*
     Procedimento para imprimir uma árvore AVL
*/
void imprimir(tArvore *raiz, int nivel) {
  int i;

  if (raiz) {
    imprimir(raiz->direito, nivel + 1);
    printf("\n\n");

    for (i = 0; i < nivel; i++)
      printf("\t");

    printf("%d\n", raiz->dado);
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

/* Criando uma função para quando algo for alterado
  isto é inserido ou deletado ser impresso na tela o momento exato
*/
void arvore_alterada() {
  t = time(NULL);
  tm = localtime(&t);
  strftime(str, MAX_LENGTH, "%c", tm);
  printf("\nAlteracao foi feita em: %s\n\n", str);
}

void impressao_da_arvore() {
  t = time(NULL);
  tm = localtime(&t);
  strftime(str, MAX_LENGTH, "%c", tm);
  printf("\nA impressao foi feita em: %s\n\n", str);
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
      do {
        printf("---------------Para sara sair digite 0!!---------------\n");
        printf("Digite o dado a ser inserido: ");
        scanf("\n%d", &dado);

        if (dado == 0)
          break;
        else {
          raiz = inserir(raiz, dado);
          arvore_alterada();
          printf("\nImpressao arvore binaria:\n");
          imprimir(raiz, 1);
        }

      } while (dado != 0);

      break;
    case 2: // remover elemento

      do {
        printf("---------------Para sara sair digite 0!!---------------\n");
        printf("Digite o dado a ser deletado: ");
        scanf("%d", &dado);

        if (dado == 0)
          break;
        else {
          raiz = remover(raiz, dado);
          arvore_alterada();
          printf("\n Impressao arvore binaria:\n");
          imprimir(raiz, 1);
        }

      } while (dado != 0);
      break;
    case 3: // imprimir em-ordem
      impressao_da_arvore();
      printf("Impressao da arvore: \n");
      imprimir(raiz, 1);
      printf("\nImpressao em-ordem: ");
      imprimir_ord(raiz);
      printf("\n");
      break;
    case 4: // imprimir pre-ordem
      impressao_da_arvore();
      printf("Impressao da arvore: \n");
      imprimir(raiz, 1);
      printf("\nImpressao em pre-ordem: ");
      imprimir_pre(raiz);
      printf("\n");
      break;
    case 5: // imprimir pos-ordem
      impressao_da_arvore();
      printf("Impressao da arvore: \n");
      imprimir(raiz, 1);
      printf("\nImpressao em pos-ordem: ");
      imprimir_pos(raiz);
      printf("\n");
      break;
    case 6: // imprimir árvore binária
      impressao_da_arvore();
      printf("\nImpressao da arvore binaria:\n");
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
