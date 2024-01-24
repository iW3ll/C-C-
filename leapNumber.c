#include <stdio.h>

/*Autor: Wesley Luiz
  Data de entrega: 10/9/22
  Construa um programa que mostre a quantidade de números bissextos contidos no intervalo fechado [a,b], 
onde  a, b são números inteiros quaisquer informados pelo usuário. Deve-se assegurar que a e b sejam positivos, e a menor que b.
  */

int matchInter(int x){
  int a,b,count=0,i;
  
  do{
    do{
      printf("Digite um número inteiro a: ");
      scanf("%i", &a);
      if (a < 1){
      printf("Digite números positivos!\n");
      
    }
    }while(a < 1);
  
    do{
      printf("Digite um número inteiro b: ");
      scanf("%i", &b);
      if (b < 1){
      printf("Digite números positivos!\n");

    }
    }while(b < 1);

    if (a > b){
      printf("O valor a tem que ser menor que b, tente novamente!\n");
    }
    
    for (i = a;i <= b;i++){
      if(i%4==0 && (i%400==0 ||i%100!=0)) {
        count++;
        }
     
    }
  }while(a > b);
  
  

  return count;
  
}


int main(void) {
  int r,z;
  
  r= matchInter(z);

  printf("A quantidade de números bissextos contido no intervalo: %i",r);
  
  return 0;
}
