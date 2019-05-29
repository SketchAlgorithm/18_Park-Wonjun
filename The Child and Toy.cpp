#include <queue>
#include <iostream>
using namespace std;

int n, m;
int* parts;

int main(void)
{
	/*데이터 입력*/
	cin >> n >> m;
	parts = new int[n];
	for (int i = 0; i < n; i++)
		cin >> parts[i];

	/*TC 입력 & 계산*/
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		int part1, part2;
		cin >> part1 >> part2;
		sum += (parts[part1 - 1] > parts[part2 - 1] ? parts[part2 - 1] : parts[part1 - 1]);
	}

	/*결과 출력*/
	cout << sum << endl;

	/*동적 메모리 해제*/
	delete[]parts;
	
	return 0;
}
