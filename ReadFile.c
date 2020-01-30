#include<stdio.h>
#include <stdlib.h> // For exit() function
#include <string.h>




int main() {
    char buffer[2048];
    char tempBuffer[255]={0};
	
	
    FILE *fptr;
    if ((fptr = fopen("sample.txt", "r")) == NULL) {
        printf("Error! opening file");
        // exit if file pointer returns NULL.
        exit(1);
    }
	int countSamples =0;
	//fgets reads till buffer size or new line character is encountered	
	while (fgets(buffer, sizeof buffer, fptr) != NULL){
	   //printf("%s", buffer);
		//strtok modifies the original buffer save the line for printing	   		
		char * token = strtok(buffer, ";");
		if(token != NULL){//; was found   	   
			//printf( " %s\n", token ); //printing the token
			   if(strcmp(token,"WIFI")==0){
				countSamples++;
				//printf("%s", tempBuffer);
				while( token != NULL ) {
					token = strtok( NULL,";");					
    					
  				}	
			    }
		}
	}
    	printf("No of 'WIFI' is %d\n", countSamples);
    fclose(fptr);
    return 0;
}


