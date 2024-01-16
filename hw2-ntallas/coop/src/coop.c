#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char get(void);
void coop(void);
void defect(void);

int roundCount = 0;
int coopCount = 0;
int defectCount =0;

int main(){

  //int reward = 3;
  //int payoff = 1;
  //int temptation = 5;
  //int sucker = 0;

  putchar('C');
  putchar('\n');
  fflush(stdout);

  while(roundCount<=pow(10,6)){
    char c = get();

    if(c == 'C'){
      coopCount++;
      if(coopCount > 4*defectCount + 1/*player is very likely to play cooperatively*/){
      defect();
      }
      else{
        coop();
      }
    }
    else{
      defectCount++;
      if(coopCount > 4*defectCount + 1/*player is very likely to play cooperatively*/){
      coop();
      } 
      else{
      defect();
      }
    }
  }
}

char get(void){
  roundCount++;
  int c = getchar();
  if(c == EOF){
    exit(0);
  }
  if(c == 'D' || c == 'C'){
    return c;
  }
  else{
    return get();
  }
}

void coop(void){
      putchar('C');
      putchar('\n');
      fflush(stdout);
}
void defect(void){
      putchar('D');
      putchar('\n');
      fflush(stdout);
}
