#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct library
{
    char bookname[50];
    char authorname[50];
    char bookid[50];
    long int year;
    char borrowername[20];
    char borrowedbook[50];
    char borroweddate[20];
    char duedate[20];
};
int main()
{
   printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
   printf("\n\t\t\t\t\t\t\t\t\t\t\t  ****LIBRARY MANAGEMENT SYSTEM****");
   printf("\n\t\t\t\t\t\t\t\t\t\t\t\tNAME:S.HARIHARAN\n\t\t\t\t\t\t\t\t\t\t\t\tREG.NO:RA2111047010087\n\t\t\t\t\t\t\t\t\t\t\t\tDEPARTMENT:AI\n\t\t\t\t\t\t\t\t\t\t\t\tSECTION:B");
   struct library l[100];
   int option,n,m,count,status,serial,availability,j=0;
   char booksearch[50],borrow[50],bookborrow[50],borrowedbook[50];
   while(option!=6)
   {
   printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
   printf("\n\t\t\t\t\t\t\t\t\t\t\t  WELCOME TO E-LIBRARY MANAGEMENT");
   printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
   printf("\n\t\t\t\t\t\t\t\t\t\t\t    OPTION                   VALUE\n\t\t\t\t\t\t\t\t\t\t\t       1                   ADD NEW BOOKS\n\t\t\t\t\t\t\t\t\t\t\t       2                   DISPLAY ALL BOOKS\n\t\t\t\t\t\t\t\t\t\t\t       3                   BOOK SEARCH\n\t\t\t\t\t\t\t\t\t\t\t       4                   BORROW BOOKS\n\t\t\t\t\t\t\t\t\t\t\t       5                   BORROWERS LIST\n\t\t\t\t\t\t\t\t\t\t\t       6                   EXIT");
   printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
   printf("\nENTER YOUR SELECTION:");
   scanf("%d",&option);
   switch(option)
   {
       case 1:
            printf("-------------------------------------------------------------------------------------------------*ADD NEW BOOKS*---------------------------------------------------------------------------------------------------\n");
            printf("ENTER NUMBER OF BOOKS TO BE ADDED:");
            scanf("%d",&n);
            n=n+serial;
            for(j;j<n;j++)
            {
            printf("\n----------------------------------------------------------------------------------------------------BOOK %d---------------------------------------------------------------------------------------------------------",j);
            printf("BOOK NAME                        :");
            scanf("%s",l[j].bookname);
            printf("AUTHOR NAME                      :");
            scanf("%s",l[j].authorname);
            printf("BOOK ID                          :");
            scanf("%s",l[j].bookid);
            printf("YEAR PUBLISHED                   :");
            scanf("%ld",&l[j].year);
            count++;
            }
            serial=serial+n;
            break;
        case 2:
            printf("----------------------------------------------------------------------------------------------*DISPLAYING BOOKS*---------------------------------------------------------------------------------------------------\n");
            for(int i=0;i<count;i++)
            {
            printf("\n----------------------------------------------------------------------------------------------------BOOK %d---------------------------------------------------------------------------------------------------------",i);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tBOOK NAME:%s",l[i].bookname);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tAUTHOR NAME:%s",l[i].authorname);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tYEAR PUBLISHED:%ld",l[i].year);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tBOOK ID:%s",l[i].bookid);
            }
            break;
        case 3:
            printf("--------------------------------------------------------------------------------------------------*BOOK  SEARCH*---------------------------------------------------------------------------------------------------\n");
            printf("\nBOOK NAME:");
            scanf("%s",booksearch);
            for(int z=0;z<count;z++)
            {
            if(strcmp(booksearch,l[z].bookname)==0)
            {
                status=1;
                break;
            }
            else
            {
                status=0;
            }
            }
            for(int z=0;z<count;z++)
            {
                if(strcmp(booksearch,l[z].borrowedbook)==0)
                {
                    availability=1;
                }
                else
                {
                    availability=0;
                }
            if(status==1)
            {
                printf("\nBOOK FOUND SUCCESFULLY!");
                if(availability==0)
                {
                    printf("\nBOOK AVAILABLE TO BORROW");
                }
                else
                {
                    printf("\nBOOK NOT AVAILABLE TO BORROW");
                }
            }
            else
            {
                printf("\nOOPS,BOOK NOT FOUND!");
            }
            break;
        case 4:
            printf("\n---------------------------------------------------------------------------------------------------*BORROW BOOKS*--------------------------------------------------------------------------------------------------\n");
            printf("\nTOTAL BOOKS TO BORROW    :");
            scanf("%d",&m);
            printf("ENTER BOOK NAME TO BORROW:");
            scanf("%s",booksearch);
            for(int i=0;i<m;i++)
            {
            for(int z=0;z<count;z++)
             {
                if(strcmp(booksearch,l[z].borrowedbook)==0)
                {
                    availability=1;
                }
                else
                {
                    availability=0;
                }
             }
             if(availability==0)
             {
                printf("\nENTER BORROWER NAME   :");
                scanf("%s",l[i].borrowername);
                printf("\nENTER BOOK NAME       :");
                scanf("%s",l[i].borrowedbook);
                printf("\nENTER DATE OF BORROWAL:");
                scanf("%s",l[i].borroweddate);
                printf("\nENTER DUE DATE        :");
                scanf("%s",l[i].duedate);
                printf("\nBOOK BORROWED SUCCESFULLY!");
            }
                else
                {
                    printf("\nBOOK CANT BE BORROWED");
                }
            }
            break;
         case 5:
            printf("-----------------------------------------------------------------------------------------------------*BORROWER LIST*-----------------------------------------------------------------------------------------------\n");
            for(int i=0;i<=strlen(l[i].borrowedbook);i++)
            {
                printf("-----------------------------------------------------------------------------------------------------*BORROWER %d*--------------------------------------------------------------------------------------------------\n",i);
                printf("\t\t\t\tNAME         :%s",l[i].borrowername);
                printf("\t\t\t\tBOOK NAME    :%s",l[i].borrowedbook);
                printf("\t\t\t\tBORROWED DATE:%s",l[i].borroweddate);
                printf("\t\t\tDUE DATE     :%s",l[i].duedate);
                printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            }
            break;
         case 6:
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n\t\t\t\t\t\t\t\t\t\t   THANK YOU FOR USING E-LIBRARY MANAGEMENT! HAVE A NICE DAY");
            printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            break;
        default:
            printf("\nInvalid choice!Please choose between 1 to 6");
   }
}
}
}


