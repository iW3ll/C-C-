#include <stdio.h>

/* Autor Wesley Luiz
Fazer um programe que receba as notas no vetor qualquer */

void generateGrade(){
  int i,c=0,qtGrade = 3;
  float n[qtGrade];
  
  //ask user input and store in a variable
  printf("Digite quantas notas vão ser armazenadas?: ");
  scanf("%i",&qtGrade);

  
  for (i=0 ; i < qtGrade ; i++){
    //c++ for view grade position
    printf("Digite a nota [%i]: ",c++);
    scanf("%f", &n[i]);
  }

  //print vector
  for (i=0;i < qtGrade; i++){
    printf("valor da nota %d : %.1f\n",i,n[i]);
  }

  
}



int main(void) {
  
  void generateGrade();

  generateGrade();


  
  return 0;
}