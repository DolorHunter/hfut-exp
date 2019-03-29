#pragma once
#define INF 65535
#include"grpAdjMatrix.h"
#include"seqQueue.h"
#include"seqStack.h"
#include"BiTree.h"
#include"forest.h"

typedef struct edgetype
{
	int vBegin;  //�ߵ���ʼ�����ţ���1��ʼ
	int vEnd;     //�ߵ���һ�����ţ���1��ʼ
	int eWeight;  //�ߵ�Ȩֵ
}EdgeType;   //�����������

typedef struct minEdgeType
{
	int v;//������һ�˵Ķ�����
	cellType eWeight;//�ߵ�Ȩֵ
}MinEdgeType;//�������Ԫ������

//1.��ӡͼ�����ֱ�����

//DFS��ȱ����㷨
    //�����ڽӾ����DFS��ʵ��
void DFS(Graph &G, int verID){
    int w;
	visit(G, verID);
	w=firstAdj(G, verID);
	while(w!=0){
		if(!visited[w])            //w��δ����
			DFS(G, w);             //�ݹ���ȱ���
		w=nextAdj(G, verID, w);    //�ݹ鷵�غ�����verID��λ��w�����һ���ڽӵ�
	}
}
void AdjMatrixDFSTraverse(Graph &G){
    int vID=0;
    cout << "�������׸����ʵ�����:" ;
    cin >> vID;
    cin.get();
    //��������ǵ�visit�����ʼ��Ϊfalse
    for(vID=1; vID<=G.VerNum; vID++){
        visited[vID]=false;
    }
    DFS(G, vID);//��ָ���������
    for(vID=1; vID<=G.VerNum; vID++){
        //����ö���ı��λΪfalse����������������������
        if(!visited[vID]){
            DFS(G, vID);
        }
    }
    cout << "\nDFS��ȱ��������!" << endl;
}

//BFS��ȱ����㷨
    //�����ڽӾ����BFSʵ��
void BFS(Graph &G, int verID){
	visit(G, verID);
	seqQueue Q;
	initialSeqQueue(Q);           //��ʼ��ѭ��˳�����
	seqEnQueue(Q, verID);         //���ΪverID�Ķ������
	char v, w;
	while(!seqQueueEmpty(Q)){     //���в���ѭ��������
		seqOutQueue(Q, v);        //v����
		w=firstAdj(G, v);         //����v�ĵ�һ���ڽӵ�
		while(w!=0){
			if(!visited[w]){      //w��δ���ʣ�����w��������ѷ���
				visit(G, w);
				seqEnQueue(Q, w); //����w���
			}
			w=nextAdj(G,v,w);     //��������vλ��w�����һ���ڽӵ�
		}
	}
}
void AdjMatrixBFSTraverse(Graph &G){
    int vID=0;
    cout << "�������׸����ʵ�����:" ;
    cin >> vID;
    cin.get();
	for(vID=1; vID<=G.VerNum; vID++)  //��ʼ��
		visited[vID]=false;
	BFS(G, vID);  //��ָ���Ķ��㣬����ָ���ĵ�һ����ͨ����
	for(vID=1; vID<=G.VerNum; vID++){  //�����α���ͼ����������ͨ����
		if(!visited[vID])
			BFS(G, vID);
	}
	cout << "\nBFS��ȱ��������!" << endl;
}

//2. ͼ�Ļ���Ŀ.
void ArcNum(Graph &G){
    cout << "ͼ�Ļ���ĿΪ:" << G.ArcNum << "." << endl;
}

