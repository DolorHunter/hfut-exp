#pragma once
#define elementType int
#define MaxLen 100

using namespace std;

//˳����д洢�ṹ����
typedef struct sQueue{
    elementType data[MaxLen];       //��Ŷ���Ԫ��
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
void seqEnQueue(seqQueue &sQ){
    cout << "����������Ԫ��(����9999�˳�)" << endl;
    elementType x;
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

    _pause();                        //��ͣ
}

//���.
void seqEnQueueOnce(seqQueue &sQ, elementType &x){
    if(seqQueueFull(sQ)){
        cout << "����!���������Ӳ���!" << endl;
    }
    else{
        sQ.rear=(sQ.rear+1)%MaxLen;       //����rear
        sQ.data[sQ.rear]=x;               //��������x
    }
}

//5.����
void seqOutQueue(seqQueue &sQ, elementType &x){
    if(seqQueueEmpty(sQ)){
        cout << "�ӿ�!����ȡ��ͷԪ��!" << endl;
    }
    else{
        x=sQ.data[(sQ.front+1)%MaxLen];           //frontָʾ����һ����Ԫ���Ƕ�ͷԪ��
        cout << x << endl;                      //��ӡx
        sQ.front=(sQ.front+1)%MaxLen;     //frontָ�����һ����λ
    }

    _pause();                        //��ͣ
}

//6.ȡ��ͷԪ��
void seqQueueFront(seqQueue &sQ, elementType &x){
    if(seqQueueEmpty(sQ)){
        cout << "�ӿ�!����ȡ��ͷԪ��!" << endl;
    }
    else{
        x=sQ.data[(sQ.front+1)%MaxLen];           //frontָʾ����һ����Ԫ���Ƕ�ͷԪ��
        cout << x << endl;                        //��ӡx
    }

    _pause();                        //��ͣ
}

//7.�����Ԫ�ظ���
void seqQueueLength(seqQueue &sQ){
    int iLen;
    iLen=(sQ.rear-sQ.front+MaxLen)%MaxLen;
    cout << "����Ԫ�ظ���Ϊ" << iLen <<  "��." << endl;

    _pause();                        //��ͣ
}

//8.����ż���㷨
void seqQueueOddInEvenOut(seqQueue &sQ){
    initialSeqQueue(sQ);
    cout << "������Ԫ��(����0�˳�):";
    elementType x;
    cin >> x;
    while(x!=0){
        if(x%2==1){
            seqEnQueueOnce(sQ, x);
            cout << "��ӳɹ�!" << endl;
            prtSeqQueue(sQ);                 //��ӡLinkedQueue
            cout << "������Ԫ��(����0�˳�):";
            cin >> x;
        }
        else{
            if(seqQueueEmpty(sQ)){
                seqOutQueue(sQ, x);
            }
            else{
                seqOutQueue(sQ, x);
                cout << "���ӳɹ�!" << endl;
            }
            prtSeqQueue(sQ);                 //��ӡLinkedQueue
            cout << "������Ԫ��(����0�˳�):";
            cin >> x;
        }
    }

    _pause();                        //��ͣ
}
