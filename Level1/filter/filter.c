#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>



void filter(char *text, char *mask){
    int len = strlen(mask);
    int start = 0;
    int i  =0 ;
    int j = 0;
    char star = '*';
    while (text[i]){
        start = i;
         j =0;
        while (text[i] && j < len && text[i] == mask[j]){
            i++;
            j++;
        }
        if ( j == len){
            j  =0;
            while ( j < len){
                write(1, &star , 1);
                j++;
            }
        }else{
            i = start ; 
            write(1 , &text[i]  , 1);
            i++;
        }
    }
}



int main(int argc , char **argv){
    if (argc != 2 || argv[1][0] == '\0')return 1;
    ssize_t line ; 
    size_t total = 0;
    char *buffer = malloc(sizeof(char ) * 256);
    if (!buffer){
        perror("Error");
        return 1;
    }
    char *tmp;
    line = read( 0 , buffer  + total, 255);
    while (line  > 0){
        total += line;
        tmp = realloc (buffer , total + 256);
        if (!tmp){
            perror("Error");
            free(buffer);
            return 1;
        }
        buffer = tmp;
        line = read(0 ,buffer + total, 255);
    }
    if (line < 0 ){
        perror("Error");
        free(buffer);
        return 1;
    }
    buffer[total] = '\0';
    filter (buffer , argv[1]);
    free(buffer);




    return 0;

}