//3. ������ȱ�������������.
void DFS_CreatTree(Graph &G, csNode *&T, int verID){
	csNode *p;
	csNode *u;
	int w;
	visited[verID] = true;
	w=firstAdj(G,verID);
	if(w!=0){
		while(visited[w] && w!=0)
			w=nextAdj(G, verID, w);
		if(w!=0){
			p=new csNode;
			p->data = G.Data[w];
			p->firstChild=NULL;
			p->nextSibling=NULL;
			T->firstChild=p;
		}
	}
	u=p;
	while(w!=0){
		if(!visited[w])        //w��δ����
			DFS_CreatTree(G, u, w);          //�ݹ���ȱ���
		w=nextAdj(G,verID, w);    //�ݹ鷵�غ�����verID��λ��w�����һ���ڽӵ�
		if(w!=0 && !visited[w]){
			p=new csNode;
			p->data=G.Data[w];
			p->firstChild=NULL;
			p->nextSibling=NULL;
			while(u->nextSibling!=NULL)
				u=u->nextSibling;
			u->nextSibling=p;
		}
		if(u!=NULL)
			u=u->nextSibling;
	}
}
void DFSTraverseCreatTree(Graph &G, csNode *&T){
    int vID;
    cout << "�������׸����ʵ����:" ;
    cin >> vID;
    cin.get();
	csNode *p;
	csNode *u;
	for(vID=1;vID<=G.VerNum;vID++)  //��ʼ��
		visited[vID]=false;
	T=new csNode;
	T->data=G.Data[vID];
	T->firstChild=NULL;
	T->nextSibling=NULL;
	u=T;
	DFS_CreatTree(G, T, vID);  //��ָ���Ķ��㣬����ָ���ĵ�һ����ͨ����
	for(vID=1; vID<=G.VerNum; vID++){  //�����α���ͼ����������ͨ����
		if(!visited[vID]){
			p=new csNode;
			p->data=G.Data[vID];
			p->firstChild=NULL;
			p->nextSibling=NULL;
			while(u->nextSibling)
				u=u->nextSibling;
			u->nextSibling=p;
			DFS_CreatTree(G, p, vID);
		}
	}
	cout << "�ڽӾ��󴴽�����ɭ�ֱ������Ϊ(DFS):";
	prOrder(T);
	destroyTree(T);
}

//4. ������ȱ�������������.
void BFS_CreatTree(Graph &G, csNode *&T, int verID){
	csNode *u=T;
	csNode *p;
	int v, w;      //������
	v=verID;
	seqQueue Q;
	initialSeqQueue(Q);         //��ʼ��ѭ��˳�����
	visited[verID]=true;
	seqEnQueue(Q, verID);       //���ΪverID�Ķ������
	while(!seqQueueEmpty(Q)){     //���в���ѭ��������
		seqOutQueue(Q, v);       //v����
		w=firstAdj(G,v);      //����v��verID���ĵ�һ���ڽӵ㣬���ص�w
		if(w!=0){
			while(visited[w] && w!=0)
				w=nextAdj(G,v,w);
			if(w == 0)
				break;
			p=new csNode;
			p->data=G.Data[w];
			p->firstChild=NULL;
			p->nextSibling=NULL;
			u->firstChild=p;
		}
		u=p;
		while(w!=0){
			if(!visited[w]){   //w��δ���ʣ�����w����ǣ����
				visited[w]=true;
				seqEnQueue(Q,w);
			}
			w=nextAdj(G,v,w);  //��������vλ��w֮�����һ���ڽӵ�
			if(w!=0 && !visited[w]){
				p=new csNode;
				p->data=G.Data[w];
				p->firstChild=NULL;
				p->nextSibling=NULL;
				while(u->nextSibling!=NULL)
					u=u->nextSibling;
				u->nextSibling=p;
			}
		}
	}
}
int BFSTraverseCreatTree(Graph &G, csNode *&T){
    int vID;
    cout << "�������׸����ʵ����:" ;
    cin >> vID;
    cin.get();
	csNode *p;
	csNode *u;
	for(vID=1;vID<=G.VerNum;vID++)  //���ʱ�������ʼ��
		visited[vID]=false;
	T=new csNode;
	T->data=G.Data[vID];
	T->firstChild=NULL;
	T->nextSibling=NULL;
	u=T;
	BFS_CreatTree(G, T, vID);  //��ָ���Ķ��㣬����ָ���ĵ�һ����ͨ����
	for(vID=1; vID<=G.VerNum; vID++){  //�����α���ͼ����������ͨ����
		if(!visited[vID]){
			p=new csNode;
			p->data=G.Data[vID];
			p->firstChild=NULL;
			p->nextSibling=NULL;
			while(u->nextSibling!=NULL)
				u=u->nextSibling;
			u->nextSibling=p;
			BFS_CreatTree(G, p, vID);
		}
	}
	cout << "�ڽӾ��󴴽�����ɭ�ֱ������Ϊ(BFS):";
	prOrder(T);
	destroyTree(T);
}

