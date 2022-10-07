/*Write a program that takes a single integer n as a command-line argumentand finds its prime factors, excluding 1.  
The output should consist of a single line listing each prime factor in non-decreasing order, separated by a space. 
If n is prime, just print n itself. If there are repeat factors, print the factor as many times as it divides n. 
You can assume that2≤n≤231−1(i.e.,n will fit in a signed 32-bit integer).

Take an input as the commane line 
    //use argv and atoi to get the input and place into function factor 
creating factor.c 
    // find the prime factors 
    // use math.h to find the dividends 
    // for loop to print out 
output 
    // increasing order such as 13, 17 
    // if n is prime print out n 
    // if factors are repeated then print them out as many times needed // 32 = 2 2 2 2 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
// prints factors of prime
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factorCheck(int x)  
{  
    int target_number;  
    // checking the number starting at 2 to make sure it is greater than increment
    for(target_number = 2; x > 1; ++target_number)  
    {  
        // while the number is still equalling out
        while(x % target_number == 0)  
        {  
            printf("%d ", target_number);  
            x = x / target_number;  
        }  
    }  
}  
  // driver for test cases
int main(int argc, char* argv[argc + 1])  
{  
    int factor = atoi(argv[1]);
    // works with scanf
   // scanf("%d", &factor);  
    
    factorCheck(factor);  
    return EXIT_SUCCESS;  
}  
