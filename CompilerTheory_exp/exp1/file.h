#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#pragma once
#include<iostream>
#include<cstdio>
#include<string.h>
        ///300�л�����
#define MAXWORDS 20
#define MAXLEN 10

using namespace std;

//���������ļ�����ؼ���
bool readFileToArray(char *fileName, char keyWords[MAXWORDS][MAXLEN]){
    FILE *fp;
    char str[65535];
    fp=fopen(fileName, "r");
    if(fp==NULL){
        cout << "�����ļ���ʧ��!" << endl;
        return false;
    }
    //Read the identification and judge
    if(fgets(str, 1000, fp)!=NULL){
        if(fileName=="keywords.txt"){
            if(strcmp(str, "Keywords\n")!=0){
            cout << "�򿪵��ļ���ʽ����!" << endl;
            return false;
            fclose(fp);
            }
        }
        if(fileName=="delimiters.txt"){
            if(strcmp(str, "Delimiters\n")!=0){
            cout << "�򿪵��ļ���ʽ����!" << endl;
            return false;
            fclose(fp);
            }
        }
    }
    //Empty file protection
    else{
        cout << "�򿪵��ļ�" << fileName << "Ϊ��!" << endl;
        return false;
        fclose(fp);
    }
    int Line=0;
    while(fscanf(fp, "%s\n", &keyWords[Line]) != EOF){
        Line++;
    }
    fclose(fp);
    return true;
}

#endif // FILE_H_INCLUDED
