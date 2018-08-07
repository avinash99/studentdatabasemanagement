/*after returning the medicine mark * on the old bill*/

/*****************************************************************************
 * Copyright (C) AVINASH M. JADHAV javinash31@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
struct student {
	char firstname[64], lastname[64], address[100] , email[32];
	long int mo_no, mis;
	int   age ; 
	char grade ;
	char DOB[20];
	}input, data[1000];
struct acadmic
	{
	long int mis;
	int sub1;
	int sub2;
	int sub3;
	int sub4;
	int sub5;
	int sgpa;
	} input1,data1[1000];
int a,count1;
float sgpa[1000];
int count = 0;
void add() {	
	printf("MIS enter:");
	scanf(" %ld", &input.mis);
	printf("please enter the full name\n");
	printf("first Name: ");
	scanf (" %s", input.firstname);
	printf("last Name: ");
	scanf (" %s", input.lastname);
	printf("address :");
	scanf("%s", input.address);
	printf("email:");
	scanf(" %s", input.email);
	printf("age : ");
	scanf (" %d", &input.age);
	printf("mo_no : ");
	scanf (" %ld", &input.mo_no);
	printf("enter the DOB in dd-mm-yy :");
	scanf("%s", input.DOB);

}

void addmarks(){
	int i;
	printf("\t\t you are in first year\n");
	printf("\t\t MIS enter");
	scanf("%ld", &input1.mis);
	printf("please enter the marks of Sub1 out of 100:");
	scanf("%d", &input1.sub1);
	printf("please enter the marks of Sub2 out of 100:");
	scanf("%d", &input1.sub2);
	printf("please enter the marks of Sub3 out of 100:");
	scanf("%d", &input1.sub3);
	printf("please enter the marks of Sub4 out of 100:");
	scanf("%d", &input1.sub4);
	printf("please enter the marks of Sub5 out of 100:");
	scanf("%d", &input1.sub5);
}



void read(){
	g();
	int i = 0;
	printf("MISno.	 firstName   lastname    Address    Email    Age    mobile no. Dateofbirth \n");
	FILE *fp;
	fp = fopen("student.txt", "a+");
	while(fscanf(fp, "%ld  %s  %s  %s  %s  %d  %ld  %s \n", &data[i].mis, data[i].firstname, data[i].lastname, data[i].address, data[i].email, &data[i].age, &data[i].mo_no, data[i].DOB) != EOF) {	
		printf("%10ld  %8s  %8s  %8s  %8s  %4d  %10ld  %s\n", data[i].mis,data[i].firstname,data[i].lastname,
									data[i].address, data[i].email, data[i].age,data[i].mo_no, data[i].DOB);
		i++;
	}
}
void read1(){    
	float p; 
	int i;
	SGPA();
	printf("MISNO.		  SUB1	    SUB2     SUB3     SUB4     SUB5	SGPA\n");
	for(i=0;i<count1;i++){
		printf("%10ld  %8d  %8d  %8d  %8d  %8d  %f\n", data1[i].mis, data1[i].sub1,data1[i].sub2, data1[i].sub3, data1[i].sub4, data1[i].sub5, sgpa[i]);
	}
}


int g1()
   {
	int i=0;
	FILE *fp;
	if(a == 1 )
		fp = fopen ("firstyear.txt","a+");
	else if(a == 2)
		fp = fopen("secondyear.txt","a+");

	else if(a == 3)
		fp = fopen ("thirdyear.txt","a+");
	else if(a == 4)
		fp = fopen("fouryear.txt","a+");


	while(fscanf(fp, "%ld  %d  %d  %d  %d  %d\n", &data1[i].mis, &data1[i].sub1,&data1[i].sub2, &data1[i].sub3, 								&data1[i].sub4, &data1[i].sub5) != EOF) {
		i++;
	}
	count1 = i;
}


int g() {
	int i=0;
	FILE *fp;
	fp = fopen("student.txt", "a+");
	while(fscanf(fp, "%ld  %s  %s  %s  %s  %d  %ld  %s \n",&data[i].mis, data[i].firstname,data[i].lastname, data[i].address, data[i].email, &data[i].age,&data[i].mo_no, data[i].DOB)!= EOF) {
		i++;
	}
	count = i;
	return count;
}
int f(){
	FILE *fp;
	fp = fopen ("student.txt","a+");
	if (fp == NULL){
	fprintf(stderr, "\nError opening student.txt\n\n");
	exit (1);
	}
	fprintf(fp,"%ld	%s	%s	%s	%s	%d	%ld	%s \n ",input.mis,input.firstname,input.lastname,input.address,input.email,input.age,input.mo_no,input.DOB);

	fclose(fp);
}


void f1()
	{
 	FILE *fp;
	if(a == 1 )
		fp = fopen ("firstyear.txt","a+");
	else if(a == 2)
		fp = fopen("secondyear.txt","a+");

	else if(a == 3)
		fp = fopen ("thirdyear.txt","a+");
	else
		fp = fopen("fouryear.txt","a+");
		
   if (fp == NULL){
      fprintf(stderr, "\nError opening student.txt\n\n");
      exit (1);
   }
      fprintf(fp,"%ld	%d	%d	%d	%d	%d	\n",input1.mis,input1.sub1,input1.sub2,input1.sub3,input1.sub4,input1.sub5);
	
	fclose(fp);
}
void modifymark()
{
	int choice;
	char a[20];
	char y;
	long int q;
	int p,i,r,z=1;
	g1();
	printf("enter the mis of student :");				
	while(r != 1) {	
		scanf("%ld", &q);
		for(i = 0; i < count1; i++) {
			if(data1[i].mis == q) {
				r = 1;
				break;
			}
		}
		if( r != 1){	
			printf("please enter the correct mis:");
		}
	}
	printf("\t\twhat do you want to change\n");
	printf("\t\t1.MIS Number\n\t\t2.sub1\n\t\t3.sub2\n\t\t4.sub3\n\t\t5.sub4\n\t\t6.sub5\n ");

	
		scanf("%d", &choice);
		switch(choice){	
			case 1:
				printf("current mis is : %ld\n", data1[i].mis);
				printf("enter the new mis:");
				scanf("%ld", &q);
				data1[i].mis = q;
	
			case 2: 
				printf("the current marks in sub1 out of 100: %d\n", data1[i].sub1);
				printf("enter the new marks of sub1 out of 100: ");
				scanf("%d", &p);
				data1[i].sub1 = p ;
				break;
			case 3: 
				printf("the current marks in sub2 out of 100: %d\n", data1[i].sub2);
				printf("enter the new marks of sub2 out of 100: ");
				scanf("%d", &p);
				data1[i].sub2 = p ;
				break;
			case 4: 
				printf("the current marks in sub3 out of 100: %d\n", data1[i].sub3);
				printf("enter the new marks of sub3 out of 100: ");
				scanf("%d", &p);
				data1[i].sub3 = p ;
				break;
			case 5: 
				printf("the current marks in sub4 out of 100: %d\n", data1[i].sub4);
				printf("enter the new marks of sub4 out of 100: ");
				scanf("%d", &p);
				data1[i].sub4 = p ;
				break;

			case 6: 
				printf("the current marks in sub5 out of 100: %d\n", data1[i].sub5);
				printf("enter the new marks of sub5 out of 100: ");
				scanf("%d", &p);
				data1[i].sub5 = p ;
				break;
			case 7:
				break; 
			
			}
		
	
	fileprint();
}

// when file modification is done then reprint all data in the file 
int fileprint()
	{
	int i;
 	FILE *fp;
	if(a == 1 )
		fp = fopen ("firstyear.txt","w");
	else if(a == 2)
		fp = fopen("secondyear.txt","w");

	else if(a == 3)
		fp = fopen ("thirdyear.txt","w");
	else
		fp = fopen("fouryear.txt","w");
	if (fp == NULL){
      fprintf(stderr, "\nError opening student.txt\n\n");
      exit (1);
     }
	for(i=0;i<count1;i++) {
      fprintf(fp,"%ld	%d	%d	%d	%d	%d\n",data1[i].mis,data1[i].sub1,data1[i].sub2,data1[i].sub3, data1[i].sub4, data1[i].sub5);
	}
	fclose(fp);
		
}

/* modifying the function in to array of structure */
void modify()
{
	int choice,r,z = 1;
	char a[20];
	char y;
	g();
	long int i=0, t, p, q;
	printf("enter the mis of student :");
	while(r != 1) {	
		scanf("%ld", &q);
		for(i = 0; i < count; i++) {
			if(data[i].mis == q){ 		// comparing the mis with data
				r = 1;
				break;
			}
		}
		if( r != 1)
			printf("please enter the correct mis:");
	}	
				
	printf("\t\twhat do you want to change\n");
	printf("\t\t1.MIS Number\n");
	printf("\t\t2.first Name\n");
	printf("\t\t3.last name\n");
	printf("\t\t4.address\n");
	printf("\t\t5.email\n");
	printf("\t\t6.age\n");
	printf("\t\t7.mobile number\n");
	printf("\t\t8.date of birth\n");
	scanf("%d", &choice);
	switch(choice){	
		case 1:
			printf("current mis is : %ld\n", data[i].mis);
			printf("enter the new mis:");
			scanf("%ld",&p);
			data[i].mis = p;
			break;
	
		case 2: 
			printf("the current first name is : %s\n", data[i].firstname);
			printf("enter the new first name : ");
			scanf("%s",a);
			strcpy(data[i].firstname,a) ;
			break;
		case 3: 
			printf("the current last name is : %s\n", data[i].lastname);
			printf("enter the new  last name : ");
			scanf("%s",a);
			strcpy(data[i].lastname,a) ;
			break;
	
		case 4:		
			printf("the current address is : %s\n", data[i].address);
			printf("enter the new address : ");
			scanf("%s", a);
			strcpy(data[i].address, a);
			break;
		case 5:
			printf("the current email address : %s\n", data[i].email);
			printf("enter the new email : ");
			scanf("%s", a);
			strcpy(data[i].email, a);
			break;
		case 6:
			printf("the current age is : %d\n", data[i].age);
			printf("enter the new age : ");
			scanf("%ld", &p);
			data[i].age = p;
			break;
		case 7:
			printf("the current mobile number is : %ld\n", data[i].mo_no);
			printf("enter the new mo_no : ");
			scanf("%ld", &p);
			data[i].mo_no = p;
			break;
		case 8:
			printf("the current Date of Birth is : %s\n", data[i].DOB);
			printf("enter the new Date of Birth : ");
			scanf("%s", a);
			strcpy(data[i].DOB , a) ;
			break;
		case 9:
			break;
	
	}
	FILE *fp;
	fp = fopen ("student.txt","w");
	if (fp == NULL){
		fprintf(stderr, "\nError opening student.txt\n\n");
		exit (1);
	}
	for(i=0;i<count;i++){
		fprintf(fp,"%ld	%s	%s	%s	%s	%d	%ld	%s\n", data[i].mis, data[i].firstname, data[i].lastname, data[i].address, data[i].email, data[i].age, data[i].mo_no, data[i].DOB);
	}
	fclose(fp);
}

 void delete()
{	
	char a[20];
	long int r;
	int p;
	int i,t;
	printf("enter the mis of the student :");
	scanf("%ld", &r);
	printf("please reconfirm that you want to delete information of  %ld ",r);
	printf("press 1 for yes :" );
	scanf("%d", &p);
	if(p == 1){
		g();
		for(i=0; i < count; i++){
			if(data[i].mis == r){
				t = i;
				break;
			}
		}
		for (i = t; i < count; i++) 
			data[i] = data[i+1];
	}
	else
		return;

	FILE *fp;
	fp = fopen("student.txt","w");
	for(i = 0;i < count-1; i++){
		fprintf(fp,"%ld  %s  %s  %s  %s  %d  %ld  %s\n", data[i].mis, data[i].firstname, data[i].lastname, data[i].address, data[i].email, data[i].age, data[i].mo_no, data[i].DOB);
	}
	fclose(fp);
}
void record () {

	int p,i,j=0,n,k;		
	float cgpa = 0 ;
	printf("\t\t\tstudents information\n");	
	i = search();
	n = selectyear();
	a = 0 ;
	for(a = 1 ; a < n+1; a++) {
		if(a == 1)
			printf("Your Marks in First Year\n");
		if(a == 2)
			printf("Your Marks in Second Year\n");
		if(a == 3)
			printf("Your Marks in third Year\n");
		if(a == 4)
			printf("Your Marks in Fourth Year\n");
		g1();
		SGPA();
		if(data[i].mis = data1[j].mis)
			p = j;
		else
			j++;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("\t\tstudents acadamic information \n ");
      		printf("\t\t\tmarks of sub1 = %d \n", data1[p].sub1);
		printf("\t\t\tmarks of sub2 = %d \n", data1[p].sub2);
		printf("\t\t\tmarks of sub3 = %d \n", data1[p].sub3);
		printf("\t\t\tmarks of sub4 = %d \n", data1[p].sub4);
		printf("\t\t\tmarks of sub5 = %d \n", data1[p].sub5);
		printf("\t\t\t your sgpa is = %f\n", sgpa[p]);
		cgpa = cgpa + sgpa[p];
		if(a != 1)
			cgpa = cgpa/2;
		printf("\t\t\tYour CGPA IS = %f\n",cgpa);
		printf("-------------------------------------------------------------------------------------------\n");
	} 
}

		
			
