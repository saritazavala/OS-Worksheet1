#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int ffile;
	int sfile;
	if(argc!= 3){
		printf("El numero de argumentos es suficiente\n");
	}else{
		ffile = open(argv[1], O_RDONLY);
		if(ffile < 0){
			printf("El primer archivo no abrió \n");
			exit(0);
		}
		sfile = open(argv[2], O_CREAT|O_WRONLY);
		if(sfile < 0){
			printf("El segundo no abrió \n");
			exit(0);
		}
		int ctotal = lseek(ffile, SEEK_SET, SEEK_END);
		lseek(ffile, 0, SEEK_SET);
		char c[ctotal - 1];
		read(ffile, c, ctotal - 1);
		close(ffile);
		c[ctotal - 1] = 0;
		write(sfile, c, ctotal - 1);
		close(sfile);
	}
	return 0;
}