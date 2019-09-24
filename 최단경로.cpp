/*
*	최단경로.
*	Quest URL : https://www.acmicpc.net/problem/1753

*	박원준
*	2019.09.24

*	log : .
*/
/* 전처리 상수 정의 */
#define MAX 20001
#define INF 987654321
/**/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Class 선언 및 정의 */
class DirectedGraph
{
public : 
	int u, v;	// u : 시작 Node, v : 끝 Node.
	int w;		// w : Edge의 weight.

	DirectedGraph(int u, int v, int w) : u(u), v(v), w(w) {}
	friend bool operator<(const DirectedGraph& a, const DirectedGraph& b);
};
bool operator<(const DirectedGraph& a, const DirectedGraph& b) { return a.w > b.w; }

/* 전역변수 선언 및 정의 */
int V, E;	// V : Number of Vertex. E : Number of Edge
int start_node;	// start_node : 그래프 시작점.
vector<pair<int, int>> graph[MAX];	// first: Edge 목적지. second: Edge Weight.
vector<int> result;

/* 전역함수 Dijkstra() 선언 */
vector<int> Dijkstra(int start, int vertex);

/* main() 정의 */
int main(void)
{
	/* Input Data */
	cin >> V >> E;
	V++;	// 1번부터 시작.
	cin >> start_node;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back(pair<int, int>(v, w));
	}

	/* Search */
	result = Dijkstra(start_node, V);
	
	/* Print Result */
	//for (int e : result)
	for (int i = 1; i < V; i++)
		if (result[i] == INF)
			cout << "INF" << endl;
		else
			cout << result[i] << endl;

	return 0;
}

/* 전역함수 DIjkstra() 정의 */
vector<int> Dijkstra(int start, int vertex)
{
	vector<int> distance(vertex, INF);	// vertex개의 배열. -1로 초기화.
	// distance[vertex]에는 vertex로 가는 최단경로의 weight 합이 들어있음.
	distance[start] = 0;	// 자기 자신에게 가는 것 0.

	priority_queue<pair<int, int>> pq;	// first: cost. second: vertex.
	pq.push(pair<int, int>(0, start));	// 초기 비용과 시작점.

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		// -의 이유.	pq의 deafult 순서를 뒤집기 위해 cost를 -로 넣음.
		
		int curVertex = pq.top().second;
		pq.pop();

		// if문의 이유.
		if (distance[curVertex] < cost)	continue;

		for (int i = 0; i < graph[curVertex].size(); i++)
		{
			int neighbor = graph[curVertex][i].first;	// curVertex에서 first로 가는 Edge가 있을 때, first.
			int neighbor_distance = cost + graph[curVertex][i].second;	// curVertex에서 first로 가는 Edge가 있을 때, Edge의 weight.

			if (distance[neighbor] > neighbor_distance)
			{
				distance[neighbor] = neighbor_distance;
				// pq의 default 순서를 뒤집기 위해.
				pq.push(pair<int, int>(-neighbor_distance, neighbor));
			}
		}
	}

	return distance;
}
