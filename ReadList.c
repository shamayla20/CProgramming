#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct ACCE{
	double x;
	double y;
	double z;
	double avg;	
};

struct Node{
	struct ACCE data;
	struct Node* nextNode;	
};

struct LList{
	struct Node* head;
	struct Node* last;
	int count;
};


struct Node * addNodeInList(struct LList* list, int index){
	struct Node * newNode = malloc(sizeof(struct Node));
	newNode->nextNode = NULL;	
	if(list->head == NULL){
		list->head = newNode;
		list->last = newNode;
	}else if(index == 0){
		//Add at the start
		newNode->nextNode = list->head;
		list->head = newNode;
	}else if(index == -1){
		//Append at the end
		list->last->nextNode = newNode;
		list->last = newNode;		
	}else{
		//Append at index
		struct Node *insertAfter = list->head;	
		int count  = 1;	
		while(count != index){
			insertAfter = insertAfter->nextNode;
			count++;
		}
		insertAfter->nextNode = newNode;
	}
	list->count++;
	return newNode;
}

void printLList(struct LList* list){
	struct Node * node = list->head;
	while(node!=NULL){
		printf("Avg is %.2f\n",node->data.avg);		
		node = node->nextNode;		
	}
}

void freeLList(struct LList* list){
	struct Node * head = list->head;
	struct Node * current = list->head;
	while(current!=NULL){
		head = current->nextNode;
		free(current);		
	}
}

int main() {
    char buffer[1024];

    struct LList list;
    list.head = NULL;
    list.last = NULL;	
    list.count = 0;
	
    struct Node * insertedNode = NULL;	
	
    FILE *fptr;
    if ((fptr = fopen("sample.txt", "r")) == NULL) {
        printf("Error! opening file");
        // exit if file pointer returns NULL.
        exit(1);
    }
	//fgets reads till buffer size or new line character is encountered	
	while (fgets(buffer, sizeof buffer, fptr) != NULL){
	   //printf("%s", buffer);
		//strtok modifies the original buffer save the line for printing	   		
		char * token = strtok(buffer, ";");
		if(token != NULL){//; was found   	   
			//printf( " %s\n", token ); //printing the token
			   if(strcmp(token,"WIFI")==0){
				//printf("%s", tempBuffer);
     				insertedNode = 	addNodeInList(&list,-1);			
				token = strtok( NULL,";");
				token = strtok( NULL,";");						
    				token = strtok( NULL,";");//x
				insertedNode->data.x = strtod(token,NULL);					
				token = strtok( NULL,";");//y
				insertedNode->data.y = strtod(token,NULL);
				token = strtok( NULL,";");//z
				insertedNode->data.z = strtod(token,NULL);
				insertedNode->data.avg = (insertedNode->data.x+insertedNode->data.y+insertedNode->data.z)/3.0;
			    }
		}
	}
   printLList(&list);
   freeLList(&list);
    	//printf("No of 'WIFI' is %d\n", countSamples);
    fclose(fptr);
    return 0;
}




