#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



int is_safe(int *queens, int row ,int col){
    int i = 0;
    while (i  < col){
        if (queens[i] == row)
            return 0;
        if (queens[i] - i == row - col)
            return 0;
        if (queens[i] + i == row + col )
            return 0;
        i++;
    }
    return 1;
}

void print_sol(int *queens , int n){
    int i =0 ;
    while (i  < n){
        if (i > 0)
            fprintf(stdout , " ");
        fprintf(stdout , "%d" , queens[i]);
        i++;
    }
    fprintf(stdout, "\n");
}


void solve ( int *queens , int n , int col){
    if (col == n ){
        print_sol(queens , n );
        return ;
    }
    int row = 0;
    while ( row < n){
        if (is_safe(queens , row , col)){
            queens[col] = row ;
            solve(queens, n , col +1 );
        }
        row ++;
    }
}




int main(int argc, char **argv){
    int *queens;
    int n ;
    if ( argc != 2){
        return 1;
    }
    n = atoi(argv[1]);
    if (n <= 0 ){
        return 0;
    }
    queens = malloc(sizeof(int) * n);
    if (!queens)
        return 1;
    solve(queens , n , 0);
    free(queens);

 


    return 0;

 }