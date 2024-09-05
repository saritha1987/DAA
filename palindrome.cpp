#include<stdio.h>
int main()
{
	int n,rev=0,rem,org;
	printf("enter an integer:");
	scanf("%d",&n);
	org=n;
	while(n!=0){
		rem=n%10;
		rev=rev*10+rem;
		n/=10;
	}
	if(org==rev)
	printf("%d is palindrome",org);
	else
	printf("%d is not a palindrome",org);
	return 0;
}
