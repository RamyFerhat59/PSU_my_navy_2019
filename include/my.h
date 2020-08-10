/*
** EPITECH PROJECT, 2020
** navy
** File description:
** navy
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void get_pid(void);
void handle_signal(int signum);
int my_put_nbr(int nb);
int my_put_nbr_base(long long nb, char *base);
int my_put_nbrbi_base(long long nb, char *base);
void my_printf(char *str, ...);
int binarybase(va_list print);
void traitement(int arg, va_list print);
void my_putchar(char c);
void my_putstr(char const *str);
int my_getnbr(char const *str);
void connect_one(int i, siginfo_t *sigpid, void *s);
int	client_one();
int	client_two(char **av);
int	start_game();
void connect_two();

#endif /* !MY_H_ */
