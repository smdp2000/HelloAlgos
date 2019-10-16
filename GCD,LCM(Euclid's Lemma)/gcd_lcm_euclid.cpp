/*The given program is used for finding the GCD , LCM of two numbers.
______________________________________________________________________
  Used Algorithm :- Euclid's GCD Lemma.
  Time Complexity :- O(log(min(n1,n2)))
______________________________________________________________________
  According to the Euclid's Lemma , | GCD(a,b) = GCD(b,a%b).|
______________________________________________________________________
  *NOTE* :-
    *)If one number is zero , the other automatically becomes the GCD.
    *) If both are zeroes , then the GCD doesn't exist
______________________________________________________________________
  Hence , we make a recursive function using GCD(a,b) = GCD(b,a%b),
  and, if you observe , the values of (a,b) will strictly decrease, 
  Hence , the function terminates when GCD(a,b) is found. 
_______________________________________________________________________*/
*CODE*
________________________________________________________________________
//Function For GCD :-
int GCD(int a , int b){
    if(b) return GCD(b , a%b);    //If b is non-zero , then recurse.
    else return a;                //if b is 0 , a is the GCD.
}
_________________________________________________________________________________
LCM :-
================================================================================
/*For LCM , we use the relation :-
             __________________________
            | LCM(a,b)*GCD(a,b) == a*b |
 */
 ___________________________________________________________________________________
*CODE*
____________________________________________________________________________________
int LCM(int a , int b){
    return (a*b)/GCD(a,b);
}
______________________________________________________________________________________
