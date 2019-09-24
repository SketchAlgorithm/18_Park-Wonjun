/*
*	Water
*	Quest URL : https://www.spoj.com/problems/WATER/

*	2019.09.23
*	박원준

*	log : .
*/
#include <iostream>
#include <queue>
using namespace std;

class Cuboid
{
public : 
	int n, m;				// cuboid의 좌표
	int cuboid_height;		// cuboid의 높이
	int real_height;		// 실제 높이(물 높이 포함)
	int level;				// 탐색 level

	Cuboid() {}
	Cuboid(int n, int m, int cuboid_height) : n(n), m(m), cuboid_height(cuboid_height), real_height(cuboid_height), level(0) {}
	//friend bool operator<(const Cuboid &a, const Cuboid &b);
	bool operator<(const Cuboid& comp) const { return this->real_height > comp.real_height; }
};
//bool operator< (const Cuboid &a, const Cuboid &b) { return a.real_height > b.real_height; }

int t, n, m;
priority_queue<Cuboid*> pq;
Cuboid chessboard[100][100];
queue<Cuboid*> q;

int main(void)
{
	cin >> t;
	while (t--)
	{
		/* Input Data */
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int height;	cin >> height;
				chessboard[i][j] = Cuboid(i, j, height);
				pq.push(&chessboard[i][j]);	// pointer 연산에 대해서도 따로 오버라이딩 해야 됐던가?
			}
		}

		/* Search */
		int level = 1;	// 현재 탐색 level.
		auto cur = pq.top();	pq.pop();
		// 1.첫 탐색이 아래 탐색의 탈출조건에 들어가는 것에 대해서. 예외처리
		while (cur->m == 0 || cur->m == m - 1 || cur->n == n - 1 || cur->n == 0)
		{
			cur = pq.top();
			pq.pop();
		}
		// 2.탐색.
		while (cur->m < m - 1 && cur->n < n - 1 && cur->m > 0 && cur->n > 0)
		{
			cur->real_height++;	cur->level++;

			if (cur->level < level)
				q.push(cur);
			else if (cur->level >= level)
			{
				level++;
				while (!q.empty())	q.pop();
			}

			pq.push(cur);
			cur = pq.top();	pq.pop();
		}
		// 3.동일한 level에서 모서리가 나중에 증가한 경우에 대해. 예외처리.
		while (!q.empty())
		{
			auto temp = q.front();	q.pop();
			temp->real_height--;
		}

		/* Sum Volume of Water */
		int sum = 0;
		for (int i = 1; i < n - 1; i++)
			for (int j = 1; j < m - 1; j++)
				sum += (chessboard[i][j].real_height - chessboard[i][j].cuboid_height);

		/* Print Result */
		cout << sum << endl;
	}

	return 0;
}
