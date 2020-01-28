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
	struct Node * newNode = createNewNode(44,"NewBookName",insertAfter->nextNode);		
	insertAfter->nextNode = newNode;
}

struct Node * reverseNodes(struct Node *start,int nodeCount){
	struct Node *newStart = NULL;
	struct Node *cur = NULL;
	struct Node *prevNode = NULL;	
	int nodesUpdated =1;
	//until all nodes are updated
	while(nodesUpdated != nodeCount){
		//Update the address		
		int j=0;
		cur = start;
		for(;j<nodeCount-nodesUpdated;j++){
			prevNode = cur;						
			cur = cur->nextNode;
			
		}
		if(nodesUpdated==1)
			newStart = cur;
		cur->nextNode = prevNode;
		nodesUpdated++;
	}
	return newStart;
}

struct Node * reverseNodes1(struct Node *start,int nodeCount){
	struct Node *newStart = start;
	struct Node *cur = NULL;
	struct Node *prevNode = NULL;	
	int nodesUpdated =0;
	//until all nodes are updated
	while(nodesUpdated != nodeCount){
		//Update the address		
		cur = start;
		int cond = (nodeCount-nodesUpdated-1);
		for(int j=0;j<cond;j++){
		    if((j+1)==cond){
               if(nodesUpdated==0){
			     newStart = cur->nextNode;
               }
               cur->nextNode->nextNode = cur;
			   nodesUpdated++;
		       cur->nextNode = prevNode;
		       nodesUpdated++;
		       if(nodesUpdated==4){
			     prevNode->nextNode=NULL;
			     nodesUpdated++;
               }
		    }else{
			   prevNode = cur;						
		 	   cur = cur->nextNode;
		    }
		}
		printf("Nodes Updated %d \n",nodesUpdated);
	}
	return newStart;
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
	printf("\n-----------------------------------\n");
	head = reverseNodes1(head,count);
	
	printAllNodes(head,count);
	
	insertNewAfterNode(head,2);
	count++;
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
