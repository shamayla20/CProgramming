#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book{
	int id; 
	char title[50];
};

struct Node{
	struct Book data;
	struct Node* nextNode;
};


struct Node* createNewNode(int id, char title[50],struct Node* nextNode){
	struct Node *node = malloc(sizeof(struct Node)); 	
	node->data.id = id;
	strcpy(node->data.title,title);
	node->nextNode = nextNode;
	return node;
}

void insertNewAfterNode(struct Node *start,int nodeNo){
	struct Node *insertAfter = NULL;	
	int count  = 1;	
	while(count != nodeNo){
		insertAfter = start->nextNode;
		count++;
		start = insertAfter;
	}
	struct Node * newNode = createNewNode(++count,"NewBookName",insertAfter->nextNode);		
	insertAfter->nextNode = newNode;
}

struct Node * reverseNodes(struct Node *start,int nodeCount){
	struct Node *cur = NULL;
	struct Node *prevNode = NULL;	
	cur = start;
	//For every node
	for(int i=nodeCount-1;i>0;i--){
		//Update the address		
		for(int j=0;j<i;j++){
			prevNode = cur;						
			cur = cur->nextNode; 
		}
		if(i==nodeCount-1)
			start = cur->nextNode;
		cur->nextNode = prevNode;
	}
	return start;
}

void printAllNodes(struct Node *start,int nodeCount){

	for(int i=0;i<nodeCount;i++){
		printf("%d -- %s\n",start->data.id,start->data.title);		
		//printf("%s\n",start->data.title);
		start = start->nextNode;		
	}
}


int main(){
	
	struct Node *head = NULL; 			
	struct Node *current = NULL;
	
	int count = 0;

	//Create 5 Nodes
	char snum[10];
	char str[50];
	strcpy(str,"BookName");	
	//itoa(1,snum,10);	
	snprintf (snum, sizeof(snum), "%d",1); 	
	strcat(str,snum);
	current = head = createNewNode(++count,str,NULL);		
	for(int i=2;i<6;i++){
		strcpy(str,"BookName");	
		//itoa(i,snum,10);		
		snprintf (snum, sizeof(snum), "%d",i);		
		strcat(str,snum);		
		current->nextNode = createNewNode(++count,str,NULL);
		current = current->nextNode; 	
	}
	
	printAllNodes(head,count);
	
	insertNewAfterNode(head,2);
	count++;
	printf("\n-----------------------------------\n");
	printAllNodes(head,count);

	head = reverseNodes(head,count);
	
	printf("\n-----------------------------------\n");
	printAllNodes(head,count);

	//Free the memory
	current = head;
	for(int i=0;i<count;i++){
		head = current->nextNode; 	
		free(current);
		current = head;
	}		
	return 0;
}

