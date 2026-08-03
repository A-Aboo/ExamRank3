#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void swap(char *a ,char *b){
    char tmp = *a ;
    *a = *b;
    *b = tmp;
}


void sortfrom(char *s , int start, int len){
    int i ;
    int j ;
    i = start;
    while (i < len){
        j = i +1;
        while (j  <len){
            if (s[j]  < s[i]){
                swap(&s[i] , &s[j]);
            }
            j++;
        }
        i++;
    }
}



void solve(char *str, int pos, int len){
    if (pos == len){
        puts(str);
    }
    int i = pos;
    while (i  < len){
        swap(&str[pos] , & str[i]);
        sortfrom(str, pos  + 1, len);
        solve(str, pos + 1, len);
        sortfrom(str, pos , len);
        //swap(&str[pos] , & str[i]);
        i++;
    }

}


int main(int argc, char **argv){
    if (argc != 2 ){
        return 1;
    }
    sortfrom(argv[1] , 0 , strlen(argv[1]));
    solve(argv[1] , 0 , strlen(argv[1]));
    return 0;

}

