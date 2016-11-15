#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
FILE *f,*fg;
int dpd;
typedef struct
{
int day;
int month;
int year;
} birth;
typedef struct{
int id;
char name[50];
int age;
birth dob;
char fname[50];
char fopt[50];
char mname[50];
char mopt[100];
char edu[50];
char address[100];
}g;
g sport;
void duplicate();
void insert();
void display();
void delete();
void update();
void search();
void print();
void main()
{
    print();
    int again=0;
    int n,a;
    while(again==0)
    {
    printf("\n\n\n****************1 INSERT NEW DATA.");
    printf("\n****************2 DISPLAY EXISTING DATA.");
    printf("\n****************3 DELETE EXISTING DATA.");
    printf("\n****************4 UPDATE EXISTING DATA.");
    printf("\n****************5 SEARCH & DISPLAY EXISTING DATA.");
    printf("\n****************6 EXIT.");
    printf("\n\n#USE THE RESPECTIVE NUMBERS<1/2/3/4/5/6> TO PROCEED#");
    printf("\n\nPLEASE SELECT WHAT YOU WANT TO PROCEED WITH : ");
    scanf("\n\t%d",&n);

    switch(n)
    {
    case 1:
       //  duplicate();
         insert();
        break;
    case 2:
        display();
        break;
    case 3:
        delete();
        break;
    case 4:
        update();
        break;
    case 5:
        search();
        break;
    case 6:
        printf("*****************THANK YOU FOR USING PLAYER'S PROFILE APPLICATION.********************\n**************************TO STOP THE APPLICATION PLEASE PRESS 1 ***************************\n ************************************NOW PLEASE CLOSE THE APPLICATION TO EXIT.**********************");
        scanf("%d",&again);break;
    default:
        printf("\tINVALID NUMBER CHOICE !! \n \tPLEASE SELECT THE NUMBER <1/2/3/4/5/6> FROM ABOVE.");break;


    }
    }
}
void insert()
{
    char a='y';
    while(a=='y')
    {
    f=fopen("Nepal Gymnastic Association.dat","a+");
    // duplicate();
     printf("\nEnter Applicant's ID to check : ");
    scanf("%d",&dpd);
  //  fread(&sport, sizeof(sport),1,f);
    dpd=sport.id;
    printf("\n\tEnter Applicant's ID : ");
    scanf("%d",&sport.id);
    if(sport.id==dpd)
    {
        printf("duplicate data found .");
        break;
    }

    printf("\tEnter Applicant's Name : ");
    scanf("%s",&sport.name);
    fflush(stdin);
    printf("\tEnter Applicant's age : ");
    scanf("%d",&sport.age);
    fflush(stdin);
    printf("\tEnter Applicant's Date of Birth (dd/mm/yy) : ");
    scanf("%d/%d/%d",&sport.dob.day,&sport.dob.month,&sport.dob.year);
    fflush(stdin);
    printf("\tEnter Applicant's Father's Name : ");
    scanf("%s",&sport.fname);
    fflush(stdin);
    printf("\tEnter Applicant's Father's Occupation : ");
    scanf("%s",&sport.fopt);
    fflush(stdin);
    printf("\tEnter Applicant's Mother's Name : ");
    scanf("%s",&sport.mname);
    fflush(stdin);
    printf("\tEnter Applicant's Mother's Occupation : ");
    scanf("%s",&sport.mopt);
    fflush(stdin);
    printf("\tEnter Applicant's Education Qualification : ");
    scanf("%s",&sport.edu);
    printf("\tEnter Applicant's Permanent Address : ");
    scanf("%s",&sport.address);
    fwrite(&sport,sizeof(sport),1,f);
   // fprintf(f,"%d %s %d %d %d %d %s %s %s %s %s",sport.id,sport.name,sport.age,sport.dob.day,sport.dob.month,sport.dob.year,sport.fname,sport.fopt,sport.mname,sport.mopt,sport.edu);
    printf("\n\n\n***** The Applicant's Information was Successfully Registered. *****");
    fclose(f);
    printf("\n\n DO YOU WANT TO REGISTER ANOTHER APPLICANT ? (Y/N)" );
    a=getche();

    }
}
void duplicate()
{
    f=fopen("Nepal Gymnastic Association.dat","r");
    printf("\nEnter Applicant's ID to check : ");
    scanf("%d",&dpd);
   /* while((fread(&sport, sizeof(sport),1,f))==1)
    {
     if(dpd==sport.id)
    {
     printf("duplicate data found");
     break;
    } */
    fread(&sport, sizeof(sport),1,f);
    dpd=sport.id;
    fclose(f);
}


