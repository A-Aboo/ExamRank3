#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



int minimum(char *s){
    int i  =0 ;
    int open = 0;
    int remove = 0;
    while (s[i]){
        if (s[i] == '(')
            open++;
        else if (s[i] == ')'){
            if (open > 0)
                open--;
            else    
                remove++;
        }
        i++;
    }
    return remove + open;
}

int balance(char *s){
    int i = 0;
    int balance =0;
    while (s[i]){
        if (s[i] == '(')
            balance++;
        else if (s[i] == ')'){
            balance --;
            if (balance < 0){
                return 0;
            }
        }
        i++;
    }
    return balance == 0;
}



void solve(char *c , int pos, int min , int remove , int  len){
    if (pos == len){
        if ( remove == min &&  balance(c) ){
            puts(c);
        }
        return ;
    }
    char save ;
    
    solve(c , pos + 1 , min , remove , len);
    save =  c[pos];
    c[pos ] = ' ';
    solve(c , pos  +1 , min  , remove + 1 , len);
    c[pos] = save;
} 







int main( int argc, char **argv){
    if (argc != 2){
        return 1;   
    }
    solve(argv[1] , 0 , minimum(argv[1]), 0 ,strlen(argv[1])  );




    return 0;
}