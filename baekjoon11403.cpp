#include <stdio.h>
int n;
bool visit[100];
int arr[100][100];

void init() {
	for (int i = 0; i < n; i++) {
		visit[i] = false;
	}
}
void dfs(int i) {
	for (int j = 0; j < n; j++) {
		if (arr[i][j] == 1 && visit[j] == false) {
			visit[j] = true;
			dfs(j);
		}

	}
}

void printgraph() {
	
	for (int i = 0; i < n; i++) {
		if (visit[i] == true)
			printf("1 ");
		else {
			printf("0 ");
		}
		
	}
	printf("\n");
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		init();
		dfs(i);
		printgraph();
	}
	
}