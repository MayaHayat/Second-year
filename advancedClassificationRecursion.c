#include <stdio.h>
#include <math.h>

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
    int temp = n, power = digCount(n);
    if(n == isArmstrongHelp(n,power)) 
        return 1;
    return 0;
    
}

int reverseHelp(int n, int help){
    if (n==0) return help;
    help = help*10 + n%10;
    return (reverseHelp(n/10, help));
}

int isPalindrome(int n){
    if (n== reverseHelp(n/10, 0)) return 1;
    return 0;
}

