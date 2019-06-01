/** encoding: gbk **/

/*

(3)  ��ʿ�������⣺
�ڹ���������ʹһ����ʿ�������еĸ���һ���ҽ�һ�飬������������Ķ��㣬
���һ����������Ҫ���·����

*/

# include <iostream>
# include <cstring>
# include <stack>

// �����������
# define MAXROW 8
# define MAXCOL 8

using namespace std;

void printBoard();
void printRoute();

stack<pair<int, int> > route;
// ��ʼ������
bool board[MAXROW][MAXCOL];
// ��ʿ�߷�(x��1, y��2), (x��2, y��1) ��8�����
const int delX[8]={-2,-2,-1,-1, 1, 1, 2, 2};   // ������X
const int delY[8]={-1, 1,-2, 2,-2, 2,-1, 1};   // ������Y

int ct=0;

bool inBoard(int x, int y){
    if((0<=x && x<MAXROW) && (0<=y && y<MAXCOL))
        return true;
    return false;
}

bool newBlock(int x, int y){
    return !board[x][y];
}

bool doneTravel(){
	for(int i=0; i<MAXROW; ++i){
		for(int j=0; j<MAXCOL; ++j){
			if(!board[i][j])
				return false;
		}
	}
	return true;
}

void gotoPos(int x, int y){
	board[x][y] = true;
	route.push(make_pair(x, y));
	// ��·����ӡ·�����˳�
	if(doneTravel() && route.size() == MAXROW*MAXCOL){
        ///ct++;   // count route
        ///cout << "--------" << ct << "--------" << endl;
        printRoute();
        exit(0);// ����һ��·�ߺ�exit()ǿ���˳�
        ///return ;// ��������·�ߺ�return�˳�
	}
	for(int i=0; i<8; ++i){
		int nextX = x + delX[i];
		int nextY = y + delY[i];
        // ������������, ��Ϊ�µĵ�
		if(newBlock(nextX, nextY) && inBoard(nextX, nextY)){
			gotoPos(nextX, nextY);
			board[nextX][nextY] = false;
            route.pop();
		}
	}
}

void printRoute(){
	stack<pair<int, int> > prtS=route;
	int CR = 0;
	while(!prtS.empty()){
		pair<int, int> p = prtS.top();
		cout << "(" << p.first << ", " << p.second << ") ";
		prtS.pop();
		CR++;
		if(CR%MAXCOL==0)
            cout << endl;
	}
}

/// test
void printBoard(){
    for(int i=0; i<MAXROW; ++i){
        for(int j=0; j<MAXCOL; ++j){
            if(board[i][j] == 0)
                cout << 0 ;
            else
                cout << 1;
        }
        cout << endl;
    }
}


int main(int argc, char *argv[]){
	int x=-1, y=-1;
	while(!inBoard(x, y)){
        cout << "�������ʼ������:";
        cin >> x;
        cout << "�������ʼ������:";
        cin >> y;
    }
    gotoPos(x, y);
	return 0;
}
