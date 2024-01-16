#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(unsigned long long int);
int isSquare (unsigned long long int);
unsigned long long int mirror (unsigned long long int);
int isNotPalindromic(unsigned long long int );
int everythingChecker(unsigned long long int );


/*Main : δέχεται το εύρος των αριθμών και δίνει για 
εξέταση(εάν είναι κατοπτρικάπρώτα τετράγωνα)
τους αριθμούς τού εύρους που της δόθηκαν
*/

int main(int argc, char **argv) {
  unsigned long long int lowSq, highSq, high, low, numSq, sum;

  if (argc != 3) {
	printf("Program needs to be called as' ./mirror lowSq, highSq' \n");
    return 1;
  }

  low = atoll(argv[1]);
  high = atoll(argv[2]);

  lowSq = floorl(sqrtl(low));
  highSq = ceill(sqrtl(high));

  if (low>high || lowSq<1 || high > powl(10,15)){
     return 1;
  }
  
  sum = 0;
  numSq = lowSq;
  if(numSq % 2 == 0){
    numSq = numSq + 1;
  }
  while(numSq <= highSq){

    if(numSq % 10 != 1 && numSq %10 != 3){
      numSq +=2;
      continue;
    }

    if(mirror(numSq) % 10 != 1 && mirror(numSq) % 10 != 3){
      numSq +=2;
      continue;
    }

    if(everythingChecker(numSq)){
      
      //printf("YES, num = %lld, root = %lld\n", numSq*numSq, numSq);

      sum = sum + numSq*numSq;
    }

    numSq += 2;
  }

  printf("%lld \n", sum);
  
  return 0;
}

// Εξετάζει αν ο αριθμός είναι πρώτος
int isPrime(unsigned long long int numSq){

  unsigned long long int i;
  unsigned long long int limit = floorl(sqrtl(numSq));

  if(numSq%2 == 0){
    return 0;
  }

  for (i = 3; i <= limit ; i+=2){ 
  
    if (numSq % i == 0){
      return 0;
    }
  }
  
  return 1;
}

//  (1). Εξετάζει αν ο αριθμός είναι τέλειο τετράγωνο.
int isSquare(unsigned long long int numSq){

  if (ceil((long double)sqrtl(numSq)) != floor((long double)sqrtl(numSq))){
    return 0;
  }

  return 1;
}

// Βρίσκει το κάτοπτρο ενός αριθμού.
unsigned long long int mirror(unsigned long long int numSq){

  unsigned long long int mirror = 0, lastDigit;

  while (numSq != 0) {
    lastDigit = numSq % 10;
    mirror = mirror * 10 + lastDigit;
    numSq = numSq - lastDigit;
    numSq /= 10;
  }

  return mirror;

}




// Εξετάζει ο αριθμός δεν είναι παλλινδρομικός
int isNotPalindromic(unsigned long long int num){
  if(mirror(num) == num){
    return 0;
  }

  return 1;
}



//Ελέγχει αν ο αριθμός είναι κατοπτρικό πρώτο τετράγωνο
int everythingChecker(unsigned long long int numSq){

  long long int numReal = numSq*numSq;
  long long int mirr = mirror(numReal);

  if(
    isPrime(numSq) &&
    isPrime(sqrtl(mirr))&&
    isSquare(mirr) &&
    isNotPalindromic(numReal)


    
  ){
    return 1;
  }

  return 0;
}
