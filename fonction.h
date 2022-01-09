#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void printSTR(char*);
char buffer[100];

void testInstruction(char*);
void readInstruction(void);
