#include<cstdlib>
#include<iostream>
#include"basis.h"
#include"file.h"
#include"forest.h"

using namespace std;

int main()
{
    char fileName[20];
    pTree T;
    csTree p;
	p=new csNode;

	bool sign = true;
	do {
		system("CLS");
		cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "��         Power by:�������ѧ�뼼��17-1�� ������         ��" << endl;
        cout << "��                     ����ɭ��ʵ��                       ��" << endl;
        cout << "���������������������������������������������������������Щ���������������������������������������������������������" << endl;
        cout << "�� 1. ��ӡɭ�ֵ����ֱ�����.  �� 5. ɭ�ֵĶ�.               ��" << endl;
        cout << "�� 2. ɭ�ֵĸ߶�.            �� 6. �����������ֵ�����. ��" << endl;
        cout << "�� 3. ɭ�ֽ������.          �� 7. ���������ʾ����.     ��" << endl;
        cout << "�� 4. ɭ��Ҷ������.          ��                            ��" << endl;
        cout << "���������������������������������������������������������ة���������������������������������������������������������" << endl;
        cout << "��0. �˳�.                                                ��" << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "���������:";

		int iChose;
		cin >> iChose;

		switch (iChose) {
		case 0:
			sign = false;
			break;
		case 1:
            openFile(fileName);
            initialTree(T);
            createTreeFromFile(fileName, T);
            cout << "\n�������Ϊ:";
			preTraverse(T);
			cout << "\n�������Ϊ:";
			postTraverse(T);
			cout << "\n��α���Ϊ:";
			levelTraverse(T);
            _pause();
			break;
		case 2:
            openFile(fileName);
            initialTree(T);
            createTreeFromFile(fileName, T);
            cout << "ɭ�ֵĸ߶�Ϊ" << height(T) << "." << endl;
			_pause();
			break;
		case 3:
            openFile(fileName);
            initialTree(T);
            createTreeFromFile(fileName, T);
            cout << "ɭ�ֵĽ����Ϊ" << T.n << "." << endl;
			_pause();
			break;
		case 4:
            openFile(fileName);
            initialTree(T);
            createTreeFromFile(fileName, T);
            cout << "ɭ�ֵ�Ҷ����Ϊ" << leafNode(T) << "." << endl;
			_pause();
			break;
		case 5:
		    openFile(fileName);
		    initialTree(T);
            createTreeFromFile(fileName, T);
            cout << "ɭ�ֵĶ�Ϊ" << degree(T) << "." << endl;
			_pause();
			break;
		case 6:
		    openFile(fileName);
		    initialTree(T);
            createTreeFromFile(fileName, T);
            preTraverseNode(T);
			_pause();
			break;
		case 7:
		    openFile(fileName);
		    initialTree(T);
            createTreeFromFile(fileName, T);
            createCsTree(p,T);
            outgList(p);
			_pause();
			break;

		default:
			break;
		}
	}while(sign);

	cout << "\n������ֹ." << endl;

	return 0;
}
