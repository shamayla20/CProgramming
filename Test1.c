#include <stdio.h>
#include <string.h>

struct Book{
	int id; 
	char title[50];
};

struct Node{
	struct Book data;
	struct Node* nextNode;
};

void printBook(struct Book *myBook){
	printf("Book id is %d\n",myBook->id);	
	printf("Book Name is %s\n",myBook->title);	
}

void initializeBook(struct Book *book,int id,char* bookName){
	book->id = id;
	strcpy(book->title,bookName);
}

struct Node createNewNode(struct Book *book,struct Node *nextNode){
	struct Node node; 	
	node.data = *book;
	node.nextNode = nextNode;
	return node;
}

int main(){
	struct Book books[10];

	initializeBook(&books[0],1,"C programming");
	initializeBook(&books[1],2,"System programming");
		
	struct Node firstNode = createNewNode(&books[0],NULL);	
	struct Node secondNode = createNewNode(&books[1],NULL);
	firstNode.nextNode = &secondNode;	
	
	printBook(&firstNode.data);
	printBook(&secondNode.data);
	
	return 0;
}



