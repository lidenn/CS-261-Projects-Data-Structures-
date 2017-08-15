#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


/*  Create a task from the description and the priority

    param:  priority    priority of the task
    param:  desc    	pointer to the description string
    pre:    none
    post:   none
	ret: 	a task with description and priority
*/
TYPE createTask (int priority, char *desc) 
{

	TYPE newTask;
	newTask.priority = priority;
	strcpy(newTask.description, desc);

	return newTask;
}

/*  Save the list to a file

    param:  heap    pointer to the list
    param:  filePtr	pointer to the file to which the list is saved
    pre:    The list is not empty
    post:   The list is saved to the file in tab-delimited format.
			Each line in the file stores a task, starting with the 
			task priority, followed by a tab character (\t), and 
			the task description.
			
			The tasks are not necessarily stored in the file in 
			priority order. 
	
*/
void saveList(DynArr *heap, FILE *filePtr)
{
  	/* FIX ME */
	int i;
	for(i=0;i<heap->size;i++){
		fprintf(filePtr, "%i\t%s\n",heap->data[i].priority, heap->data[i].description);	
	}

	

}

/*  Load the list from a file

    param:  heap    pointer to the list
    param:  filePtr	pointer to the file
    pre:    none
    post:   The tasks are retrieved from the file and are added to the list.
			Refer to the saveList() function for the format of tasks in the file				
*/
void loadList(DynArr *heap, FILE *filePtr)
{
  	/* FIX ME */
	int p;
	char description[TASK_DESC_SIZE];
	struct Task temp;
	
	if(filePtr ==NULL){
		printf("Cannot open");
	}
	while(fscanf(filePtr,"%d\t", &p)!= EOF){
		fgets(description, sizeof(description), filePtr);
		temp.priority = p;
		strcpy(temp.description, description);

		/*Testers*/
		/*printf("%i\n", temp.priority);
		printf("%s\n", temp.description);*/
	
		addHeap(heap, temp);
		
	}

}

/*  Print the list

    param:  heap    pointer to the list
    pre:    the list is not empty
    post:   The tasks from the list are printed out in priority order.
			The tasks are not removed from the list.
*/
void printList(DynArr *heap)
{
  	/* FIX ME  */
	struct DynArr temp_array;
	int i=0;
	struct Task min;

	initDynArr(&temp_array, heap->size);	
	temp_array.size= heap->size;

	copyDynArr(heap, &temp_array);

	/*replaced by copy*/
/*	for(i=0;i<heap->size;i++){
		temp_array.data[i].priority = heap->data[i].priority;
		strcpy(temp_array.data[i].description, heap->data[i].description);
	}*/

	for(i=0;i<heap->size;i++){
		min = getMinHeap(&temp_array);

		printf("%i\t%s\n",min.priority, min.description);
		removeMinHeap(&temp_array);
	}

}

/*  Compare two tasks by priority

    param:  left    first task
    param:  right 	second task
    pre:    none
    post:   none
	ret: 	-1 if priority of left < priority of right
			1 if priority of left > priority of right
			0 if priority of left = priority of right
*/
int compare(TYPE left, TYPE right)
{
	if (left.priority < right.priority)
		return -1;
	else if (left.priority > right.priority)
		return 1;
	else
		return 0;
}
