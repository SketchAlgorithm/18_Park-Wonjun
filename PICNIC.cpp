/*
*	quest url : https://www.algospot.com/judge/problem/read/PICNIC
*	박원준
*/

#include <vector>
#include <set>
#include <iostream>
using namespace std;

void Reculsive(int n, vector<set<int>>);

vector<set<int>> vector_set;
vector<bool> am_i_visit;
int count_case;
vector<int> answer;

int main(void)
{
	int C;
	cin >> C;
	while (C-- > 0)
	{
		int n, m;
		cin >> n >> m;	// n : 학생의 수, m : 친구 쌍의 수

		// 전역변수 초기화.
		while (n-- > 0)
			am_i_visit.push_back(false);	// 각 숫자는 학생들을 나타냄.

		// 하위 8줄. 학생 쌍 입력
		while (m-- > 0)
		{
			int a, b;
			cin >> a >> b;	// 쌍 입력
			set<int> tmp;
			tmp.insert(a);	tmp.insert(b);
			vector_set.push_back(tmp);
		}

		Reculsive(am_i_visit.size(), vector_set);
		answer.push_back(count_case);

		count_case = 0;
		am_i_visit.clear();
		vector_set.clear();
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;

	return 0;
}

void Reculsive(int n, vector<set<int>> clone_vector_set)
{
	if (n == 0)
	{
		count_case++;
		return;
	}

	// 친구 쌍에 이렇게 이어도 되는지 비교.
	// 되면 둘 다 true로 만들고, 서로 이어줌
	// 안되면 리턴.
	for (int j = 0; j < am_i_visit.size(); j++)
	{
		if (am_i_visit[j] == true)	continue;

		for (int k = j + 1; k < am_i_visit.size(); k++)
		{
			if (am_i_visit[k] == true)	continue;

			set<int> tmp;
			tmp.insert(j);	tmp.insert(k);
			for (int l = 0; l<clone_vector_set.size(); l++)
				if (!clone_vector_set[l].empty() && clone_vector_set[l] == tmp)
				{
					am_i_visit[j] = true;	am_i_visit[k] = true;

					Reculsive(n - 2, clone_vector_set);

					am_i_visit[j] = false;	am_i_visit[k] = false;
					clone_vector_set[l].clear();
					break;
				}
		}
	}
	return;
}
