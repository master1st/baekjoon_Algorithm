#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int money = 1000;
	int payment;

	scanf("%d", &payment);
	int coin[] = {500,100,50,10,5,1};
	int count = 0;
	int j = 0;
	int changes = money - payment;
	while (changes > 0) {
		if (changes >= coin[j]) {
			changes -= coin[j];
			count++;
		}
		else {
			j++;
		}
	}
	printf("%d", count);
	return 0;
}