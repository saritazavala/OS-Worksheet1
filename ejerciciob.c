#include <stdio.h>
#include <unistd.h>

int main(){
	int f = fork();

	if (f ==0){
		execl("Hello", (char*)NULL);}
	else{
		printf("%d\n", (int)getpid());
		execl("Hello", (char*)NULL);
	
	}

	return(0);

}

