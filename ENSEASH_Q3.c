#include "fonction.h"

ssize_t nblus;//nombe de caractères lus
size_t nbytes=sizeof(buffer);
const char* instruction0="fortune";
const char* exitInstruction="exit";

int main(){
	char * hello = "$ ./enseash\nBienvenue dans le Shell ENSEA\nPour quitter taper 'exit'.\nenseash % ";
	printSTR(hello);		
	while(1){
		readInstruction();
		testInstruction(buffer);
		
		
		//GESTION DE L'ERREUR//
        //La fonction strcmp ser à comparer deux aines de caractères et retourne 0 si elles sont identiques.
        //<ctrl+d> rnvoie une fin de fichier ( EOF = nd of file). Si l bufer est vide quand le caractère fin de fichier est reçu,
        //le shell lira une chaine de caractèes de taille 0.
		// Si la chaine == "EXIT" ou si la chaine n'a lu aucun caractère i.e <ctrl+d> pressé on quitte à l'aide de exit
		if(strcmp(buffer,exitInstruction)==0 || nblus==0){
			printSTR("\n");
			exit(EXIT_SUCCESS);
			break;
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
		printSTR("enseash % ");
		} 
	else{
		printSTR("enseash % ");
		}
	}

