We can design a recursive function that calculates the Factorial of a positive integer n. We know that the factorial of 0 and 1 is 1 always and is given.

Algorithm Factorial(int n){
    if n == 0 or n == 1 then
        return 1
    else 
        return n*Factorial(n-1)
}


Clearly if n = 1 or n = 0 , The function returns 1. Assume the algorithm computes (n-1)! correctly

Then if we have 
