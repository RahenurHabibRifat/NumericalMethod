#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) ((x*x*x)-(2*x) -5)

int main(){
	float a=0, b=0, error=0, m, c;
	int i=0;
	
	//User input a and b
	printf("Input Interval: ");
	scanf("%f%f",&a,&b);
	
	//Check the value a and b valid or invalid
	if((f(a)*f(b))>0){
		printf("Invalid Interval Exit!\n");
		exit(1);
	}else if(f(a)==0 || f(b)==0){
		if(f(a)==0){
			printf("Root is one of Interval Bounds. Root is %f.\n",a);
		}else{
			printf("Root is one of Interval Bounds. Root is %f.\n",b);
		}
		exit(0);
	}
	printf("Ite\t   a\t\t   b\t\t   f(a)\t\t   f(b)\t\t   c\t\t   f(c)\t\n");
	printf("---------------------------------------------------------------------------------------------------\n");
	
	//Using Do While Loop
	do{
		c = m;
		m = (a+b)/2;
		printf("%2d\t%4.6f\t%4.6f\t%4.6f\t%4.6f\t%4.6f\t%.6f\t\n",i++,a,b,f(a),f(b),m,f(m));
		printf("---------------------------------------------------------------------------------------------------\n");
		
		//Initialize a and b
		if(f(m) == 0){
			printf("Root is %d\n",m);
		}else if((f(a)*f(m))<0){
			b = m;
		}else{
			a = m;
		}
		
		error = fabs(m-c);
		/*
		if(i==1){
			printf("-----\n");
		}else{
			printf("%4.6f\n",error);
		}
		*/
		
	}while(error>0.00005);
	
	//Print Root
	printf("Approximate Root Is: %4.6f\n",m);
	
	
	
	return 0;
}
