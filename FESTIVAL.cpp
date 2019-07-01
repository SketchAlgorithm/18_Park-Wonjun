/*
*	Quest URL : https://algospot.com/judge/problem/read/FESTIVAL
*	박원준
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
		printf("%.12lf\n", Festival());
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
