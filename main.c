#include<stdio.h>
#include "NumClass.h"

int main(){
	int small, large=0;
	
	scanf("%d", &small);
	scanf("%d", &large);
	
	
	printf("\nThe Armstrong numbers are:");
	for (int i = small; i <=large; i++)
		if (isArmstrong(i)) 
			printf(" %d", i);
	
	
	printf("\nThe Palindromes numbers are:");
	for (int i = small; i <=large; i++)
		if (isPalindrome(i)) 
			printf(" %d", i);
	
	
	printf("\nThe Prime numbers are:");
	for (int i = small; i <=large; i++)
		if (isPrime(i)) 
			printf(" %d", i);
	
	
	printf("\nThe Strong numbers are:");
	for (int i = small; i <=large; i++)
		if (isStrong(i)) 
			printf(" %d", i);
	
}
