#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <limits.h>
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

#define INIT_PARSER(P) format_parser P = { .flag = ' ', .precision = -1, .specifier = ' ', .width = -1, .is_dynamic_precision = 0, .is_dynamic_wdith = 0};

int ft_printf(char *args, ...);
void parse_flags(int *i, char *str, format_parser *parser);
void parse_width(int *i, char *str, format_parser *parser);
void parse_precision(int *i, char *str, format_parser *parser);
void parse_specifier(int *i, char *str, format_parser *parser);
int output(va_list *parms_arry, format_parser *parser);

int output_c_specifier(va_list *parms_arry, format_parser *parser);
int output_d_specifier(va_list *parms_arry, format_parser *parser);
int output_u_specifier(va_list *parms_arry, format_parser *parser);
int output_p_specifier(va_list *parms_arry, format_parser *parser);
int output_s_specifier(va_list *parms_arry, format_parser *parser);
int output_x_specifier(va_list *parms_arry, format_parser *parser);
int output_X_specifier(va_list *parms_arry, format_parser *parser);

int output_int_flag(int nb, int width, int precision, char flag);
int output_pointer_flag(long long int ptr, int width, int lenght, char flag);
int output_s_flags(format_parser *parser, char *str, int precision, int width);
int output_x_flags(format_parser *parser, char *str, int precision, int width);

int write_nb(int nb, int precision, char flag);
int write_nb_u(long long nb, int precision);
int write_str(char *str, int precision);
int write_str_x(char *str, int precision);
int write_flags(char c, char *str, int width, int precision);
int write_flag_p(int size);

int is_valid_specifier(char c);

int ft_strlen(const char *str);
void ft_putchar(char c);
void ft_putstr(char *s);
void ft_putnbr(long long nb);
int ft_isdigit(int c);
int check_base(char *base);
char *ft_itoa(long long nbr, char *base);
char *ft_substr(char const *s, unsigned int start, size_t len);
int ft_atoi(const char *str);
int ft_isalpha(int c);
int ft_strcmp(char *s1, char *s2);

int write_string(char *str);
int write_char(char c);
int write_number(long long nb);

#endif