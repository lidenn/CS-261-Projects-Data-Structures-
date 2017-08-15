/* CS261- HW1 - Program3.c*/
/* Name:Dennis Li
 * Date:4/11/17
 * Solution description:Program sorts an random array of integers
 * using bubble sort.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<assert.h>


/*Function Description:Sorts the array of numbers
 * Input:array of numbers, and amount of numbers in array
 * Output:sorted array
 */
void sort(int* number, int n){
     /*Sort the given array number , of length n*/     
	assert(number != NULL); 
	int a = 1;
	int b;
	int temp_num;
	int flag=1;
	int length = n;

	while(a<length && flag == 1){
		flag = 0;
		for(b=0; b<length-1; b++){ 
			if(number[b+1]<number[b]){
				temp_num = number[b];
				number[b] = number [b+1];
				number[b+1] = temp_num;		
				flag = 1;
			}

		}
		a++;
	}
}

/*Function Description: creates random array of integers and sorts
 * Input:none
 * Output:sorted array
 */
int main(){
	srand(time(NULL));
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
	int*  num_array;
	num_array = (int*) malloc(n*sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
   	int i;
	for(i=0;i<n;i++){
		num_array[i]=rand()%101;

	}	

    /*Print the contents of the array.*/
	printf("%s\n","Unsorted scores: " );
	for(i=0;i<n;i++){
		printf("%i%s%i",i+1,". ",num_array[i]);
	printf("\n");	
	}



    /*Pass this array along with n to the sort() function of part a.*/
	sort(num_array, n);


    /*Print the contents of the array.*/    
	printf("%s\n","Sorted scores: " );
	for(i=0;i<n;i++){	    
		printf("%i%s%i",i+1,". ",num_array[i]);
		printf("\n");	

	}
    
    return 0;
}
