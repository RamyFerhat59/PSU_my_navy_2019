/*
** EPITECH PROJECT, 2020
** navy.c
** File description:
** navy
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int	main(int ac, char **av)
{
    if (ac == 1 || ac > 3) {
      my_putstr("wrong arguments\n");
      return (84);
    }
    if (ac == 2 && client_one(av) == -1) {
	    my_putstr("Bad file\n");
	    return (84);
    }
    if (ac == 3 && client_two(av) == -1) {
	    my_putstr("Bad pid\n");
	    return (84);
    }
  return (0);
}

int	client_one()
{
  struct sigaction	signal;

  signal.sa_sigaction = connect_one;
  signal.sa_flags = SA_SIGINFO;
  my_putstr("my_pid:\t");
  my_put_nbr(getpid());
  my_putstr("\nwaiting for ennemy connexion...\n");
  sigaction(SIGUSR2, &signal, NULL);
  pause();
  return 1;
}

int	client_two(char **av)
{
  int	pid;

  pid = my_getnbr(av[1]);
  my_putstr("my_pid:\t");
  my_put_nbr(getpid());

  if (kill(pid, SIGUSR2) == -1)
    return (84);
  else
    start_game();
  return (0);
}

void connect_one(int i, siginfo_t *sigpid, void *s)
{
  int pid = 0;
  pid = sigpid->si_pid;
  my_putstr("enemy connected\n\n");
  if (kill(pid, SIGUSR1) == -1);
}

void connect_two()
{
  my_putstr("\nsuccessfully connected\n\n");
}

int	start_game()
{
  struct sigaction	signal;
 
  signal.sa_sigaction = connect_two;
  signal.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &signal, NULL);
  pause();
  return 1;
}