//5. Prim�㷨����С������.
int HasEdge(Graph &G, int vBegin, int vEnd){
	if(G.gKind==UDN || G.gKind==DN){  //�����
		if(G.AdjMatrix[vBegin][vEnd]!=INF)  //Ȩֵ��������б�
			return 1;  //�бߣ�����1
		else
			return 0;  //�ޱߣ�����0
	}
	else{  //ͼ���
		if(G.AdjMatrix[vBegin][vEnd]==1)  //�������������±��1
			return 1;  //�бߣ�����1
		else
			return 0;  //�ޱߣ�����0
	}
}
void InitialTE(Graph &G, MinEdgeType TE[], int vID){
	int i;
	for(i=1;i<=G.VerNum;i++){
		if(HasEdge(G, vID, i) == 1){
			TE[i].v=vID;
			TE[i].eWeight=G.AdjMatrix[vID][i];
		}
		else
			TE[i].eWeight=INF;//�����ڸ�ֵΪ�����
	}
}
int GetMinEdge(Graph &G, MinEdgeType TE[]){
	cellType eMin=INF;  //������С��Ȩֵ
	int i,j;
	for(i=1;i<=G.VerNum;i++){
		if(visited[i]== false && TE[i].eWeight<eMin){
			j=i;//������С����±�
			eMin=TE[i].eWeight;
		}
	}
	return j;  //j��ΪV-U�У���С�߹�������ı��
}
void UpdateTE(Graph &G, MinEdgeType TE[], int vID){
	//����ѡ���ı��ΪvID�Ķ��㣨�¼��뼯��U�У���������ѡ�߼���
	int i,j;
	for(i=1;i<=G.VerNum;i++){
		if(visited[i]== false){  //���i������V-U�У�����U��
			if(HasEdge(G,vID,i) && G.AdjMatrix[vID][i]<=TE[i].eWeight){
				TE[i].v=vID;
				TE[i].eWeight=G.AdjMatrix[vID][i];
			}
		}
	}
}
void Prim(Graph &G){
    int vID;
    cout << "�������׸����ʵ����:" ;
    cin >> vID;
    cin.get();
	MinEdgeType TE[MaxVerNum];
	int curID;
	int i;
	cellType wALL=0;//Ȩֵ�ܺ�
	InitialTE(G, TE, vID);//��ȡ����㵽 vID��Ȩֵ
	visited[vID]=true;//�����Ѿ�����
	for(i=1; i<G.VerNum; i++){
		curID=GetMinEdge(G, TE);
		visited[curID]=true;
		UpdateTE(G, TE, curID);
	}
	cout << "Prim��С��������ʼ����Ϊ:" << G.Data[vID] << endl;
	cout << "ѡ��ıߺ�Ȩֵ:" << endl;
	for(i=1; i<=G.VerNum; i++){
		if(i!=vID){
			cout << "(" << G.Data[TE[i].v] << "," << G.Data[i] << ")";
			wALL+=TE[i].eWeight;
		}
	}
	cout << "��С��������Ȩֵ:"<< wALL << endl;
}

