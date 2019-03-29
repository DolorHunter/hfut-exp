#include<cstdlib>
#include<iostream>
#include"basis.h"
#include"search.h"

using namespace std;

int main(int argc, char argv[]){
    sList L;
    bstNode bsT;
    AVLTree avlT;
	bool sign = true;
	do {
		system("CLS");
		cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "��         Power by�������ѧ�뼼��17-1�� ������          ��" << endl;
        cout << "��                       ����ʵ��                         ��" << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "�� 1. ���ֲ��Ҳ���ӡ�����бȽϵ�Ԫ��.                     ��" << endl;
        cout << "�� 2. ������������ѭ�������㹹������������.             ��" << endl;
        cout << "�� 3. �����������в���ָ��ֵ�Ľ��.                       ��" << endl;
        cout << "�� 4. ������������ɾ���ض�ֵ�Ľ��.                       ��" << endl;
        cout << "�� 5. ����һ��ƽ��Ķ����������������.                   ��" << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "��0. �˳�.                                                ��" << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "���������:";

		int iChose;
		cin >> iChose;
		switch (iChose){
		case 0:
			sign=false;
			break;
		case 1:
		    initialSearchList(L);
            binSearch(L);
            _pause();
            sign=true;
			break;
		case 2:
            bstCreat(&bsT);
            cout << "��ӡ����������:";
            prtBinarySortTree(&bsT);
			_pause();
			sign=true;
			break;
		case 3:
            bstSearch(&bsT);
			_pause();
			sign=true;
			break;
		case 4:
            bstDeleteNode(&bsT);
            cout << "��ӡɾ����Ķ���������:";
            prtBinarySortTree(&bsT);
			_pause();
			sign=true;
			break;
		case 5:
		    creatAVLFromArray(&avlT);
		    cout << "��ӡAVL��:";
            prtAVLTree(avlT);
			_pause();
			sign=true;
			break;

		default:
		    sign=true;
			break;
		}
	}while(sign);

	cout << "\n������ֹ!" << endl;

	destoryBinarySortTree(&bsT);
	destoryAVLTree(avlT);

	return 0;
}
