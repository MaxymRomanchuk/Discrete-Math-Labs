#include <stdio.h>

void print_the_shortest_way(int array [30][4],int node) {
	if(array[node][3]==-1) {
		printf("V%d=%d ",array[node][0],array[node][2]);
	}
	else {
		print_the_shortest_way(array,array[node][3]);
		printf("V%d=%d ",array[node][0],array[node][2]);
	}
}

int main(void) {
	int i,k,lenth=0;
	int result [30] [2];
	int nodes [30] [4] = { //{number,times_used,path_value,last_node}
		{1,1,0,-1},{2,0,0,0},{3,0,0,0},{4,0,0,0},{5,0,0,0},{6,0,0,0},
		{7,0,0,0},{8,0,0,0},{9,0,0,0},{10,0,0,0},{11,0,0,0},{12,0,0,0},
		{13,0,0,0},{14,0,0,0},{15,0,0,0},{16,0,0,0},{17,0,0,0},{18,0,0,0},
		{19,0,0,0},{20,0,0,0},{21,0,0,0},{22,0,0,0},{23,0,0,0},{24,0,0,0},
		{25,0,0,0},{26,0,0,0},{27,0,0,0},{28,0,0,0},{29,0,0,0},{30,0,0,0}
	};
	int edges [49] [3] = { //{from,to,weight}
		{1,2,3},{2,3,4},{3,4,8},{4,5,6},{5,6,4},
		{1,7,1},{2,8,2},{3,9,3},{4,10,4},{5,11,5},{6,12,8},
		{7,8,4},{8,9,1},{9,10,1},{10,11,2},{11,12,7},
		{7,13,7},{8,14,7},{9,15,1},{10,16,4},{11,17,1},{12,18,3},
		{13,14,4},{14,15,5},{15,16,2},{16,17,7},{17,18,7},
		{13,19,1},{14,20,7},{15,21,3},{16,22,3},{17,23,2},{18,24,7},
		{19,20,8},{20,21,3},{21,22,1},{22,23,1},{23,24,5},
		{19,25,5},{20,26,3},{21,27,3},{22,28,1},{23,29,2},{24,30,8},
		{25,26,1},{26,27,7},{27,28,3},{28,29,6},{29,30,3}
	};
	//sorting edges
	int temp,pointer;
	do{
		pointer=0;
		for (i = 0; i < 48; i++){
        	if (edges[i][2] > edges[i + 1][2]) {
            	for (k = 0, temp = 0; k < 3; k++) {
                	temp = edges [i + 1][k];
                	edges [i + 1][k] = edges [i][k];
                	edges [i][k] = temp;
                }
                pointer++;
            }
        }
    }while(pointer!=0);

    while(nodes[29][1]==0) {
    	for(k=1;k<9;k++) {
    		for (i = 0; i < 49; i++) {
	        	if (nodes [edges[i][0] - 1][1] != nodes [edges[i][1] - 1][1] && edges[i][2]==k) {
        	    	if (nodes [edges[i][0] - 1][1] == 0 && nodes [edges[i][1] - 1][1] != 0) {
            	    	nodes [edges[i][0] - 1][1] = nodes [edges[i][1] - 1][1];
            	    	nodes [edges[i][1] - 1][1] = nodes [edges[i][1] - 1][1] + 1;
            	    	nodes [edges[i][0] - 1][2] = nodes [edges[i][1] - 1][2] + edges[i][2];
            	    	result[lenth][0] = nodes[edges[i][0] - 1][0] - 1;
                		result[lenth][1] = nodes[edges[i][0] - 1][2];
                		nodes [edges[i][0] - 1][3] = nodes [edges[i][1] - 1][0]-1;
                		lenth++;
    				}
            		else if (nodes [edges[i][0] - 1][1] != 0 && nodes [edges[i][1] - 1][1] == 0) {
                		nodes [edges[i][1] - 1][1] = nodes [edges[i][0] - 1][1];
                		nodes [edges[i][0] - 1][1] = nodes [edges[i][0] - 1][1] + 1;
                		nodes [edges[i][1] - 1][2] = nodes [edges[i][0] - 1][2] + edges[i][2];
                		result[lenth][0] = nodes[edges[i][1] - 1][0] - 1;
                		result[lenth][1] = nodes[edges[i][1] - 1][2];
                		nodes [edges[i][1] - 1][3] = nodes [edges[i][0] - 1][0]-1;
                		lenth++;
            		}
				}
			}
		}
	}
	//sorting valuable nodes
	do{
		pointer=0;
		for (i = 0; i < lenth; i++){
        	if (result[i][1] > result[i + 1][1]) {
            	for (k = 0, temp = 0; k < 2; k++) {
                	temp = result [i + 1][k];
                	result[i + 1][k] = result[i][k];
                	result[i][k] = temp;
                }
                pointer++;
            }
        }
    }while(pointer!=0);
    printf("Used edges: \n");
	for(i=1;i<=lenth;i++) {
		printf("V%d = %d\n",result[i][0],result[i][1]);
	}
	printf("the shortest way is: \n");
	print_the_shortest_way(nodes,29);
	
	return 0;
}
