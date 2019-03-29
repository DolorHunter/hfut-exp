//�޸İ�BiTree.h
//2019.01.03

#pragma once
#include<iostream>
#include<string.h>

typedef char elementType;

using namespace std;

//��������洢�ṹ����
typedef struct lBNode{
    elementType data;                   //�������Ԫ��
    struct lBNode *lChild, *rChild;     //���Һ���ָ��
}BiNode, *BiTree;

//1.1��ӡ��������ݹ��㷨
void PrtPreOrderTraverse(BiNode *T){
    if(T!=NULL){
        cout << T->data << "\t";               //��ӡ��֧��
        PrtPreOrderTraverse(T->lChild);        //�ݹ�����������������
        PrtPreOrderTraverse(T->rChild);        //�ݹ�����������������
    }
}

//1.2��ӡ��������ݹ��㷨
void PrtInOrderTraverse(BiNode *T){
    if(T!=NULL){
        PrtInOrderTraverse(T->lChild);     //�ݹ�����������������
        cout << T->data << "\t";           //��ӡ��֧��
        PrtInOrderTraverse(T->rChild);     //�ݹ�����������������
    }
}

//1.3��ӡ��������ݹ��㷨
void PrtPostOrderTraverse(BiNode *T){
    if(T!=NULL){
        PrtPostOrderTraverse(T->lChild);   //�ݹ���ú������������
        PrtPostOrderTraverse(T->rChild);   //�ݹ���ú������������
        cout << T->data << "\t";           //��ӡ��ӡ��֧��
    }
}

//1.��ӡ�������������ֱ�����
void PrtBinaryTree(BiNode *T){
    cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��1.1 ��������ݹ��㷨                                    ��" << endl;
    cout << "��1.2 ��������ݹ��㷨                                    ��" << endl;
    cout << "��1.3 ��������ݹ��㷨                                    ��" << endl;
    cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "�������ӡ����:" ;
    int iRules;
    cin >> iRules;
    cin.get();

    switch(iRules){
        case 1:
            PrtPreOrderTraverse(T); break;
        case 2:
            PrtInOrderTraverse(T); break;
        case 3:
            PrtPostOrderTraverse(T); break;
        default:
            break;
    }
}

//2.����㷨�������������������и�����ֵ��������Ӧ�Ĳ����
void PrtInTraverseLevel(BiNode *T){
	static int i=0;
	if(T!=NULL){
		i++;
		PrtInTraverseLevel(T->lChild);
		cout << T->data << "�Ĳ���Ϊ" << i << endl;
		PrtInTraverseLevel(T->rChild);
		i--;
	}
}

//3.��������ĸ߶�
int BiTreeDepth(BiNode *T){
    int m,n;
    if(T==NULL){
        return 0;
    }
    else{
        m=BiTreeDepth(T->lChild);
        n=BiTreeDepth(T->rChild);
        return ((m>n)?m:n)+1;
    }
}
void PrtBiTreeDepth(BiNode *T){
    cout << "�������߶�Ϊ" << BiTreeDepth(T) << endl;
}

//4.��������Ľ����
void GetNodeNumber(BiNode *T,int &iN){
    if(T!=NULL){
        GetNodeNumber(T->lChild, iN);
        iN++;
        GetNodeNumber(T->rChild, iN);
    }
}
void PrtGetNodeNumber(int &iN){
    cout << "�����������Ϊ" << iN << endl;
    iN=0;                                              //���ú����
}

//5.���������Ҷ�ӽ����
void InTraverseN0(BiNode *T, int &iN0){
    if(T!=NULL){
        InTraverseN0(T->lChild, iN0);                  //�ݹ�����������������
        if(T->lChild==NULL && T->rChild==NULL){        //����֧�����Ϊ0, iN0++
            iN0++;
        }
        InTraverseN0(T->rChild, iN0);                  //�ݹ�����������������
    }
}
void PrtInTraverseN0(int &iN0){
    cout << "��������Ҷ�ӽ����Ϊ" << iN0 << endl;
    iN0=0;                                             //���ú����
}

//6.��������Ķ�Ϊ2�Ľ����
void InTraverseN2(BiNode *T, int &iN2){
    if(T!=NULL){
        InTraverseN2(T->lChild, iN2);                  //�ݹ�����������������
        if(T->lChild!=NULL && T->rChild!=NULL){ //����֧�����Ϊ2, iN2++
            iN2++;
        }
        InTraverseN2(T->rChild, iN2);                  //�ݹ�����������������
    }
}
void PrtInTraverseN2(int &iN2){
    cout << "�������Ķ�Ϊ2�Ľ����Ϊ" << iN2 << endl;
    iN2=0;                                             //���ú����
}

//7.��������һ��Ԫ��x�����丸�ڵ㡢�ֵܽ�㡢�ӽ���ֵ��������ʱ������Ӧ��ʾ��Ϣ��
//  ���ֵܽ��ͺ��ӽ�㣬����ʱҪ��ȷָ�������ֵܡ����ӡ����ֵܻ��Һ���

