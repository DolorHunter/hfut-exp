#pragma once
#include<iostream>
#include<windows.h>
#define MAXLEN 1024
#define elementType int

using namespace std;

//����˳���ṹ��
typedef struct{
    elementType data[MAXLEN];   //����洢����Ԫ�ص�����
    int listLen;                //������ȷ���
}seqList;

//������...
void loading(){
    int i= 0;
    while(i<5){
        system("CLS");
        cout << "loading." << endl;
        Sleep(300);
        i++;
        system("CLS");
        cout << "loading.." << endl;
        Sleep(300);
        i++;
        system("CLS");
        cout << "loading..." << endl;
        Sleep(300);
        i++;
    }
}
//-1. ��ӡ˳���(������)
void printList(seqList *L){
    loading();
    cout << "���ڴ�ӡ˳���..." << endl;
    for(int i=0; i<L->listLen; i++){
        cout << L->data[i] << endl;
    }

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//-2. ����ͣ��ӡ(�����ʹ��)
void prtNpauseList(seqList *L){
    loading();
    for(int i=0; i<L->listLen; i++){
        cout << L->data[i] << endl;
    }
}

//0. ��ʼ��˳���
void initialList(seqList *L){
    loading();
    L->listLen = 0; //˳���ĳ���Ϊ0
}

//1. ����˳���
void buildList(seqList *L){
    loading();
    int bit;
    cout << "������˳���Ĵ�С:" << endl;
    cin >> bit;
    L->listLen = bit;

    for(int i=0; i<bit; i++){
        cout << "�������" << i << "��Ԫ��:" << endl;
        cin >> L->data[i];
    }
    cout << "˳����ѽ���." << endl;

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//2. ����Ԫ��(��˳����е�i��Ԫ��, �������ڱ���)
void searchList(seqList *L){
    loading();
    int iLoc;
    cout << "������Ҫ���ҵ�λ��:" << endl;
    cin >> iLoc;

    //�������ʧ�ܱ�־defeat
    bool defeat;
    if(iLoc<0 || iLoc>L->listLen-1){
        cout << "λ�ô���!����ʧ��!" << endl;
    }
    else{
        for(int i=0; i<L->listLen; i++){
            if(iLoc == i){
                cout << "���ҳɹ�!��λ��Ԫ��Ϊ" << L->data[i] << "." << endl;
                defeat = false;
                break;
            }
        }
        if(defeat){
            cout << "λ����ȷ!����ʧ��!" << endl;
        }
    }

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//3. ����ڵ�(�ڵ�i�����ǰ����ֵΪx�Ľ��)
void insertList(seqList *L){
    loading();
    int iLoc;
    cout << "���������ڵ��λ��:" << endl;
    cin >> iLoc;

    elementType inp;
    cout << "����������ֵ:" << endl;
    cin >> inp;

    if(L->listLen == MAXLEN){
        cout << "���, ���ܲ���!\n" << endl;
    }
    else if(iLoc<0 || iLoc>L->listLen){
        cout << "λ�ô���!\n" << endl;
    }
    else{
        for(int i=L->listLen; i>iLoc-1; i--){
            L->data[i+1] = L->data[i];
        }
        L->data[iLoc] = inp;
        L->listLen++;
    }

    cout << "****����˳���L(�����)****" << endl;
    prtNpauseList(L);

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//4. ɾ���ڵ�(ɾ��˳����е�i��Ԫ�ؽ��)
void deleteList(seqList *L){
    loading();
    int iLoc;
    cout << "������ɾ���ڵ��λ��:" << endl;
    cin >> iLoc;

    if(iLoc<0 || iLoc>L->listLen-1){
        cout << "λ�ô���!\n" << endl;
    }
    else{
        for(int i=iLoc; i<L->listLen; i++){
            L->data[i] = L->data[i+1];
        }
        L->listLen--;
    }

    cout << "****����˳���L(�����)****" << endl;
    prtNpauseList(L);

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//5. ��������(��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ��������������������)
void increinseList(seqList *L){
    loading();
    elementType inp;
    cout << "��������������ֵ:" << endl;
    cin >> inp;

    if(L->listLen == MAXLEN){
        cout << "���, ���ܲ���!\n" << endl;
    }
    else{
        int iLoc;
        for(int j=L->listLen; j>=0; j--){
            if(inp > L->data[j]){
                iLoc = j+1;
                break;
            }
            else{
                iLoc = 0;   //С������Ԫ��ͷ��
            }
        }
        for(int j=L->listLen; j>=iLoc; j--){
            L->data[j+1] = L->data[j];
        }
        L->data[iLoc] = inp;
        L->listLen++;
    }

    cout << "****����˳���L(�����)****" << endl;
    prtNpauseList(L);

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//6. ������ż(��˳�����е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µ�˳�����)
void seperateOEList(seqList *L){
    loading();
    seqList A;
    seqList B;
    initialList(&A);    //��ʼ��˳���A(�������)
    initialList(&B);    //��ʼ��˳���B(���ż��)
    int iA=0, iB=0;
    for(int i=0; i<L->listLen; i++){
        if((L->data[i] % 2) ==1){
            A.data[iA] = L->data[i];
            iA++;
            A.listLen++;
        }
        else{
            B.data[iB] = L->data[i];
            iB++;
            B.listLen++;
        }
    }

    cout << "****����˳���L(ԭʼ��)****" << endl;
    prtNpauseList(L);  //��ӡ˳���L

    cout << "****����˳���A(������)****" << endl;
    prtNpauseList(&A);  //��ӡ˳���A

    cout << "****����˳���B(ż����)****" << endl;
    prtNpauseList(&B);  //��ӡ˳���B

    cout << "���뻻���Լ���." << endl;
    getchar();
}

//7. ��ȡ����Ԫ��(��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3��)
void mixIncreList(){
    loading();
    seqList L1;
    seqList L2;
    seqList L3;
    initialList(&L1);
    initialList(&L2);
    initialList(&L3);

    cout << "****���ڽ���˳���L1****" << endl;
    buildList(&L1);
    cout << "****˳���L1�������!****\n" << endl;

    cout << "****���ڽ���˳���L2****" << endl;
    buildList(&L2);
    cout << "****˳���L2�������!****\n" << endl;

    int iA=0, iB=0, iC=0;
    int Lmax = L1.listLen>L2.listLen?L1.listLen:L2.listLen;

    for(int i=0; i<Lmax; i++){
        if(L1.data[iA] == L2.data[iB]){
            L3.data[iC] = L1.data[iA];
            L3.listLen++;

            iA++;
            iB++;
            iC++;
        }
        else if(L1.data[iA] > L2.data[iB]){
            iB++;
        }
        else{
            iA++;
        }
    }

    cout << "****����˳���L1(�����)****" << endl;
    prtNpauseList(&L1);  //��ӡ˳���L

    cout << "****����˳���L2(�����)****" << endl;
    prtNpauseList(&L2);  //��ӡ˳���A

    cout << "****����˳���L3(���ɱ�)****" << endl;
    prtNpauseList(&L3);  //��ӡ˳���B

    cout << "���뻻���Լ���." << endl; ///��߶���һ���س���Ϊʲô???
}

//8. ȥ��(ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش�����Ҫ��ʱ���������)
void delRepList(seqList *L){
    loading();
    for(int i=L->listLen; i>=0; i--){
        if(L->data[i] == L->data[i-1]){
            int iLoc=i;
            for(int j=iLoc; j<L->listLen; j++){
                L->data[j-1] = L->data[j];
            }
            L->listLen--;
        }
    }

    cout << "****����˳���L(ȥ�غ�)****" << endl;
    prtNpauseList(L);

    cout << "���뻻���Լ���." << endl;
    getchar();
}
