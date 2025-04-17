#include<stdio.h>
#include<stdlib.h>
int * fun(int n){
	int *p;
	p=(int *)malloc(n*sizeof(int));
	if(p==NULL){
		printf("dma failed");
	}
	return (p);
}
int main(){
	int *A;
	A=fun(5);
	for(int i=0;i<5;i++){
		A[i]=+i;
	}
	/*for(int i=0;i<5;i++){
		printf("%d ",A[i]);
	}*/
	printf("%d ",*A);
	A++;
	printf("%d",*A);
	free(A);
}
