/** encoding: gbk **/

/*

(1) ��ϰvector��list��ʹ�á�
����һ���յ�vector��Ԫ������Ϊint������10����������뵽vector�У��õ���
������vector��������е�Ԫ��ֵ����vectorͷ������һ����������õ���������vector
��������е�Ԫ��ֵ���÷����㷨find����ĳ�������������ҵ�����������򽫴���
����vectorβ�����÷����㷨sort��vector�����õ���������vector��������е�Ԫ
��ֵ��ɾ��vectorβ����Ԫ�أ��õ���������vector��������е�Ԫ��ֵ����vector��
�ա�
����һ��list�����ظ�����ʵ�飬��ע��۲�����

*/

# include <algorithm>
# include <vector>
# include <list>
# include <iostream>

using namespace std;

void myVector(){
    vector<int> myV;

    cout << "����10�����������vector" << endl;

    // ����10�����������vector
    for (int i = 0; i < 10; ++i){
        myV.push_back(rand());
    }

    // ����������vector�����Ԫ��ֵ
    vector<int>::iterator it;
    for (it = myV.begin(); it != myV.end(); ++it){
        cout << *it << ' ';
    }

    cout << "\nͷ�����������" << endl;

    // ͷ�����������
    myV.insert(myV.begin(), rand());

    // ����������vector�����Ԫ��ֵ
    for (it = myV.begin(); it != myV.end(); ++it){
        cout << *it << ' ';
    }

    cout << "\n�����㷨find����ĳ�������" << endl;

    // �����㷨find����ĳ�������
    int x = rand();
    it = find(myV.begin(), myV.end(), x);

    if (*it == x){  // �ҵ����
        cout << *it << endl;
    }
    else{   // �Ҳ�������������β��
        myV.push_back(x);
    }

    // ����������vector�����Ԫ��ֵ
    for (it = myV.begin(); it != myV.end(); ++it){
        cout << *it << ' ';
    }

    cout << "\n�����㷨sort��vector����" << endl;

    // �����㷨sort��vector����
    sort(myV.begin(), myV.end());

    // ����������vector�����Ԫ��ֵ
    for (it = myV.begin(); it != myV.end(); ++it){
        cout << *it << ' ';
    }

    cout << "\nɾ��vectorβ��Ԫ��" << endl;

    // ɾ��vectorβ��Ԫ��
    myV.pop_back();

    // ����������vector�����Ԫ��ֵ
    for (it = myV.begin(); it != myV.end(); ++it){
        cout << *it << ' ';
    }

    cout << "\n��vector���" << endl;

    // ��vector���
    myV.erase(myV.begin(), myV.end());

    // ����������vector�����Ԫ��ֵ
    for (it = myV.begin(); it != myV.end(); ++it){
        cout << *it << ' ';
    }
}

void myList(){
    list<int> myL;

    cout << "����10�����������list" << endl;

    // ����10�����������list
    for (int i = 0; i < 10; ++i){
        myL.push_back(rand());
    }

    // ����������list�����Ԫ��ֵ
    list<int>::iterator it;
    for (it = myL.begin(); it != myL.end(); ++it){
        cout << *it << ' ';
    }

    cout << "\nͷ�����������" << endl;

    // ͷ�����������
    myL.push_front(rand());

    // ����������list�����Ԫ��ֵ
    for (it = myL.begin(); it != myL.end(); ++it){
        cout << *it << ' ';
    }

    cout << "\n�����㷨find����ĳ�������" << endl;

    // �����㷨find����ĳ�������
    int x = rand();
    it = find(myL.begin(), myL.end(), x);

    if (*it == x){  // �ҵ����
        cout << *it << endl;
    }
    else{   // �Ҳ�������������β��
        myL.push_back(x);
    }

    // ����������list�����Ԫ��ֵ
    for (it = myL.begin(); it != myL.end(); ++it){
        cout << *it << ' ';
    }

    cout << "\n�����㷨sort��list����" << endl;

    // �����㷨sort��list����
    myL.sort();

    // ����������list�����Ԫ��ֵ
    for (it = myL.begin(); it != myL.end(); ++it){
        cout << *it << ' ';
    }

    cout << "\nɾ��listβ��Ԫ��" << endl;

    // ɾ��listβ��Ԫ��
    myL.pop_back();

    // ����������list�����Ԫ��ֵ
    for (it = myL.begin(); it != myL.end(); ++it){
        cout << *it << ' ';
    }

    cout << "\n��list���" << endl;

    // ��list���
    myL.erase(myL.begin(), myL.end());

    // ����������list�����Ԫ��ֵ
    for (it = myL.begin(); it != myL.end(); ++it){
        cout << *it << ' ';
    }
}

int main(int argc, char *argv[]){
    cout << "--------vector--------" << endl;
    myVector();
    cout << "------vector end------" << endl;
    cout << "---------list---------" << endl;
    myList();
    cout << "-------list end-------" << endl;

    return 0;
}
