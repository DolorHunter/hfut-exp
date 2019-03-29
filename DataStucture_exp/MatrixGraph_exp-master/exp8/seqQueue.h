//�޸İ�seqQueue.h
//date:2019.01.01

#pragma once
#define MaxLen 100

typedef int QelementType;

using namespace std;

//˳����д洢�ṹ����
typedef struct sQueue{
    QelementType data[MaxLen];       //��Ŷ���Ԫ��
    int front;                      //��ͷָ��
    int rear;                       //��βָ��
}seqQueue;

//��ӡseqQueue
void prtSeqQueue(seqQueue &sQ){
    int u=sQ.front+1;
    cout << "ѭ��˳����д�ӡ�������:" << endl;
    while(u%MaxLen!=sQ.rear+1){
        cout << sQ.data[u%MaxLen] << "\t";
        u=u+1;
    }
    cout << endl;
}

//1.��ʼ������
void initialSeqQueue(seqQueue &sQ){
    sQ.front=0;
    sQ.rear=0;
}

//2.�ж϶ӿ�
bool seqQueueEmpty(seqQueue &sQ){
    if(sQ.front==sQ.rear){
        return true;
    }
    else{
        return false;
    }
}

//3.�ж϶���
bool seqQueueFull(seqQueue &sQ){
    if(((sQ.rear+1)%MaxLen)==sQ.front){
        return true;
    }
    else{
        return false;
    }
}

//4.ѭ�����
void seqEnQueueLoop(seqQueue &sQ){
    cout << "����������Ԫ��(����9999�˳�)" << endl;
    QelementType x;
    cin >> x;

    while(x!=9999){
        if(seqQueueFull(sQ)){
            cout << "����!���������Ӳ���!" << endl;
        }
        else{
            sQ.rear=(sQ.rear+1)%MaxLen;       //����rear
            sQ.data[sQ.rear]=x;               //��������x
            cin >> x;
        }
    }
}

//���.
void seqEnQueue(seqQueue &sQ, QelementType x){
    if(seqQueueFull(sQ)){
        cout << "����!���������Ӳ���!" << endl;
    }
    else{
        sQ.rear=(sQ.rear+1)%MaxLen;       //����rear
        sQ.data[sQ.rear]=x;               //��������x
    }
}

//5.����
void seqOutQueue(seqQueue &sQ, QelementType x){
    if(seqQueueEmpty(sQ)){
        cout << "�ӿ�!����ȡ��ͷԪ��!" << endl;
    }
    else{
        x=sQ.data[(sQ.front+1)%MaxLen];           //frontָʾ����һ����Ԫ���Ƕ�ͷԪ��
        sQ.front=(sQ.front+1)%MaxLen;             //frontָ�����һ����λ
    }
}

//6.ȡ��ͷԪ��
void seqQueueFront(seqQueue &sQ, QelementType &x){
    if(seqQueueEmpty(sQ)){
        cout << "�ӿ�!����ȡ��ͷԪ��!" << endl;
    }
    else{
        x=sQ.data[(sQ.front+1)%MaxLen];           //frontָʾ����һ����Ԫ���Ƕ�ͷԪ��
        cout << x << endl;                        //��ӡx
    }
}

//7.�����Ԫ�ظ���
void seqQueueLength(seqQueue &sQ){
    int iLen;
    iLen=(sQ.rear-sQ.front+MaxLen)%MaxLen;
    cout << "����Ԫ�ظ���Ϊ" << iLen <<  "��." << endl;
}
