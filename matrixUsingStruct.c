#include <stdio.h>

/*Autor: Wesley Luiz
Fazer um programa que receba as notas em uma matriz qualquer */

void generateMatrix(){
  const int qtUnit = 1;
  int qtStudent = 2,student,gradeX;
  float grade[qtStudent][qtUnit];

  //ask to user type quantity of grade and store in variable
  printf("Digite a quantidade de notas!: ");
  scanf("%i", &qtStudent);

  //matrix need 2 loops first line second colums 
  for(student =0;student < qtStudent; student++){
    for (gradeX=0; gradeX < 1; gradeX++){
      printf("Digite a nota do aluno %i: ",student);
      scanf("%f",&grade[student][gradeX]);
    }
  }
     
  //print matrix
  for(student =0;student < qtStudent; student++){
    for (gradeX=0; gradeX < 1; gradeX++){
      printf(" Aluno%d Nota: %.1f\n",student, grade[student][gradeX]);
    }
  }
}
  
  

int main(void){

  void generateMatrix(); 
  //call matrix
  generateMatrix();
  
  
  return 0;
}