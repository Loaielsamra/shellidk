#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

int builtinexit(char **var);
int cmpstr(char *s1, char *s2);
size_t cmpnstr(char *s1, char *s2, size_t s);
int lenstr(char *str);
char *cpystr(char *dest, char *src);
char *catstr(char *dest, char *src);
int _putchar(char c);
char *pfetch(char **env);
int plocate(char **arguements, char **env);
char *mygetline(void);
char **tokenization(char *usercomm);
int birth(char **msc, char **av, char **env, char *usercomm, int mpid, int f);
void mygetenv(char **env);

#endif
