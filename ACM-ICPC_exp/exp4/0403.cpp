/** encoding:WINDOWS-936 **/

/*

(3)  ����һ�����󣬼������е��Ӿ����к͵����ֵ��
���磬����
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
���Ϊ��15
˼����������ܴ�ʱ������100*100�ľ�����ĳ����ܹ��ܿ�ĵó���������
���ܣ���˼������ö�̬�滮��˼������

*/

# include <iostream>
# include <cstring>

using namespace std;

int a[100][100], p[100][100];

int maxSonMat(int n){
    for(int i=0; i<=n; ++i){
        p[i][0] = 0;
        p[0][i] = 0;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            // �����Ӿ���
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j];
        }
    }
    int MAX = 0;
    // ��������Ӿ����
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            int sum=0;
            for(int k=1; k<=n; ++k){
                // ����i~j��, k~m�еľ���Ԫ�غ�
                int temp = p[j][k] - p[j][k-1] - p[i-1][k] + p[i-1][k-1];
                if(sum > 0)
                    sum += temp;
                else
                    sum = temp;
                // ����������
                if(sum>MAX)
                    MAX = sum;
            }
        }
    }
    return MAX;
}

int main(){
    int n=4;
    int num;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin>>num;
            a[i][j] = num;
        }
    }
    cout << maxSonMat(n) << endl;
}
