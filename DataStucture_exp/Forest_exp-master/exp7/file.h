#pragma once
#include<iostream>
#include<cstdio>
#include<string.h>
#include"forest.h"

using namespace std;

//ɾ���ַ������ַ�������߿ո�
void strLTrim(char* str)
{
	int i,j;
	int n=0;
	n=strlen(str)+1;
	for(i=0;i<n;i++)
	{
		if(str[i]!=' ')  //�ҵ������һ���ǿո�λ��
			break;
	}
	    //�Ե�һ���ǿո��ַ�Ϊ���ַ��ƶ��ַ���
	for(j=0;j<n;j++)
	{
		str[j]=str[i];
		i++;
	}
}
//****************** �ļ�����˫�ױ�ʾ������ɭ�֣�********************//
//* �������ܣ����ı��ļ�����˫�ױ�ʾ��ͼ                            *//
//* ��ڲ���  char fileName[]�������ļ���                           *//
//* ���ڲ�����pTree &T������������                                  *//
//* �� �� ֵ��bool��true�����ɹ���false����ʧ��                     *//
//* �� �� ����CreateTreeFromFile(char fileName[], pTree &T)         *//
//* ��ע��������ʹ�õ������ļ���ʽ�Աߣ����Ӷԣ�Ϊ��������          *//
//*******************************************************************//
bool createTreeFromFile(char fileName[], pTree &T)
{
	FILE* pFile;     //����˳�����ļ�ָ��
	char str[1000];  //��Ŷ���һ���ı����ַ���
	char strTemp[10]; //�ж��Ƿ�ע����

    int i=0,j=0;


	pFile=fopen(fileName,"r");
	if(!pFile)
	{
		printf("�����ļ�%s��ʧ�ܡ�\n",fileName);
		return false;
	}

	while(fgets(str,1000,pFile)!=NULL)  //�������к�ע����
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //����ע����
			continue;
		else  //��ע���С��ǿ��У�����ѭ��
			break;
	}

    //ѭ��������str��Ӧ���Ѿ����ļ���ʶ���ж��ļ���ʽ
	if(strstr(str,"Tree or Forest")==NULL)
	{
		printf("���󣺴򿪵��ļ���ʽ����\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}


	//��ȡ������ݣ���str����������
	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;
		else  //�ǿ��У�Ҳ��ע���У���ͼ�Ķ���Ԫ����
			break;
	}

	//������ݴ������Ľ������
	char* token=strtok(str," ");
	int nNum=0;
	while(token!=NULL)
	{
		T.node[nNum].data=*token;
		T.node[nNum].parent=-1;       //�����ָ���ʼ��Ϊ-1

		token = strtok( NULL, " ");

		nNum++;
	}

    //ѭ����ȡ�ߣ����Ӷӣ�����
	int nP;  //����������±�
	int nC;  //�ӽ�������±�

	elementType Nf,Ns; //���ӽ��Ե��������
	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;

		char* token=strtok(str," ");  //�Կո�Ϊ�ָ������ָ�һ�����ݣ�д���ڽӾ���

		if(token==NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡ���ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}
		Nf=*token;  //��ȡ�����

		token = strtok( NULL, " ");  //��ȡ��һ���Ӵ������ӽ��
		if(token==NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡ���ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}

		Ns=*token;  //��ȡ�ߵĵڶ�����㣨�ӽ�㣩
            //ȡ�ø�����±�
		for(nP=0;nP<nNum;nP++)
		{
			if(T.node[nP].data==Nf)  //�Ӷ����б��ҵ���һ������ı��
				break;
		}
           //��ȡ�ӽ��������±�
		for(nC=0;nC<nNum;nC++)
		{
			if(T.node[nC].data==Ns)  //�Ӷ����б��ҵ��ڶ�������ı��
				break;
		}

		T.node[nC].parent=nP;        //nC�ĸ������±�ΪnP
	}

    T.n=nNum;  //���Ľ�����������������ʵ�ʴ�С

	fclose(pFile); //�ر��ļ�
	return true;
}

//��ʾ���Դ򿪵�.tre�ļ�
void openFile(char fileName[20]){
    system("CLS");
    cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "�� �����ǿɵ�������ļ�:                                  ��" << endl;
    cout << "�����������������������������������������������������������Щ�������������������������������������������������������" << endl;
	cout << "��1. F14.tre                  ��4. F20.tre                 ��" << endl;
	cout << "��2. F16.tre                  ��5. tree10.tre              ��" << endl;
	cout << "��3. F18.tre                  ��6. tree11.tre              ��" << endl;
	cout << "�����������������������������������������������������������ة�������������������������������������������������������" << endl;
    cout << "��ѡ����Ҫ������������:" ;
    int choseFile;
    cin >> choseFile;
    cin.get();
    switch(choseFile){
        case 1:
            sprintf(fileName, "%s", "D:\\download\\tData\\F14.tre");
            break;
        case 2:
            sprintf(fileName, "%s", "D:\\download\\tData\\F16.tre");
            break;
        case 3:
            sprintf(fileName, "%s", "D:\\download\\tData\\F18.tre");
            break;
        case 4:
            sprintf(fileName, "%s", "D:\\download\\tData\\F20.tre");
            break;
        case 5:
            sprintf(fileName, "%s", "D:\\download\\tData\\tree10.tre");
            break;
        case 6:
            sprintf(fileName, "%s", "D:\\download\\tData\\tree11.tre");
            break;

        default:
            break;
    }
}
