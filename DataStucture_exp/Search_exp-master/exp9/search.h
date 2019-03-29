#pragma once
#define MAXLEN 1024
#define LH 1
#define EH 0
#define RH -1

typedef int elementType;
typedef int keytype;


using namespace std;

    //���ֲ��ұ�Ľ��ṹ
typedef struct searchList_2{
    elementType key;                         //���ֲ��ұ�Ľ���־
    keytype x;                               //���ֲ��ұ�Ľ������(��ʵ����ʱ��ʹ�ô˲���)
}sLNode;
    //���ֲ��ұ�ṹ
typedef struct searchList_1{
    sLNode str[MAXLEN];                      //���ֲ��ұ������
    int iLen;                                //���ֲ��ұ�ĳ���
}sList;

    //�����������Ľ��ṹ
typedef struct biSortTreeNode{
    elementType key;                         //�����������Ľ������
    struct biSortTreeNode *lChild, *rChild;  //�����������Ľ�����Һ���
}bstNode, *bstTree;

/*
    //����ƽ��������
typedef enum AVL_FacNum{
    LH=1;
    EH=0;
    RH=-1;
}bh_t;
*/
    //����ƽ�������(AVL)
typedef struct AdelsonVelskyLandisTreeNode{
    elementType key;
    int bf;                                 //ƽ��ֵ
    struct AdelsonVelskyLandisTreeNode *lChild, *rChild;
}*AVLTree, AVLNode;


//��ʼ�����ֲ��ұ�
void initialSearchList(sList &L){
    L.iLen=0;                                   //���ñ�Ϊ0
    L.str[MAXLEN]={0};                          //���ñ�Ϊ0
}

//��ʼ������������
void initialBinarySortTree(bstNode *T){
    T=NULL;                                     //������Ϊ��
}

//�ݹ��㷨��ӡ����������
void prtBinarySortTree(bstNode *T){
    if(T!=NULL){
        prtBinarySortTree(T->lChild);
        cout << T->key << "\t" ;
        prtBinarySortTree(T->rChild);
    }
}
//�ݹ��㷨��ӡAVL��
void prtAVLTree(AVLTree T){
    if(T!=NULL){
        prtAVLTree(T->lChild);
        cout << T->key << "\t" ;
        prtAVLTree(T->rChild);
    }
}

//���ٶ���������
void destoryBinarySortTree(bstNode *T){
    if(T!=NULL){
        destoryBinarySortTree(T->lChild);
        destoryBinarySortTree(T->rChild);
        delete T;
    }
}

//����AVL��
void destoryAVLTree(AVLTree T){
    if(T!=NULL){
        destoryAVLTree(T->lChild);
        destoryAVLTree(T->rChild);
        delete T;
    }
}

//1. ���ֲ��Ҳ���ӡ�����бȽϵ�Ԫ��.
int bin_search(sList &L, elementType x){
    int mid, low=0, high=L.iLen-1;   //��ʼ����������
    while(low<=high){
        mid=(low+high)/2;
        if(x==L.str[mid].key){
            cout << "\n�ҵ�Ԫ��:" << L.str[mid].key << endl;
            return mid;             //���ز���ֵ��λ��
        }
        else if(x<L.str[mid].key){
            cout << "\t�Ƚ�Ԫ��:" << L.str[mid].key << endl;
            high=mid-1;
        }
        else{
            cout << "\t�Ƚ�Ԫ��:" << L.str[mid].key << endl;
            low=mid+1;
        }
    }
    cout << "\nû���ҵ���Ԫ��!" << endl;
    return -1;                      //���ز���ʧ�ܱ�־
}
void binSearch(sList &L){
    cout << "\n���ڵ����Զ������ݱ�.." << endl;
    //�����Զ������ݱ�L.str[].key={5, 10, 15, ...., 500};
    for(int i=1; i<100; i++){
        L.str[i].key=i*5;
        cout << i*5 << "\t" ;
        L.iLen++;
    }
    cout << "\n�Զ������ݱ���ɹ�!" << endl;
    cout << "������Ҫ���ҵ�Ԫ��:" ;
    elementType x;
    cin >> x;
    cin.get();
    bin_search(L, x);
}

//2. ������������ѭ�������㹹������������.
void bst_insert(bstNode *&T, bstNode *S){//��ָ��S��ָ�����뵽����������T��
    if(T==NULL)
        T=S;//���뵽����ʱ,�������Ϊ���ڵ�
    else if(S->key < T->key)
        bst_insert(T->lChild, S);//���뵽T->lChild
    else
        bst_insert(T->rChild, S);//���뵽T->lChild
}
void bstCreat(bstNode *T){
    elementType x;
    cout << "���������Ԫ��(����9999�˳�):" ;
    cin >> x;
    cin.get();
    while(x!=9999){
        bstNode *S=new bstNode;
        S->key=x;
        S->lChild=NULL;
        S->rChild=NULL;
        bst_insert(T, S);
        cin >> x;
    }
}

//3. �����������в���ָ��ֵ�Ľ��.
int bst_search(bstNode *T, elementType x){
    bstNode *P=T;
    while(P!=NULL){
        if(x==P->key){
            cout << "�ҵ�Ԫ��:" << P->key << endl;
            return P->key;
        }
        else if(x<P->key){
            P=P->lChild;
        }
        else{
            P=P->rChild;
        }
    }
    cout << "û���ҵ���Ԫ��!" << endl;
    return -1;
}
void bstSearch(bstNode *T){
    elementType x;
    cout << "�����������Ԫ��:" ;
    cin >> x;
    bst_search(T, x);
}

