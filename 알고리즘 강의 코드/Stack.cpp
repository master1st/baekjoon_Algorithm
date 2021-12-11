#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	stack<int> s;
	for (int i = 0; i < 7; i++) {
		s.push(i);
	}
	while (!s.empty()) {
		printf("%d", s.top());
		s.pop();
	}
	return 0;
}