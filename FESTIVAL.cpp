/*
*	Quest URL : https://algospot.com/judge/problem/read/FESTIVAL
*	박원준
*	log : 1) Problem TestCase 1 Wrong 
			최소비용부터 사용하고, 연속된 일 수가 L을 넘을 시 값 구하는 방법 사용(Greedy)
			해당 TestCase에서 cost 3을 사용할 때, 전체 비용을 사용하는 경우 발생
		: 2) Wrong
			i는 Index가 아닌 상수이므로, 탐색 범위에 포함 해야한다.
			부등호 등호 처리.
*/
#include <algorithm>
#include <iostream>
using namespace std;

int C, N, L;	// C : TestCase, N : 공연장 대여 가능 일 수, L : 최소 공연 일 수
int costs[1000];

double Festival();

int main(void)
{
	cin >> C;
	while (C--)
	{
		// Init Data
		fill(costs, costs + 1000, -1);

		// Input Data
		cin >> N >> L;
		for (int i = 0; i < N; i++)
			cin >> costs[i];

		// Print Answer
		//cout << Festival() << endl;
		printf("%.12lf\n", Festival());

		// Clear Memory
	}

	return 0;
}

double Festival()
{
	double min = 987654321;
	// L부터 시작해서 N까지 봤을 때 최소비용. i : [L, N]
	for (int i = L; i <= N; i++)
	{
		// j부터 i개씩 더해서 가장 작은 것이 무엇인지 비교.	j : [0, N-1]
		for (int j = 0; j < N; j++)
		{
			// index 예외처리
			if (j + i > N)	break;

			double average = 0;
			for (int k = j; k < j + i; k++)	// k : [0, N-1]
				average += costs[k];
			average /= i;

			if (min > average)	min = average;
		}
	}
	return min;
}
