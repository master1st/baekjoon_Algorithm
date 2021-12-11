#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> q;
	for (int i = 0; i < 7; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		printf("%d", q.front());
		q.pop();
	}
	return 0;
}