void delete1(){
	long int y;
	char a[20];
	int p,x;
	int i,r;
	g();
	printf("enter the MIS of the student :");
	while(r != 1) {
		scanf("%ld",&y);	
		for(i = 0; i < count1; i++) {
			if(data1[i].mis== y){
				x = i;
				r = 1;
				break;
			}
		}
		if( r != 1)	
			printf("please enter the correct mis:");
			
	}		
	for (i = x; i < count1-1; i++)
		data1[i] = data1[i+1];
				
	count1 = count1-1;
	fileprint();
}
	

int search(){
	long int q ,r = 0; 
	char a[20];
	printf("enter the mis of the student :");
 	int i;
	g();
	while(r != 1) {	
		scanf("%ld",&q);
		for(i = 0; i < count; i++) {
			if(data[i].mis == q) {
				r = 1;
				break;
			}
		}
		if( r != 1)	
			printf("please enter the correct mis:");
	}
	printf("\t\t students personal information\n");
	printf("-------------------------------------------------------------------------------------------\n");
	printf("\t\t\tMIS no:- %ld\n", data[i].mis);
      	printf("\t\t\tName = %s %s \n", data[i].firstname, data[i].lastname);
	printf("\t\t\tAddress = %s\n", data[i].address);
	printf("\t\t\tEmail = %s\n", data[i].email);
	printf("\t\t\tAge = %d\n", data[i].age);
	printf("\t\t\tmo_no = %ld\n", data[i].mo_no);
	printf("\t\t\tDate of Birth = %s\n", data[i].DOB);	
	r = i;
	printf("-------------------------------------------------------------------------------------------\n");
	return i;
}

