
#include <stdio.h>
#include <math.h>

int isPalindrome(int n){
	int reversed = 0, temp =n;
	while (temp != 0){
		int rem = temp%10;
		reversed = (reversed*10)+rem;
		temp/=10;
	}
	if (reversed == n) return 1;
	return 0;
}

int isArmstrong(int n){
	int rem = 0, sum = 0, temp = n;
	int power = 0;
	while (temp!= 0){
		temp/=10;
		power++;
	}

	temp = n;
	while (n > 0){
		rem = temp%10;
		sum += pow(rem,power);
		temp /=10;
	}
	if (sum ==n) return 1;
	return 0;
}
	