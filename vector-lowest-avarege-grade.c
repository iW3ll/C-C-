#include <stdio.h>
#include <string.h>

/*Autor: Wesley Luiz
  data entrega: 10/09/22
Desenvolver um programa para receber um conjunto de nomes e notas, onde a quantidade de itens (nome, nota) não pode ultrapassar n (onde n é um número qualquer obrigatoriamente maior que 20). Contudo, o usuário pode encerrar a digitação a qualquer momento. Ao final, o programa deve exibir nome associado à menor nota e a média das seis primeiras notas.
*/
//Função pára descobrir
int setN(int x){
  int n=21,cn;
  char nome[100],menor_Nome[100];
  float nota=0,menorN,notaDiv=0,notaC;
  int c=1,z,p,i=0,f=0,s=0,count=0;

  printf("Deseja colocar um valor n? [1 = sim , 0 = nao]: ");
  scanf("%i",&cn);
  if (cn == 0){
    printf("O Valor de n é maior que 20 porém você pode parar a qualquer momento");
  }else if(cn ==1){
    do{
      printf("Digite o valor de n: ");
      scanf("%i", &n);

      if (n <= 20){
        printf("Digite um número maior que 20!\n");
      }
      
    }while(n <= 3);
    }
  else{
    printf("Você digitou outro número, n continua sendo maior que 20");
  }
    

    do{ 
      printf("\nInforme um nome[%i]:",c);
      scanf("%s",nome);
      
          
      printf("\nInforme um nota[%i]:",c);
      scanf("%f",&nota);
    
            
      printf("Deseja continuar? [1 = sim; 0 = não]: ");
      scanf("%i",&p);
      count++;
     

      if (count <=6){
        notaDiv += nota;
      }
      
      
      if (c==1){
      menorN = nota;
      strcpy(menor_Nome,nome);
      }
      else if(nota < menorN){
        menorN = nota;
        strcpy(menor_Nome,nome);
      }
      c++;

      
    }while((count < n) || (p == 0));

    if (count == 6){
       notaDiv = notaDiv / 6;
    }
    else if (count < 6){
      notaDiv = notaDiv / count;
    }
  
    printf("\nNome com a menor nota: %s\n",menor_Nome);

    printf("Valor media das 6 primeiras notas ou se o usuario parou antes: %.1f\n",notaDiv);
    return notaDiv;
}

int main(void) {
  float r,z;
  
  r = setN(z);


  return 0;
}
