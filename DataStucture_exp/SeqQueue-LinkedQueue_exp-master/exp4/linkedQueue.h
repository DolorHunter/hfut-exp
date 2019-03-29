#pragma once
#define elementType int

using namespace std;

//�����н��ṹ����
typedef struct LNode{
    elementType data;           //�������Ԫ��
    struct LNode *next;         //��һ�����ָ��
}node;

//�����нṹ����
typedef struct{
    node *front;                //��ͷָ��
    node *rear;                 //��βָ��
}linkQueue;

//��ӡlinkedQueue
void prtLinkedQueue(linkQueue &lQ){
    node *u=lQ.front->next;
    cout << "�����д�ӡ�������:" << endl;
    while(u!=NULL){
        cout << u->data << "\t";
        u=u->next;
    }
    cout << endl;
}

//9. ��ʼ������.
void initialLinkedQueue(linkQueue &lQ){
    lQ.front=new node;           //����ͷ���,ָ��Ϊfront
    lQ.rear=lQ.front;             //rearҲָ��ͷ���
    lQ.front->next=NULL;         //ͷ����next��ΪNULL
}

//10.�ж��Ƿ�ӿ�.
bool linkedQueueEmpty(linkQueue &lQ){
    return (lQ.front==lQ.rear);       //��Q.front==Q.rearʱΪ1,����Ϊ0.���丳��return
}

//11.�ж��Ƿ����.
void linkedQueueFull(){
    cout << "[Warning]-��������ô���ܻ�����?XD" << endl;
}

//12.ѭ�����.
void linkedEnQueue(linkQueue &lQ){
    cout << "����������Ԫ��(����9999�˳�)" << endl;
    elementType x;
    cin >> x;

    while(x!=9999){
        node *P=new node;               //�����ڴ�,�����½��
        P->data=x;                      //x�����½��
        P->next=NULL;                   //x����Ϊ�µ�β�ڵ�,next��NULL
        lQ.rear->next=P;                 //�½�����ӵ�ԭ��β
        lQ.rear=P;                       //����Ϊ֮��,ָ���¶�β
        cin >> x;
    }

    _pause();                        //��ͣ
}

//���.
void linkedEnQueueOnce(linkQueue &lQ, elementType &x){
    node *P=new node;               //�����ڴ�,�����½��
    P->data=x;                      //x�����½��
    P->next=NULL;                   //x����Ϊ�µ�β�ڵ�,next��NULL
    lQ.rear->next=P;                 //�½�����ӵ�ԭ��β
    lQ.rear=P;                       //����Ϊ֮��,ָ���¶�β
}

//13.����.
void linkedOutQueue(linkQueue &lQ, elementType &x){
    node *u;
    if(linkedQueueEmpty(lQ)){
        cout << "�ն���!�޷�����!" << endl;
    }
    else{
        x=lQ.front->next->data;          //ȡ��ͷԪ�ص�x
        cout << x << endl;
        u=lQ.front->next;                //uָ���ͷ
        lQ.front->next=u->next;         //���¶�ͷָ��
        delete u;                       //ɾ��ԭ��ͷ,�ͷ��ڴ�
        if(lQ.front->next==NULL){        //���ɾ������ӿ�,��Ҫ�޸�rearָ��
            lQ.rear=lQ.front;             //�ž�Ұָ��
        }
    }

    _pause();                        //��ͣ
}

//14.ȡ��ͷԪ��.
void linkedQueueFront(linkQueue &lQ, elementType &x){
    if(linkedQueueEmpty(lQ)){
        cout << "�ն���!�޷�ȡͷԪ��!" << endl;
    }
    else{
        x=lQ.front->next->data;
        cout << x << endl;
    }

    _pause();                        //��ͣ
}

//15.�����Ԫ�ظ���.
void linkedQueueLength(linkQueue &lQ){
    int iLen=1;
    node *u=lQ.front->next;
    while(u!=lQ.rear){
        iLen++;
        u=u->next;
    }
    cout << "������" << iLen << "��Ԫ��." << endl;

    _pause();                        //��ͣ
}

//16.����ż���㷨.
void linkedOddInEvenOut(linkQueue &lQ){
    initialLinkedQueue(lQ);
    cout << "������Ԫ��(����0�˳�):";
    elementType x;
    cin >> x;
    while(x!=0){
        if(x%2==1){
            linkedEnQueueOnce(lQ, x);
            cout << "��ӳɹ�!" << endl;
            prtLinkedQueue(lQ);                 //��ӡLinkedQueue
            cout << "������Ԫ��(����0�˳�):";
            cin >> x;
        }
        else{
            if(linkedQueueEmpty(lQ)){
                linkedOutQueue(lQ, x);
            }
            else{
                linkedOutQueue(lQ, x);
                cout << "���ӳɹ�!" << endl;
            }
            prtLinkedQueue(lQ);                 //��ӡLinkedQueue
            cout << "������Ԫ��(����0�˳�):";
            cin >> x;
        }
    }

    _pause();                        //��ͣ
}
