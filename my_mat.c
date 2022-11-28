#include <stdio.h>
#include <math.h>
#define SIZE 10;


int mat[SIZE][SIZE];



void isTherePath(){
    int i,j;
    scanf("%d", &i);
    scanf("%d" , &j);

    if (mat[i][j] == 0) printf("False\n");
    else printf("True\n");
}

int min(int a, int b){
    if (a<= b) return a;
    return b;
}

void shortestPathHelp(){
    for (int k = 0; k < SIZE; k++){
        for (int i = 0; i <10; i++){
            for (int j = 0 ; j < 10 ; j++){
                if(mat[i][j]!= 0 && mat[i][k]!= 0 && mat[k][j]!= 0)
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                if (i!=j&& mat[i][j] == 0 && mat[i][k]!= 0 && mat[k][j]!=0)
                    mat[i][j] = mat[i][k] +mat[k][j];
            }
        }
    }
}

void createMat(){
    for (int i = 0 ; i < 10; i++){
        for (int j = 0 ; j < 10 ; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    shortestPathHelp();
}

void shortestPath(){
    int a,b;
    scanf("%d%d" , &a, &b);
    if (mat[a][b]==0) printf("-1\n");
    printf("%d\n" , mat[a][b]);

}

