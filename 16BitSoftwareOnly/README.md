# 16 BIT S/W ONLY
### https://dmoj.ca/problem/16bitswonly



Early in the production process of the 80386, Intel discovered a fatal bug in the processor, which they of course fixed. The bug involved errors when performing 32-bit multiplication. But by the time they fixed the issue, a number of processors were already produced, and they decided that it would be a shame to throw them all out. It was decided that these processors would be sold at a reduced price with the tag 16 BIT S/W ONLY (16 bit software only). Conversely, the newer processors which don't have the bug instead have two sigmas (ΣΣ) stamped on. We will call them DOUBLE SIGMA processors.

Back in 1985, 32-bit software was something out of reach of most consumers. Even in 1989, the ancient 8086 was sold as new technology. Hence, there is a market for the defective processors.

You, a programmer, decided to get a programming job in the 1992 world so you can survive until you find a way to return to the modern age. In a cluster of servers, some of them use the 16 BIT S/W ONLY processors, but you don't know which ones. Your first job is to determine the bad processors from the 32-bit multiplication results.

The 80386 has an instruction to multiply two 32-bit integers into a 64-bit result, conventionally stored in EDX:EAX register (i.e. temporary variable) pairs because there were no 64-bit registers.

## Input Specification
The first line of input will be the integer ![N](http://static.dmoj.ca/mathoid/b51a60734da64be0e618bacbea2865a8a7dcd669/svg)
such that ![](http://static.dmoj.ca/mathoid/ad3dac10413dfc1e4d32597de9df880410ea485e/svg) . The next ![N](http://static.dmoj.ca/mathoid/b51a60734da64be0e618bacbea2865a8a7dcd669/svg)
 lines of input will contain integers ![](http://static.dmoj.ca/mathoid/6dcd4ce23d88e2ee9568ba546c007c63d9131c1b/svg)
 , ![](http://static.dmoj.ca/mathoid/ae4f281df5a5d0ff3cad6371f76d5c29b6d953ec/svg)
 , and ![](http://static.dmoj.ca/mathoid/511993d3c99719e38a6779073019dacd7178ddb9/svg)
 , such that ![](http://static.dmoj.ca/mathoid/34b6f735666d880c36f037cc249a1975dcb51b36/svg)
  and ![](http://static.dmoj.ca/mathoid/315497b0c946dc2692c5b86358d56d5c42b9f2ea/svg).
  
## Output Specification
For every line of input except the first, output ```16 BIT S/W ONLY``` if the product is wrong (i.e. ![](http://static.dmoj.ca/mathoid/3113fd6f21ffa9a7154ac108eddf1c6b0d00ce27/svg)), or ``POSSIBLE DOUBLE SIGMA`` if correct.

## Sample Input
```
3
1 1 2
2147483647 2147483647 4611686014132420610
12345678 87654321 1082152022374638
```

## Sample Output
```
16 BIT S/W ONLY
16 BIT S/W ONLY
POSSIBLE DOUBLE SIGMA
```

