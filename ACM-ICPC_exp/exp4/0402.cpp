/** encoding:WINDOWS-936 **/

/*

(2)  ���������ַ���a��b���ֽ���aͨ���任��Ϊ��b�����õĲ���Ϊ��ɾ����a�е�һ
���ַ����ڴ�a��ĳ��λ�ò���һ��Ԫ�أ�����a�е�ĳ����ĸ��Ϊ��һ����ĸ������
����Ĵ�a�ʹ�b��������ٶ��ٴ��ܹ�������Ϊ��b��
˼��������任�Ĳ��衣

*/

# include <iostream>
# include <stack>

using namespace std;

//stack<char> ans;
int ans;
string str1;
string str2;
int mat[100][100];

int min3(int a, int b, int c){
    int min2 = min(a, b);
    return min(min2, c);
}

///test
void print(){
    for(int i=0; i<str1.length(); ++i){
        for(int j=0; j<str2.length(); ++j){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    str1 = "abcff2";
    str2 = "bce543d";

    mat[str1.length()][str2.length()];
    // ������һ��
    for(int i=0; i<str2.length(); ++i){
        mat[0][i] = i;
    }
    // ������һ��
    for(int i=0; i<str1.length(); ++i){
        mat[i][0] = i;
    }
    // ���ƹ�ʽ����mat[i][j]
    for(int i=1; i<str1.length(); ++i){
        for(int j=1; j<str2.length(); ++j){
            mat[i][j] = min3(mat[i-1][j]+1, mat[i][j-1]+1, mat[i-1][j-1]+(str1[i]==str2[j]?0:1));
        }
    }

    print();
    // ���һ�У����һ��Ϊ��С�༭����
    ans = mat[str1.length()-1][str2.length()-1];
    cout << ans << endl;

    return 0;
}
