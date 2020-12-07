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
    int errors_count;

} format_parser;

#define INIT_PARSER(P) format_parser P = {.errors_count = 0, .flag = ' ', .precision = 0, .specifier = ' ', .width = 0, .is_dynamic_precision = 0, .is_dynamic_wdith = 0};

void parse_flags(int *i, char *str, format_parser *parser);
void parse_width(int *i, char *str, format_parser *parser);
void parse_precision(int *i, char *str, format_parser *parser);
void parse_specifier(int *i, char *str, format_parser *parser);
void output(va_list *parms_arry, format_parser *parser);

void output_c_specifier(va_list *parms_arry, format_parser *parser);
void output_d_specifier(va_list *parms_arry, format_parser *parser);
void output_u_specifier(va_list *parms_arry, format_parser *parser);
void output_p_specifier(va_list *parms_arry, format_parser *parser);
void output_s_specifier(va_list *parms_arry, format_parser *parser);
void output_x_specifier(va_list *parms_arry, format_parser *parser);
void output_X_specifier(va_list *parms_arry, format_parser *parser);


void write_nb(int nb, int precision);
void write_str(char *str, int size);
void write_str_x(char *str, int precision);
void write_flags(char c, int width, int length, int precision);
void pointer_flag(int lenght);
void output_int_flag(int nb, int width, int precision, char flag);
void output_pointer_flag(unsigned int ptr, int width, int lenght, char flag);
void output_s_flags(format_parser *parser, char *str, int precision, int width);
void output_x_flags(format_parser *parser, char *str, int precision, int width);

int ft_strlen(const char *str);
void ft_putchar(char c);
void ft_putstr(char *s);
void ft_putnbr(int nb);
int ft_isdigit(int c);
int check_base(char *base);
char *ft_itoa(long long nbr, char *base);
char *ft_substr(char const *s, unsigned int start, size_t len);
unsigned long long ft_iterative_power(int nb, int poweer);
int ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
int		is_valid_specifier(char c);

#endif