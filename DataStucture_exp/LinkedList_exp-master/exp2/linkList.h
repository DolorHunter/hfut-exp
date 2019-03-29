#pragma once
#include<iostream>
#define elementType int

using namespace std;

//���嵥����ڵ�ṹ
typedef struct slNode{
    elementType data;           //������
    struct slNode *next;        //ָ����,�ṹ(�ڵ�)��������
}node, *linkList;

//-1. ��ӡ������(������)
void printList(linkList L){
    cout << "���ڴ�ӡ˳���..." << endl;

    node *p=L->next;
    while(p){
        cout << p->data << endl;
        p = p->next;
    }

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//����ͣ��ӡ(�����ʹ��)
void prtNpauseList(linkList L){
    node *p=L->next;
    while(p){
        cout << p->data << endl;
        p = p->next;
    }
}

//��ʼ������(ʹ��C++�����ûش���ʼ���������)
void initialList(node *&L){
    L=new node;
    L->next=NULL;
}

//1. β�巨������������ӡ�������
void creatListR(node *&L){
    node *u, *R;
    L=new node;
    L->next=NULL;
    R=L;
    elementType x;      //���Ԫ��ֵ
    cout <<"������Ԫ������(����,9999�˳�):" << endl;
    cin >> x;
    while(x != 9999){
        u=new node;
        u->data=x;
        u->next=NULL;
        R->next=u;
        R=u;
        cin >> x;
    }
    cout << "�������ɹ�!" << endl;

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//2. ͷ�巨������������ӡ�������
void creatListH(node *&L){
    node *u;
    L=new node;
    L->next=NULL;
    elementType x;      //���Ԫ��ֵ
    cout <<"������Ԫ������(����,9999�˳�):" << endl;
    cin >> x;
    while(x != 9999){
        u=new node;
        u->data=x;
        u->next=L->next;
        L->next=u;
        cin >> x;
    }
    cout << "�������ɹ�!" << endl;

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//3. ���ٵ�����
void destoryList(linkList *L){
    linkList q, p=*L;
    while(p){
        q=p->next;
        delete p;
        p=q;
    }
    *L=NULL;
    cout << "���������ٳɹ�!" << endl;

    /**�ٴγ�ʼ����ֹ�������**/
    cout << "�Ƿ��ʼ��?(Y/N) -[ע��]������ʼ���������ĳЩ����ʱ���ܱ���!" << endl;
    char x;
    cin >> x;
    if(x=='Y' || x=='y'){
        initialList(*L);
        cout << "��ʼ���ɹ�!" << endl;
    }

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//4. ��������
void listLength(node *L){
    int iLen=0;
    node *p=L->next;
    while(p){
        iLen++;
        p=p->next;
    }
    cout << "������Ϊ:" << iLen << endl;

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//5. ����Ԫ��(λ�ò���)(�������е�i��Ԫ�أ����������������ڣ�����)
void getElement(node *L){
    cout << "���������λ��:" << endl;
    int iLoc;
    cin >> iLoc;
    int j=1;             //��1�������϶�������֪
    node *p=L->next;
    while(j!=iLoc && p!=NULL){
        j++;
        p=p->next;
    }
    if(p){
        cout << "λ�ô���! �������е�" << iLoc << "��Ԫ��Ϊ" << p->data << endl;
    }
    else{
        cout << "����!λ�ò�����!" << endl;
    }

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//6. ����ڵ�(�ڵ�i�����ǰ����ֵΪx�Ľ��)
void listInsert(node *L){

    cout << "���������λ��:" << endl;
    int iLoc;
    cin >> iLoc;

    cout << "������Ԫ��ֵ:" << endl;
    int x;
    cin >> x;

    node *p=L;
    node *u;
    int k=1;                //��1�������϶�������֪
    while(k!=iLoc && p){
        p=p->next;
        k++;
    }
    if(!p){
        cout << "����!����λ����Ч!" << endl;
    }
    else{
        //��ʱ, k=i-1, pΪe(i-1)����ָ��
        u=new node;
        u->data=x;
        u->next=p->next;
        p->next=u;

        cout << "����ɹ�!" << endl;
    }

    prtNpauseList(L);                //��ӡ������L

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//7. ����Ԫ��(ֵ����)(�����в���Ԫ��ֵΪx�Ľ�㣬�ɹ����ؽ��ָ�룬ʧ�ܱ���)
void listLocate(node *L){
    elementType x;
    cout << "�����������Ԫ��ֵ:" << endl;
    cin >> x;
    node *p=L->next;
    while(p && p->data!=x){
        //pָԪ�ؽ��,�ֲ���Ŀ��ڵ�,����������һ���ڵ�
        p=p->next;
    }
    if(p){
        cout << "���ҳɹ�!�������д���Ԫ��" << x << "!" << endl;
    }
    else{
        cout << "����!Ԫ�ز�����!" << endl;
    }

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//8. ɾ���������е�i��Ԫ�ؽ��
void listDelete(node *L){
    cout << "�������ɾ��Ԫ�صĽڵ�:" << endl;
    int iLoc;
    cin >> iLoc;

    node *u;
    node *p=L;
    int k=1;                //��1�������϶�������֪
    while(k!=iLoc && p){
        p=p->next;
        k++;
    }
    if(!p || !(p->next)){
        cout << "����!ɾ��λ�ó�����Χ,ɾ��ʧ��!" << endl;
    }
    else{
        u=p->next;
        p->next=u->next;
        delete u;
        cout << "ɾ���ɹ�!" << endl;
    }

    prtNpauseList(L);                   //��ӡ������L

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//9. ��������(��һ����������ĵ�����L�в���һ��ֵΪx��Ԫ�أ��������������������)
void setInsert(node *&L){
    node *u;
    node *P=L;

    elementType x;
    cout << "������Ҫ�����Ԫ��:" << endl;
    cin >> x;

    //��������λ��P(P->data<=x,���践����һ��λ�ò���,�Լ�����鷳)
    while(P->next!=NULL && P->next->data<=x){
        P=P->next;
    }

    //Pָ���β,��P->next��Ԫ�ر�x��,P->next��Ϊ����λ��
    if(P->next==NULL || P->next->data>x){
        u=new node;
        u->data=x;
        u->next=P->next;
        P->next=u;
    }

    prtNpauseList(L);               //��ӡ������L

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//10. ������ż(����������е��������ż������ֽ⿪��Ԫ��ֵΪ������ż����)
void seperateOEList(node *L){
    linkList L1;
    linkList L2;
    initialList(L1);
    initialList(L2);
    node *u,*R;     //L1ָ��
    node *v,*S;     //L2ָ��
    R=L1;
    S=L2;

    node *p=L->next;
    while(p){
        if(p->data%2 ==1){
            u=new node;
            u->data=p->data;
            u->next=NULL;
            R->next=u;
            R=u;
        }
        else{
            v=new node;
            v->data=p->data;
            v->next=NULL;
            S->next=v;
            S=v;
        }
        p=p->next;
    }

    cout << "****����ԭʼ��L****" << endl;
    prtNpauseList(L);                   //��ӡ������L

    cout << "****����������L1****" << endl;
    prtNpauseList(L1);                   //��ӡ������L1

    cout << "****����ż����L2****" << endl;
    prtNpauseList(L2);                   //��ӡ������L2

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//11. ����ȡ��(������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3��)
void intersecIncreList(){
    linkList L1;
    linkList L2;
    linkList L3;
    initialList(L1);
    initialList(L2);
    initialList(L3);

    cout << "β�巨��������������L1" << endl;
    creatListR(L1);

    cout << "β�巨��������������L2" << endl;
    creatListR(L2);

    node *u,*p;     //L1, L2ָ��
    node *v,*S;     //L3ָ��
    u=L1->next;
    p=L2->next;
    S=L3;

    while(u && p){
        if(u->data == p->data){
            v=new node;
            v->data=u->data;
            v->next=NULL;
            S->next=v;
            S=v;
            u=u->next;
            p=p->next;
        }
        else if(u->data > p->data){
            p=p->next;
        }
        else{
            u=u->next;
        }
    }

    cout << "****����L1��****" << endl;
    prtNpauseList(L1);                   //��ӡ������L1

    cout << "****����L2��****" << endl;
    prtNpauseList(L2);                   //��ӡ������L2

    cout << "****���ǽ�����L3****" << endl;
    prtNpauseList(L3);                   //��ӡ������L3

    cout << "���뻻���Լ���." << endl;
    //getchar();
}

//12. ȥ��(ɾ���������������е��ظ�Ԫ�أ�Ҫ��ʱ���������)
void deleteRepList(node *L){
    node *u=L;          //ǰָ��
    node *R=u->next;    //��ָ��
    node *p;            //ɾ��ָ��(��ָ��)
    while(R->next){
        if(u->next->data == R->next->data){
            p=u->next;
            u->next=R->next;
            R=R->next;
            delete p;

        }
        else{
            u=u->next;
            R=R->next;
        }
    }

    cout << "���ȥ�ز���!" << endl;
    prtNpauseList(L);

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//13.�ϲ�������(�������½�㣬����ԭ�����2����кϲ���Ϊһ�����ϣ�
//              �ϲ�����L1��ͷ�����Ϊͷ��㣬ɾ��L2��ͷ��㣬Ҫ��ʱ��������á�)
void mergeIncreList(){
    linkList L1;
    linkList L2;
    initialList(L1);
    initialList(L2);

    cout << "β�巨��������������L1" << endl;
    creatListR(L1);

    cout << "β�巨��������������L2" << endl;
    creatListR(L2);

    node *u=L1;
    node *R=L2;
    node *p;                         //����L2ָ��
    while(u->next && R->next){
        if(u->next->data == R->next->data){
            u->next;
            R->next;
        }
        else if(u->next->data > R->next->data){
            p=R->next->next;
            R->next->next=u->next;
            u->next=R->next;
            R->next=p;
            u->next;
            R->next;
        }
        else{
            u=u->next;
        }
    }
    if(R->next){                    //ĩλL2�ǿս���L1β
        u->next=R->next;
    }

    cout << "" << endl;
    cout << "**����ɾ��L2ͷ���**" << endl;
    R=L2;
    delete R;
    cout << "**L2ͷ���ɾ���ɹ�!**" << endl;

    cout << "" << endl;
    cout << "****���Ǻϲ����L1****" << endl;
    prtNpauseList(L1);                  //��ӡ������L1


    cout << "���뻻���Լ���." << endl;
    getchar();
}
