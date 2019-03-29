#pragma once
#include<iostream>
#include<cstdio>

using namespace std;

//���������ļ���������
//////////////////////////////////////////////////////////////////////////////////////
//����:ReadFileToArray(char fileName[], char strLine[100][3], int &nArrLen)         //
//����˵��:                                                                         //
//fileName[]����ļ���                                                              //
//strLine[][3]��Ž��Ķ�ά����, �����3�ж�Ӧ�����ļ�������                       //
//nArrLen���ض��������ĸ���                                                       //
//////////////////////////////////////////////////////////////////////////////////////
bool ReadFileToArray(char *fileName, char strLine[100][3], int &nArrLen){
    FILE *fp;
    char str[1000];
    fp=fopen(fileName, "r");
    if(fp==NULL){
        cout << "�����������ļ���ʧ��!" << endl;
        return false;
    }
    //�����һ���ж϶�������ʶBinaryTree�Ƿ���ȷ
    if(fgets(str, 1000, fp)!=NULL){
        if(strcmp(str, "BinaryTree\n")!=0){
            cout << "�򿪵��ļ���ʽ����!" << endl;
            return false;
            fclose(fp);
        }
    }
    //���ļ�����
    else{
        cout << "�򿪵��ļ�Ϊ��!" << endl;
        return false;
        fclose(fp);
    }
    nArrLen=0;
    while(fscanf(fp, "%c %c %c\n", &strLine[nArrLen][0], &strLine[nArrLen][1], &strLine[nArrLen][2]) != EOF){
        nArrLen++;
    }
    fclose(fp);
    return true;
}

//�����鰴������򴴽�������
//////////////////////////////////////////////////////////////////////////////////////
//����:CreatBiTreeFromArray(BiNode *&pBT, char strLine[100][3], int nLen, int &nRow)//
//����˵��:                                                                         //
//strLine[100][3]Ϊ���������ݵĶ�ά����                                           //
//nArrLenΪ������                                                                    //
//nRowΪ���鵱ǰ�к�                                                                //
//////////////////////////////////////////////////////////////////////////////////////
bool CreatBiTreeFromArray(BiNode *&pBT, char strLine[100][3], int nArrLen, int &nRow){
    if(nRow>=nArrLen || nArrLen==0){
        return false;                           //�����Ѿ�������ϻ�û������,�˳�
    }
    //�����������ݵݹ鴴��������
    pBT=new BiNode;                             //�������ڵ�
    pBT->data=strLine[nRow][0];
    pBT->lChild=NULL;
    pBT->rChild=NULL;
    int nRowNext=nRow;  //�������εݹ���к�
    if(strLine[nRowNext][1]=='1'){
        //��ǰ�����������,����һ������,�ݹ���ô���������
        nRow++;
        CreatBiTreeFromArray(pBT->lChild, strLine, nArrLen, nRow);
    }
    if(strLine[nRowNext][2]=='1'){
        //��ǰ�ڵ���������,����һ������,�ݹ���ô���������
        nRow++;
        CreatBiTreeFromArray(pBT->rChild, strLine, nArrLen, nRow);
    }
    return true;
}

//��װReadFileToArray() &CreatBiTreeFromArray()����
void CreatBiTree(BiNode *&T, char (&fileName)[20], char (&strLine)[100][3], int &nArrLen, int &nRow){
    bool import=false;
    nRow=0;
    if(ReadFileToArray(fileName, strLine, nArrLen)){
        if(CreatBiTreeFromArray(T, strLine, nArrLen, nRow)){
            cout << "����������ɹ�!" << endl;
            import=true;
        }
    }
    if(!import){
        cout << "����������ʧ��!ִ��exit(1)." << endl;
        exit(1);
    }
}

//��ʾ���Դ򿪵�.btr�ļ�
void openFile(char fileName[20]){
    system("CLS");
    cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "�������ǿɵ�������ļ�:                                   ��" << endl;
    cout << "�����������������������������������������������������������Щ�������������������������������������������������������" << endl;
	cout << "��1. bt4.btr                  ��7. bt15.btr                ��" << endl;
	cout << "��2. bt8.btr                  ��8. bt21.btr                ��" << endl;
	cout << "��3. bt9.btr                  ��9. bt261.btr               ��" << endl;
	cout << "��4. bt10.btr                 ��10.bt262.btr               ��" << endl;
	cout << "��5. bt12.btr                 ��11.fu1l4.btr               ��" << endl;
	cout << "��6. bt14.btr                 ��12.fu1l5.btr               ��" << endl;
	cout << "�����������������������������������������������������������ة�������������������������������������������������������" << endl;
    cout << "��ѡ����Ҫ������������:" ;
    int choseFile;
    cin >> choseFile;
    cin.get();
    switch(choseFile){
        case 1:
            sprintf(fileName, "%s", "D:\\download\\BTdata\\bt4.btr");
            break;
        case 2:
            sprintf(fileName, "%s", "D:\\download\\BTdata\\bt8.btr");
            break;
        case 3:
            sprintf(fileName, "%s", "D:\\download\\BTdata\\bt9.btr");
            break;
        case 4:
            sprintf(fileName, "%s", "D:\\download\\BTdata\\bt10.btr");
            break;
        case 5:
            sprintf(fileName, "%s", "D:\\download\\BTdata\\bt12.btr");
            break;
        case 6:
            sprintf(fileName, "%s", "D:\\download\\BTdata\\bt14.btr");
            break;
        case 7:
            sprintf(fileName, "%s", "D:\\download\\BTdata\\bt15.btr");
            break;
        case 8:
            sprintf(fileName, "%s", "D:\\download\\BTdata\\bt21.btr");
            break;
        case 9:
            sprintf(fileName, "%s", "D:\\download\\BTdata\\bt261.btr");
            break;
        case 10:
            sprintf(fileName, "%s", "D:\\download\\BTdata\\bt262.btr");
            break;
        case 11:
            sprintf(fileName, "%s", "D:\\download\\BTdata\\full4.btr");
            break;
        case 12:
            sprintf(fileName, "%s", "D:\\download\\BTdata\\full5.btr");
            break;
        default:
            break;
    }
}
