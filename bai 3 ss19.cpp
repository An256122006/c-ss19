#include <stdio.h>
#include <string.h>
typedef struct sinhvien{
	char name[50];
	int age;
	char phone[50];
};
void print(sinhvien *std,int *length)
{
	for (int i=0; i<*length; i++)
	{
		printf ("sinh vien thu %d:\n",i+1);
		printf ("id:%d\n",i+1);
		printf ("ten:%s\n",std[i].name);
		printf ("tuoi:%d\n",std[i].age);
		printf ("sdt:%s\n",std[i].phone);
	}
}
void update(sinhvien *std,int *length)
{
	int addindex;
	printf ("moi ban nhap vi tri muon them:");
	scanf ("%d",&addindex);
	addindex--;
	if (addindex>=0 && addindex<=*length)
	{
		for (int i=*length; i>addindex;i--)
		{
			std[i]=std[i-1];
		}
		fflush(stdin);
		printf ("moi ban nhap ten :\n");
		fgets(std[addindex].name,50,stdin);
		std[addindex].name[strcspn(std[addindex].name,"\n")]='\0';
		printf ("moi ban nhap tuoi:");
		scanf ("%d",&std[addindex].age);
		fflush(stdin);
		printf ("moi ban nhap sdt :\n");
		fgets(std[addindex].phone,50,stdin);
		std[addindex].phone[strcspn(std[addindex].phone,"\n")]='\0';
		(*length)++;
	}else
	{
		printf ("khong hop le\n");
	}
}
void sua(sinhvien *std,int *length)
{
	int addindex;
	printf ("moi ban nhap vi tri muon sua:");
	scanf ("%d",&addindex);
	addindex--;
	fflush(stdin);
	printf ("moi ban nhap ten :\n");
	fgets(std[addindex].name,50,stdin);
	std[addindex].name[strcspn(std[addindex].name,"\n")]='\0';
	printf ("moi ban nhap tuoi:");
	scanf ("%d",&std[addindex].age);
	fflush(stdin);
	printf ("moi ban nhap sdt :\n");
	fgets(std[addindex].phone,50,stdin);
	std[addindex].phone[strcspn(std[addindex].phone,"\n")]='\0';
}
void xoa(sinhvien *std,int *length)
{
	int addindex;
	printf ("moi ban nhap vi tri muon xoa:");
	scanf ("%d",&addindex);
	addindex--;
	if (addindex>=0 && addindex<=*length)
	{
		for (int i=addindex; i<*length;i++)
		{
			std[i]=std[i+1];
		}
		(*length)--;
	} else
	{
		printf ("khong hop le\n");
	}
}
void tim(sinhvien *std,int *length)
{
	char search[50];
	printf ("moi ban nhap ten muon tim:");
	fflush(stdin);
	fgets(search,50,stdin);
	search[strcspn(search,"\n")]='\0';
	int temp=-1;
	for (int i=0; i<*length;i++)
	{
		if (strcmp(std[i].name,search)==0)
		{
			temp=i;
			printf ("sinh vien thu %d:\n",temp+1);
	     	printf ("id:%d\n",temp+1);
		    printf ("ten:%s\n",std[temp].name);
	    	printf ("tuoi:%d\n",std[temp].age);
		    printf ("sdt:%s\n",std[temp].phone);
		}
	}
	if (temp==-1)
	{
		printf ("ko tim thay phan tu\n");
	}
}
void sapxep(sinhvien *std,int *length)
{
	sinhvien temp;
	for (int i=0; i<(*length)-1; i++)
	{
		for (int j=0;j<(*length)-1-i; j++)
		{
			if (std[j].age>std[j+1].age)
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
	int value,length;
	printf("moi ban nhap so phan tu sinh vien:");
	scanf ("%d",&length);
	sinhvien user[100];
    for (int i=0; i<length; i++)
	{
     	printf ("sinh vien thu %d:\n",i+1);
		printf ("moi ban nhap ten :\n");
		fflush(stdin);
		fgets(user[i].name,50,stdin);
		user[i].name[strcspn(user[i].name,"\n")]='\0';
		printf ("moi ban nhap tuoi:");
		scanf ("%d",&user[i].age);
		fflush(stdin);
		printf ("moi ban nhap sdt :\n");
		fgets(user[i].phone,50,stdin);
		user[i].phone[strcspn(user[i].phone,"\n")]='\0';
	} 
	do
	{
		printf ("1.Hi?n th? danh sách sinh viên\n");
		printf ("2.Thêm sinh viên\n");
		printf ("3.S?a thông tin sinh viên\n");
		printf ("4.Xóa sinh viên\n");
		printf ("5.Tìm ki?m sinh viên\n");
		printf ("6.S?p x?p danh sách sinh viên");
		printf ("7.thoat\n");
		
		printf ("moi ban nhap lua chon:");
		scanf ("%d",&value);
		switch (value)
		{
			case 1:
				print(user,&length);
				break;
			case 2:
				update(user,&length);
				print(user,&length);
				break;
			case 3:
				sua(user,&length);
				print(user,&length);
				break;
			case 4:
				xoa(user,&length);
				print(user,&length);
				break;
			case 5:
				tim(user,&length);
				break;
			case 6:
				sapxep(user,&length);
				print(user,&length);
				break;
			case 7:
				printf ("thoat");
				return 1;
			default:
				printf ("khong hop le\n");
				break;
		}
	}while (1);
}
