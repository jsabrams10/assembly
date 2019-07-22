Deciphering mystery.s:

To be honest, given the hint that mystery.s "performs a well 
known and easily recognizable function," a cursory scan of 
the file, the function name "compute_fib", and the example 
of input: 14; output: 165580141 were enough for me to 
conclude that mystery.s represents a program that finds the 
nth-term of the FIBonacci sequence.

Another thing I noticed was that the function"compute_fib" 
calls itself in verious places within mystery.s. To me, 
this meant that the function compute_fib (and consequently 
the program itself) is recursive.

At this point I began coding and devised my own program 
mystery.c. One thing I have not been able to resolve is 
the purpose of the "add" function present in mystery.s, and 
how it might optimize an already seemingly efficient and 
straight-forward program.

mystery.s Original vs Optimized:

The first thing I noticed when inspecting the two versions 
of my mystery.s files is that the unoptimized version was 
about 10 lines longer than the optimized version. A closer 
look revealed that many of the mov commands that were 
present in the original were ommitted, suggesting that many 
of the original moves were unneccesarily present. Obviously 
if some data were placed into a register uneccesarily, only 
to be moved to its final destination sometime later, it 
would be more efficient to simply move said data to its 
final destination in one move. Furthermore, loops can 
quickly compound such inefficiencies.