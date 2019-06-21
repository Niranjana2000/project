#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define RED "\x1b[31m"
#define BOLD_RED "\x1b[1;31m"
#define BOLD_GREEN "\x1b[1;32m"
#define YELLOW "\x1b[33m"
#define BOLD_CYAN "\x1b[1;36m"
#define BOLD_YELLOW "\x1b[1;33m"
#define BOLD_MAGENTA "\x1b[1;35m"
#define BOLD_BLUE "\x1b[1;34m"
#define RESET "\x1b[0m" 
struct record
{
	char name[100],blood[5],email[100];
	long int number;
	struct date
	{
		int d,m,y;
	}dob;
};
void menu();
void add();
void edit();
void search();
void list();
void delete();
void exit_();
void main()
{
	system("clear");
	int ch1;
	char c1;
	do
	{
		menu();
		printf("\n\n\tEnter your choice:");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1:add();
				break;
			case 2:edit();
				break;
			case 3:search();
				break;
			case 4:list();
				break;
			case 5:delete();
				break;
			case 6:exit_();
				break;
			default:printf(RED);
				printf("\n\aInvalid choice!!!!!!!");
				printf(RESET);				
				break;
		}
		printf(BOLD_RED);
		printf("\n\n\n\t\a\a\aWant to perform again(y/n):");
		scanf("%*c %c",&c1);
		printf(RESET);
	}while(c1=='Y'||c1=='y');				
}
void menu()				//menu function
{
	system("clear");
	printf(BOLD_YELLOW);
	printf("\n\n\n\n\n\n\t****************");	
	printf(RESET);
	printf(BOLD_MAGENTA);	
	printf("WELCOME TO PHONEBOOK APPLICATION");
	printf(RESET);
	printf(BOLD_YELLOW);
	printf("****************");
	printf(RESET);
	printf(BOLD_GREEN);
	printf("\n\n\n\t1.Add a contact");
	printf("\n\t2.Edit a contact");
	printf("\n\t3.Search a contact");
	printf("\n\t4.List a contact");
	printf("\n\t5.Delete a contact");
	printf("\n\t6.Exit");
	printf(RESET);
}
void add()				//function to add a contact
{
	char c2;
	do
	{
		FILE *p;
		struct record r;
		p=fopen("contact.txt","ab+");
		printf(BOLD_BLUE);	
		printf("\n\n\n\n\n\t----------Enter details----------");
		printf(RESET);
		printf("\n\n\tEnter Name:");		
		scanf("%*c %[^\n]s",r.name);
		printf("\n\tEnter phone number:");
		scanf("%ld",&r.number);		
		printf("\n\tEnter Email id:");
		scanf("%*c %s",r.email);	
		printf("\n\tEnter date of birth(dd mm yyyy):");				
		scanf("%d %d %d",&r.dob.d,&r.dob.m,&r.dob.y);
		printf("\n\tEnter Blood group:");
		scanf("%*c %[^\n]s",r.blood);		
		fwrite(&r,sizeof(r),1,p);
		printf(BOLD_YELLOW);
		printf("\n\t\a\a\aCONTACT SAVED!!!!\n\n");
		printf(RESET);		
		fclose(p);
		printf(RED);		
		printf("\n\n\t\aWant to add contact again(y/n):");
		printf(RESET);
		scanf("%*c %c",&c2);
	}while(c2=='Y'||c2=='y');
}
void edit()
{
	char c4;	
	do
	{
		char name[100]; 
		int flag=0;
		FILE *p;	
		struct record r1,r2;
		p=fopen("contact.txt","rb+");
		if(p==NULL)
		{
			printf(RED);
			printf("\n\n\t\aNO CONTACT FOUND!!!!!\n");
			exit(1);	 
			printf(RESET);
		}
		else
		{
			printf("\n\tEnter the contact name to modify:");
			scanf("%*c %[^\n]s",name);
			while(fread(&r1,sizeof(r1),1,p)==1)
			{
				if(strcmp(name,r1.name)==0)
				{
					printf(BOLD_BLUE);
					printf("\n\t---------Enter details-----------");
					printf(RESET);
					printf("\n\tEnter Name:");
					scanf("%*c %[^\n]s",r2.name);
					printf("\n\tEnter phone number:");
					scanf("%ld",&r2.number);	
					printf("\n\tEnter Email id:");
					scanf("%*c %s",r2.email);
					printf("\n\tEnter date of birth(dd mm yyyy):");	
					scanf("%d %d %d",&r2.dob.d,&r2.dob.m,&r2.dob.y);
					printf("\n\tEnter Blood group:");	
					scanf("%*c %[^\n]s",r2.blood);
					fseek(p,-sizeof(r1),SEEK_CUR);
					fwrite(&r2,sizeof(r2),1,p);
		                       	for(int i=0;i<10000;i++);
					printf(BOLD_YELLOW);
					printf("\n\t\a\a\aCONTACT SAVED!!!!\n\n");
					printf(RESET);
					flag=1;
					fclose(p);
				}
		}			
		if(flag==0)
		{
					printf("\n\tData is not found!!!!!");
				}		
		}
		printf(RED);		
		printf("\n\t\aWant to edit more(y/n):");
		scanf("%*c %c",&c4);
		printf(RESET);
	}while(c4=='Y'||c4=='y');
}
void search()
{
	char c6;
	do
	{
		FILE *p;
		struct record r;
		p=fopen("contact.txt","rb");
		char name[100];	
		int flag=0;
		if(p==NULL)
		{
			printf(RED);
			printf("\n\n\t\a\a\aNO CONTACT FOUND!!!!!\n");
			exit(1);
			printf(RESET);
		}
		else
		{
			printf("\n\tEnter the contact name to be searched for:");
			scanf("%*c %[^\n]s",name);
			while(fread(&r,sizeof(r),1,p)==1)
			{
				if(strcmp(r.name,name)==0)
				{	
					printf(BOLD_YELLOW);
					printf("\n\t*************DETAILS****************\n");
					printf(RESET);
					printf("\n\tName:%s\n\tPhone Number:%ld\n\tEmail ID:%s\n\tDate of Birth:%d-%d-%d\n\tBlood group:%s",r.name,r.number,r.email,r.dob.d,r.dob.m,r.dob.y,r.blood); 
					flag=1;
				}
			}
			if(flag==0)
			{
				printf(RED);
				printf("\n\tCONTACT NOT FOUND!!!!!!!!");
				printf(RESET);
			}
		}
		printf(RED);
		printf("\n\t\a\a\a\aWant to search more(y/n):");
		printf(RESET);
		scanf("%*c %c",&c6);
	}while(c6=='Y'||c6=='y');
}					
void list()			//function to list contacts
{
	FILE *p;
	struct record r;
	p=fopen("contact.txt","rb");
	if(p==NULL)
	{	
		printf(RED);
		printf("\n\n\t\a\a\aNO CONTACT FOUND!!!!!\n");
		exit(1);
		printf(RESET);	
	}
	else
	{
		printf(BOLD_BLUE);
		printf("\n\n\tNAME\t\t\tNUMBER\t\tEMAIL ID");
		printf(RESET);
		while(fread(&r,sizeof(r),1,p)==1)
		{
			printf("\n\t%s\t\t%ld\t%s",r.name,r.number,r.email);
		}
	}
}
void delete()			//function to delete a contact
{
	char c7;
	do
	{
		FILE *fp,*ft;
		struct record r;
		char name[100];
		int flag;
		fp=fopen("contact.txt","rb");		
		if(fp==NULL)
		{	
			printf(RED);
			printf("\n\n\t\a\a\aNO CONTACT FOUND!!!!!\n");
			printf(RESET);	
		}
		else
		{
			ft=fopen("temp.txt","wb+");
			if(ft==NULL)
			{	
				printf(RED);
				printf("\n\n\t\a\a\aFILE OPENING ERROR!!!!!\n");	
				printf(RESET);	
			}
			else
			{			
				printf("\n\tEnter contact name:");
				scanf("%s",name);
				while(fread(&r,sizeof(r),1,fp)!=0)
				{
					if(strcmp(r.name,name)!=0)
						fwrite(&r,sizeof(r),1,ft);		
					if(strcmp(r.name,name)==0)
                				flag=1;	
				}			
				fclose(fp);
					fclose(ft);				
				if(flag!=1)
				{
					printf("NO CONACT'S RECORD TO DELETE.");
					remove("temp.txt");
				}
				else
				{
					remove("contact.txt");
					rename("temp.txt","contact.txt");
					printf(RED);
	   				 printf("\n\n\n\t\a\a\aCONTACT DELETED!!!!");					
					printf(RESET);
				}
			}
		}	
		list();				
		printf(RED);
		printf("\n\n\tWant to delete more(y/n):");
		printf(RESET);		
		scanf("%*c %c",&c7);
	}while(c7=='Y'||c7=='y');
}
void exit_()			//function to exit application
{
	char c4;
	printf(BOLD_RED);
	printf("\n\t\aAre you sure you want exit(y/n):");
	printf(RESET);
	scanf("%*c %c",&c4);
	if(c4=='Y'||c4=='y')
	{
		printf(BOLD_RED);
		printf("\n\t\aEXITING!!!!!!!");
		printf(RESET);
		exit(0);
	}
	else
	{
		menu();
	}	
}
