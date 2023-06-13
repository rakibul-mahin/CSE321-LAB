#include <stdlib.h>
#include <stdio.h>

int main() {
	    int alloc[5][4] = { 
            { 0, 1, 0, 3 }, 
		    { 2, 0, 0, 0 }, 
		    { 3, 0, 2, 0 }, 
		    { 2, 1, 1, 5 },
		    { 0, 0, 2, 2 } 
        };
	
	    int max[5][4] = { 
            { 6, 4, 3, 4 }, 
		    { 3, 2, 2, 1 }, 
		    { 9, 1, 2, 6 },
		    { 2, 2, 2, 8 }, 
		    { 4, 3, 3, 7 } 
        };

	    int avai[4] = {3,3,2,1};

    	char finish[5] = {'F','F','F','F','F'};
    	
    	int need[5][4];
    	int count = 0;
    	int op = 0;
    	int oip = 0;
    	
    	printf("Need matrix\n");

    	for(int i = 0; i < 5; i++) {
        	for(int j = 0; j < 4; j++) {
            	need[i][j] = max[i][j] - alloc[i][j];
            	printf("%d ", need[i][j]);
		    }
	        printf("\n");
	    }
    
    	while(op <= 10){
        	for(int i = 0; i < 5; i++) {
            	for(int j = 0; j < 4; j++) {
                	if (finish[i] =='F' & need[i][j] <= avai[j]){
                    		count += 1;
            		}
        		}
        		
            	if (count == 4){
                	finish[i] = 'T';
                	for(int j = 0; j < 4; j++) {
                    		avai[j] = alloc[i][j] + avai[j];
			        }
		        }
           	 count = 0;
		    }
    	    op += 1;
    	}

    	printf("Work available array\n");

    	for(int r = 0; r < 4; r++) {
        	printf("%d", avai[r]);
        	printf(" ");
    	}
    	printf("\n");
    	printf("----------------------\n");

    	for(int e = 0; e < 5; e++) {
        	if (finish[e]=='F'){
            		oip+=1;
            		break;
        	}
    	}

    	if (oip != 1){
            printf("safe");
        }else{ 
             printf("Deadlock Ahead"); 
        }

        return 0;
}
