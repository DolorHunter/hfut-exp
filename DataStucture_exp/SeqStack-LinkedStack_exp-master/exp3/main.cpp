#include<iostream>
#include<cstdlib>
#include"linkedStack.h"
#include"seqStack.h"

using namespace std;

int main(int argc, char *argv[])
{
    do{
            system("CLS");
            cout << " # # # # Power by:�������ѧ�뼼��17-1�� ������# # # # # #" << endl;
            cout << "************************˳��ջ&��ջ***********************" << endl;
            cout << "*1. 10������ת��Ϊ16����(˳��ջ).                        *" << endl;
            cout << "*2. �ж����еĸ������Ƿ���ƥ��(˳��ջ).                  *" << endl;
            cout << "*3. 10������ת��Ϊ16����(��ջ).                          *" << endl;
            cout << "*4. �ж����еĸ������Ƿ���ƥ��(��ջ).                    *" << endl;
            cout << "*- - - - - - - - - - - - - - - - - - - - - - - - - - - - *" << endl;
            cout << "*0. �˳�.                                                *" << endl;
            cout << "**********************************************************" << endl;
            cout << "���������:";

            int iChose;
            cin >> iChose;

            cout << "\n" << endl;

            switch(iChose){
            case 0:
                return 0;
            case 1:
                radixChange10to16sStack(); break;
            case 2:
                bracketMatchsStack(); break;
            case 3:
                radixChange10to16lS(); break;
            case 4:
                bracketMatchlS(); break;
            default:
                break;
            }
    }while(getchar()!='0');

    return 0;
}
