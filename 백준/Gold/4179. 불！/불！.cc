#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int visJ[1002][1002];
int visF[1002][1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int R, C, flag = 0;
	int cnt = 0;
	cin >> R >> C;
	pair<int, int> J;
	pair<int, int>F;
	string* arr = new string[R];
	for (int i = 0; i < R; i++) {
		fill(visJ[i], visJ[i] + C, -1);
		fill(visF[i], visF[i] + C, -1);
	}
	queue < pair<int, int>> q1; //지훈이
	queue<pair<int, int>>q2; // 불
	for (int i = 0; i < R; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'J') {
				J = { i,j };
				visJ[i][j] = 0;
				q1.push(J);
				flag++;
			}
			else if (arr[i][j] == 'F') {
				F = { i,j };
				visF[i][j] = 0;
				q2.push(F);
				flag++;
			}
		}
	}
	while (!q2.empty()) {
		auto curF = q2.front();
		q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nxF = curF.X + dx[dir];
			int nyF = curF.Y + dy[dir];
			if (nxF < 0 || nxF >= R || nyF < 0 || nyF >= C) continue;
			if (visF[nxF][nyF] >= 0 ||arr[nxF][nyF] == '#' ) continue;
			visF[nxF][nyF] = visF[curF.X][curF.Y] + 1;
			q2.push({ nxF,nyF });
		}
	}
	while (!q1.empty()) {
		auto curJ = q1.front();
		q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nxJ = curJ.X + dx[dir];
			int nyJ = curJ.Y + dy[dir];
			if (nxJ < 0 || nxJ >= R || nyJ < 0 || nyJ >= C) {
				cout << visJ[curJ.X][curJ.Y] + 1;
				return 0;
			}
			if (visJ[nxJ][nyJ]>=0 || arr[nxJ][nyJ] == '#') continue;
			if (visF[nxJ][nyJ] != -1 && visF[nxJ][nyJ] <= visJ[curJ.X][curJ.Y] + 1)continue;
			visJ[nxJ][nyJ] = visJ[curJ.X][curJ.Y] + 1;
			q1.push({ nxJ,nyJ });
		}
	}
	cout << "IMPOSSIBLE";
}