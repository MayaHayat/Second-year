#include<stdio.h>
#include<math.h>

int isArmstrongHelp(int n, int power){
	if (n>0){
		return (pow(n%10, power)+isArmstrongHelp(n/10,power));
	return 0;
}

int isArmstrong(int n){
}


int isPalindromeHelp(int n){
	int rem, sum = 0;
	if (n!= 0){
		rem
