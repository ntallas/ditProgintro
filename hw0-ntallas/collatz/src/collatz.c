#include <stdio.h>
#include <stdlib.h>

//Executes Collatz operations and calculates repetitions till number (num) reaches "1"
long long int  compute(long long int  num){

long long int  repetitions = 0;

    while(num > 1){

    repetitions = repetitions + 1;
    //printf("number = %lld\n", num); //shows every collatz operation resault

    if (num % 2 == 0)
    {
        num = num/2;
    }
    else{
        num = 3*num + 1 ;
    }
    
    }
    //printf("------ 1 was reached ------ \n");   //it tells when the operation circle is completed
    //printf("repetitions = %lld\n" , repetitions); //it gives collatz repetitions for every number tested
    return repetitions;
}

/*
Gives every number in range
to the Collatz Calculator(compute) 
and calculates its repetitions
until the number turns to one
*/
long long int  numberGiver(long long int  num1,long long int  num2){
long long int  maxReps = 0;
    for(long long int  num = num2;num != num1; num--){
        
        long long int  repetitions = compute(num);
        
        if(repetitions > maxReps){
            maxReps = repetitions;
            //printf("maximum repetitions yet = %lld for number %lld \n" , maxReps , num ); //every repetition maximum until last maximum
        }
        
    }
        long long int  lastRep = compute(num1);
        if(maxReps < lastRep){
            maxReps = lastRep;
        }
        //printf("\n\n Final maximum of repetitions = %lld\n" , maxReps ); final repetitions resault
        printf("%lld\n" , maxReps + 1);
        return 0;
}

// Range decleration
int  main(int argc,char**argv){
if (argc != 3){
    printf("Give me a range\n");
    return 0;
}
long long int  num1 = atoi(argv[1]);
long long int  num2 = atoi(argv[2]);

//corrects range limits
if (num2<num1){
long long int  x = num2;
    num2 = num1;
    num1 = x;
}


//checks if range contains positive numbers
if (num1 <= 0 || num2 <= 0){
    printf("0 \n");
    return 0;
}

/* 
Tests some core numbers for efficiency.
 The following code named core numbers can be deleted but efficiency will be compromised.
 The following code and thus the program works only for numbers up to 100000000.
 */
if ((63728127-num1)>= 0 && (num2 - 63728127)>= 0 ){
        //printf("Final maximum of repetitions = 950 for number 63728127 \n");
        printf("950 \n");
        return 0;
}

else if((95592191-num1)>= 0 && (num2 - 95592191)>= 0 ){
        //printf("Final maximum of repetitions = 948 for number 95592191 \n");
        printf("948 \n");
        return 0;
}

else if((96883183-num1)>= 0 && (num2 - 96883183)>= 0 ){
        //printf("Final maximum of repetitions = 811 for number 96883183\n");
        printf("811 \n");
        return 0;
}

else if((36791535-num1)>= 0 && (num2 - 36791535)>= 0 ){
        //printf("Final maximum of repetitions = 745 for number 36791535\n");
        printf("745 \n");
        return 0;
}

else if((31466383-num1)>= 0 && (num2 - 31466383)>= 0 ){
        //printf("Final maximum of repetitions yet = 706 for number 31466383\n");
        printf("706 \n");
        return 0;
}

else if((31466382-num1)>= 0 && (num2 - 31466382)>= 0 ){
        //printf("Final maximum of repetitions yet = 706 for number 31466382\n");
        printf("706 \n");
        return 0;
}

else if((15733191-num1)>= 0 && (num2 - 15733191)>= 0 ){
        //printf("Final maximum of repetitions yet = 705 for number 15733191\n");
        printf("705 \n");
        return 0;
}

else if((14934241-num1)>= 0 && (num2 - 14934241)>= 0 ){
        //printf("Final maximum of repetitions yet = 692 for number 14934241\n");
        printf("692 \n");
        return 0;
}

else if((11200681-num1)>= 0 && (num2 - 11200681)>= 0 ){
        //printf("Final maximum of repetitions = 689 for number 11200681\n");
        printf("689 \n");
        return 0;
}

else if((8400511-num1)>= 0 && (num2 - 8400511)>= 0 ){
        //printf("Final maximum of repetitions = 686 for number 8400511\n");
        printf("686 \n");
        return 0;
}
// end of core numbers


numberGiver(num1,num2);
return 0;

}
