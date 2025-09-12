#include<stdio.h>
struct Array{
	int A[10];
	int size;
	int length;
};
void Append(struct Array *arr,int element){
	int i;
	if(arr->length<arr->size){
		arr->A[arr->length++]=element;
	}
		printf("Modified array is:");
	for(i=0;i<arr->size;i++){
		printf("%d ",arr->A[i]);
	}
}
void Insert(struct Array *arr,int element,int index){
	if(index<arr->size){
	int i=0;
	for(i=arr->length;i>index;i--){
		arr->A[i]=arr->A[i-1];
	}
	arr->A[i]=element;
	printf("%d element insrted successfully at %d:",element,index);
	printf("Modified array is:");
	for(i=0;i<arr->size;i++){
		printf("%d ",arr->A[i]);
	}
}
	else{
	printf("invalid index");
}
}
Delete(struct Array *arr,int index){
	int i;
	if(index<arr->length){
		for(i=index;i<arr->length;i++){
			arr->A[i]=arr->A[i+1];
		}
	}
	printf("Modified array is:");
	for(i=0;i<arr->size;i++){
		printf("%d ",arr->A[i]);
	}
}
int main(){
	struct Array arr;
	arr={{2,3,4,5,8,9},10,6};
	int el;
	int ind;
//	printf("enter element to enter: ");
//	scanf("%d",&el);
	printf("enter index at which to enter/delete: ");
	scanf("%d",&ind);
//	Insert(&arr,el,ind);
//	Append(&arr,el);
	Delete(&arr,ind);
	
}