//4. ������������ɾ���ض�ֵ�Ľ��.
void bst_deleteNode(bstNode *T, elementType x){
	bstNode *p=T;       //�������ָ��
	bstNode *q;         //˫�׽��ָ��
	elementType temp;
	while(p!=NULL && p->key!=x){
		q=p;
		if(x<p->key)
			p=p->lChild ;
		else
			p=p->rChild ;
	}
	if(p==NULL)
		cout << "Ԫ��" << x << "������!" << endl;
	else {
		//���1:���p��˫�׽��Ϊq, ��pΪҶ�ӽ��, ��ֱ�ӽ���ɾ��
		if(p->lChild==NULL && p->rChild==NULL){
			if(p==q->lChild)//p��q����
				q->lChild=NULL;
			if(p==q->rChild)//p��q�Һ���
				q->rChild=NULL;
			delete p;
		}
		//���2:���p��˫�׽��Ϊq, ��pֻ����������ֻ��������,
		//��ɽ�p����������������ֱ�Ӹ�Ϊ��˫�׽��q����������������.
		else if(p->rChild==NULL && p->lChild!=NULL){//pֻ��������
			if(p==q->lChild)//p��q����
				q->lChild=p->lChild;
			else if(p==q->rChild)//p��q�Һ���
				q->rChild=p->lChild;
			delete p;
		}
		else if(p->lChild==NULL && p->rChild!=NULL){//pֻ��������
			if( p==q->lChild )//p��q����
				q->lChild=p->rChild;
			if( p==q->rChild )//p��q�Һ���
				q->rChild=p->rChild;
			delete p;
		}
		//���3:���p��˫�׽��Ϊq, ��p��������������������.
		//������ʹ��ֱ��ǰ����Ҳ����ֱ�Ӻ�̣�
		else if(p->lChild!=NULL && p->rChild!=NULL ){
				bstNode *s, *sParent;
				sParent=p;
				s=sParent->lChild ;
				while(s->rChild!=NULL){//�ҵ�p��ֱ��ǰ��
					sParent=s;
					s=s->rChild ;
				}
				temp=s->key ;
				bst_deleteNode(T, temp);
				p->key=temp;
		}
	}
}
void bstDeleteNode(bstNode *T){
    elementType x;
    cout << "�������ɾ��Ԫ��:" ;
    cin >> x;
    bst_deleteNode(T, x);
}

//5. ����һ��ƽ��Ķ����������������.
//��������ת
void R_Rotate(AVLTree *T){
	AVLTree p;
	p=(*T)->lChild;
	(*T)->lChild=p->rChild;
	p->rChild=(*T);
	(*T)=p;
}
//��������ת
void L_Rotate(AVLTree *T){
	AVLTree p;
	p=(*T)->rChild;
	(*T)->rChild=p->lChild;
	p->lChild=(*T);
	(*T)=p;
}
//������������ƽ����ת
void LeftBalance(AVLTree *T)
{
	AVLTree lc=(*T)->lChild;
	AVLTree rd=lc->rChild;
	//�жϽ������ı���ת
	switch (lc->bf){
		case LH:
			(*T)->bf=lc->bf=EH;
			R_Rotate(T);
			break;
		case RH:
			switch (rd->bf){
			case LH:
				(*T)->bf = RH;
				lc->bf=EH;
				break;
			case EH:
				(*T)->bf=lc->bf=EH;
				break;
			case RH:
				(*T)->bf=EH;
				lc->bf=LH;
				break;
			}
		rd->bf=EH;
		L_Rotate(&((*T)->lChild));
		R_Rotate(T);
		break;
	}
}
//������������ƽ����ת
void RightBalance(AVLTree *T){
	AVLTree rc=(*T)->rChild;
	AVLTree ld=rc->lChild;
	switch (rc->bf){
		case RH:
			(*T)->bf=rc->bf=EH;
			L_Rotate(T);
			break;
		case LH:
			switch (ld->bf){
				case RH:
					(*T)->bf=LH;
					rc->bf=EH;
					break;
				case EH:
					(*T)->bf=rc->bf=EH;
					break;
				case LH:
					(*T)->bf=EH;
					rc->bf=RH;
					break;
			}
		ld->bf=EH;
		R_Rotate(&((*T)->rChild));
		L_Rotate(T);
		break;
	}
}
//ƽ�������AVL����Ԫ��
bool InsertAVL(AVLTree *T, elementType x, bool *taller){
	if (*T==NULL){
		(*T)=new AVLNode;
		(*T)->key=x;
		(*T)->lChild=(*T)->rChild=NULL;
		(*T)->bf=EH;
		*taller=true;
		return true;
	}
	else{
		if(x==(*T)->key){
			*taller=false;
			return false;
		}
		else if(x<(*T)->key){
			if(!InsertAVL(&((*T)->lChild), x, taller)){
				//���ж�Ҫ������������Ƿ�������
				return false;
			}
			if(*taller){
				switch ((*T)->bf){
					case LH:
						LeftBalance(T);
						*taller=false;
						break;
					case EH:
						(*T)->bf=LH;
						*taller=true;
						break;
					case RH:
						(*T)->bf=EH;
						*taller=false;
						break;
				}
			}
		}
		else{
			if(!InsertAVL(&((*T)->rChild), x, taller)){
				return false;
			}
			if(*taller){
				switch ((*T)->bf){
					case RH:
						RightBalance(T);
						*taller=false;
						break;
					case EH:
						(*T)->bf=RH;
						*taller=true;
						break;
					case LH:
						*taller=false;
						(*T)->bf=EH;
						break;
				}
			}
		}
	}
}
void creatAVLFromArray(AVLTree *T){
	bool taller;
    elementType str[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    cout << "��ʼ��������!" << endl;
	for (int i=0; i < 26; i++) {
		InsertAVL(T, str[i], &taller);
	}
    cout << "AVL�������ɹ�!" << endl;
}