void search1(){
	long int q, r; 
	printf("enter the mis of the student :");
 	int i;
	g1();
	while(r!=1) {	
		scanf("%ld",&q);
		for(i = 0; i < count1; i++) {
			if(data1[i].mis== q) {
				r=1;
				break;
			}
		}
		if( r!=1)	
				printf("please enter the correct mis:\n");
	}
	printf("-------------------------------------------------------------------------------------------\n");
	printf("\t\t\tMIS no:- %ld\n",data1[i].mis);
	printf("\t\t\tmarks of sub1 out of 100 = %d \n",data1[i].sub1);
	printf("\t\t\tmarks of sub2 out of 100 = %d \n",data1[i].sub2);
	printf("\t\t\tmarks of sub3 out of 100 = %d \n",data1[i].sub3);
	printf("\t\t\tmarks of sub4 out of 100 = %d \n",data1[i].sub4);
	printf("\t\t\tmarks of sub5 out of 100 = %d \n",data1[i].sub5);
	printf("\t\t\tsgpa is out of 10 = %f\n",sgpa[i]);
	printf("-------------------------------------------------------------------------------------------\n");
}
		
void merge(struct student p[], int l, int m, int h){
	struct student b[1000];
	int i = l, k = 0, t = 0;
	int j = m + 1;
	while(i <= m && j <= h) {
		if(p[i].mis < p[j].mis)
			b[k++] = p[i++];
		else
			b[k++] = p[j++];
	}
	if(i > m)
		while(j <=h) 
			b[k++] = p[j++];
	else
		while(i <=m) 
			b[k++] = p[i++];
			
	while(t < k) {	
		p[l + t] = b[t];
		t++;
	}
	
}

