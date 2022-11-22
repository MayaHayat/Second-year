#include<stdio.h>
#include<math.h>

int isArmstrongHelp(int n, int power){
    if (n>0) 
        return pow(n%10,power + isArmstrongHelp(n/10, power));
    return 0;
}

int digCount(int n){
    if (n> 0 && n< 10) return 1;
    return (1+ digCount(n/10));
}

int isArmstrong(int n){
    
}