#include <stdio.h>


long long int c;
long long int julban;
long long int multiple(long long int a, long long int b) {
	
	if (b == 0)
		return 1;
	else if (b == 1)
		return a;
	if (b % 2 == 1)
		return multiple(a, b - 1) * a;

	julban = multiple(a, b / 2);
	julban %= c;
	return (julban * julban) % c;
	
}
 
int main(void) {
	long long int a, b;
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld", multiple(a,b)%c);

	return 0;
}


