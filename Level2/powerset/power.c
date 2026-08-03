#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


  
void show(int *s , int len){
    int i = 0;
    while (i < len ){
        if (i  > 0)
            printf(" ");
        printf("%d",s[i]);
        i++;
    }
    printf("\n");
}



void solve(int * set, int set_size ,int index , int target, int current_sum , int *sub_set ,int sizeof_subset) {
    if (index == set_size){
        if (current_sum == target){
            show(sub_set ,sizeof_subset);
        }
        return ;
    }

    solve(set,set_size , index + 1 , target , current_sum , sub_set , sizeof_subset );
    sub_set[sizeof_subset] = set[index];
    solve(set , set_size , index  +1 , target  , current_sum + set[index] , sub_set , sizeof_subset + 1);
}





int main(int argc ,char **argv){
    if (argc < 3)return 1;
    int target = atoi(argv[1]) ;
    int set_size = argc -2;
    int i;
    int *set = malloc(sizeof(int) * set_size);
    if (!set){
        return 1 ;
    }
    int *sub_set= malloc(sizeof(int) * set_size);
    if (!sub_set ){
        free(set);
        return 1 ;
    }

    i = 0;
    while (i  < set_size){
        set[i] = atoi(argv [i +2]);
        i++;
    }

    solve (set , set_size , 0 , target, 0 , sub_set, 0 );








    return 0;
}

