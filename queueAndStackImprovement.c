#include <stdio.h>
#include <stdlib.h>

/*
 Autores: Wesley Luiz, Ronald Oliveira.
 Objetivo: Construir um algoritmo que seja capaz de poder adicionar e remover elementos em forma de pilha e fila 
 ou em qualquer posição com base na escolha do usúario.
 Data de estrega: 22/12/2022.
 */

// Definition of the node structure for the queue and stack
typedef struct node {
  int data;
  struct node *prev;
  struct node *next;
} Node;

// Pointers to the head and tail of the queue and stack
Node *head = NULL;
Node *tail = NULL;

// Function to create a new node and return a pointer to it
Node* createNode(int data) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  if (!newNode) {
    printf("Error allocating memory for new node\n");
    exit(1);
  }
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a new node at the end of the queue
void enqueue(int data) {
  Node *newNode = createNode(data);

  if (tail == NULL) {
    // Queue is empty, so new node is both head and tail
    head = newNode;
    tail = newNode;
  } else {
    // Insert new node at the end of the queue
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

// Function to add at the head
void enqueue_head(int data) {
  Node *newNode = createNode(data);

  if (head == NULL) {
    // Queue is empty, so new node is both head and tail
    head = newNode;
    tail = newNode;
  } else {
    // Insert new node at the beginning of the queue
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    
 }
 
}

// Function to remove the head node from the queue
void dequeue() {
  if (head == NULL) {
    printf("Error: Queue is empty\n");
    return;
  }

  Node *temp = head;
  head = head->next;
  if (head) {
    head->prev = NULL;
  } else {
    // Queue is now empty, so update tail
    tail = NULL;
  }
  free(temp);
}


// Function remove at the end
void dequeue_end() {
  if (head == NULL) {
    printf("Error: Queue is empty\n");
    return;
  }

  Node *temp = head;
  // Find the last node in the queue
  while (temp->next != NULL) {
    temp = temp->next;
  }
  // Remove the last node from the queue
  if (temp->prev != NULL) {
    temp->prev->next = NULL;
  } else {
    // The queue is now empty, so update head and tail
    head = NULL;
    tail = NULL;
  }
  free(temp);
}

// Function to print the queue from head to tail
void printQueue() {
  Node *temp = head;
  printf("Queue: ");
  while (temp) {
    printf(" %d -> ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Function to push a new node onto the stack
void push(int data) {
  Node *newNode = createNode(data);

  if (head == NULL) {
    // Stack is empty, so new node is both head and tail
    head = newNode;
  } else {
    // Insert new node at the top of the stack
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

// Function to push a new node onto the stack
void push_end(int data) {
  Node *newNode = createNode(data);

  if (head == NULL) {
    // Stack is empty, so new node is both head and tail
    head = newNode;
  } else {
    // Find the last node in the stack
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    // Insert new node at the end of the stack
    temp->next = newNode;
    newNode->prev = temp;
  }
}


// Function to pop at the end the top node from the stack
void pop() {
  if (head == NULL) {
    printf("Error: Stack is empty\n");
    return;
  }

  Node *temp = head;
  head = head->next;
  if (head) {
    head->prev = NULL;
  }
  free(temp);
}


// pop at the end of stack
void pop_end() {
  if (head == NULL) {
    printf("Error: Stack is empty\n");
    return;
  }

  Node *temp = head;
  // Find the last node in the stack
  while (temp->next != NULL) {
    temp = temp->next;
  }
  // Remove the last node from the stack
  if (temp->prev != NULL) {
    temp->prev->next = NULL;
  } else {
    // The stack is now empty, so update top
    head = NULL;
  }
  free(temp);
}

// Function to print Stack
void printStack() {
  Node *temp = head;
  printf("Stack: ");
  while (temp) {
    printf(" <- %d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Add any position, Using for queue and stack
void enqueueAtPosition(int data, int position) {
  Node *newNode = createNode(data);

  if (head == NULL) {
    // Queue is empty, so new node is both head and tail
    head = newNode;
    tail = newNode;
  } else if (position == 0) {
    // Insert new node at the beginning of the queue
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  
  }else {
    // Find the node at the specified position
    Node *temp = head;
    int i;
    for (i = 1; i < position && temp->next != NULL; ++i) {
      temp = temp->next;
    }
    // Insert the new node after the node at the specified position
    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next != NULL) {
      temp->next->prev = newNode;
    } else {
      // The new node is being inserted at the end of the queue, so update tail
      tail = newNode;
    }
    temp->next = newNode;
  }
}

// Remove any position, Using for queue and stack
void dequeueAtPosition(int position) {
  if (head == NULL) {
    printf("Error: Queue is empty\n");
    return;
  }

  if (position == 0) {
    // Remove the head node from the queue
    Node *temp = head;
    head = head->next;
    if (head) {
      head->prev = NULL;
    } else {
      // Queue is now empty, so update tail
      tail = NULL;
    }
    free(temp);
  } else {
    // Find the node at the specified position
    Node *temp = head;
    int i;
    for (i = 0; i < position && temp->next != NULL; i++) {
      temp = temp->next;
    }
    // Remove the node at the specified position
    if (temp->prev != NULL) {
      temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
      temp->next->prev = temp->prev;
    }
    free(temp);
  }
}

// Menu for queue
void queue(){
    int option;
    int data;
    int position;
    
    do{
        printf("==================Queue==================\n");
	 printf("\t0 - Exit\n\t1 - Push Tail\n\t2 - Push Head\n\t3 - Remove Head\n\t4 - Remove Tail\n\t5 - Add Any Position\n\t6 - Remove Any Position\nType an option: ");
     scanf("%d", &option); 
        switch(option){
            case 1:
            do{
                printf("Type an element or type 999 for exit: ");
                scanf("%i", &data);
                if (data ==999){
                    break;
                }
                enqueue(data);
                printQueue();
            }while(data !=999);
             
                 break;
            case 2:
            do{    
                printf("Type an element or type 999 for exit: ");
                scanf("%i", &data);
                if (data ==999){
                    break;
                }
                enqueue_head(data);
                printQueue();
            }while(data != 999);
                break;
            case 3:
                dequeue();
                printQueue();
                break;
            case 4:
                dequeue_end();
                printQueue();
                break;
            case 5:
            printQueue();
            do{
                printf("Type an element or type 999 for exit: ");
                scanf("%i", &data);
                if (data ==999){
                    break;
                }
                printf("Type a position: ");
                scanf("%i", &position);
                
                enqueueAtPosition(data,position);
                printQueue();
            }while(data !=999);
             
                 break;
            case 6:
             printQueue();
            do{
                printf("Type a position or 999 for exit: ");
                scanf("%i", &position);
                if (position ==999){
                    break;
                }
                dequeueAtPosition(position);
                printQueue();
            }while(position !=999);
             
                 break;
         
         }
        
        
    }while(option !=0);
    head = NULL;
    tail = NULL;
}

// Menu for stack
void stack(){
    int option;
    int data,position;
    
    do{
        printf("==================Stack==================\n");
	 printf("\t0 - Exit\n\t1 - Push Head\n\t2 - Push Tail\n\t3 - Remove Tail\n\t4 - Remove Head\n\t5 - Add Any Position\n\t6 - Remove Any Position\nType an option: ");
     scanf("%d", &option); 
        switch(option){
            case 1:
            do{
                printf("Type an element or 999 for exit: ");
                scanf("%i", &data);
                if (data ==999){
                    break;
                }
                push(data);
                printStack();
            }while(data !=0);
             
                 break;
            case 2:
            do{    
                printf("Type an element or 999 for exit: ");
                scanf("%i", &data);
                if (data ==999){
                    break;
                }
                push_end(data);
                printStack();
            }while(data != 999);
                break;
            case 3:
                pop_end();
                printStack();
                break;
            case 4:
                pop();
                printStack();
                break;
            case 5:
                printStack();
                do{
                printf("Type an element or type 999 for exit: ");
                scanf("%i", &data);
                if (data ==999){
                    break;
                }
                printf("Type a position: ");
                scanf("%i", &position);
                
                enqueueAtPosition(data,position);
                printStack();
            }while(data !=999);
             
                 break;
            case 6:
            printStack();
            do{
                printf("Type a position or 999 for exit: ");
                scanf("%i", &position);
                if (position ==999){
                    break;
                }
                dequeueAtPosition(position);
                printStack();
            }while(position !=999);
             
                 break;
         
         }
                
            
        
    }while(option !=0);
    head = NULL;
    tail = NULL;
    
}

// Main menu
int main() {
    
    int option;
 
 printf("===========================WELCOME===========================\n\n");
    do{
        printf("====================MENU====================\n");
        printf("\tType - [1] For Queue\n ");
        printf("\tType - [2] For Stack\n ");
        printf("\tType - [0] For Exit:\n\n\tChoose an option: ");
        scanf("%d", &option);                                              
        printf("====================MENU====================\n\n ");
      
        switch(option){
        case 1:
         queue();
            break;
 
        case 2:
          stack();
            break;
    
                     	
        default:
            if(option != 0)
                printf("\nTry Again!\n");
        }
 
    }while(option != 0);
  printf("===========================Thanks Bye===========================\n\n");		
}
