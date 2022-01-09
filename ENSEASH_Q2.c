#include "fonction.h"

ssize_t nblus; //nombe de caractères lus
size_t nbytes=sizeof(buffer);
const char* instruction0="fortune";
const char* exitInstruction="exit";


int main(){
	char * hello = "$ ./enseash\nBienvenue dans le Shell ENSEA\nPour quitter taper 'exit'.\nenseash % ";
	printSTR(hello);	
	while(1){
		
	nblus=read(STDIN_FILENO,buffer,nbytes);
	buffer[nblus-1]=0;
	
	if(strcmp(buffer,instruction0)==0){
		printSTR("Today is what happened to yesterday \n");
		}
	
		
	printSTR("enseash % ");
	}
	return(0);
	}
	
	
// void printSTR(char*)
// @return affiche le char*
// @param une chaine de caractere
	
void printSTR(char* mot){
	write(STDOUT_FILENO,mot,strlen(mot));
}



