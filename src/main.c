#include "ft_printf.h"

int main()
{
    //ft_printf("hello, %s.", NULL);
    //printf("\n");
    //printf("%010.5i", -216);

    // printf("%%s         =>");printf("%s!\n", NULL);
    // printf("%%3s        =>");printf("%3s!\n", NULL);
    // printf("%%9s        =>");printf("%9s!\n", NULL);
    // printf("%%.2s       =>");printf("%.2s!\n", NULL);
    // printf("%%.9s       =>");printf("%.9s!\n", NULL);
    // printf("%%.6s       =>");printf("%.6s!\n", NULL);
    // printf("%%3.2s      =>");printf("%3.2s!\n", NULL);
    // printf("%%3.6s      =>");printf("%3.6s!\n", NULL);
    // printf("%%9.6s      =>");printf("%9.6s!\n", NULL);
    // printf("%%9.2s      =>");printf("%9.2s!\n", NULL);
    // printf("%%-9s       =>");printf("%-9s!\n", NULL);
    // printf("%%.-2s      =>");printf("%.-2s!\n", NULL);
    //printf("%%.s      =>");printf("%.s!\n", NULL);

    // printf("1=>%0s\n", "abcdefghij");//10 => 0 // ""| 0-0-10=-10
    // printf("1=>%.0s\n", "abcdefghij");//10 => 0 // ""| 0-0-10=-10
    // printf("1=>%0.0s\n", "abcdefghij");//10 => 0 // ""| 0-0-10=-10
    // printf("2=>%5.5s\n", "abcdefghij");//10 => //abcde| 5-5-10 =-10
    // printf("3=>%7.5s\n", "abcdefghij");//10 =>  abcde|  7-5 =2
    // printf("4=>%5.7s\n", "abcdefghij");//10 =>abcdefg| 5-7=-2
    // printf("5=>%0.0s\n", "abcd");//4
    // printf("6=>%5.5s\n", "abcd");//4 => abcd
    // printf("7=>%7.5s\n", "abcd");//4 =>    abcd
    // printf("8=>%5.7s\n", "abcd");//4 => abcd

    // ft_printf("%u\n", 4294967295u);
    // printf("%u", 4294967295u);

    //printf("%7.5s\n", "yolo");
    //ft_printf("%7.5s\n", "yolo");
    // ft_printf("%7.5s\n", "bombastic");
    // printf("%7.5s\n", "bombastic");
    //ft_printf("%3.3s%7.7s", "hello", "world");
    //ft_printf("%.03s", "hello");

    ft_printf("%%d 0000042 == |%d|", 0000042);
   
    printf("\n");

    printf("%%d 0000042 == |%d|", 0000042);

    return 0;
}