#include "fonction.h"

ssize_t nblus;
size_t nbytes=sizeof(buffer);
const char* instruction0="fortune";
const char* exitInstruction="exit";
char exitINFO[50];
char signalINFO[50];
int pid;
int status;
struct timespec start, end; //variables globales.
long deltaT; //var globale, permet de socker la diférence de temps. Type long car le temps sera exprimé en nanosecondes donc avec des nombres relativement élevés.


int main(){
	char * hello = "$ ./enseash\nBienvenue dans le Shell ENSEA\nPour quitter taper 'exit'.\nenseash % ";
	printSTR(hello);		
	while(1){
		readInstruction();
		testInstruction(buffer);
		
		
		//GESTION DE L'ERREUR//
		// Si la chaine == "EXIT" ou si la chaine n'a lu aucun caractère i.e <ctrl+d> pressé on quitte
		if(strcmp(buffer,exitInstruction)==0 || nblus==0){
			printSTR("\n");
			exit(EXIT_SUCCESS);
			break;
		}

		pid=fork();
		if(pid>0){
			wait(&status);
			clock_gettime(CLOCK_REALTIME,&end); //permet de mesurer le temps; Type d'holoe utilisée : CLOCK_REALTIME.
			deltaT=(end.tv_sec-start.tv_sec)*1000+(end.tv_nsec-start.tv_nsec)/1000000;
			if(WIFEXITED(status)){
				sprintf(exitINFO,"enseash [exit : %d | %ld ms] :", WEXITSTATUS(status), deltaT);
				printSTR(exitINFO);
				}
			if(WIFSIGNALED(status)){
				sprintf(signalINFO, "enseash [signal exit : %d| %ld ms] :", WTERMSIG(status), deltaT);
				printSTR(signalINFO);
				}
		
		}else{
			execlp(buffer,buffer, "-i",(char*)NULL);
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
	clock_gettime(CLOCK_REALTIME,&start);
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


