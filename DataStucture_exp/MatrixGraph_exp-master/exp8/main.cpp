#include<cstdlib>
#include<iostream>
#include"basis.h"
#include"file.h"
#include"createGrpAdjMatrix.h"
#include"graph.h"

using namespace std;

int main(int argc, char *argv[])
{
    char fileName[20];
    Graph G;
    csNode *T;
    int topoList[MaxVerNum+1];
	bool _continue = true;
	do {
		system("CLS");
		cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "��         Power by:�������ѧ�뼼��17-1�� ������         ��" << endl;
        cout << "��                        ͼʵ��                          ��" << endl;
        cout << "���������������������������������������������������������Щ���������������������������������������������������������" << endl;
        cout << "�� 1. ��ӡͼ�����ֱ�����.    �� 6. Kruskal�㷨����С������.��" << endl;
        cout << "�� 2. ͼ�Ļ���Ŀ.            �� 7. Dijkstra�㷨�����·��. ��" << endl;
        cout << "�� 3. ������ȱ�������������.�� 8. Floyd�㷨�����·��.    ��" << endl;
        cout << "�� 4. ������ȱ�������������.�� 9. ��������.               ��" << endl;
        cout << "�� 5. Prim�㷨����С������.  �� 10.AOE���ؼ�·��.          ��" << endl;
        cout << "���������������������������������������������������������ة���������������������������������������������������������" << endl;
        cout << "��0. �˳�.                                                ��" << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "���������:";

		int iChose;
		cin >> iChose;
		cin.get();

		switch (iChose) {
		case 0:
			_continue = false;
			break;
		case 1:
		    openFile(fileName);
		    CreateGrpFromFile(fileName, G);
            AdjMatrixDFSTraverse(G);
            AdjMatrixBFSTraverse(G);
            _pause();
            _continue=true;
			break;
		case 2:
		    openFile(fileName);
		    CreateGrpFromFile(fileName, G);
		    ArcNum(G);
			_pause();
            _continue=true;
			break;
		case 3:
		    openFile(fileName);
		    CreateGrpFromFile(fileName, G);
            DFSTraverseCreatTree(G, T);
			_pause();
            _continue=true;
			break;
		case 4:
		    openFile(fileName);
		    CreateGrpFromFile(fileName, G);
		    BFSTraverseCreatTree(G, T);
			_pause();
            _continue=true;
			break;
		case 5:
		    openFile(fileName);
		    CreateGrpFromFile(fileName, G);
		    Prim(G);
			_pause();
            _continue=true;
			break;
		case 6:
		    openFile(fileName);
		    CreateGrpFromFile(fileName, G);
		    Kruskal(G);
			_pause();
            _continue=true;
			break;
		case 7:
		    openFile(fileName);
		    CreateGrpFromFile(fileName, G);
            Dijkstra(G);
		    _pause();
            _continue=true;
			break;
        case 8:
            openFile(fileName);
		    CreateGrpFromFile(fileName, G);
		    Floyd(G);
		    _pause();
            _continue=true;
			break;
        case 9:
            openFile(fileName);
		    CreateGrpFromFile(fileName, G);
            TopologicalSort(G, topoList);
		    _pause();
            _continue=true;
			break;
        case 10:
            openFile(fileName);
		    CreateGrpFromFile(fileName, G);
		    KeyPath(G, topoList);
		    _pause();
            _continue=true;
			break;

        case 11://��ӡͼ(����)
            openFile(fileName);
		    CreateGrpFromFile(fileName, G);
            printGraph(G);
            _pause();
            _continue=true;
            break;

		default:
			break;
		}
	}while(_continue);

	cout << "\n������ֹ." << endl;

	return 0;
}
