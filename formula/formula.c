#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/time.h>
#include	"nCr.h"

int main(int argc, char* argv[]){

	struct timeval t0;					// Start the clock.
	gettimeofday(&t0, 0);

	if(argc == 1){

		printf("\nNo value entered - please try again.\n\n");
		
		return 0;
	}

	if(!strcmp(argv[1], "-h")){

		printf("\nUsage: formula <positive integer>\n\n");
		
		return 0;
	}

	int numDigits = strlen(argv[1]);
	int numDex = 0;
	int n = 0;

	while(numDex < numDigits){				// Parse the input.

		if(argv[1][numDex] != '0' &&
			argv[1][numDex] != '1' &&
                        argv[1][numDex] != '2' &&
                        argv[1][numDex] != '3' &&
                        argv[1][numDex] != '4' &&
                        argv[1][numDex] != '5' &&
                        argv[1][numDex] != '6' &&
                        argv[1][numDex] != '7' &&
                        argv[1][numDex] != '8' &&
                        argv[1][numDex] != '9'){

			printf("\nNon-numeric value entered - please try again.\n\n");
		
			return 0;
		}

		int nextTerm = argv[1][numDex] - '0';
		int tensPow = numDigits - numDex;
		int count = 1;		

		while(count < tensPow){

			nextTerm *= 10;
			count++;
		}

		n += nextTerm;
		numDex++;
	}
	
	if(n < 0){

		printf("\nNegative value entered - please try again.\n\n");

		return 0;
	}

	if(n > 12){

		printf("\nOverflow detected - please try again.\n\n");

		return 0;
	}

	printf("\n(1 + x)^%d = 1", n);

	if(n == 0){						// Base case 1.
		
		printf("\n");

		struct timeval t1;     				// Stop the clock.
       		gettimeofday(&t1, 0);

       		long tElap = (t1.tv_sec - t0.tv_sec) + 
			(t1.tv_usec - t0.tv_usec);

       		printf("\nTime required = %ld microsecond(s)\n\n", tElap);

                return 0;
        }

	if(n == 1){						// Base case 2.

		printf(" + 1*x^1\n");

		struct timeval t1;     				// Stop the clock.
                gettimeofday(&t1, 0);

                long tElap = (t1.tv_sec - t0.tv_sec) + 
                        (t1.tv_usec - t0.tv_usec);

                printf("\nTime required = %ld microsecond(s)\n\n", tElap);

		return 0;
	}

	if(n == 2){						// Base case 3.

		printf(" + 2*x^1 + 1*x^2\n");

		struct timeval t1;     				// Stop the clock.
                gettimeofday(&t1, 0);

                long tElap = (t1.tv_sec - t0.tv_sec) + 
                        (t1.tv_usec - t0.tv_usec);

                printf("\nTime required = %ld microsecond(s)\n\n", tElap);

		return 0;
	}

	printf(" + %d*x^1", n);			// Print first non-constant term.

	int coeff[(n / 2) - 1];
	int r = 2;
	int coeffDex = 0;

	while(coeffDex < (n / 2) - 1){				// Print first
								// half of the
		coeff[coeffDex] = nCr(n, r);			// terms one
								// by one.
		printf(" + %d*x^%d", coeff[coeffDex], r);

		r++;
		coeffDex++;
	}

	int nIsEven = 0;			// Determine whether the number of
						// terms (excluding the constant 1)
	if(n % 2 == 0){				// will be even or odd.

		 nIsEven = 1;
	} 

	if(nIsEven){						// Prep "coeffDex"
								// depending on
		coeffDex = (n / 2) - 3;				// "nIsEven".
	}

	else{

		coeffDex = (n / 2) - 2;
	}

	while(coeffDex >= 0){					// Print the second
								// half of the terms.
		printf(" + %d*x^%d", coeff[coeffDex], r);

		r++;
		coeffDex--;
	}

	printf(" + %d*x^%d + 1*x^%d", n, n - 1, n);

	struct timeval t1;					// Stop the clock.
	gettimeofday(&t1, 0);

	long tElap = (t1.tv_sec - t0.tv_sec) + 
		(t1.tv_usec - t0.tv_usec);

	printf("\n\nTime required = %ld microsecond(s)\n\n", tElap);
	
	return 0;
}
