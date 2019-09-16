/*
*	Quest URL : https://www.acmicpc.net/problem/9663
*	N-Queen

*	박원준
*/
#include <iostream>
#include <vector>
using namespace std;

int N;
int board[14][14];
int temp;		// NQueen(), 재귀함수를 도는 중에 현재까지 체스판에 놓여진 Queen의 갯수.
int result;
vector<pair<int, int>> coor;

void NQueen(const int&, const int&);
void PutQueen2(const int&, const int&, const bool&);	// bool형 인자값이 true면 Put Queen. false면 Minus Queen.

int main(void)
{
	// Input Data
	cin >> N;

	// Set Start Point
	for (int j = 0; j < N; j++)
	{
		NQueen(0, j);
		temp = 0;
	}

	// Print Result
	cout << result << endl;

	return 0;
}

void NQueen(const int& i, const int& j)
{
	if (i >= N && j >= N)	// Fail to Search.
		return;

	// Queen Already on a board.
	if (board[i][j])	return;

	temp += 1;
	if (temp == N)	// Success to Search.
	{
		result += 1;
		temp -= 1;
		return;
	}
	coor.push_back(pair<int, int>(i, j));
	PutQueen2(i, j, true);
	// DFS
	for (int l = 0; l < N; l++)
		NQueen(i + 1, l);

	coor.pop_back();
	temp -= 1;
	PutQueen2(i, j, false);

	return;
}

void PutQueen2(const int& i, const int& j, const bool& status)
{
	if (status)
	{
		for (int m = i; m >= 0; m--)	// Put Queen to Upper Row.
			board[m][j] += 1;
		for (int m = i; m < N; m++)		// Put Queen to Lower Row.
			board[m][j] += 1;
		for (int n = j; n >= 0; n--)	// Put Queen to Left Col.
			board[i][n] += 1;
		for (int n = j; n < N; n++)		// Put Queen to Right Col.
			board[i][n] += 1;

		// Put Queen to Upper Left Diagonal.
		for (int m = i, n = j; m >= 0 && n >= 0; m--, n--)
			board[m][n] += 1;
		// Put Queen to Lower Right Diagonal.
		for (int m = i, n = j; m < N && n < N; m++, n++)
			board[m][n] += 1;
		// Put Queen to Upper Right Diagonal.
		for (int m = i, n = j; m >= 0 && n < N; m--, n++)
			board[m][n] += 1;
		// Put Queen to Lower Left Diagonal.
		for (int m = i, n = j; m < N && n >= 0; m++, n--)
			board[m][n] += 1;
	}
	else
	{
		for (int m = i; m >= 0; m--)	// Put Queen to Upper Row.
			board[m][j] -= 1;
		for (int m = i; m < N; m++)		// Put Queen to Lower Row.
			board[m][j] -= 1;
		for (int n = j; n >= 0; n--)	// Put Queen to Left Col.
			board[i][n] -= 1;
		for (int n = j; n < N; n++)		// Put Queen to Right Col.
			board[i][n] -= 1;

		// Put Queen to Upper Left Diagonal.
		for (int m = i, n = j; m >= 0 && n >= 0; m--, n--)
			board[m][n] -= 1;
		// Put Queen to Lower Right Diagonal.
		for (int m = i, n = j; m < N && n < N; m++, n++)
			board[m][n] -= 1;
		// Put Queen to Upper Right Diagonal.
		for (int m = i, n = j; m >= 0 && n < N; m--, n++)
			board[m][n] -= 1;
		// Put Queen to Lower Left Diagonal.
		for (int m = i, n = j; m < N && n >= 0; m++, n--)
			board[m][n] -= 1;
	}
}
