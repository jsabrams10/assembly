#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"mystery.h"

int main(int argc, char* argv[]){

	int n = atoi(argv[1]);
	int nthTerm = compute_fib(n);
	
	printf("Value: %d", nthTerm);

	return 0; 
}

int compute_fib(int n){

	if(n == 0){

		return 0;
	}

	if(n == 1){

		return 1;
	}

	return compute_fib(n - 1) + compute_fib(n - 2);
}
