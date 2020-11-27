#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct format_parser
{
    char specifier;
    char flag;
    int width;
    int precision;
    int is_dynamic_precision;
    int is_dynamic_wdith;

} format_parser;

void write_char(char c, int width, int lenght, int precision);
void write_str(char *str, int size);
int ft_strlen(const char *str);
void ft_putchar(char c);
void ft_putstr(char *s);
void ft_putnbr(int nb);
char *ft_itoa(long long nbr, char *base);
void ft_putnbr_base(int nbr, char *base);
int ft_atoi(const char *str);
int ft_isdigit(int c);
char *ft_substr(char const *s, unsigned int start, size_t len);

int ft_printf(char *args, ...);

void parse_flags(int *i, char *str, format_parser *parser);
void parse_width(int *i, char *str, format_parser *parser);
//void parse_precision(int *i, char *str, format_parser *parser);
void parse_precision(int *i, char *str, format_parser *parser, va_list *parms_arry);
void parse_specifier(int *i, char *str, format_parser *parser);
void output_s_precision(va_list *parms_arry, format_parser *parser);
void output_d_precision(va_list *parms_arry, format_parser *parser);

void output_int_flag(int nb, int width, int length, char flag);
//void output_char_flag(char *str, int width, int lenght, char flag);

void output_c_specifier(va_list *parms_arry, format_parser *parser);
void output_u_specifier(va_list *parms_arry, format_parser *parser);
void output_d_specifier(va_list *parms_arry, format_parser *parser);
void output_s_specifier(va_list *parms_arry, format_parser *parser);
void output_x_specifier(va_list *parms_arry, format_parser *parser);
void output_X_specifier(va_list *parms_arry, format_parser *parser);
void output_p_specifier(va_list *parms_arry, format_parser *parser);


void output_precision(char *str, int size, int width);

#endif