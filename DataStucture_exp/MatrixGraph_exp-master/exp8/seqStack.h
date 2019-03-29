//�޸İ�seqStack.h
//2019.01.03

#pragma once
#include<iostream>
#define MAXLEN 1024

typedef char elementType;

using namespace std;

//˳��ջ�洢�ṹ����
typedef struct sStack{
    elementType data[MAXLEN];
    int top;
}seqStack;

//��ʼ��ջ
void initialStacksS(seqStack &S){
    S.top=-1;
}

//�жϿ�ջ
bool stackEmptysS(seqStack &S){
    if(S.top == -1){
        return true;
    }
    else{
        return false;
    }
}

//�ж�ջ��
bool stackFullsS(seqStack &S){
    if(S.top == MAXLEN-1){
        return true;
    }
    else{
        return false;
    }
}

//��ջ
void pushStacksS(seqStack &S, elementType x){
    if(stackFullsS(S)){
        cout << "ջ��!�޷���ջ!" << endl;
    }
    else{
        S.top++;
        S.data[S.top]=x;
    }
}

//��ջ
void popStacksS(seqStack &S, elementType x){
    if(stackEmptysS(S)){
        cout << "ջ��!�޷���ջ!" << endl;
    }
    else{
        x=S.data[S.top];
        S.top--;
    }
}
