#pragma once
#include<iostream>
#define MAXLEN 100

using namespace std;

typedef char elementType;

	//ɭ��˫�ױ�ʾ���Ľ��ṹ
typedef struct pNode
{
	elementType data;   //���������
	int parent;         //�����ָ�루�±꣩

}PTNode;
    //ɭ��˫�ױ�ʾ���ṹ
typedef struct pTree
{
	PTNode node[MAXLEN];   //�������
	int n;                 //�������
}pTree;

    //ɭ�ֺ���-�ֵ������ʾ
typedef struct csNode
{
	elementType data;
	struct csNode *firstChild, *nextSibling;
}csNode,*csTree;


//����˫�ױ�ʾ�У��±�w����һ���ֵܽ�㣬�����ֵܽ����±�
int next(pTree T, int w)
{
	int i;
	for(i=w+1;i<T.n;i++)
	{
		if(T.node[w].parent==T.node[i].parent)
			return i;
	}
	return -1;
}

//��ʼ����
void initialTree(pTree &T)
{
	T.n=0;   //�������ʼ��Ϊ0
}

//1.1�������
int firstChild(pTree &T, int v){    //�����±�Ϊv�Ľ��ĵ�һ�����ӽ���±�
	int w;
	if(v==-1)
		return -1;

	for(w=0; w<T.n; w++){
		if(T.node[w].parent==v)
			return w;
	}
	return -1;
}
int nextSibling(pTree &T, int v, int w){  //����v���±�λ��w֮�����һ�����ӽ���±�
	int i;
	for(i=w+1; i<T.n; i++)
		if(T.node[i].parent==v)
			return i;
	return -1;
}
void preOrder(pTree &T,int v)
{
	int w;
	cout << T.node[v].data << "\t" ;

	w=firstChild(T,v);
	while(w!=-1)
	{

		preOrder(T,w);
		w=nextSibling(T,v,w);
	}
}

void preTraverse(pTree &T)
{
	int i;
	int visited[MAXLEN];
	for(i=0; i<T.n; i++)
	{
		visited[i]=0;
	}
	    //��������㣬������ɭ�֣��ж�������
	for(i=0; i<T.n; i++)
	{
		if(T.node[i].parent==-1)
			preOrder(T,i);
	}
}

//1.2�������
void postOrder(pTree &T, int v)
{
	int w;
	w=firstChild(T,v);
	while(w!=-1)
	{
		postOrder(T,w);
		w=nextSibling(T,v,w);
	}
	cout << T.node[v].data << "\t" ;   //���ʸ����
}

void postTraverse(pTree &T){
	int i;
	int visited[MAXLEN];
	for(i=0; i<T.n; i++){
		visited[i]=0;
	}
	    //��������㣬������ɭ�֣��ж�������
	for(i=0; i<T.n; i++){
		if(T.node[i].parent==-1)
			postOrder(T,i);
	}
}

//1.3��α���
int level(pTree &T, int n){
	int parent=n;
	int count=0;
	while(parent!=-1){
		parent=T.node[parent].parent;
		count++;
	}
	return count;
}
int height(pTree &T){
	int i=-1;
	int max=0;
	while(i!=T.n){
		if(max<level(T,i)){
            max=level(T,i);
		}
		i++;
	}
	return max;
}
void levelTraverse(pTree &T){
    int i,j,k=0;
	char len[MAXLEN];
	for(i=1; i<=height(T); i++){
        for(j=0; j<T.n; j++){
            if(i==level(T, j)){
                len[k]=T.node[j].data;
                k++;
            }
        }
    }
	for(i=0; i<k; i++){
		cout << len[i] << "\t";
	}
}

//2. ��ɭ�ָ߶�
//int height(pTree &T)

//3. ��ɭ�ֽ����Ŀ
//cout << "ɭ�ֵĽ���Ϊ" << T.n << endl;

//4. ��ɭ��Ҷ����Ŀ
int leafNode(pTree &T){
	int parent[MAXLEN];
	int i,j=0;
	parent[0]=-1;
	for(i=0; i<T.n; i++){
		if(T.node[i].parent>parent[j])
			parent[++j]=T.node[i].parent;
	}
	return T.n-j;
}

//5. ɭ�ֵĶ�
int degree(pTree &T){
	int parent[MAXLEN];
	int num[MAXLEN];
	int i=0,j=0,k=0,n=0;
	parent[0]=-1;
	for(i=0; i<T.n; i++){
		if(T.node[i].parent > parent[k])
			parent[k++] = T.node[i].parent;
	}
    for(i=0; i<k; i++){
        int h=0;
        for(j=0; j<T.n; j++){
            if(parent[i]==T.node[j].parent){
                num[i]=++h;
            }
        }
	}
	for(i=0; i<k; i++){
		if(n<num[i]){
			n=num[i];
		}
		return n;
	}
}

//6.����������ֵ������
void preOrderNode(pTree &T, int v){
	int w;
	cout << '(' << T.node[v].data << ',' << level(T,v) << ')' << "\t";
	w=firstChild(T,v);
	while(w!=-1){
		preOrderNode(T,w);
		w=nextSibling(T,v,w);
	}
}
void preTraverseNode(pTree &T){
	int i;
	int visited[MAXLEN];
	for(i=0;i<T.n;i++){
		visited[i]=0;
	}
	    //��������㣬������ɭ�֣��ж�������
	for(i=0;i<T.n;i++){
		if(T.node[i].parent==-1)
			preOrderNode(T,i);
	}
}

//7.���������ʾ����
void outgList(csNode *T){
    if(T!=NULL){
        cout<<T->data;
        if(T->firstChild!=NULL){
            cout<<"(";
            outgList(T->firstChild);
        }
        if(T->nextSibling!=NULL){
			cout<<",";
			outgList(T->nextSibling);
		}
		else
			cout<<")";
    }
}

//�ݹ鴴��һ�ú����ֵ������ʾ����
void create(csNode *&T, pTree &T1, int v)
{
	int w;
	T=new csNode;
	T->data=T1.node[v].data;
	T->firstChild=NULL;
	T->nextSibling=NULL;
	w=firstChild(T1,v);  //����v�ĵ�һ�����ӽ��
	if(w!=-1)
	{
		create(T->firstChild, T1, w);
	}

	w=next(T1, v);       //����v����һ���ֵܽ��
	if(w!=-1)
	{
		create(T->nextSibling, T1, w);
	}
}

//��˫�ױ�ʾ������ɭ�֣����������ֵ������ʾ������ɭ�֣�
void createCsTree(csNode *&T, pTree T1)
{
	int i;
	//����T1�ĵ�һ�������
	for(i=0; i<T1.n; i++)
	{
		if(T1.node[i].parent==-1)   //�ҵ���һ�������
			break;
	}
	if(i<T1.n)
		create(T, T1, i);
}
