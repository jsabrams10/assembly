Implementation of "formula" Program

Design:

My "formula" program consists of 4 files working in concert: 
nCr.s, nCr.h, formula.c, and Makefile. My main() method is 
contained in formula.c. The first parts of formula.c can be 
summarized in steps as follows:

	1) Start a timer
	2) Parse and test the input:
		a) if no value was entered, complain and return
		b) if "-h" is given as input, provide a helpful
			help message
		c) if the input contains non-numeric character,
			complain and return
		d) convert the input to an int
		e) if input is < 0, complain and return
		f) if input is > 12, complain about overflow and
			return
	3) Print the initial string common to all remaining
		outputs: "(1 + x)^n = 1" - where n is the input
	4) Handle base cases in linear time (O(1)):
		 a) if n == 0, answer is simply 1. Stop timer, print 
		 	time elapsed, and return
		 b) if n == 1, answer is 1 + x^1. Print " + 1*x^1".
		 	Stop timer, print time elapsed, and return
		 c) if n == 2, answer is 1 + 2x^1 + x^2. Print 
		 	" + 2*x^1 + 1*x^2". Stop timer, print time
		 	elapsed, and return
	5) Run the algorithm:
		a) print " + n*x^1" as the first non-constant term, 
			which is always of the form nx^1, where n is the 
			input
		b) initialize an array "coeff" of size n/2 - 1; the 
			size of this array is equal to the remaining 
			number of unique coefficients (the expanded form
			always has a symmetric nature - one which I
			exploit for increased speed and reduced space)
		c) loop through this array, finding each unique 
			coefficient using nCr() and storing them in 
			order, and printing the correct term.
		d) determine whether the number of remaining terms
			to print will be odd or even. This is imperative 
			to getting the indexing of the array correctly
			prepared for the next step
		e) loop backwards through the same array, utilizing
			the symmetry of the expression to correctly 
			print the remaining terms
	6) Stop timer, print time elapsed, and return

nCr.s utilizes calls to the function Factorial() in order to
provide formula.c the integer coefficient corresponding to 
the term containing x raised to the given power, in 
accordance with the known formulas "n-choose-r."

Design/Implementation Challenges:

The biggest hurdle of this assignment was successfully 
linking the nCr.s file (assembly code) with the formula.c 
file (C code) via a Makefile. Though this can be achieved 
with merely a few lines of code, determining the exact 
code required took many hours of tinkering and research.

Space/Time Analysis:

While there must certainly exist a more efficient version 
of this program, it's clever in its own way in that it 
manages to cut the amount of storage space required by 
its array in half by leveraging the symmetry inherent in 
the functions on which it operates on. The program as a 
whole appears to run close to contant time (O(1)) by 
separating out base cases and minimizing the run time of
its loops.