#include <iostream>
using namespace std;

int T;	// Test Case Number
int score_count[101];	// 0~100점까지

int MaxCount();	// 최빈수 return

int main(void)
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int tmp;	cin >> tmp;
		cout << "#" << tmp << " " << MaxCount() << endl;
		fill(score_count, score_count + 101, 0);
	}

	return 0;
}

int MaxCount()
{
	for (int i = 0; i < 1000; i++)
	{
		int score;	cin >> score;
		score_count[score]++;
	}

	int max_idx = 0;
	for (int i = 1; i < 101; i++)
		if (score_count[max_idx] <= score_count[i])
			max_idx = i;

	return max_idx;
}
