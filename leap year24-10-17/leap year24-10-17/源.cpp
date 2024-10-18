#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int year;
int main() {
	scanf("%d", &year);
	if (year % 100 == 0 && year % 400 == 0) {
		printf("1");
	}
	else if (year % 100 == 0 && year % 400 != 0) {
		printf("0");
	}
	if (year % 100 != 0 && year % 4 == 0) {
		printf("1");
	}
	else if(year % 100 != 0 && year % 4 != 0)
	{
		printf("0");

	}
	return 0;
}