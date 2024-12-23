#include <stdio.h>
#include <string.h>
typedef struct Sinhvien{
	int id;
	char name[50];
	int age;
	char phone[50];
}sinhvien;
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
void sapxep(sinhvien *std,int *length)
{
	sinhvien temp;
	for (int i=0; i<*length-1;i++)
	{
		for (int j=0; j<*length-1-i;j++)
		{
			if(strcmp(std[j].name,std[j+1].name)>0)
			{
				temp=std[j];
				std[j]=std[j+1];
				std[j+1]=temp;
			}
		}
	}
}
int main()
{
	int length=5; 
	sinhvien user[5]={
	{1,"nguyen van a",17,"01234567"},
	{2,"tu van b",17,"01234567"},
	{3,"chu van c",17,"01234567"},
	{4,"phung van d",17,"01234567"},
	{5,"do van e",17,"01234567"}
	};
	in(user,&length); 
	sapxep(user,&length);
	printf ("sau khi sap xep:\n");
	in(user,&length); 
	return 0; 
 } 
