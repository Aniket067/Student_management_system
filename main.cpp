#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include<windows.h>
#include<ctime>

using namespace std;
int main()
{

    while(1)
    {
    FILE *fp, *ft;
    char any, cho;
    int opt= 0;

    struct student
    {
        char firstname[50], lastname[50];
        int id;
        char stream[100];
        int batch;
        int mathmark;
        int phymark;
        int attend;
    };

    struct student s;
    char xfirstname[50], xlastname[50];
    int xid;
    int sid;
    long int ssize;

    fp=fopen("users.dat","rb+");

    if (fp == NULL)
    {
        fp = fopen("users.dat","wb+");

        if (fp==NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }


    ssize = sizeof(s);
    while(opt!=3)
    {
        jump:

        system("cls");
        cout<<"\t\t\t\t*****************************************************\n";
        cout<<"\t\t\t\t**************STUDENT MANAGEMENT SYSTEM ************\n";
        cout<<"\t\t\t\t*****************************************************";
        cout <<"\n\n";

        cout << "\n MAIN HOMEPAGE MENU:";
        cout<<"\n";
        cout<<"\n1 Teachers Login\n2.Student Login ";
        cout<<"\n3.Exit\n";
        cout<<"Enter choice: ";
        cin>>opt;

        if(opt==1)
        {
            while(cho!='5')
            {
             system("cls");
             cout << "\n\n";
             cout << "\n \t\t\t 1. Add   Students Basic and Academic details ";
             cout << "\n \t\t\t 2. Display Details ";
             cout << "\n \t\t\t 3. Search and Edit Details";
             cout << "\n \t\t\t 4. Delete student Details";
             cout << "\n \t\t\t 5.Return to the main homepage menu";
             cout << "\n\n";
             cout << "\t\t\t Enter Your Choice : ";
             fflush(stdin);
             cho = getche();
             switch(cho)
             {
             case '1' :
              fseek(fp,0,SEEK_END);
               any ='Y';
               while(any == 'Y' || any == 'y')
               {
                system("cls");
                cout<<"Enter the University id number of student:";
                cin>>s.id;
                cout << "Enter the First Name : ";
                cin >> s.firstname;
                cout << "Enter the Last Name : ";
                cin >> s.lastname;
                cout << "Enter the Stream   : ";
                cin >> s.stream;
                cout << "Enter the Batch no.  : ";
                cin >> s.batch;
                cout<<"Marks in  Engineering Mathematics out of 100:";
                cin>>s.mathmark;
                cout<<"Marks in  Physics out of 100:";
                cin>>s.phymark;
                cout<<"Enter the Attendance :";
                cin>>s.attend;
                fwrite(&s,ssize,1,fp);
                cout << "\n Add Another Record (y/n) ";
                fflush(stdin);
                any = getchar();
            }
            break;
           case '2':

            system("cls");
            rewind(fp);
            cout <<"----------------------------------------------------------- \n";
            cout << "********************** Display Details ******************* \n";
            cout <<"----------------------------------------------------------- \n";
            cout << "\n";
            while (fread(&s,ssize,1,fp) == 1)
            {
                cout << "\n";
                cout<<s.id<<"\t"<<s.firstname<<"\t"<<s.lastname<<"\t";
                cout<<s.stream<<"\t"<<s.batch<<"\t"<<s.mathmark<<"\t"<<s.phymark<<"\t"<<s.attend<<"%"<<"\t";

            }
            cout << "\n";
            system("pause");

            break;

        case '3' :
            system("cls");
            any = 'Y';
            while (any == 'Y'|| any == 'y')
            {
                cout << "\n Enter the university id number of the student to edit : ";
                cin >> xid;

                rewind(fp);
                while (fread(&s,ssize,1,fp) == 1)
                {
                    if (s.id==xid)
                    {

                        cout<<"Update marks in  Engineering Mathematics :";
                        cin>>s.mathmark;
                        cout<<" Update Marks in  Physics :";
                        cin>>s.phymark;
                        cout<<"Enter the updated Attendance :";
                        cin>>s.attend;
                        fseek(fp, - ssize, SEEK_CUR);
                        fwrite(&s,ssize,1,fp);
                        break;
                    }
                 //else



                }
                cout << "\n Edit another Record (y/n) ";
                fflush(stdin);
                any = getchar();
            }
            break;


        case '4':
            system("cls");
            any = 'Y';
            while (any == 'Y'|| any == 'y')
            {
                cout << "\n Enter the university id no. of the student to delete : ";
                cin >> xid;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&s, ssize,1,fp) == 1)

                    if (s.id!=xid)
                    {
                        fwrite(&s,ssize,1,ft);
                    }
                    else
                    {
                        cout<<"\n Record Deleted";
                    }

                fclose(fp);
                fclose(ft);
                remove("users.dat");
                rename("temp.dat","users.dat");

                fp=fopen("users.dat","rb+");

                cout << "\n Delete Another Record (y/n) ";
                fflush(stdin);
                any = getchar();
            }

            break;

        }
       }
      break;
      goto jump;
    }
    else if(opt==2)
    {
        int choice;
         while(choice!=2)
         {
          system("cls");

        cout << "\n1. View your details \n";
        cout << "2. Return to the main homepage menu\nEnter option: ";
        cin >> choice;
        if(choice==1)
        {
           system("cls");
            cout <<"----------------------------------------------------------- \n";
            cout << "***************** View your Details ********************** \n";
            cout <<"----------------------------------------------------------- \n";
            cout << "\n";
            cout << "\n";
            cout<<"Enter your University id number :";
            cin>>sid;
            rewind(fp);
            while (fread(&s,ssize,1,fp) == 1)
            {    if(s.id==sid)
                 {
                cout << "\n";
                cout<<"Name:";
                cout<<s.firstname;
                //cout<< "\t";
                cout<<" ";
                cout<<s.lastname;
                cout<<"\n";
                cout<<"Stream:";
                cout<<s.stream;
                cout<<"\n";
                cout<<"Batch:";
                cout<<s.batch;
                cout<<"\n";
                cout<<"Engineering Mathematics Marks out of 100 :";
                cout<<s.mathmark;
                cout<<"\n";
                cout<<"Physics Marks out of 100 :";
                cout<<s.phymark;
                cout<<"\n";
                cout<<"Attendance : ";
                cout<<s.attend<<"%";
                cout<<"\n";


                 }
            }
            cout << "\n";
            system("pause");

        }


        }
        break;
        goto jump;

    }

        fclose(fp);
        //cout<<"closing";
        goto h;
    }



    }




    //system("pause");
    h:
    return 0;
}
