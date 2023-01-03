// Program    : ASM_04_stack.c
// Created by : Peter Oo
// Created on : 1/2/2023 (1:01 PM).
//

/*
 * Please, run it from command prompt, or
 * Run it from PowerShell
 * To enjoy delay animation, better.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK 20

typedef struct stack{
    int data[MAX_STACK];
    int top;
}st;

void delay(int interval);
void createEmptyStack(st *Stack);
int isStackFull(st *Stack);
int isStackEmpty(st *Stack);
void pushStack(st *Stack, int value);
int popStack(st *Stack);
void listStackData(st *Stack);

int main(){

    int values[] = {10,20,30,40,50,60,70,80,90,100,
                    110,120,130,140,150,160,170,180,190,200, 210};

    st *Stack = (st*)(malloc(sizeof(st)));
//    st *Stack = NULL;
    createEmptyStack(Stack);

    for(int i=0; i<sizeof(values)/sizeof(values[0]); i++){
        pushStack(Stack, values[i]);
    }
    printf("\n");
    listStackData(Stack);
    printf("Popping data from the stack...\n");
    delay(500);
    int limit = Stack->top+1;
    for(int i=0; i<limit; i++){
        int data = popStack(Stack);
        printf("%d\n", data);
        delay(100);
    }
    printf("\n");
    listStackData(Stack);
    return 0;
}

void delay(int interval){
    clock_t t;
    t = clock();
    while((clock() - t) <= interval);
}

void createEmptyStack(st *stack){
    stack->top = -1;
}

int  isStackFull(st *Stack){
    if(Stack->top == MAX_STACK-1)
        return 1;
    else
        return 0;
}

void pushStack(st *Stack, int value){
    if(isStackFull(Stack))
        printf("Stack is full!\n");
    else{
        Stack->top++;
        printf("Pushing value @ %d: %d\n", Stack->top+1, value);
        Stack->data[Stack->top] = value;
    }
    delay(300);
}


int isStackEmpty(st *Stack){
    if(Stack->top == -1)
        return 1;
    else
        return 0;
}

int popStack(st *Stack){
    int data = 0;
    if(isStackEmpty(Stack)){
        printf("Stack is empty! ");
        return -1;
    }
    else{
        data = Stack->data[Stack->top];
        Stack->top--;
        return data;
    }
}

void listStackData(st *Stack){
    int cnt = 0;
    if(isStackEmpty(Stack))
        printf("Empty Stack!");
    else{
        printf("No: of elements in the Stack: %d\n", Stack->top+1);
        delay(200);
        for(;cnt<Stack->top+1; cnt++){
            printf("value @ %d: %d\n", cnt+1, Stack->data[cnt]);
            delay(200);
        }
        printf("\n");
    }
}