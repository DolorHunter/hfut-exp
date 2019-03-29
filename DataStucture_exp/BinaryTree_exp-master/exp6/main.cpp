#include<cstdlib>
#include<iostream>
#include"BiTree.h"
#include"file.h"
#include"basis.h"

using namespace std;

int main(int argc, char *argv[])
{
    BiTree T;
    char strLine[100][3];
    int nArrLen;
    char fileName[20];
    int nRow;
    int iN=0, iN0=0, iN2=0;

    bool sign=true;
    do{
            system("CLS");
            cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
            cout << "��         Power by:�������ѧ�뼼��17-1�� ������         ��" << endl;
            cout << "��                       ������ʵ��                       ��" << endl;
            cout << "���������������������������������������������������������Щ���������������������������������������������������������" << endl;
            cout << "�� 1. ��ӡ�����������ֱ�����.�� 6. ������N2�����.         ��" << endl;
            cout << "�� 2. ������������ֵ�����.�� 7. ����Ԫ�ز�ˮ��.         ��" << endl;
            cout << "�� 3. �������߶�.            �� 8. ����Ԫ�ز���.         ��" << endl;
            cout << "�� 4. �����������.          �� 9. ������ת��Ϊ��������.   ��" << endl;
            cout << "�� 5. ������Ҷ�ӽ����.      �� 10.�������Һ���.           ��" << endl;
            cout << "���������������������������������������������������������ة���������������������������������������������������������" << endl;
            cout << "��0. �˳�.                                                ��" << endl;
            cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
            cout << "���������:";

            int iChose;
            cin >> iChose;

            switch(iChose){
            case 0:
                sign=false; break;
            case 1:
                openFile(fileName);
                CreatBiTree(T, fileName, strLine, nArrLen, nRow);
                PrtBinaryTree(T);
                _pause();
                break;
            case 2:
                openFile(fileName);
                CreatBiTree(T, fileName, strLine, nArrLen, nRow);
                PrtInTraverseLevel(T);
                _pause();
                break;
            case 3:
                openFile(fileName);
                CreatBiTree(T, fileName, strLine, nArrLen, nRow);
                PrtBiTreeDepth(T);
                _pause();
                break;
            case 4:
                openFile(fileName);
                CreatBiTree(T, fileName, strLine, nArrLen, nRow);
                GetNodeNumber(T, iN);
                PrtGetNodeNumber(iN);
                _pause();
                break;
            case 5:
                openFile(fileName);
                CreatBiTree(T, fileName, strLine, nArrLen, nRow);
                InTraverseN0(T, iN0);
                PrtInTraverseN0(iN0);
                _pause();
                break;
            case 6:
                openFile(fileName);
                CreatBiTree(T, fileName, strLine, nArrLen, nRow);
                InTraverseN2(T, iN2);
                PrtInTraverseN2(iN2);
                _pause();
                break;
            case 7:
                openFile(fileName);
                CreatBiTree(T, fileName, strLine, nArrLen, nRow);
                InTraverseGetXAllInf(T);
                _pause();
                break;
            case 8:
                openFile(fileName);
                CreatBiTree(T, fileName, strLine, nArrLen, nRow);
                findXDepth(T);
                _pause();
                break;
            case 9:
                openFile(fileName);
                nRow=0;           //�кŹ���(�Զ��������Ż���CreatBiTree()��)
                ReadFileToArray(fileName, strLine, nArrLen);
                CreatBiTreeFromArray(T, strLine, nArrLen, nRow);
                PrtInOrderTraverse(T);
                _pause();
                break;
            case 10:
                openFile(fileName);
                CreatBiTree(T, fileName, strLine, nArrLen, nRow);
                ExchangeSon(T);
                PrtInOrderTraverse(T);
                _pause();
                break;

            default:
                break;
            }
    }while(sign);

    cout << "\n������ֹ." << endl;

    DestoryBiTree(T);

    return 0;
}
