#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

struct Dlist
{
   Dlist *prev;
	int item;
   Dlist *next;
};

void Insert (void);
void Delete (void);
void Display (void);
void MoveToFront (void);
void reverse(Dlist *temp);
void ispresent(Dlist *first);
void add(void);
void find_multiples();
void duplicate(void);

Dlist *first=NULL;
Dlist *last=NULL;

void main(void)
{
   int a;
	while (1)
   {
      start:
      system("cls");
   	cout<<"1.Insert\t2.Delete\t3.Display\t4.Move To Front\t5.reverse\t6.ispresent\t7.Add\t8.find multiples\t9.exit\nChoose any Option: ";
      cin>>a;
      switch(a)
      {
      	case 1: Insert();
         		  break;
         case 2: Delete();
         		  break;
         case 3: Display();
         		  break;
         case 4: MoveToFront();
                 break;
         case 5: reverse(first);
                 Sleep(1500);
                 break;
         case 6: ispresent(first);
         			break;
      	case 7: add();
         			break;
         case 8: find_multiples(); break;
         case 9:  duplicate();
         			break;
         case 10:goto end;
         		  break;
         default: cout<<"Wrong Selection!";
         		   Sleep(1500);
                  goto start;

      }
   }
   end: system("exit");
}

void Insert(void)
{
	Dlist *newnode=new Dlist;
   newnode->next=NULL;
   newnode->prev=NULL;
   cout<<endl<<"Enter no: ";
   cin>>newnode->item;

   if(last==NULL)
   {
   	newnode->prev=NULL;
      newnode->next=NULL;
      first=last=newnode;
   }

   else
   {
   	last->next=newnode;
      newnode->prev=last;
      newnode->next=NULL;
      last=newnode;
   }
}

void Delete(void)
{
   int a;
   int i=0;
	Dlist *temp=first;
   Dlist *temp2;
   if (last==NULL)
      {
   	cout<<endl<<"List Empty!"<<endl;
      Sleep(1500);
      }
   else
      {
      cout<<endl<<"Enter No to Search and Delete: ";
      cin>>a;
   	while (temp!=NULL)
      	{
            if (a==temp->item)
            	{
               	if (temp==first)
               	{
                  	temp->next->prev=NULL;
                     first=temp->next;
                  }
   					else if (temp==last)
                  {
                  	temp->prev->next=NULL;
                     last=temp->prev;
                  }
                  else
                  {
            			temp->prev->next=temp->next;
            			temp->next->prev=temp->prev;
                  }
               temp2=temp;
               temp2=temp2->next;
            	delete temp;
               temp=temp2;
               i=1;
               }
            else
         	temp=temp->next;
         }
     if (i)
     	cout<<endl<<"Successfully Deleted!"<<endl;
     else
     	cout<<endl<<"No Data Match!"<<endl;
     Sleep(1500);
     }
}

void Display()
{
	Dlist *temp=first;
   while (temp!=NULL)
   {
   	cout<<endl<<temp->item;
      temp=temp->next;
   }
   getch();
}

void MoveToFront(void)
{
   int a;
   int i=0;
	Dlist *temp=first;
   Dlist *temp2;
   if (last==NULL)
      {
   	cout<<endl<<"List Empty!"<<endl;
      Sleep(1500);
      }
   else
      {
      cout<<endl<<"Enter No to Search and Move: ";
      cin>>a;
   	while (temp!=NULL)
      	{
            if (a==temp->item)
            	{
               	if (temp==first)
               	{
                  	temp->next->prev=NULL;
                     first=temp->next;
                  }
   					else if (temp==last)
                  {
                  	temp->prev->next=NULL;
                     last=temp->prev;
                  }
                  else
                  {
            			temp->prev->next=temp->next;
            			temp->next->prev=temp->prev;
                  }
               temp->prev=NULL;
               temp->next=first;
               first->prev=temp;
               first=temp;
               i=1;
               temp=temp->next;
               }
            else
         	temp=temp->next;
         }
     if (i)
     	cout<<endl<<"Successfully Moved to Front!"<<endl;
     else
     	cout<<endl<<"No Data Match!"<<endl;
     Sleep(1500);
     }
}

void reverse(Dlist *temp) {
   if(temp->next!=NULL){
   		reverse(temp->next);
      }
      printf("%d\n",temp->item);
      Sleep(1500);
}

void ispresent(Dlist *temp) {
	int s;
   int FOUND=0;
	printf("Enter the the data u want to search:\n");
   scanf("%d",&s);
while(temp!=NULL && FOUND==0)
	{
   	if(s==temp->item)
   		{
      	FOUND=1;
      	}
   	else
   		temp=temp->next;
   }
	if (FOUND==1)
   	printf("PRESENT\n");
   	Sleep(1500);

   if (FOUND==0)
   	printf("NOT FOUND\n");
   	Sleep(1500);
}

void add (void) {
   Dlist *temp = first;
	if(temp!=NULL)
   	{
      	temp->next->next->item=temp->item + temp->next->item;
         Display();
         Sleep(1500);
      }
      temp=temp->next;
}
void find_multiples() {
	int x;
   Dlist *temp=first;
   cout<<"Enter the number and its multiples will be displayed:";
   cin>>x;
   while (temp!=NULL)
   {
		if(temp->item % x ==0)
      {
      	cout<<temp->item;
      }
      else
      {
      	cout<<"Multiples not found";
      }
   temp=temp->next;
   }
  Sleep(1500);
}
void duplicate() {
   int i,no,degree;
	printf("Enter the number you want to duplicate\n");
   scanf("%d",&no);
   printf("degree of duplication:\n");
   scanf("%d", &degree);
   for(i=0;i<degree;i++)
   {
   	printf("%d",no);
   }
   Sleep(1500);
}
