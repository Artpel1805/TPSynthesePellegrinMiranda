#include "fonction.h"

ssize_t nblus;
size_t nbytes=sizeof(buffer);
const char* instruction0="fortune";
const char* exitInstruction="exit";
char exitINFO[50];
char signalINFO[50];
int pid; //ientifiant du processus
int status; //satut du processus

int main(){
	char * hello = "$ ./enseash\nBienvenue dans le Shell ENSEA\nPour quitter taper 'exit'.\nenseash % ";
	printSTR(hello);		
	while(1){
		readInstruction();
		testInstruction(buffer);
		
		
		//GESTION DE L'ERREUR//
		// Si la chaine == "EXIT" ou si la chaine n'a lu aucun caractère i.e <ctrl+d> pressé on quitte.
		if(strcmp(buffer,exitInstruction)==0 || nblus==0){
			printSTR("\n");
			exit(EXIT_SUCCESS);
			break;
		}

		pid=fork();
		if(pid>0){
			wait(&status);
			if(WIFEXITED(status)){
				sprintf(exitINFO,"enseash [exit : %d] :", WEXITSTATUS(status));
				printSTR(exitINFO);
				}
			if(WIFSIGNALED(status)){
				sprintf(signalINFO, "enseash [signal exit : %d] :", WTERMSIG(status));
				printSTR(signalINFO);
				}
		
		}else{
			execlp(buffer,buffer,(char*)NULL);
			exit(-1);
			}
		
	}
	
	return(0);
	}
	





// void printSTR(char*)
// @return affiche le char*
// @param une chaine de caractere
	
void printSTR(char* mot){
	write(STDOUT_FILENO,mot,strlen(mot));
}

// void readInstruction(void)
// lit une chaine de caractère rentréé par l'utilisateur 

void readInstruction(void){
	nblus=read(STDIN_FILENO,buffer,nbytes);
	buffer[nblus-1]=0;
	}

// void testInstruction(char*)
// effectue les actions de la chaine de caractère
// @param la chaine rentréé par l'utilisateur
// 

void testInstruction(char* buffer){
	
	if(strcmp(buffer,instruction0)==0){
		printSTR("Today is what happened to yesterday \n");
		} 

	}


