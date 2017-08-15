/* CS261- HW1 - Program2.c*/
/* Name: Dennis
 * Date: 4/7/17
 * Solution description:Program generates random number of students 
 * with initials and scores and then calculates the average, min and 
 * max scores.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>



struct student{
	char initials[2];
	int score;
};


/*Function Description:allocate
 * Input:none
 * Output:Creates 10 students
 */
struct student* allocate(){
	/*Allocate memory for ten students*/
	struct student * student_ptr;
	student_ptr = (struct student *) malloc(10*sizeof(struct student));
	return student_ptr;
	/*return the pointer*/
}


/*Function Description:Generates initials and scores for students
 * Input:array of students
 * Output:information of all the students
 */
void generate(struct student* students){
	/*Generate random initials and scores for ten students.
	 *The two initial letters must be capital and must be between A and Z. 
	 *The scores must be between 0 and 100*/
	assert(students != NULL); 
	srand(time(NULL));
	int rand_score;
	char c1, c2;
	int i;

	for(i=0; i<10; i++){
		rand_score = rand()%101;
		c1 = rand()%26 + 'A';
		c2 = rand()%26 + 'A';

		students[i].score = rand_score;
		students[i].initials[0] = c1;
		students[i].initials[1] = c2;
	}
}


/*Function Description:Output
 * Input:array of students
 * Output:Displays information of students
 */
void output(struct student* students){
	/*Output information about the ten students in the format:
	 *              1. Initials  Score
	 *              2. Initials  Score
	 *              ...
	 *              10. Initials Score*/
	assert(students != NULL); 
	int i;
	for(i=0; i<10; i++){
		printf("%i",i+1);
		printf("%s",". ");  
		printf("%c", students[i].initials[0]);
		printf("%c", students[i].initials[1]);
		printf("%s","  ");
		printf("%i\n", students[i].score);
	
	}
}


/*Function Description: Finds min, max, and average
 * Input:array of students
 * Output:displays min, max, and average
 */
void summary(struct student* students){
	/*Compute and print the minimum, maximum and average scores of the ten students*/
	assert(students != NULL); 
	int min = students[0].score;
	int max = students[0].score;
	int average = 0;
	int i;
	for (i=0; i<10; i++){
		if (students[i].score<min){
			min = students[i].score;
		}
	}
	printf("%s", "Minimum Score: ");
	printf("%i\n", min);
	for (i=0; i<10; i++){
		if(students[i].score>max){
			max = students[i].score;
		}
	}
	printf("%s", "Maximum Score: ");
	printf("%i\n", max);
	
	for (i=0; i<10; i++){
		average = average + students[i].score;
	}
	average = average/10;
	printf("%s", "Average Score: ");
	printf("%i\n", average);
}


/*Function Description:Deallocate
 * Input:student array
 * Output:Deletes pointer
 */
void deallocate(struct student* stud){
	/*Deallocate memory from stud*/
	assert(stud != NULL); 
	free(stud);
}


/*Function Description:Calls functions
 * Input:none
 * Output:none
 */
int main(){
	struct student* stud = NULL;
	/*call allocate*/
	stud = allocate();

	/*call generate*/
	generate(stud);

	/*call output*/
	output(stud);

	/*call summary*/
	summary(stud);

	/*call deallocate*/
	free(stud);	

	return 0;
}

