#include<stdio.h> 
int main(){ 
 int arr[10],max,min; 
 printf("Enter the numbers:"); 
 for(int i=0;i<10;i++){ 
 	scanf("%d",&arr[i]); 
 } 
 max=arr[0]; 
 min=arr[0]; 
 for(int j=0;j<10;j++){ 
 	if(arr[j]>=max){ 
 		max=arr[j]; 
 	} 
 	if(arr[j]<=min){ 
 		min=arr[j]; 
 	} 
 } 
 printf("Max:%d,Min:%d\n",max,min); 
 return 0; 
} 
