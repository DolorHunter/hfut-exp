#include<cstdlib>
#include<iostream>
#include"basis.h"
#include"sort.h"

using namespace std;

int main(int argc, char argv[]){
    SqList L;
    int iSwap=0, iCmp=0;
	bool sign = true;
	do {
		system("CLS");
		cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "��         Power by�������ѧ�뼼��17-1�� ������          ��" << endl;
        cout << "��                       ����ʵ��                         ��" << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "�� 1. ��������ȽϺͽ���Ԫ�صĴ���.                       ��" << endl;
        cout << "�� 2. mod3����.                                           ��" << endl;
        cout << "�� 3. ��ͬ������ϣ�������㷨.                             ��" << endl;
        cout << "�� 4. ��̬��ʾ��������.                                   ��" << endl;
        cout << "�� 5. ��̬��ʾ�������㷨.                                 ��" << endl;
        cout << "�� 6. ��·�鲢������.                                     ��" << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "��0. �˳�.                                                ��" << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "���������:";

		int iChose;
		cin >> iChose;
		cin.get();
		switch (iChose){
		case 0:
			sign=false;
			break;
		case 1:
		    iCmp=0, iSwap=0;//���ü�������
		    QuickSort(&L, iSwap, iCmp);
		    cout << "\n�����������ս��:" << endl;
            prtsqList(&L);
            cout << "\n�Ƚ�Ԫ�صĴ���:" << iCmp << endl;
            cout << "����Ԫ�صĴ���:" << iSwap << endl;
            _pause();
            sign=true;
			break;
		case 2:
            mod3Sort(&L);
            cout << "\nmod3�������ս��:" << endl;
            prtsqList(&L);
			_pause();
			sign=true;
			break;
		case 3:
		    //���ϴ�ӡ��ϣ������
		    ShellSort(&L);
		    _pause();
			sign=true;
			break;
		case 4:
		    QuickSort(&L, iSwap, iCmp);
		    cout << "\n�����������ս��:" << endl;
            prtsqList(&L);
			_pause();
			sign=true;
			break;
		case 5:
		    heapSort(&L);
		    cout << "\n���������ս��:" << endl;
            prtsqList(&L);
			_pause();
			sign=true;
			break;
        case 6:
            MergeSort(&L);
            cout << "��·�鲢�����:" ;
            prtsqList(&L);
			_pause();
			sign=true;
			break;

		default:
		    sign=true;
			break;
		}
	}while(sign);

	cout << "\n������ֹ!" << endl;

	return 0;
}