void mergesort(struct student p[], int l, int h) {
	int m;
	if(l == h)
		return;
	m = (l + h)/2;
	mergesort(p, l, m);
	mergesort(p, m + 1, h);
	merge(p, l, m, h );	
}

void sort(struct student p[], int n) {
	int i;	
	mergesort(p, 0, n-1);
	for(i = 0; i < count; i++){
		printf("%ld  %s  %s  %s  %s  %d  %ld  %s\n", p[i].mis,p[i].firstname,p[i].lastname,p[i].address,p[i].email,p[i].age,p[i].mo_no,p[i].DOB);
	}
}
void merge1(struct acadmic p[], int l, int m, int h) {
	struct acadmic b[1000];
	int i = l, k = 0, t = 0;
	int j = m + 1;
	while(i <= m && j <= h) {
		if(p[i].mis < p[j].mis)
			b[k++] = p[i++];
		else
			b[k++] = p[j++];
	}
	if(i > m)
		while(j <=h) 
			b[k++] = p[j++];
	else
		while(i <=m) 
			b[k++] = p[i++];
			
	while(t < k) {	
		p[l + t] = b[t];
		t++;
		}
	
}

void mergesort1(struct acadmic p[], int l, int h) {
	int m;
	if(l == h)
		return;
	m = (l + h)/2;
	mergesort1(p, l, m);
	mergesort1(p, m + 1, h);
	merge1(p, l, m, h );	
}

