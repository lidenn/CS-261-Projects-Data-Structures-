/* CS261- HW1 - Program2.c*/
/* Name: Dennis Li
 * Date:4/7/17
 * Solution description: Program decrements a value and increments a value using pass by
 * reference and then prints the results. The result is a pass by value.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
#include<assert.h>

/*Function Description: increments a, decrements b, subtraction is placed into c
 * Input: int, int int
 * Output:a+1, b-1, result in c
 */
int foo(int* a, int* b, int c){
	assert(a != NULL); 
	assert(b != NULL); 
	/* Increment a */
	*a = *a + 1;
	/* Decrement  b */
	*b = *b - 1;
	/* Assign a-b to c */
	c = *a - *b;
	/* Return c */
	return c;
}

/*Function Description:runs foo and displays results
 * Input:none
 * Output:prints results
 */
int main(){
	srand(time(NULL));
	rand();
	/* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	int x = (rand()%11);
	int y = (rand()%11);
	int z = (rand()%11);
	int foo_num;


	/* Print the values of x, y and z */
	printf("%s\n","Values of x,y, and z: ");
	printf("%s%i\n","x: ",x); 
	printf("%s%i\n","y: ",y); 
	printf("%s%i\n","z: ",z); 

	/* Call foo() appropriately, passing x,y,z as parameters */

	foo_num = foo(&x,&y,z);
	/* Print the values of x, y and z */
	printf("%s\n","Values new of x,y, and z: ");
	printf("%s%i\n","x: ",x); 
	printf("%s%i\n","y: ",y); 
	printf("%s%i\n","z: ",z); 
	/* Print the value returned by foo */
	printf("%s\n","Return value of foo: ");
	printf("%i\n",foo_num);
	/* Is the return value different than the value of z?  Why? */
	
	/*It is different because z is used as a pass by value instead of a pass by reference
	 */
	return 0;
}



