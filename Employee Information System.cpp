#include<iostream>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<conio.h>
using namespace std;
struct emp
	{
	int ecode;
	char ename[30];
	char egrade;
	char address[30];
	char dept[30];
	char phoneno[30];
	float basic,da,ta,PF;
	char DOB[30];
	float salary;
	};
emp e1[4];
void CREATE(int n)
	{
	int a;
	static int x=0;
	for(a=0;a<n;a++)
	{
		e1[a].ecode=1000;
		cout<<"\nENTER DETAILS OF EMPLOYEE : = "<<(a+1)<<endl;
		cout<<"\nENTER NAME: ";
		gets(e1[a].ename);
		cout<<"\nENTER ADDRESS: ";
		gets(e1[a].address);
		cout<<"\nENTER DEPARTMENT: ";
		gets(e1[a].dept);
		cout<<"\nENTER PHONE NO.: ";
		cin>>e1[a].phoneno;
		cout<<"\nENTER DATE OF BIRTH: ";
		gets(e1[a].DOB);
		cout<<"\nENTER GRADE:= ";
		cin>>e1[a].egrade;
		e1[a].ecode=e1[a].ecode+x;
		x++;
		cout<<"\nECODE ASSIGNED TO EMPLOYEE "<<(a+1)<<" IS : = "<<e1[a].ecode;
		cout<<endl;
	}
}
void DISPLAY(int n)
	{
	int a;
	for(a=0;a<n;a++)
	{
		cout<<"\n\nRECORD OF EMPLOYEE"<<(a+1);
		cout<<"\nEcode		:	"<<e1[a].ecode;
		cout<<"\t\t\tName	:	"<<e1[a].ename;
		cout<<"\nAddress	:	"<<e1[a].address;
		cout<<"\t\t\tDept :  "<<e1[a].dept;
		cout<<"\nPhone No	:	"<<e1[a].phoneno;
		cout<<"\t\t\tDOB	:	"<<e1[a].DOB;
		cout<<"\nGrade		:	"<<e1[a].egrade;
		cout<<"\t\t\tSalary:	"<<e1[a].salary;
		cout<<endl;
	}
	}
void Cal_Sal(int n)
{
	int x,i;
	cout<<"\n\n\t\tWELCOME TO ACCOUNTS DEPARTMENT ....LETS CALCULATE SALARIES..";
	cout<<endl;
	for(i=0;i<n;i++)
	{
			cout<<"\n\n\tENTER THE BASIC SALARY OF EMPLOYEE "<<(i+1)<<" := ";
			cin>>e1[i].basic;
			if(e1[i].basic>=20000)
			{
				e1[i].da=0.20*e1[i].basic;
				e1[i].ta=0.15*e1[i].basic;
			}
			else
			{
				e1[i].da=0.15*e1[i].basic;
				e1[i].ta=0.10*e1[i].basic;
			}
			e1[i].PF=900;
			e1[i].salary=(e1[i].basic+e1[i].da+e1[i].ta)-e1[i].PF;
			cout<<"\nBASIC : = "<<e1[i].basic;
			cout<<"\nDA : = "<<e1[i].da;
			cout<<"\nTA : = "<<e1[i].ta;
         cout<<"\nPF : = "<<e1[i].PF;
			cout<<"\nSALARY : = "<<e1[i].salary;
	  }
}
void SEARCH(int n)
	{
	int b,found=0;
	cout<<"Enter code of employye you want to search:";
	cin>>b;
	for(int a=0;a<n;a++)
	{
	if(e1[a].ecode==b)
	{
		cout<<"\nEcode:"<<e1[a].ecode;
		cout<<"\nName:"<<e1[a].ename;
		cout<<"\nGrade:"<<e1[a].egrade;
		cout<<"\nAddress:"<<e1[a].address;
		cout<<"\nDepartment:"<<e1[a].dept;
		cout<<"\nPhone No:"<<e1[a].phoneno;
		cout<<"\nDOB:"<<e1[a].DOB;
		cout<<"\nEnter salary:"<<e1[a].salary;
		found=1;
	}
	}
	if(found==0)
	cout<<"\n\t\tRetry, record does not exist!!";
	else
	cout<<"\n\n\t\t\tCongrats!! Record found";
	}
