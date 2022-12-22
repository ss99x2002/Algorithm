#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, S, Y;
	// s는 0,1중 하나로 0은 여학생 1은 남학생
	// k는 최대인원수
	// n은 학생수
	// y는 학년
	
	vector<int>F(7);
	vector <int> M(7);
	int Room = 0;

	for (int i = 0; i <=6; i++)
	{
		F[i] = 0;
		M[i] = 0;
	}

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> Y;
		if (S)
		{
			M[Y]++;
		}
		else
		{
			F[Y]++;
		}
	}
	for (int i = 1; i <= 6; i++)
	{
		Room = Room + (F[i] / K) + (M[i] / K);
		if ((F[i] % K) != 0)
		{
			Room++;
		}
		if (((M[i] % K)) != 0)
		{
			Room++;
		}
	}
	cout << Room;	
}