//6. Kruskal�㷨����С������.
void GetEdges(Graph &G, EdgeType edges[]){
	int i,j;
	int k=1;
	for(i=1; i<=G.VerNum; i++){  //��ѭ��
		for(j=1; j<=G.VerNum; j++){  //��ѭ��
			if((G.AdjMatrix[i][j]>=1) && (G.AdjMatrix[i][j]<INF)){
				edges[k].vBegin=i;  //�ߵĵ�һ����
				edges[k].vEnd=j;    //�ߵĵڶ�����
				edges[k].eWeight=G.AdjMatrix[i][j];  //�ߵ�Ȩֵ
				k++;
			}
		}
	}
}
EdgeType GetMinEdge(Graph &G, EdgeType edges[], int edgeUsed[], int &n){
    //nΪ���ص���С����edges[]�����е��±�
	EdgeType minEdge;
	cellType wMin=INF;  //������СȨֵ
	int i;
	int M;  //����ѭ������
	if(G.gKind==UDG || G.gKind==UDN)
		M=G.ArcNum*2;  //������������ͼ��ӦΪ�Գ��ԣ��ڽӾ�����Ч�����Ǳ�����2��
	else
		M=G.ArcNum;    //����ͼ���������У�M��Ϊͼ�ı���
	for(i=0; i<M ;i++){
        //��Ϊ����ͼ�ڽӾ���Գ��У���Ч�����Ǳ�����2�������Գ�2
		if(edgeUsed[i]==0 && edges[i].eWeight<wMin){
			wMin=edges[i].eWeight;
			minEdge.eWeight=edges[i].eWeight;;
			minEdge.vBegin=edges[i].vBegin;
			minEdge.vEnd=edges[i].vEnd;
			n = i;//��¼��С�����
		}
	}
	return minEdge;  //����ȡ�õ���С��
}
void Kruskal(Graph &G){
	int conVerID[MaxVerNum];  //�������ͨ�����������
	EdgeType edges[MaxVerNum*MaxVerNum];  //���ͼ�����б���Ϣ
	EdgeType treeEdges[MaxVerNum];        //����������еı���Ϣ��n-1��
	int edgeUsed[MaxVerNum*MaxVerNum];
	EdgeType minEdge;
	int i,j;
	int k=0;
	int conID;  //�ߵ���ֹ�������ͨ�����ı��
	int n;  //���ص���С�ߵ����
	GetEdges(G, edges);//��ȡ���б�
	int M;  //ѭ������
	if(G.gKind==UDG ||G.gKind==UDN)
		M=G.ArcNum*2;
	else
		M=G.ArcNum;
	for(i=0; i<M; i++)
		edgeUsed[i]=0;
	for(i=1; i<=G.VerNum; i++)
		conVerID[i]=i;
	for(i=1; i<G.VerNum; i++){  //ȡ��n-1���ߣ�����������
		minEdge=GetMinEdge(G, edges, edgeUsed, n );
		while(conVerID[minEdge.vBegin] == conVerID[minEdge.vEnd]){
			edgeUsed[n]=1;  //��ǲ�����
			minEdge=GetMinEdge( G, edges, edgeUsed, n );
		}
		treeEdges[i]=minEdge;//����ѡ������С�߷ŵ�������
		conID=conVerID[minEdge.vEnd];
		for(j=1; j<=G.VerNum; j++){  //�ϲ���ͨ��
			if(conVerID[j]==conID)
				conVerID[j]=conVerID[minEdge.vBegin];
		}
		edgeUsed[n]=1; //����Ѿ�ʹ�ù�
	}
	cellType wAll=0;  //��Ȩֵ
	cout << endl;  //������
	cout << "ѡ��ıߺ�Ȩֵ:" << endl;
	for(i=1;i<G.VerNum;i++){  //n-1����
		cout << "("<<G.Data[treeEdges[i].vBegin]<<","<<G.Data[treeEdges[i].vEnd]<<")";
		wAll+=treeEdges[i].eWeight;
	}
	cout << "��С��������Ȩֵ:"<<wAll << endl;
	cout << endl;
}

