#include <stdio.h>
#include <string.h>
typedef struct Sinhvien{
	int id;
	char name[50];
	int age;
	char phone[50];
}sinhvien;
void xoa(sinhvien *std,int *addindex,int *length)
{
	for (int i=*addindex-1; i<*length; i++)
	{
		std[i]=std[i+1]; 
	} 
	*length--;
 }
void in(sinhvien *std,int *length)
{
	for (int i=0; i<*length;i++)
	{
		printf ("id:%d\n",std[i].id);
		printf ("ten:%s\n",std[i].name);
		printf ("id:%d\n",std[i].age);
		printf ("id:%s\n",std[i].phone); 
	 } 
}  
int main()
{
	int addindex, length=5; 
	sinhvien user[5]={
	{1,"nguyen van a",17,"01234567"},
	{2,"nguyen van b",17,"01234567"},
	{3,"nguyen van c",17,"01234567"},
	{4,"nguyen van d",17,"01234567"},
	{5,"nguyen van e",17,"01234567"}
	};
	in(user,&length); 
	printf ("moi ban nhap vi tri muon xoa:");
	scanf ("%d",&addindex);
	xoa(user,&addindex,&length);
	in(user,&length);  
	return 0;
}
