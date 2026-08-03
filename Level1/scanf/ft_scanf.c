#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
    int c;
    c = fgetc(f);

    while(c != EOF && isspace ( (char) c ))
        c  = fgetc(f);

    if (c != EOF){
        ungetc(c,f);
    }

    return (1);
}

int match_char(FILE *f, char c)
{
    int s; 
    s = fgetc(f);

    if ( s == EOF ){
        return 0;
    }
    if ( (char)s == c ){
        return 1;
    }
    return (0);
}

int scan_char(FILE *f, va_list ap)
{
    int c = fgetc(f);
    char *dest = va_arg ( ap , char *);

    if (c == EOF){
        return 0;
    }
    
    *dest = (char )c ;
    return (1);
}

int scan_int(FILE *f, va_list ap)
{
    int c ; 
    int *dest ;
    int value = 0;
    int sign = 1;
    int has_int = 0;
    c = fgetc  (f);
    dest = va_arg(ap , int *);
    if ( (char )c == '+' || (char) c == '-' ){
        if ((char )c == '-' )sign = -1;
        c  = fgetc(f);
    }
    while (c != EOF && isdigit( (char)c )){
        value = value * 10  + ( (char )c - '0');
        has_int = 1;
        c = fgetc(f);
    }

    if (c != EOF){
        ungetc(c ,f);
    }
    if ( has_int == 0){
        return 0;
    }
    


    *dest = value * sign;

    return (1);
}

int scan_string(FILE *f, va_list ap)
{
    int c;
    int i = 0;
    char *dest;
    
    dest = va_arg(ap , char *);
    c = fgetc(f);

    while ( c != EOF && !isspace( (char)c  )){
        dest[i] = (char)c;
        i++;
        c = fgetc(f);
    }
    if (c != EOF){
        ungetc(c ,f );
    }
    dest[i] = '\0';
    return (1);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list ap;

    va_start(ap , format);

	int ret = ft_vfscanf(stdin, format, ap);

	va_end(ap);

	return ret;
}
// int main(){


//     return 0;
// }