#include <stdio.h>
#include <math.h>

int isPrime(int n){
	if (n==0) return 0;
	if (n==1) return 1;
	
	for (int i = 2; i <= sqrt((double)(n)) ;i++){
		if (n%i == 0) 
			return 0;
	}
	return 1;
}


int isStrong(int n){
	int result = 0;
	int factorial = 1;
	int temp = n;
	while (temp != 0){
		int check = temp%10;
		for (int i = 1; i <= check ; i++){
			factorial*=i;
		}
		result += factorial;
		factorial =1;
		temp /=10;
	}
	if (result == n) return 1;
	return 0;
}
