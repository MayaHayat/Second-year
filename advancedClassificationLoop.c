
#include <stdio.h>
#include <math.h>


int isPalindrome(int n){
	int reversed = 0;
	int temp = n;
	while (temp != 0){
		int rem = temp%10;
		reversed = (reversed*10)+rem;
		temp/=10;
	}
	if (reversed == n) return 1;
	return 0;
}

int isArmstrong(int n){
	int sum , power = 0;
	int temp = n;
	
	while (temp!= 0){
		temp/=10;
		power++;
	}

	temp = n;
	while (temp!=0){
		int rem = temp%10;
		sum += pow(rem,power);
		temp /=10;
	}
	if (sum ==n) return 1;
	return 0;
}
	