//7. Dijkstra�㷨�����·��.
void PrintDijkstra(Graph &G, int path[], int dist[], int vID ){
    //����sPath[]����vID��Ŀ�궥��i�����·������
	int sPath[MaxVerNum];
	int vPre;    //ǰ�������
	int top=-1;  //�������·���ϵĶ���������Կ���������·��
	int i, j;
	for(i=1; i<=G.VerNum; i++){
		cout << G.Data[vID] << "��" << G.Data[i] << "���·��";
		if(dist[i]==INF)
			cout << "�޿ɴ�·��." << endl;
		else{
			cout << "��̾���:" <<dist[i] << endl;
			cout << "·��:";
		}
		top++;
		sPath[top]=i;     //sPath[]����Ŀ�궥����i
		vPre=path[i];
		while(vPre!=-1){
			top++;
			sPath[top]=vPre;
			vPre=path[vPre];
		}
		if(dist[i]!=INF){
            //sPath[top]Ϊָ������ʼ����vID
			for(j=top; j>=0; j-- ){
				cout << G.Data[sPath[j]];
				if(j != 0)
					cout << "->";
			}
		}
		top=-1;
		cout << endl;
	}
}
void Dijkstra(Graph &G){
    int vID;
    cout << "�������׸����ʵ����:" ;
    cin >> vID;
    cin.get();
	int path[MaxVerNum];
	int dist[MaxVerNum];
    int solved[MaxVerNum];//�����Ƿ������·��
	int i, j, v;
	cellType minDist;//������̾���
	for(i=1;i<=G.VerNum;i++){
		solved[i]=0;//��ʼ����Ƕ�δ�ҵ�
     	dist[i]=G.AdjMatrix[vID][i];//������ʼ��㵽��������
		if(dist[i]!=INF)
			path[i]=vID;  //��i�����ǰ��ΪvID
		else
			path[i]=-1;   //��ǰ����i��ǰ��
 	}
 	solved[vID]=1;//��ʼ����ѽ�
	dist[vID]=0; //��ʼ�ڵ㵽�Լ�����Ϊ0
	path[vID]=-1;
	for(i=1; i<G.VerNum; i++){
		minDist=INF;
		for(j=1;j<=G.VerNum;j++){
			if(solved[j]==0 && dist[j]<minDist){
				v=j;//�����ѽ�����±�
				minDist=dist[j];
			}
		}
		if(minDist == INF){//δ�ҵ�
			cout<<"��ͼ������ͨͼ��"<<endl;
			return;
		}
		solved[v]=1;
		for(j=1; j<=G.VerNum; j++){
		     if(solved[j]==0 && (minDist+G.AdjMatrix[v][j])<dist[j]){
                dist[j]=minDist+G.AdjMatrix[v][j];
		        path[j]=v;   //���¶���j��ֱ��ǰ��Ϊ����v
		    }
		}
	}
	PrintDijkstra(G, path, dist, vID);
}

//8. Floyd�㷨�����·��.
void PrintFloyd(Graph &G, int dist[MaxVerNum][MaxVerNum], int path[MaxVerNum][MaxVerNum]){
	int sPath[MaxVerNum];
	int prior;
	int top=-1;
	for(int i=1; i<=G.VerNum; i++){
		for(int j=1; j<=G.VerNum; j++){
			cout << G.Data[i] << "��" << G.Data[j];
			if(dist[i][j]==INF)
				cout << "��·��." << endl;
			else{
				cout << "��̾���:" << dist[i][j] << endl;
				cout << "·��Ϊ:";
				top++;
				sPath[top]=j;      //sPath[0]Ϊ��ǰ����i
				prior=path[i][j];  //i�����ǰ������
				while(prior!=i){
					top++;
					sPath[top]=prior;
					prior=path[i][prior];
				}
				top++;
				sPath[top]=i;  //�ӽ���ʼ����i
				if(dist[i][j]!=INF){
					for(int m=top;m>=0;m--){
                        //sPath[top]Ϊָ������ʼ����
						cout << G.Data[sPath[m]] << "  ";
						if(m != 0)
							cout<<"->";
					}
				}
				top=-1;
				cout << endl << endl;
			}
		}
	}
}
void Floyd(Graph &G){
	int i, j, m;
	int dist[MaxVerNum][MaxVerNum];
	int path[MaxVerNum][MaxVerNum];
	for(i=1; i<=G.VerNum; i++){  //��ʼ����������·������
		for(j=1;j<=G.VerNum;j++){
            //��������ʼ��Ϊ�ڽӾ���
			dist[i][j]=G.AdjMatrix[i][j];
        	if(i!=j && G.AdjMatrix[i][j]<INF)
				path[i][j]=i;
		    else
				path[i][j]=-1;
		}
	}
	for(m=1; m<=G.VerNum; m++){//����m
	      for(i=1; i<=G.VerNum; i++){
		  		for(j=1; j<=G.VerNum;j++){
                    //m��Ϊ���㣬i��j֮������С������m��Ϊ��ת��
		    		if(i!=j && dist[i][m]+dist[m][j]<dist[i][j]){
                        //������̾���
						dist[i][j]=dist[i][m]+dist[m][j];
						path[i][j]=path[m][j];
		        	}
		    	}
		 }
	}
	PrintFloyd(G, dist, path);
}

