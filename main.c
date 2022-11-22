#include<stdio.h>
#include "NumClass.h"

int main(){
	int x,y=0;
	
	int small = scanf("%d", x);
	int large = scanf("%d", y);
	
	if (large < small){
		int temp = large;
		large = small;
		small = large;
	}
	
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
	
	
	
	 