void display()
{

    f=fopen("Nepal Gymnastic Association.dat","r");
           while(fread(&sport,sizeof(sport),1,f)==1)
           // while(fscanf(f,"%d %s %d %d %d %d %s %s %s %s %s",&sport.id,&sport.name,&sport.age,&sport.dob.day,&sport.dob.month,&sport.dob.year,&sport.fname,&sport.fopt,&sport.mname,&sport.mopt,&sport.edu))
            {
                printf("\n\n\t\t Applicant's ID :%d\n\t\t Applicant's Name : %s\n\t\t Applicant's Age : %d\n\t\t Applicants\'s DOB :%d/%d/%d\n\t\t Applicant's Father Name: %s \n\t\t Applicant's Father's Occupation : %s\n\t\t Applicant's Mother Name : %s\n\t\t Applicant's Mother's Occupation :%s\n\t\t Applicant's Education Qualification : %s\n\t\t Applicant's Permanent Address : %s  ",sport.id,sport.name,sport.age,sport.dob.day,sport.dob.month,sport.dob.year,sport.fname,sport.fopt,sport.mname,sport.mopt,sport.edu,sport.address);
            }
            fclose(f);
             getch();

}
void delete()
{
            int tid;
            f=fopen("Nepal Gymnastic Association.dat","r");
            fg=fopen("temp.dat","w");
            printf("Enter Applicant's ID : ");
            scanf("%d",&tid);
            if(f==NULL || fg==NULL )
            {
                printf("THIS APPLICANT'S ID IS NOT FOUND !");
            }
            else
                {
                while((fread(&sport,sizeof(sport),1,f))==1)
                    {
                      if(sport.id==tid)
                   {
                     delete;
                     printf("THIS DATA IS NOW DELETED.");
                     continue;

                   }
                   else{fwrite(&sport,sizeof(sport),1,fg);}
                }

                }
                fclose(f);
                fclose(fg);
                remove("Nepal Gymnastic Association.dat");
                rename("temp.dat","Nepal Gymnastic Association.dat");

}
void update()
{           int tid;
            f=fopen("Nepal Gymnastic Association.dat","r");
            fg=fopen("temp.dat","w");
            printf("Enter Applicant's ID : ");
            scanf("%d",&tid);
            if( f==NULL || fg==NULL )
            {
                printf("THIS APPLICANT'S ID IS NOT FOUND !");
            }
            else
                {
                while((fread(&sport,sizeof(sport),1,f))==1)
                    {
                      if(sport.id==tid)
                   {

                    printf("\tEnter Applicant's New Name : ");
                    scanf("%s",&sport.name);
                    fflush(stdin);
                    printf("\tEnter Applicant's New age : ");
                    scanf("%d",&sport.age);
                    fflush(stdin);
                    printf("\tEnter Applicant's New Date of Birth (dd/mm/yy) : ");
                    scanf("%d,%d,%d",&sport.dob.day,&sport.dob.month,&sport.dob.year);
                    fflush(stdin);
                    printf("\tEnter Applicant's Father's Name : ");
                    scanf("%s",&sport.fname);
                    fflush(stdin);
                    printf("\tEnter Applicant's Father's New Occupation : ");
                    scanf("%s",&sport.fopt);
                    fflush(stdin);
                    printf("\tEnter Applicant's Mother's Name : ");
                    scanf("%s",&sport.mname);
                    fflush(stdin);
                    printf("\tEnter Applicant's Mother's New Occupation : ");
                    scanf("%s",&sport.mopt);
                    fflush(stdin);
                    printf("\tEnter Applicant's New Education Qualification : ");
                    scanf("%s",&sport.edu);
                    printf("\tEnter Applicant's Permanent Address : ");
                    scanf("%s",&sport.address);
                    fwrite(&sport,sizeof(sport),1,fg);
                   }
                   else{fwrite(&sport,sizeof(sport),1,fg);
                        }
                }

                }
                fclose(f);
                fclose(fg);
                remove("Nepal Gymnastic Association.dat");
                rename("temp.dat","Nepal Gymnastic Association.dat");
}
void search()
{
            int tid;
            f=fopen("Nepal Gymnastic Association.dat","r");
            fg=fopen("temp.dat","w");
            printf("Enter Applicant's ID : ");
            scanf("%d",&tid);
            if(f==NULL)
            {
                printf("THIS APPLICANT'S ID IS NOT FOUND !");
            }
            else
                {
                while((fread(&sport,sizeof(sport),1,f))==1)
                    {
                      if(sport.id==tid)
                   {
                     printf("\n Applicant's ID :%d\n Applicant's Name : %s\n Applicant's Age : %d\n Applicants\'s DOB :%d/%d/%d\n Applicant's Father Name: %s \n Applicant's Father's Occupation : %s\n Applicant's Mother Name : %s\n Applicant's Mother's Occupation :%s\n Applicant's Education Qualification : %s\n Applicant's Permanent Address : %s",sport.id,sport.name,sport.age,sport.dob.day,sport.dob.month,sport.dob.year,sport.fname,sport.fopt,sport.mname,sport.mopt,sport.edu,sport.address);

                   }
                   else{fwrite(&sport,sizeof(sport),1,fg);}
                }

                }
                fclose(f);


}
void print()
{
   printf("######################################################################################################################################################################################################################################");
   printf("################################################################   NATIONAL SPORTS COUNCIL OF NEPAL  #####################################################################################################################");
   printf("\n###########################################################################      WELCOME TO       ##############################################################################################################################");
   printf("\n################################################################# NEPAL GYMNASTICS PLAYER PROFILE APPLICATION ##################################################################################################################");
   printf("\n################################################################################################################################################################################################################################");
   printf("\t\n\n\t*** THIS APPLICATION IS INTENDED ONLY FOR EDUCATIONAL PURPOSE ***");
   printf("\n\t\t** Application for Gymnastics players of Nepal **");
   printf("\n\t\t**** PLEASE USE '-' SIGN INSTEAD OF SPACE ****");
}

