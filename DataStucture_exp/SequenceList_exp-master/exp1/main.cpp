#include<iostream>
#include"seqList.h"

using namespace std;

int main(int argc, char *argv[]){
    seqList L;
    initialList(&L);

    do{
            system("CLS");
            cout << " # # # # Power by:�������ѧ�뼼��17-1�� ������# # # # # #" << endl;
            cout << "***************************˳���*************************" << endl;
            cout << "*0. ��ʼ��˳���.           |5. ��������.                *" << endl;
            cout << "*1. ����˳���.             |6. �ֽ���ż.                *" << endl;
            cout << "*2. ����Ԫ��.               |7. ��ȡ����Ԫ��.            *" << endl;
            cout << "*3. ����ڵ�.               |8. ȥ��.                    *" << endl;
            cout << "*4. ɾ���ڵ�.               |9. �˳�.                    *" << endl;
            cout << "*- - - - - - - - - - - - - -+- - - - - - - - - - - - - - *" << endl;
            cout << "*-1.��ӡ˳���(������)      |-2.����ͣ��ӡ(������)       *" << endl;
            cout << "**********************************************************" << endl;
            cout << "���������:" <<endl;
            int iChose;
            cin >> iChose;

            cout << "\n" << endl;

            switch(iChose){
                case 0:
                    initialList(&L); break;
                case 1:
                    buildList(&L); break;
                case 2:
                    searchList(&L); break;
                case 3:
                    insertList(&L); break;
                case 4:
                    deleteList(&L); break;
                case 5:
                    increinseList(&L); break;
                case 6:
                    seperateOEList(&L); break;
                case 7:
                    mixIncreList(); break;
                case 8:
                    delRepList(&L); break;
                case 9:
                    cout << "�˳�����." << endl;
                    return 0;
                case -1:
                    printList(&L); break;
                case -2:
                    prtNpauseList(&L); break;
                default:
                    break;
            }

    }while(getchar()!='9');

    return 0;
}