void sort1(struct acadmic p[], int n) {
	int i;	
	mergesort1(p, 0, n-1);
	printf("MISNO. SUB1  Sub2  SUB3  SUB4  SUB5\n");
	for(i = 0; i < count1; i++){
		printf("%ld  %d  %d  %d  %d  %d\n", p[i].mis, p[i].sub1, p[i].sub2, p[i].sub3, p[i].sub4, p[i].sub5);
	}
}		
void login(){
	int i,q=1;
	char p[16];
	
	printf("\t\t WELCOME IN STUDENT DATABASE!!\n");
	printf("\t\t your are students or admistration \n");
	printf("\t\t please presss 1 for admin and press 2 for student and please press 3 for new registration\n");
	scanf("%d",&i);
	while(i == 1){
		printf("please enter your password:");
		scanf("%s",p);
		if(strcmp(p,"123456")==0){
			printf("\n\t\tWELCOME ADMIN!!\n");
			i=0;
		}
		else{
			printf("\n\t\tpassword incorrect!");
			printf("\n\t\tplease enter the corret password:\n");
		        i=1;
		}
	}		
	while(i==2){
		printf("\t\twelcome in collage database!!\n");
		printf("\n\t\tplease enter your password:");
		scanf("%s",p);
		if(strcmp(p,"student") == 0){    
			while(q ==1 ){
				printf ("for read all data press 1 and 2 for search record:\n");
				scanf("%d",&q);
				if(q == 1){	
					g();
					read();
				}	
				if(q == 2){
					g();
					g1();
					record();
				}
					printf("do you want to continue press 1 \n ");
					scanf("%d",&q);
			}
			exit(0);
		}
		else{
			printf("\t\tpassword incorrect!\n\n");
			printf("\t\tplease enter the corret password!\n");	
		}	
	}
}
int selectyear(){	
		printf("\t\tSELECT YOUR YEAR\n");
		printf("\t\t1.FIRST YEAR\n");
		printf("\t\t2.SECOND YEAR\n");
		printf("\t\t3.THIRD YEAR\n");
		printf("\t\t4.FOURTH YEAR\n");
		printf("\t\t5.exit\n");
		scanf("%d",&a);
		return a;
}	
int printmenu(){
	int choice;	
	printf("\n\t\t Choose from the following options\n\n");
	printf("\t\t\t 1.ADD PERSONAL INFORMATION  \n\t\t\t 2.LIST PERSONAL INFORMATION \n\t\t\t 3.MODIFY PERSONAL INFORMATION \n\t\t\t 4.SORT PERSONAL INFORMATION \n\t\t\t 5.DELETE PERSONAL INFORMATION \n\t\t\t 6.SEARCH PERSONAL INFORMATION \n\t\t\t7.exit\n\n\t\t\t Your Choice: ");
	scanf("%d",&choice);
	return choice;
}
int printmenu1(){
	int choice;	
	printf("\n\t\t Choose from the following options\n\n");
	printf("\t\t\t 1.ADD ACADMIC INFORMATION  \n\t\t\t 2.LIST ACADMIC INFORMATION \n\t\t\t 3.MODIFY ACADMIC INFORMATION \n\t\t\t 4.SORT ACADMIC INFORMATION \n\t\t\t 5.DELETE ACADMIC INFORMATION \n\t\t\t 6.SEARCH ACADMIC INFORMATION \n\t\t\t7.exit\n\n\t\t\t Your Choice: ");
	scanf("%d",&choice);
	return choice;
}
int SGPA(){
	int i,k=0,m;
	g1();
	int j[5],l[5];
	float p,n;	
	for(i=0;i<count1;i++) {	
		m=0;
		j[0] = data1[i].sub1;
		j[1] = data1[i].sub2;
		j[2] = data1[i].sub3;
		j[3] = data1[i].sub4;
		j[4] = data1[i].sub5;
		for(k=0;k<5;k++){		
			if (j[k]>=91 && j[k]<= 100 )
					l[m] = 10;
			else if (j[k]>=81 && j[k]<= 90)
					l[m] = 9;
			else if (j[k]>=71 && j[k]<= 80)
					l[m] = 8;
			else if (j[k]>=61 && j[k]<= 70)
					l[m] = 7;
			else if (j[k]>=51 && j[k]<= 60)
					l[m] = 6;
			else if (j[k]>=41 && j[k]<= 50)
					l[m] = 5;
			else if (j[k]>=31 && j[k]<= 40)
					l[m] = 4;
			else if (j[k]>=21 && j[k]<= 30)
					l[m] = 3;
			else if (j[k]>=11 && j[k]<= 20)
					l[m] = 2;
			else if (j[k]>=1 && j[k]<= 10)		
					l[m] = 1;
				m++;
		}
	/* here we conside credits for sub1 = 3 , for sub2 = 3 , for sub3 = 4 ,for sub4 = 4, for sub5 = 5 */ 
		p =  l[0] * 3 + l[1] * 3 + l[2] * 4 + l[3] * 4 + l[4] * 3  ;
		sgpa[i] = p/17;	
	}		
}
void main(){
	login();
	count = 0;
	g();
	g1();
	int choice;
	int ch=1 ,c;
	int n = count , x,i;	
	printf("if you want to see whole record of any student please press 1  = ");
	scanf("%d",&i);
	if(i==1)
		record();
	while (ch ==1){
		printf("\nplease for accessing student information press 1 and accessing students mark press anything number:");
		scanf("%d",&x);	
		if(x == 1){
			choice = printmenu();
			switch(choice){
				case 1:
				 	 add();
					 f();
					 break;

				case 2:
					read();
				   	break;
				case 3:

					modify();		
					  break;
				case 4 :
					g(); 
					sort(data,n);
					  break;
				case 5 :
					delete();
				  	break;
				case 6 :
					search();
					break;
				case 7 : 
					 exit(0);
				default:
					printf("inavalid input\n");
					break ;
			}
		}
		else {
			selectyear();
			choice = printmenu1();
			switch(choice){
				case 1:
					addmarks();
					f1();
					break;
				case 2:
					read1();
					break;
				case 3:
					modifymark();
					break;
				case 4:
					g1();
					sort1(data1,count1);
					break;
				case 5:
					delete1();
					break;
				case 6:
					search1();
					break;
				case 7:
					exit(0);
				default:
					printf("inavalid input\n");
					break ;
			}
		}	
	printf("do you want to continue press 1 :");
	scanf("%d",&ch);
	}
}

