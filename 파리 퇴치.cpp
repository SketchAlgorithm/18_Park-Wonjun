#include <iostream>
using namespace std;

int T;	//Test Cast Number
int N, M;
int** area;	// 배열 칸마다 파리의 갯수 저장

int CatchFly();

int main(void)
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		/*데이터 입력 및 동적할당*/
		cin >> N >> M;
		area = new int*[N];
		for (int j = 0; j < N; j++)
		{
			area[j] = new int[N];
			for (int k = 0; k < N; k++)
				cin >> area[j][k];
		}

		/*함수 호출*/
		cout << "#" << i + 1 << " " << CatchFly() << endl;

		/*메모리 해제*/
		for (int j = 0; j < N; j++)
			delete area[j];
		delete[]area;
	}	

	return 0;
}

int CatchFly()
{
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (i + M > N)	continue;	// 예외처리
		for (int j = 0; j < N; j++)
		{
			if (j + M > N)	continue;	// 예외처리
	
			int sum = 0;
			for (int k = i; k < i + M; k++)
				for (int l = j; l < j + M; l++)
					sum += area[k][l];
	
			if (max < sum)	max = sum;
		}
	}
	
	return max;
}
