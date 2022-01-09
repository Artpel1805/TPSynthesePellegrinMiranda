#include "fonction.h"


int main(){
	char * hello = "$ ./enseash\nBienvenue dans le Shell ENSEA\nPour quitter taper 'exit'.\nenseash %";
	printSTR(hello);
	return(0);
	}
	
	
// void printSTR(char*)
// @return affiche le char*
// @param une chaine de caractere
	
void printSTR(char* mot){
	write(STDOUT_FILENO,mot,strlen(mot));
	}
	
// ssize_t write(int fd, const void* buf, size_t count)

// @lib <unistd.h>
// @param int fd fichier dans lequel ecrire la chaine de caractère (Ici sortie Standard)
// @param void* buf chaine de caractère a écrire
// @param nombre de caractère à ecrire 
// @return nombre d'octet écris

	