//9. ��������.
void GetInDegrees(Graph &G, int inds[]){
	for(int j=1; j<=G.VerNum; j++){
		for(int i=1; i<=G.VerNum; i++){
			if(G.AdjMatrix[i][j]>=1 && G.AdjMatrix[i][j]<INF)
				inds[j]++;
		}
	}
}
bool TopologicalSort(Graph &G, int topoList[]){
	seqStack S;
	initialStacksS(S);
	int v, w;//������
	int ind[MaxVerNum];
	for(int i=1; i<=G.VerNum; i++)
		ind[i]=0;  //��������ʼ��
	for(int i=1; i<G.VerNum; i++)
		topoList[i]=-1;
	GetInDegrees(G, ind);
	for(int i=1; i<=G.VerNum; i++){
		  if(ind[i]==0)
		  	pushStacksS(S, i);
	}
	int iCount=0;
	while(!stackEmptysS(S)){
		popStacksS(S, v);    //��ջ������һ�����Ϊ0�Ķ����ŵ�v
		cout << G.Data[v];
		w = firstAdj(G,v);
		iCount++;
		topoList[iCount]=v;
     	while(w!=0){
        	ind[w]--;
            if(ind[w]==0)   //����w������Ѿ�Ϊ0����ջ
				pushStacksS(S,w);
            w=nextAdj(G,v,w);
      	}
	}
	if(iCount == G.VerNum){
        //nΪͼ�Ķ�����
		cout << endl << "���Բ�����������!" << endl;
		return true;
	}
	else{
		cout << endl << "�����Բ�����������" << endl;
		return false;
	}
}

//10.AOE���ؼ�·��.
void PrintKeyPath(Graph &G ,int topoList[] , int vlt[],int vet[]){
	int w, v;                              //�ж��ؼ�·�������
	cout << "�ؼ�·��Ϊ:";
	v=topoList[1];
	cout << G.Data[v];    //���Դ��
	while(v!=0){
		w=firstAdj(G, v);          //����v�ĵ�һ���ڽӵ�
		if(w!=0)
			cout<<"->";
		while(w!=0){
			if(vet[w]==vlt[w]){
                //����ؼ�������Ķ���
				cout<<G.Data[w];
				break;
			}
			else
			  w=nextAdj(G,v,w);  //������һ���ڽӵ�
		}
		v=w;
	}
}
void _KeyPath(Graph &G, int topoList []){
	int i,j;
	int vet[MaxVerNum];//���緢��ʱ��
	int vlt[MaxVerNum];//����ʼʱ��
	int vPre;  //���涥���ǰ��������
	int vSuc;  //���涥��ĺ�̶�����
	for(i=1; i<=G.VerNum; i++)
        vet[i]=0;
	for(i=1; i<=G.VerNum; i++){
		vPre=topoList[i];
		for(j=1; j<=G.VerNum; j++){
		    if(G.AdjMatrix[vPre][j]>=1 && G.AdjMatrix[vPre][j]<INF)
		         if(vet[j]<vet[vPre]+G.AdjMatrix[vPre][j])
				 	vet[j]=vet[vPre]+G.AdjMatrix[vPre][j];
		}
	}
	for(i=1;i<=G.VerNum;i++)
        vlt[i]=vet[G.VerNum];
	for(i=G.VerNum; i>=1; i--){
		vSuc=topoList[i];
		for(j=G.VerNum;j>=1;j--){
            //j��vSuc����
		    if(G.AdjMatrix[j][vSuc]>=1 && G.AdjMatrix[j][vSuc]<INF)
				if(vlt[j] > vlt[vSuc]-G.AdjMatrix[j][vSuc])
					vlt[j]=vlt[vSuc]-G.AdjMatrix[j][vSuc];
		}
	}
	PrintKeyPath(G, topoList, vlt, vet);
}
void KeyPath(Graph &G, int topoList[]){
    if(TopologicalSort(G, topoList)){
		cout << "�ڽӾ���ʵ��:" << endl;
        _KeyPath(G, topoList);
	}
    else
        cout << "�����ڹؼ�·��!" <<endl;
}
