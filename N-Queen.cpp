/*
*	Quest URL : https://www.acmicpc.net/problem/9663
*	N-Queen
*	박원준
*	Log : Wrong 1 : PutQueen()에서 temp 값의 +- 1.
					기존에 쌓인 좌표 덮어쓰기 하는 과정에서 status 값을 true로 넘겨줘서 temp 값이 +1이 되고 있었음.
		Modify 1 : 체스판 첫 줄의 퀸의 위치만 확인하면 되므로, main에서 NQueen()의 호출을 이중for문에서 단일for문으로 바꿨음.
		Wrong 2 : DFS 탐색 성공 시에 탈출조건(temp == N)의 위치 변경.
					해당 탈출 조건이 (N-1, N-1)에서 일어나는 건지, temp == N이 되면 바로 일어나는 건지에 대해 명확하지 않았음. 후자의 경우로 명확히 함.
		Wrong 3 : 서버 제출. 시간 초과.
					PutQueen2() 만듬. 변수 board의 변수형을 bool->int 로 바꿈.
		Wrong 4 : 서버 제출. 시간 초과.
					변수 board를 동적할당 하는 방식에서 N의 최댓값(14)로 임의로 할당함.
		Wrong 5 : 서버 제출. 시간 초과.
					NQueen()에서 다음 줄까지 확인하는 이중 for문을, Modify1과 같은 이유로, 단일 for문으로 바꿨음.
					: Success.
*/
#include <iostream>
#include <vector>
using namespace std;

int N;
//bool** board;	// N x N 체스판. true : 퀸 존재(or 퀸이 갈 수 있는 곳). false : 퀸 없음.
//int** board;
int board[14][14];
int temp;		// NQueen(), 재귀함수를 도는 중에 현재까지 체스판에 놓여진 Queen의 갯수.
int result;
vector<pair<int, int>> coor;

void NQueen(const int&, const int&);
void PutQueen(const int&, const int&, const bool&);	// bool형 인자값이 true면 Put Queen. false면 Minus Queen.
void PutQueen2(const int&, const int&, const bool&);

int main(void)
{
	// Input Data
	cin >> N;
	////board = new bool*[N];
	//board = new int*[N];
	//for (int i = 0; i < N; i++)
	//{
	//	//board[i] = new bool[N];
	//	board[i] = new int[N];
	//	for (int j = 0; j < N; j++)
	//		board[i][j] = 0;
	//}

	// Set Start Point
	/*for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			NQueen(i, j);
			temp = 0;
		}*/
	for (int j = 0; j < N; j++)
	{
		NQueen(0, j);
		temp = 0;
	}

	// Print Result
	cout << result << endl;
	
	// Delete Memory
	/*for (int i = 0; i < N; i++)
		delete board[i];
	delete[]board;*/

	return 0;
}

void NQueen(const int& i, const int& j)
{
	//if (temp == N)	// Success to Search.
	//{
	//	result += 1;
	//	return;
	//}
	//else 
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
	//int l = j;
	//for (int k = i; k < N; k++)
	//{
	//	for (; l < N; l++)
	//	{
	//		// 예외처리.
	//		if (k == i && l == j)	continue;

	//		NQueen(k, l);
	//	}
	//	l = 0;
	//}
	for (int l = 0; l < N; l++)
		NQueen(i + 1, l);

	coor.pop_back();
	temp -= 1;
	PutQueen2(i, j, false);

	return;
}

void PutQueen(const int& i, const int& j, const bool& status)
{
	for (int m = i; m >= 0; m--)	// Put Queen to Upper Row.
		board[m][j] = status;
	for (int m = i; m < N; m++)		// Put Queen to Lower Row.
		board[m][j] = status;
	for (int n = j; n >= 0; n--)	// Put Queen to Left Col.
		board[i][n] = status;
	for (int n = j; n < N; n++)		// Put Queen to Right Col.
		board[i][n] = status;

	// Put Queen to Upper Left Diagonal.
	for (int m = i, n = j; m >= 0 && n >= 0; m--, n--)
		board[m][n] = status;
	// Put Queen to Lower Right Diagonal.
	for (int m = i, n = j; m < N && n < N; m++, n++)
		board[m][n] = status;
	// Put Queen to Upper Right Diagonal.
	for (int m = i, n = j; m >= 0 && n < N; m--, n++)
		board[m][n] = status;
	// Put Queen to Lower Left Diagonal.
	for (int m = i, n = j; m < N && n >= 0; m++, n--)
		board[m][n] = status;

	/*if (status)	temp += 1;
	else
	{
		if (!coor.empty())
			for (pair<int, int> e : coor)
				PutQueen(e.first, e.second, true);
		temp -= 1;
	}*/

	if (!status)
	{
		// 기존에 쌓인 좌표에 대해서는 값이 변하면 안됨.
		if (!coor.empty())
			for (pair<int, int> e : coor)
				PutQueen(e.first, e.second, true);
	}
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
