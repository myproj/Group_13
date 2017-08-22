#include "functions.h"

int factorial(int n){
	cout>>"Hello!2";
    if(n<0){ 
	printf("\nPlease enter a positive number\n");}
    if(n!=1){
	return(n * factorial(n-1));
    }
    else return 1;
}
