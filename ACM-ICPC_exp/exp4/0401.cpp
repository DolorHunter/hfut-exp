/** encoding:WINDOWS-936 **/

/*

(1)  �������ַ���������������С�
X��һ������������Ӧ��X�±�����{1, 2, ��, m}��һ�������У�����������е�����
�������г������ģ��������룺pear, peach�����pea��

*/

# include <iostream>
# include <cstring>
# include <stack>

using namespace std;


int matrix[100][100];
string str1;
string str2;
int len;
int x, y;
stack<char> ans;

int main(){
    str1 = "abbabcdef";
    str2 = "ababbcdef";

    len = 0;

    matrix[str1.length()][str2.length()];
    // ���ҳ�ֵΪ1����Խ��߾����ҵ�������Ӵ�
    for(int i=0; i<str1.length(); ++i){
        for(int j=0; j<str2.length(); ++j){
            if(str1[i] == str2[j]){
                if(i>0 && j>0){
                    matrix[i][j] = matrix[i-1][j-1] + 1;
                }
                else{
                    matrix[i][j] = 1;
                }

                if(matrix[i][j] > len){
                    len = matrix[i][j];
                    x = i;
                    y = j;
                }
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }

    for(int i=0; i<len; ++i){
        ans.push(str1[x--]);
    }

    cout << len << endl;

    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    return 0;
}
