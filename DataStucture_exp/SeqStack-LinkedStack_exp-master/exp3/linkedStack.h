#pragma once
#include<iostream>
#define elementType int
#define MAXLEN 1024

using namespace std;

//��ջ�洢�ṹ����
typedef struct lsNode{
    elementType data;
    struct lsNode *next;
}sNode, *linkedStack;

//��ʼ��ջ
void initialStacklS(sNode *& top){
    top =NULL;
}

//��ջ
void pushStacklS(sNode *&top, elementType x){
    sNode *s;
    s=new sNode;
    s->data=x;
    s->next=top;
    top=s;
}

//��ջ
void popStacklS(sNode *&top, elementType &x){
    sNode *u;
    if(top==NULL){
        cout << "ջ��!�޷���ջ!" << endl;
    }
    else{
        x=top->data;
        u=top;
        top=top->next;
        delete u;
    }
}
/*��ջ������������*/

/**  ��Ҫ����  **/
//3. ������ջʵ�ֽ�10������ת��Ϊ16��������
void radixChange10to16lS(){
    cout << "�������ת������(10����):" ;
    elementType x;
    cin >> x;

    sNode *R;
    initialStacklS(R);

    if(x==0){
        cout << "����ת����Ϊ(16����):0" << endl;
    }
    else{
            while(x){
            elementType temp=x%16;
            pushStacklS(R, temp);
            x=x/16;
            }
            cout << "��ջ�ɹ�!" << endl;

            cout << "����ת����Ϊ(16����):" ;
            while(R){
                elementType temp;
                popStacklS(R, temp);

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

//4. ����ƥ��(��һ���Ϸ�����ѧ���ʽ��˵�����еĸ���С���š�{������}������[������]����
//            ��(���͡�)��Ӧ���໥ƥ��ġ�����㷨�����ַ�����ʽ����ı��ʽS��
//            �ж����еĸ������Ƿ���ƥ��ġ�)
void bracketMatchlS(){
    cout << "��������ѧ���ʽ:" ;
    char str[40]={0};
    cin >> str;

    sNode *R;
    initialStacklS(R);

    bool sign=true;
    int c;
    for(int i=0; str[i]!=NULL && sign; i++){
        switch(str[i]){
        case '(':
        case '[':
        case '{':
            pushStacklS(R, str[i]);
            break;
        case ')':
            popStacklS(R, c);
            if(c!='('){
                sign=false;
            }
            break;
        case ']':
            popStacklS(R, c);
            if(c!='['){
                sign=false;
            }
            break;
        case '}':
            popStacklS(R, c);
            if(c!='{'){
                sign=false;
            }
            break;
        default:
            break;
        }
    }

    if(R==NULL && sign){
        cout << "�����ȷ!" << endl;
    }
    else{
        cout << "��Դ���!" << endl;
    }

    cout << "\n\n���뻻�м���" << endl;
    getchar();
}