//�ҵ�xԪ�����ڲ��(�ش�nodeDepth��������ֵܽ��)(��������)
bool InTraverseOneDataDepth(BiNode *T, char x, int &nodeDepth){
    if(T==NULL){
        return false;
    }
    else{
        if(InTraverseOneDataDepth(T->lChild, x, nodeDepth)){
            nodeDepth++;
            return true;
        }
        if(T->data==x){
            return true;
        }
        if(InTraverseOneDataDepth(T->rChild, x, nodeDepth)){
            nodeDepth++;
            return true;
        }
    }
}
//�ҵ�x���ڵ�
void InOrderTraverseXFather(BiNode *T, char x, int &nodeDepth){
    if(T!=NULL){
        InOrderTraverseXFather(T->lChild, x, nodeDepth);
        if(T->lChild!=NULL && T->lChild->data==x){
            cout << "Ԫ��" << x << "�ĸ��ڵ�Ϊ" << T->data << "�����еĲ��Ϊ" << nodeDepth-1 << endl;
        }
        if(T->rChild!=NULL && T->rChild->data==x){
            cout << "Ԫ��" << x << "�ĸ��ڵ�Ϊ" << T->data << "�����еĲ��Ϊ" << nodeDepth-1 << endl;
        }
        InOrderTraverseXFather(T->rChild, x, nodeDepth);
    }
}
//�ҵ�x�ӽ��
void InOrderTraverseXSon(BiNode *T, char x, int &nodeDepth){
    if(T!=NULL){
        InOrderTraverseXSon(T->lChild, x, nodeDepth);
        if(T->data==x){
            if(T->lChild!=NULL){
                cout << "Ԫ��" << x << "������Ϊ:" << T->lChild->data << ".�����еĲ��Ϊ" << nodeDepth+1 << "." << endl;
            }
            else{
                cout << "Ԫ��" << x << "û������." << endl;
            }
            if(T->rChild!=NULL){
                cout << "Ԫ��" << x << "���Һ���Ϊ:" << T->rChild->data << ".�����еĲ��Ϊ" << nodeDepth+1 << "." << endl;
            }
            else{
                cout << "Ԫ��" << x << "û���Һ���." << endl;
            }
        }
        InOrderTraverseXSon(T->rChild, x, nodeDepth);
    }
}
//�ҵ�x�ֵܽ��
void InOrderTraverseXBrother(BiNode *T, char x, int &nodeDepth){
    static int iDepth=0;
    if(T!=NULL){
        iDepth++;
        InOrderTraverseXBrother(T->lChild, x, nodeDepth);
        if(iDepth==nodeDepth && T->data!=x){
        cout << "Ԫ��" << x << "���ֵܽ��Ϊ" << T->data << "�����еĲ��Ϊ" << nodeDepth << "." << endl;
        }
        InOrderTraverseXBrother(T->rChild, x, nodeDepth);
        iDepth--;
    }
}
//7.��ˮ��(�����ú���)
int InTraverseGetXAllInf(BiNode *T){
    cout << "�����������Ԫ�ص�ֵ:";
    char x;
    cin >> x;
    cin.get();

    int nodeDepth=1;                                   //���ڱ���x�Ĳ�����Ϣ

    if(T==NULL){
        return 0;
    }
    else{
        if(!InTraverseOneDataDepth(T, x, nodeDepth)){  //û���ҵ�x���
            cout << "�������ȫ������δ�ҵ�Ԫ��" << x << "!" << endl;
        }
        else{
            InOrderTraverseXFather(T, x, nodeDepth);              //�ҵ�x�ĸ����
            InOrderTraverseXSon(T, x, nodeDepth);                 //�ҵ�x���ӽ��
            InOrderTraverseXBrother(T, x, nodeDepth);             //�ҵ�x���ֵܽ��
        }
    }
    cout << "��ˮ�����������!" << endl;
}


//8.��������һ��Ԫ��x�����������еĲ�Ρ�������ʱ������Ӧ��ʾ��Ϣ
//�ҵ�xԪ�����ڲ��(���ش�nodeDepth)
bool InTraverseXDepth(BiNode *T, char x, int nodeDepth){
    if(T==NULL){
        return false;
    }
    else{
        if(InTraverseXDepth(T->lChild, x, nodeDepth+1)){
            return true;
        }
        if(T->data==x){
            cout << "Ԫ��" << x << "�����еĲ��Ϊ" << nodeDepth << endl;
            return true;
        }
        if(InTraverseXDepth(T->rChild, x, nodeDepth+1)){
            return true;
        }
    }
}
void findXDepth(BiNode *T){
    cout << "�����������Ԫ�ص�ֵ:";
    char x;
    cin >> x;
    cin.get();
    int nodeDepth=1;
    if(!InTraverseXDepth(T, x, nodeDepth)){
        cout << "�������ȫ������δ�ҵ�Ԫ��" << x << "!" << endl;
    }
}

//9.����˳��ʽ�洢�������еĶ�����ת��Ϊ����������ʽ����������Ҫ��չΪ��ȫ������
//ת������ͬfile.h�еĺ���CreatBiTreeFromArray(), Ϊ�˱����ظ�����˴�ʡȥ�˺���
//      bool CreatBiTreeFromArray(BiNode *&pBT, char (&strLine)[100][3], int &nLen, int &nRow)

//10.������������ÿ���������Һ���ָ���ֵ����������������Ϊ����������������Ϊ������
void ExchangeSon(BiTree &T)
{
	if(!(T->lChild==NULL && T->rChild==NULL)){  //��֧���к���
        BiTree temp=T->lChild;                  //������ʱ����temp�洢lChild
		T->lChild=T->rChild;
		T->rChild=temp;
	}
	//������������������������Ϊ�գ����������Ѱ�ҿ��Խ����Ľ�㣻
	if(T->lChild!=NULL){
        ExchangeSon(T->lChild);
	}
	if(T->rChild!=NULL){
        ExchangeSon(T->rChild);
	}
}

//������������
void DestoryBiTree(BiNode *pBT){
    if(pBT!=NULL){
        DestoryBiTree(pBT->lChild);
        DestoryBiTree(pBT->rChild);
        delete pBT;
    }
}
