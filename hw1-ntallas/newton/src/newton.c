#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double F(double); //f(x)
double f(double); //f'(x)
double newtonCalc(double);

double  a_0, a_1, a_2, a_3, a_4, a_5 ;

int reps = 0; //Global NewtonCalc Repetitions
int nanCond = 0; //Global f'(x) = 0 condition

int main(int argc, char **argv) {
  if (argc != 8) {
	printf("Program needs to be called as' ./newton a0 a1 a2 a3 a4 a5 x0'\n");
    return 1;
  }

  a_0 = strtod(argv[1], 0);
  a_1 = strtod(argv[2],0);
  a_2 = strtod(argv[3],0);
  a_3 = strtod(argv[4],0);
  a_4 = strtod(argv[5],0);
  a_5 = strtod(argv[6],0);
  double x_0 = strtod(argv[7],0);

  //printf("%f %f %f %f %f %f %f", a_0, a_1, a_2, a_3 ,a_4, a_5, x_0);

  if(f(x_0) == 0){
    printf("nan\n");
    return 1;
  }

  // if( reps >= 1000){
  // printf("incomplete \n");
  // return 1;
  // }

  double res = newtonCalc(x_0);
  if(res == 0){
    if(reps >= 1000){
      printf("incomplete \n");
      return 0;
    }
    else if(nanCond == 1){
      printf("nan\n");
      return 0;
    }
  }

  printf("%.2f\n",res);
  return 0;
}

//function F
double F(double x){
  double F_x;
  F_x  =   a_0 + (a_1 * x) + (a_2 *x*x) + (a_3* pow(x,3)) + (a_4* pow(x,4)) + (a_5* pow(x,5)) ;
  
  //printf("%f\n", F_x);
  
  return F_x;
}

//derivative of F is function f 
double f(double x){
  double f_x;

  f_x = a_1 + (a_2 * 2 *x) + (a_3 * 3 *x *x) + (a_4 * 4* pow(x,3)) + (a_5 * 5 *pow(x,4)) ;

  //printf("%f\n", f_x);

  return f_x;
}

//Calculator
double newtonCalc(double x_0){
  double x_1;
  reps += 1;
  if(reps >=1000){
    return 0;
  }

  x_1 = x_0 - F(x_0)/ f(x_0) ; //Newton-Raphson Method

  if(x_1 - x_0 < 1/pow(10,6) && x_1 - x_0 > 0){
    return x_1;
  }
  if(x_1 - x_0 > 1/pow(10,6) && x_1 - x_0 < 0){
    return x_1;
  }
  if(f(x_1) == 0){
    nanCond = 1;
    return 0;
  }
return newtonCalc(x_1);
}




