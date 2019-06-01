/** encoding: gbk **/

/*

(2) ��ϰ�����㷨��ʹ�á�
����һ��vector��Ԫ������Ϊint������10���������ʹ��sort�������������
ÿ��Ԫ�ص�ֵ���ٰ������������ÿ��Ԫ�ص�ֵ����ϰ��find����Ԫ�ء���min��
max�ҳ������е���СԪ�ظ����Ԫ�أ��������

*/

# include <algorithm>
# include <vector>
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
        cout << (*it) << ' ';
    }

    cout << "\n�����㷨sort��vector����(����)" << endl;

    // �����㷨sort��vector����(����)
    sort(myV.begin(), myV.end());

    // ����������vector�����Ԫ��ֵ
    for (it = myV.begin(); it != myV.end(); ++it){
        cout << (*it) << ' ';
    }

    cout << "\n�����㷨sort��vector����(����)" << endl;

    // �����㷨sort��vector����(����)
    sort(myV.begin(), myV.end(), greater<int>());

    // ����������vector�����Ԫ��ֵ
    for (it = myV.begin(); it != myV.end(); ++it){
        cout << (*it) << ' ';
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

    // ����������list�����Ԫ��ֵ
    for (it = myV.begin(); it != myV.end(); ++it){
        cout << *it << ' ';
    }

    cout << "\n�ҳ������е���СԪ�ظ����Ԫ��" << endl;

    //��min��max�ҳ������е���СԪ�ظ����Ԫ�أ��������
    int max = *max_element(myV.begin(), myV.end());

    cout << "max=" << max << endl;

    int min = *min_element(myV.begin(), myV.end());

    cout << "min=" << min << endl;
}

int main(int argc, char *argv[]){
    cout << "--------vector--------" << endl;
    myVector();
    cout << "------vector end------" << endl;

    return 0;
}
