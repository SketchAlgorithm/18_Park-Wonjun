#include <string>
#include <queue>
#include <iostream>
using namespace std;

class State
{
public : 
	int m, n, block;
	
	State(const int& m, const int& n, const int& block)
		: m(m), n(n), block(block) {}
	friend bool operator<(const State&, const State&);
};
bool operator<(const State& a, const State& b) { return a.block > b.block; }

const int mx[] = {1, 0, -1, 0};
const int my[] = {0, 1, 0, -1};
int N, M;
char** maze;	// 미로
bool** visited;

int Algospot();

int main(void)
{
	cin >> N >> M;

	/*동적할당 및 초기화*/
	maze = new char*[M];
	visited = new bool*[M];
	for (int i = 0; i < M; i++)
	{
		maze[i] = new char[N];
		visited[i] = new bool[N];
		for (int j = 0; j < N; j++)
		{
			cin >> maze[i][j];
			visited[i][j] = false;
		}
	}

	/*탐색 및 결과 출력*/
	cout << Algospot() << endl;

	/*메모리 해제*/
	for (int i = 0; i < M; i++)
		delete maze[i];
	delete[]maze;

	return 0;
}

int Algospot()
{
	priority_queue<State> cur;
	cur.push({ 0,0,0 });

	while (!cur.empty())
	{
		auto now = cur.top();
		cur.pop();

		// 제일 먼저 목적지에 도착한 것 == 최소로 벽을 깬 것(priority queue)
		if (now.m == M - 1 && now.n == N - 1)
		{
			//while (!cur.empty())	cur.pop();
			return now.block;
		}

		for (int i = 0; i < 4; i++)
		{
			int move_m = now.m + mx[i];
			int move_n = now.n + my[i];

			// index 예외처리
			if (move_m < 0 || move_n < 0)	continue;
			else if (move_m >= M || move_n >= N)	continue;

			// 이미 방문한 곳은 가지 않음
			if (visited[move_m][move_n])	continue;

			visited[move_m][move_n] = true;
			cur.push({ move_m, move_n, maze[move_m][move_n] == '1' ? now.block + 1 : now.block });
		}
	}

	return -1;
}
