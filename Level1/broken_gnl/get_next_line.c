/*
 * EXERCISE: BROKEN_GNL (Get Next Line)
 * 
 * DESCRIPTION:
 * Implement get_next_line that reads line by line from a file descriptor.
 * This version may contain special cases or intentional "bugs".
*/

#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
  if (!s) return NULL;
  int i = 0;
  while(s[i] && s[i] != (char) c)
    i++;
  if (s[i] == (char) c)
    return s + i;
  else
    return NULL;
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
  size_t i = 0;
  while( i  < n){
    ((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
    i++;
  } 
  return dest;
}

size_t ft_strlen(char *s)
{
  if (!s)return 0;
  size_t res = 0;
  while (*s)
  {
    s++;
    res++;
  }
  return res;
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
  if (!s1 || (!s2 && size2 > 0 ) )return 0;
  size_t size1 = ft_strlen(*s1);
  char *tmp = malloc(size2 + size1 + 1);
  if (!tmp)
    return 0;
  if (size1 > 0) 
    ft_memcpy(tmp, *s1, size1);
  if (size2 > 0)
    ft_memcpy(tmp + size1, s2, size2);
  tmp[size1 + size2] = '\0';
  free(*s1);
  *s1 = tmp;
  return 1; 
}

int str_append_str(char **s1, char *s2)
{
  return str_append_mem(s1, s2, ft_strlen(s2));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
  size_t i ;
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *) src;
  if (d < s){
    i = 0 ;
     while (i < n){
      d[i] = s[i];
      i++;
     }
  }else{
    i = n; 
    while ( i  > 0 ){
      i--;
      d[i] = s[i];
    }
  }
  return dest;
}

char *get_next_line(int fd)
{
  if (fd < 0 || BUFFER_SIZE <= 0)return NULL;
  static char b[BUFFER_SIZE + 1];
  char *ret = malloc(1);
  if (!ret)return NULL;
  ret[0] = '\0';
  char *tmp = ft_strchr(b, '\n');
  ssize_t read_ret;
  while(!tmp)
  {
    if (!str_append_str(&ret, b)){
      free(ret);
      return (NULL);
    }
    read_ret = read(fd, b, BUFFER_SIZE);
    if (read_ret < 0 ){
      b[0] = '\0';
      free(ret);
      return (NULL);
    }
    b[read_ret] = '\0';
    if (read_ret == 0){
      
      if (ret[0] == '\0'){
        free(ret);
        return NULL;
      }
      return ret;
    }
    tmp = ft_strchr(b , '\n');
  }
  size_t len  = tmp - b + 1;
  if (!str_append_mem(&ret, b, tmp - b + 1))
  {
    free(ret);
    return NULL;
  }
  ft_memmove(b , b + len , ft_strlen ( b + len)  +1);
  return ret;
}

// int main(){

//     return 0;

// }