void MODIFY(int n)
	{
	int c;
	char en[30];
	char add[30];
	char dep[30];
	char pno[30];
	char dob[30];
	char ch;
	cout<<"\nEnter code of employee whose record you want to change: = ";
	cin>>c;
	for(int a=0;a<n;a++)
	{
	if(e1[a].ecode==c)
	{
		cout<<"\nEnter new name. Enter(.) to retain old one.";
		gets(en);
		cout<<"\nEnter new address. Enter(.) to retain old one.";
		gets(add);
		cout<<"\nEnter new Department. Enter(.) to retain old one.";
		gets(dep);
		cout<<"\nEnter new Phone No. Enter(.) to retain old one.";
		cin>>pno;
		cout<<"\nMAKE CORRECTION IN DATE OF BIRTH.Enter(.) to retain old one.";
		gets(dob);
		if(strcmp(en,".")!=0)
		strcpy(e1[a].ename,en);
		if(strcmp(add,".")!=0)
		strcpy(e1[a].address,add);
		if(strcmp(dep,".")!=0)
		strcpy(e1[a].dept,dep);
		if(strcmp(pno,".")!=0)
		strcpy(e1[a].phoneno,pno);
		if(strcmp(dob,".")!=0)
		strcpy(e1[a].DOB,dob);
		cout<<"\n\nWant to update basic salary?(y/n): = ";
		cin>>ch;
		if(ch=='y'||ch=='Y')
		{
			Cal_Sal(n);
		}
		else
		 goto end;
	 }
  }
	end:
	cout<<"\n\nRecords after modification:\n\n";
	DISPLAY(n);
}
int main()
	{
	int choice,n;
	char ans,ch,userid[20];
	char paswd[6];
	cout<<"\t\t\t------------------------------------------------\n";
	cout<<"\t\t\t           EMPLOYEE INFORMATION SYSTEM			 \n";
	cout<<"\t\t\t------------------------------------------------\n";
	cout<<"\n\n\tPRESS ANY KEY TO CONTINUE.....";
	getch();
	cout<<"\t\t\n\nHOW MANY RECORDS YOU WANT TO ENTER?:= ";
	cin>>n;
	cout<<endl;
	beg:
	cout<<"ENTER USER ID:= ";
	gets(userid);
	cout<<"\nENTER PASSWORD:= ";
	for(int i=0;i<6;i++)
	{
		paswd[i]=getch();
		cout<<"*";
	}
	paswd[6]='\0';
	if(strcmp(userid,"ADMIN")==0&&strcmp(paswd,"emp123")==0)
	goto MENU;
	else
	{
		cout<<"\n\n\tSORRY INVALID INFORMATION ENTERED ....TRY AGAIN\n";
		goto beg;
	}

	MENU:
	cout<<"\n1. INSERT RECORDS\n";
	cout<<"\n2. PAY SCALE\n";
	cout<<"\n3. SEARCH RECORDS\n";
	cout<<"\n4. UPDATE RECORDS\n";
	cout<<"\n5. DISPLAY RECORDS\n";
	cout<<"\n6. QUIT FROM THE PROGRAM\n";
	cout<<endl<<endl;
	menu:
	cout<<"ENTER YOUR CHOICE BY ENTERING ANY NUMBER FROM (1--6): ";
	cin>>choice;
	switch(choice)
	{
	case 1:
			 cout<<"\n************CREATING RECORDS*************\n";
			 CREATE(n);
			 break;
	case 2:
			 cout<<"\t**********SALARY STRUCTURE*************\n";
			 Cal_Sal(n);
			 break;
	case 3:
			 cout<<"\t**********SEARCH EMPLOYEE*************\n";
			 SEARCH(n);
			 break;
	case 4:
			 cout<<"\t**********UPDATE RECORD*************\n";
			 MODIFY(n);
			 break;
	case 5:
			 cout<<"\t**********DISPLAY RECORDS*************\n";
			 DISPLAY(n);
			 break;
	case 6:cout<<"\n\nDO YOU OPT TO QUIT THE PROGRAM?";
			 cin>>ans;
			 if(ans=='y'||ans=='Y')
			 exit(0);
	  else
			  goto menu;
	default:cout<<"\nSORRY INVALID CHOICE......TRY AGAIN!!!!";
	}
	cout<<"\n\n\t\tDO YOU WANT TO RUN AGAIN?:= ";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	goto MENU;
	else
	cout<<"\n\n-------THANK YOU FOR RUNNING THIS PROJECT-------\n";
	return 0;
	}

   






























