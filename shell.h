#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

int builtinexit(char **);
int cmpstr(char *s1, char *s2);
size_t cmpnstr(char *s1, char *s2, size_t s);
int lenstr(char *str);
char *catstr(char *src, char *dest);
char *cpystr(char *src, char *dest);
int _putchar(char c);
char *pfetch(char **var);
int pseperation(char **env, char **usercomm);
char *mygetline(void);
void mygetenv(char **env);
char **tokenization(char *str);

int birth(char **av, char **env, char **msc, char *usercomm, int mpid, int f);


#endif
