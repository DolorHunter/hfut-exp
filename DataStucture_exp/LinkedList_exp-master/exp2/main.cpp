#include<iostream>
#include<cstdlib>
#include"linkList.h"

using namespace std;

int main(int argc, char *argv[])
{
    linkList L;
    initialList(L);
    do{
            system("CLS");
            cout << " # # # # Power by:�������ѧ�뼼��17-1�� ������# # # # # #" << endl;
            cout << "***************************������*************************" << endl;
            cout << "*1. β�巨����������.        |8. ɾ���ڵ�.               *" << endl;
            cout << "*2. ͷ�巨����������.        |9. ��������.               *" << endl;
            cout << "*3. ���ٵ�����.              |10.������ż.               *" << endl;
            cout << "*4. ��������.              |11.����ȡ��.               *" << endl;
            cout << "*5. ����Ԫ��(λ�ò���).      |12.ȥ��.                   *" << endl;
            cout << "*6. ����ڵ�.                |13.�ϲ�������.             *" << endl;
            cout << "*7. ����Ԫ��(ֵ����).        |                           *" << endl;
            cout << "*- - - - - - - - - - - - - - + - - - - - - - - - - - - - *" << endl;
            cout << "*0. �˳�.                    |-1.��ӡ������(������)      *" << endl;
            cout << "**********************************************************" << endl;
            cout << "���������:" <<endl;

            int iChose;
            cin >> iChose;

            cout << "\n" << endl;

            switch(iChose){
                case -1:
                    printList(L); break;
                case 0:
                    cout << "�˳�����." << endl;
                    return 0;
                case 1:
                    creatListR(L); break;
                case 2:
                    creatListH(L); break;
                case 3:
                    destoryList(&L); break;
                case 4:
                    listLength(L); break;
                case 5:
                    getElement(L); break;
                case 6:
                    listInsert(L); break;
                case 7:
                    listLocate(L); break;
                case 8:
                    listDelete(L); break;
                case 9:
                    setInsert(L); break;
                case 10:
                    seperateOEList(L); break;
                case 11:
                    intersecIncreList(); break;
                case 12:
                   deleteRepList(L); break;
                case 13:
                    mergeIncreList(); break;
                default:
                    break;
            }

    }while(getchar()!='0');     //˫�ر��� �˳�.

    return 0;
}
