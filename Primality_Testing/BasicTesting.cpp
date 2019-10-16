/*
   By definition a prime number doesn't have any divisors other than 1 and itself.
   Also , for every every number , if a*b == n , one of them is less than or equal to sqrt(n) and other 
   is greater than equal to sqrt(n). */
_____________________________________________________________________________________________________
A funtion to check prime
-----------------------------------------------------------------------------------------------------
bool ifprime(int n){
    bool prime = 1; // Assuming n prime.
    for(int i = 2 ; i*i <= n ; i++){
        if(n%i == 0){
            prime = 0;
            break;      //Terminate the loop if n is divisible by any i.
        }
    }
    return prime;
}
_______________________________________________________________________________________________________
*An extra optimization of the above code is when you are use the fact that except 2,3 , all other primes
 are of the form 6k+1 or 6k+5.
 Hence you check for 2 , 3 then make a loop from i = 5, checking divisibility with i , i + 2 and incrementing
 i by 6 each iteration.
 _____________________________________________________________________________________________________
