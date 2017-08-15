/* CS261- HW1 - Program4.c*/
/* Name:Dennis Li
 * Date:4/11/17
 * Solution description: Program randomly generates number of students with 
 * initials and scores and then sorts them based off of first initial and
 * second initial if necessary. Sorting is done through using bubble sort
 * it analyzes if it is necessary for the first initial and then for the 
 * second initial.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};


/*Function Description:Sort students based on initials
 * Input:number of students and array of students
 * Output:sorted array
 */
void sort(struct student* students, int n){
	/*Sort the n students based on their initials*/     
	int a = 1;
	int b;
	int flag=1;
	int length = n;
	struct student temp;

	assert(students != NULL); 

	while(a<length && flag == 1){
		flag = 0;
		for(b=0; b<length-1; b++){ 
			if( students[b+1].initials[0] - 'A' < students[b].initials[0]- 'A'){
				temp = students[b];
				students[b] = students[b+1];
				students[b+1] = temp;

			}	

			else if(students[b+1].initials[0] - 'A' == students[b].initials[0]- 'A'){  /*If the first initial is the same*/
				if( students[b+1].initials[1] - 'A' < students[b].initials[1]- 'A'){
					temp = students[b];
					students[b] = students[b+1];
					students[b+1] = temp;
				}
			}	
			flag = 1; 
		}
		a++;
	}
}


/*Function Description:Creates array of students
 * Input:none
 * Output:Sorts students and displays
 */
int main(){
	srand(time(NULL));



	/*Declare an integer n and assign it a value.*/
	int n = rand()%11; 
	if (n == 0){ /*Accoount for random number is 0 students*/
		printf("%s\n","Random number of students is 0");
		return 0;
	}

	/*Allocate memory for n students using malloc.*/
	struct student *  students;
	students = (struct student*) malloc(n*sizeof(struct student));


	/*Generate random IDs and scores for the n students, using rand().*/
	int rand_score;
	char c1, c2;
	int i;
	for(i=0; i<n; i++){
		rand_score = rand()%101;
		c1 = rand()%26 + 'A';
		c2 = rand()%26 + 'A';

		students[i].score = rand_score;
		students[i].initials[0] = c1;
		students[i].initials[1] = c2;
	}


	/*Print the contents of the array of n students.*/
	printf("%s\n","Unsorted: ");
	for(i=0; i<n; i++){
		printf("%i%s",i+1,". ");
		printf("%c %c %i\n",students[i].initials[0], students[i].initials[1], students[i].score);

	}

	/*Pass this array along with n to the sort() function*/
	sort(students, n);


	/*Print the contents of the array of n students.*/
	printf("%s\n","Sorted: ");
	for(i=0; i<n; i++){
		printf("%i%s",i+1,". ");
		printf("%c %c %i\n",students[i].initials[0], students[i].initials[1], students[i].score);

	}
	
	return 0;
}
