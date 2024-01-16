#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long length(long long);
int flawless(long long, long long);

int main(int argc, char** argv) {
  if (argc != 3) {
    return 1;
  }

  long long low = atoll(argv[1]);
  long long high = atoll(argv[2]);

  if (low > high) {
    return 1;
  }

  long long count = 0;

  for (long long root = ceill(sqrtl(low)); root <= sqrtl(high); root++) {
    long long num = root * root;

    // Includes 1
    if (num == 1) {
      count += 1;
      continue;
    }

    // Gives number to flawless function
    if (flawless(num, root) == 1) {
      printf("%lld, %lld \t", num, root);
      count += num;
    }
  }

  printf("\n\n%lld\n", count);
  return 0;
  // printf("%d", flawless(num, root));
}

// checks if the given number is a flawless square
int flawless(long long num, long long root) {
  //Δεν γινεται χρησιμοποιωντας τα ψηφια ενος αριθμου να παραξουμε εναν αριθμο
  //μεγαλυτερο αυτου.
  if (num < root) {
    return 0;
  }

  //σπαει τον αριθμο απο αριστερα προς τα δεξια σε ενα, δυο κοκ ψηφια
  long long int x = 10;
  for (long long i = 1; i < length(num); i++) {
    // long long power = powl(10,i);

    long long num1 = num / x;
    long long num2 = num % x;

    //printf("%lld %lld , %lld\n", num1, num2, root);
    if (num1 + num2 == root) {
      return 1;
    }
    if (length(num1 + num2) < 1) {
      return 0;
    }
    if (flawless(num1, root - num2) == 1) {
      return 1;
    }
    x *= 10;
  }
  return 0;
}

long long length(long long num) {
  int sum = 0;

  while (num > 0) {
    num /= 10;
    sum += 1;
  }
  return sum;
}

