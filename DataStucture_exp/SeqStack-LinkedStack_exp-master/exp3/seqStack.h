#pragma once
#include<iostream>
#define elementType int
#define MAXLEN 1024

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
void popStacksS(seqStack &S, elementType &x){
    if(stackEmptysS(S)){
        cout << "ջ��!�޷���ջ!" << endl;
    }
    else{
        x=S.data[S.top];
        S.top--;
    }
}
/*˳��ջ������������*/

/**  ��Ҫ����  **/
//1.����˳��ջʵ�ֽ�10������ת��Ϊ16������
void radixChange10to16sStack(){
    cout << "�������ת������(10����):" ;
    elementType x;
    cin >> x;

    seqStack S;
    initialStacksS(S);

    if(x==0){
        cout << "����ת����Ϊ(16����):0" << endl;
    }
    else{
            while(x){
            elementType temp=x%16;
            pushStacksS(S, temp);
            x=x/16;
            }
            cout << "��ջ�ɹ�!" << endl;

            cout << "����ת����Ϊ(16����):" ;
            while(!stackEmptysS(S)){
                elementType temp;
                popStacksS(S, temp);

                if(temp < 10){
                    cout << temp ;
                }
                else{        ///����ABCDEF
                    switch(temp){
                        case 10:
                            cout << 'A' ; break;
                        case 11:
                            cout << 'B' ; break;
                        case 12:
                            cout << 'C' ; break;
                        case 13:
                            cout << 'D' ; break;
                        case 14:
                            cout << 'E' ; break;
                        case 15:
                            cout << 'F' ; break;
                    }
                }
            }
    }

    cout << "\n\n���뻻�м���" << endl;
    getchar();
}

//2. ����ƥ��(��һ���Ϸ�����ѧ���ʽ��˵�����еĸ���С���š�{������}������[������]����
//            ��(���͡�)��Ӧ���໥ƥ��ġ�����㷨�����ַ�����ʽ����ı��ʽS��
//            �ж����еĸ������Ƿ���ƥ��ġ�)
void bracketMatchsStack(){
    cout << "��������ѧ���ʽ:" ;
    char str[40];
    cin >> str;

    seqStack S;
    initialStacksS(S);

    bool sign=true;
    int c;
    for(int i=0; str[i]!=NULL && sign; i++){
        switch(str[i]){
        case '(':
        case '[':
        case '{':
            pushStacksS(S, str[i]);
            break;
        case ')':
            popStacksS(S, c);
            if(c!='('){
                sign=false;
            }
            break;
        case ']':
            popStacksS(S, c);
            if(c!='['){
                sign=false;
            }
            break;
        case '}':
            popStacksS(S, c);
            if(c!='{'){
                sign=false;
            }
            break;
        default:
            break;
        }
    }

    if(stackEmptysS(S) && sign){
        cout << "�����ȷ!" << endl;
    }
    else{
        cout << "��Դ���!" << endl;
    }

    cout << "\n\n���뻻�м���" << endl;
    getchar();
}
