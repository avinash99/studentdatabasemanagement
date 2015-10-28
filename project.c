#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//#include"project.h"
struct student {
   char  firstname[64] , lastname[64], address[128] , email[32];
 long  int   mo_no,mis;
   int   age ; 
   char grade ;
}input, data[1000];

int t=1, count = 0;

void add()
{	printf("please enter your mis no:");
	scanf("%ld",&input.mis);
	printf("please enter the full name\n");
      printf("first Name: ");
      scanf ("%s", input.firstname);
	printf("last Name: ");
	 scanf ("%s", input.lastname);
	printf("address :");
	scanf("%s",input.address);

	printf("email:");
	scanf("%s",input.email);
	printf("age : ");
      scanf ("%d", &input.age);
	
      printf("mo_no : ");
      scanf ("%ld", &input.mo_no);
      printf("grades : ");
      scanf (" %c", &input.grade);
	t++;
}
void login()
	{
	int i,t;
	char p[64];
	
	printf("\t\t Welcome in the student Deta Base!!");
	printf("\t\t your are students or admistration ");
	printf("\t\t presss 1 for admin and press 2 for student");
	scanf("%d",&i);
	while(i == 1)
	{
		
		printf("please enter your password:");
		scanf("%s",p);
		if(strcmp(p,"123456")==0)
		{
			printf("welcome admin!!");
		    }
		else{
			printf("password incorrect!");
			printf("please enter the corret password!");
                         i=1;
			}
		  }		
	while(i==2)
		{
		printf("welcome in collage database!!");
		printf("please enter your password!!");
		scanf("%s",p);
		if(strcmp(p,"student")== 0)
		{
			printf ("if you want to read all data press 1 and 2 for search information");
			/*scanf("%d",t);
			if(i == 1)
			{
			read();
			}
			else
			{
			search();
				}*/
			}
		else
		{
			printf("password incorrect!");
			printf("please enter the corret password!");	
			}
		}
	return 0;
	}

void read()
   {
	int i=0;
	printf("MISno.	 firstName   lastname    Address    Email    Age    mobile no.    grade  \n");
	FILE *fp;
	fp = fopen("student.txt", "a+");
	while(fscanf(fp, "%ld  %s  %s  %s  %s  %d  %ld  %c\n",&data[i].mis, data[i].firstname,data[i].lastname, data[i].address, data[i].email, &data[i].age,&data[i].mo_no, &data[i].grade) != EOF) {
		
		printf("%10ld  %8s  %8s  %8s  %8s  %4d  %10ld  %4c\n",data[i].mis,data[i].firstname,data[i].lastname,data[i].address, data[i].email, data[i].age,data[i].mo_no, data[i].grade);
		i++;
	}
}

void g() {
	int i=0;
	FILE *fp;
	fp = fopen("student.txt", "a+");
	while(fscanf(fp, "%ld  %s  %s  %s  %s  %d  %ld  %c\n",&data[i].mis, data[i].firstname,data[i].lastname, data[i].address, data[i].email, &data[i].age,&data[i].mo_no, &data[i].grade) != EOF) {
		i++;
	}
	count = i;
}


void f(){
 FILE *fp;
   fp = fopen ("student.txt","a+");
   if (fp == NULL)
     {
      fprintf(stderr, "\nError opening student.txt\n\n");
      exit (1);
     }
      fprintf(fp,"%ld	%s	%s	%s	%s	%d	%ld	%c\n",input.mis,input.firstname,input.lastname,input.address,input.email,input.age,input.mo_no,input.grade);
	
	fclose(fp);
}



void modify()
{
	char choice;
	char a[20];
	char y;
	long int i=0, t ,p,q;
	
	printf("enter the mis of student :");
	scanf("%ld",&q);		
	g();						
	for(i = 0; i < count; i++) {
		if(data[i].mis== q) {			
			t = i;
			break;
		}
	}	
				
	printf("what do you want to  change press 1-mis, 2-name, 3-address,4-email,5-age,6-mo_no,7-grades\n");
	scanf("%c",&choice);
switch(choice)
	{	
	case'1':
		printf("enter the new mis:");
		scanf("%ld",&p);
		data[i].mis = p;
		
	case '2': 
		printf("enter the new name");
		scanf("%s",a);
		strcpy(a,data[t].firstname) ;
		break;
	case '3':
		printf("enter the new address");
		scanf("%s",a);
		strcpy(a,data[t].address);
		break;
	case '4':
		printf("enter the new email");
		scanf("%s",a);
		strcpy(a,data[t].email);
		break;
	case '5':
		printf("enter the new age");
		scanf("%ld",&p);
		data[t].age = p;
		break;
	case '6':
		printf("enter the new mo_no");
		scanf("%ld",&p);
		data[t].mo_no = p;
		break;
	case '7':
		printf("enter the new grade ");
		scanf("%c",&y);
		data[t].grade = y;
		break;
	case '8':
		break; 	
	
	}

}
 void delete()
{	
	char a[20];
	long int r;
	int p;
	int i;
	printf("enter the mis of the student :");
	scanf("%ld",&r);
	printf("please reconfirm that you want to delete information of  %ld ",r);
	printf("press 1 for yes :" );
	scanf("%d",&p);
	if(p == 1){
	g();
	for(i=0;i<count;i++){
		if(data[i].mis==r){
			t=i;
			break;
		}
		}
	for (i=t;i<count;i++) 
		{
		data[i] = data[i+1];
		}
		}
	 else{
		return;
		}
	FILE *fp;
	fp= fopen("student.txt","w");
	for(i=0;i<count-1;i++)
	{
	fprintf(fp,"%ld  %s  %s  %s  %s  %d  %ld  %c",data[i].mis,data[i].firstname,data[i].lastname,data[i].address,data[i].email,data[i].age,data[i].mo_no,data[i].grade);
	}
	fclose(fp);
	}



void search()
	{
	char a[20];
	printf("enter the name of the student");
	scanf("%s",a);	
 	int i;
	g();
	for(i = 0; i < count; i++) {
			
			if(strcmp(data[i].firstname, a) == 0) {
				t = i;
				break;
			}
		}
		printf("MIS no:- %ld\n",data[i].mis);
      		printf("Name = %s %s \n",data[i].firstname,data[i].lastname);
		printf("Address = %s\n",data[i].address);
		printf("Email = %s\n",data[i].email);
		printf("Age = %d\n",data[i].age);
		printf("mo_no = %ld\n",data[i].mo_no);
		printf("grade = %c\n",data[i].grade);	
		}


void main()
{
login();
char choice;
char ch=1;
g();
int t=1, count = 0;
while(ch){

	printf("\n\t\t Choose from the following options\n\n");
	printf("\t\t\t 1.Add Records \n");
	printf("\t\t\t 2.List Records \n");
	printf("\t\t\t 3.Modify Records \n");
	printf("\t\t\t 4.sort Records \n");
	printf("\t\t\t 5.Delete Records \n");
	printf("\t\t\t 6.search Records \n");
	printf("\t\t\t7.exit");
	printf("\n\n\t\t\t Your Choice: ");
	scanf("%c",&choice);

switch(choice)
	{
	
	case '1':
 	 	 add();
		 f();
  		 break;
	
	case '2':

   		read();
	   	break;
	case '3':
	
 		modify();		
		  break;
	case '4' :
		//sort() ;
		  break;
	case '5' :
		delete();
	  	break;
	case '6' :
		search();
		break;
	case '7' : 

	     exit(0);

		}
scanf("%c",&ch);
}

}


