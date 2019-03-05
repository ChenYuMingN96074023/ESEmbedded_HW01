#include <stdio.h>
int minus(int a,int c){return a-c;}
int plus(int a,int c){  return a+c;}
int multiply(int a, int c) {  return a*c; }
int divided(int a, int c) { return a/c;}
int (* show_type_attributes(char type) )(int,int){ 
    int n[4];
    n['+'] = 0;
    n['-'] = 1;
    n['*'] = 2;
    n['/'] = 3;
   int (*pFun[4])(int,int) = {plus , minus ,multiply ,divided};
  return *pFun[n[(unsigned int)type]];

}
//main() function
int main()
{
    int a, c,d; 
	char b;
	printf("key a Function \nEX: 1 + 1\n");
	scanf("%i %c %i", &a, &b, &c); 
    int (*f)(int,int);  // Declare a pointer to a function with two paramete
    f = show_type_attributes(b); // f will take the return     
    d=f(a,c);  
    printf("the value is %d\n\r",d);
    return 0;
}
