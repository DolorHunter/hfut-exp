#pragma once
#include<cstdlib>
#include"basis.h"

using namespace std;

int main(int argc, char *argv[])
{
    seqQueue sQ;
    initialSeqQueue(sQ);
    linkQueue lQ;
    initialLinkedQueue(lQ);

    elementType x;

    do{
            system("CLS");
            cout << " # # # # Power by:�������ѧ�뼼��17-1�� ������# # # # # #" << endl;
            cout << "********************ѭ��˳�����&������*******************" << endl;
            cout << "*1. ��ʼ������.             |9. ��ʼ������.              *" << endl;
            cout << "*2. �ж��Ƿ�ӿ�.           |10.�ж��Ƿ�ӿ�.            *" << endl;
            cout << "*3. �ж��Ƿ����.           |11.�ж��Ƿ����.            *" << endl;
            cout << "*4. ���.                   |12.���.                    *" << endl;
            cout << "*5. ����.                   |13.����.                    *" << endl;
            cout << "*6. ȡ��ͷԪ��.             |14.ȡ��ͷԪ��.              *" << endl;
            cout << "*7. �����Ԫ�ظ���.         |15.�����Ԫ�ظ���.          *" << endl;
            cout << "*8. ����ż���㷨.           |16.����ż���㷨.            *" << endl;
            cout << "*- - - - - - - - - - - - - -+- - - - - - - - - - - - - - *" << endl;
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
                initialSeqQueue(sQ); break;
            case 2:
                seqQueueEmpty(sQ); break;
            case 3:
                seqQueueFull(sQ); break;
            case 4:
                seqEnQueue(sQ); break;
            case 5:
                seqOutQueue(sQ, x); break;
            case 6:
                seqQueueFront(sQ, x); break;
            case 7:
                seqQueueLength(sQ); break;
            case 8:
                seqQueueOddInEvenOut(sQ); break;
            case 9:
                initialLinkedQueue(lQ); break;
            case 10:
                linkedQueueEmpty(lQ); break;
            case 11:
                linkedQueueFull(); break;
            case 12:
                linkedEnQueue(lQ); break;
            case 13:
                linkedOutQueue(lQ, x); break;
            case 14:
                linkedQueueFront(lQ, x); break;
            case 15:
                linkedQueueLength(lQ); break;
            case 16:
                linkedOddInEvenOut(lQ); break;

            default:
                break;
            }
    }while(getchar()!='0');

    return 0;
}
