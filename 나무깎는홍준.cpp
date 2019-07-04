/*
*	Quest URL : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWq43PI6L64DFARG&categoryId=AWq43PI6L64DFARG&categoryType=CODE
*	나무 깎는 홍준

*	박원준
*/
#include <algorithm>
#include <iostream>
using namespace std;

int N, M;	// N : The Number of Tree.	M : Height what he wants.
int* tree;
int tree_height_sum = 0;

int main(void)
{
	int T;	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		/* Init, Input Data */
		cin >> N >> M;
		tree = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> tree[i];
			tree_height_sum += tree[i];
		}

		/* Make Answer */
		// Sort Variation 'tree'	// if QuickSort O(nlogn)
		sort(tree, tree + N);

		// Subtract Tree Height		// O(n)
		int cut_height = tree[N - 1];
		int sum = 0;
		for (int i = N - 1; i >= 0; cut_height--)
		{
			if (cut_height < tree[i])
			{
				i--;
				while (tree[i + 1] == tree[i])
					i--;
			}

			// Cut Tree
			sum += 1 * ((N - 1) - i);

			// Case that Find Answer. Escape Condition.
			if (sum >= M)	break;
		}

		/* Print Answer */
		cout << "#" << test_case << " " << cut_height << endl;

		/* Delete Memory */
		delete[]tree;
	}

	return 0;
}
