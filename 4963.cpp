#include <stdio.h>
#include <stdlib.h>
int arr[52][52];
bool visit[52][52];
int around_W[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int around_H[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void check() {
	for (int i = 0; i <= 51; ++i) {
		for (int j = 0; j <= 51; ++j) {
			visit[i][j] = false;
		}
	}
}

void dfs(int i, int j) 
{
	for (int z = 0; z < 8; ++z) {
		int A = j + around_W[z];
		int B = i + around_H[z];

		if (visit[A][B] == false && arr[A][B] == 1) {
			visit[A][B] = true;
			dfs(A, B);
		}
	}
}

void p(){
	int w, h;
	int count;
	while (true)
	{
		
		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0)
			break;

		for (int i = 1; i <= 50; ++i) {
			for (int j = 1; j <= 50; ++j) {
				arr[j][i] = 0;
			}
		}

		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				scanf("%d", &arr[j][i]);
				check();
			}
		}
		count = 0;
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				if (visit[j][i] == false && arr[j][i] == 1) {
					dfs(j, i);
					++count;
				}
			}
		}
		printf("%d\n", count);
	}
	
}
int main()
{
	p();
	return 0;
}