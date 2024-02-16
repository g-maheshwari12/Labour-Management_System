#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
using namespace std;
class labour
{
    private:
        char name[30];
        char id[5];
        char designation[10];
        int age;
        int salary;
        int experience;

        void waitForEnter(void)
        {
            cout<<"\n\n\n Press enter to go back \n\n";
            cin.get();
            cin.get();
        }
        void listlabours(void)
        {
            system("cls");
            FILE *file;
            file= fopen("data.txt", "r");
            cout<<"\n\t      List of labours\n";
            cout<<"\n----------------------------------------------";
            cout<<"\n NAME        |     ID     |     DESIGNATION\n";
            cout<<"----------------------------------------------";
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &salary, &experience)!= EOF)
                cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<designation;
            fclose(file);
            waitForEnter();
        }
        void showDetails(void)
        {
            system("cls");
            FILE *file;
            char checkId[5];
            cout<<"\n\nEnter labour ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &salary, &experience)!=EOF)
            {
                if(strcmp(checkId,id)==0)
                {
                	cout<<"\n---------------------";
                    cout<<"\nName: "<<name;
                    cout<<"\n---------------------";
                    cout<<"\nId: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nDesignation: "<<designation;
                    cout<<"\n---------------------";
                    cout<<"\nAge: "<<age;
                    cout<<"\n---------------------";
                    cout<<"\nSalary: "<<salary;
                    cout<<"\n---------------------";
                    cout<<"\nExperience in years: "<<experience;
                    cout<<"\n---------------------";
                }
            }
            fclose(file);
            waitForEnter();
        }
        void editExisting(void)
        {
            system("cls");
            char checkId[5];
            cout<<"\nEnter labour id: ";
            cin>>checkId;
            char newDesignation[10];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new designation: ";
            cin>>newDesignation;
            int newsalary;
            cout<<"------------------------------";
            cout<<"\nEnter new Salary: ";
            cin>>newsalary;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &salary, &experience)!=EOF)
            {
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, newDesignation, age, newsalary, experience );
                else
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, salary, experience );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
        }

        void addNewlabour(void)
        { 
            system("cls");
            cout<<"\n----------------------------------------";
            cout<<"\n Enter First Name of labour: ";
            cin>>name;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter labour ID [max 4 digits]: ";
            cin>>id;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Designation: ";
            cin>>designation;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter labour Age: ";
            cin>>age;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter labour Salary: ";
            cin>>salary;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter labour Experience in years: ";
            cin>>experience;
            cout<<"\n----------------------------------------";

            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y')
            {
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, salary, experience );
                fclose(file);
                cout<<"\nNew labour has been added to database\n";
            }
            else
                addNewlabour();
            waitForEnter();
        }
        void deletelabourDetails(void)
        {
            system("cls");
            char checkId[5];
            cout<<"\n----------------------------------";
            cout<<"\nEnter labour Id To Remove: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='y')
            {
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &salary, &experience)!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, salary, experience );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nRemoved Successfully\n";
                waitForEnter();
            }
            else
                deletelabourDetails();
        }
    public:
        void options(void)
        {
            int login();
                login();
            while(true)
            {
                system("cls");
                cout<<"\n\t\t\t>>>>>>>>>  LABOUR MANAGEMENT SYSTEM  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To Add New labour Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To Modify Existing labour Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   3:   To View labour Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   4:   To View List of labours";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   5:   To Remove an labour Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   0:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";
                int choice;
                cin>>choice;
                switch (choice) 
                {
                    case 0:	system("CLS");
                            cout<<"\n\nLABOUR MANAGEMENT SYSTEM \n\n Brought To You By Gaurav Maheshwari\n\n ";
                            Sleep(100);
                            return;
                    case 1: addNewlabour();
                            break;
                    case 2: editExisting();
                            break;
                    case 3: showDetails();
                            break;
                    case 4: listlabours();
                            break;
                    case 5: deletelabourDetails();
                            break;
                    default: cout<<"\n Sorry! I don't understand that! \n";
                             break;
                }

            }
        }
};

int main()
{
    labour l;
    l.options();
    return 0;
}
int login()
{
   string password ="";
   char ch;
   cout <<"\n\n\n\n\t\t\t\t\tLABOUR MANAGEMENT SYSTEM";
   cout <<"\n\n\n\n\n\t\t\t\t\tEnter Your Password :";
   ch = _getch();
   while(ch != 13)
   {
      password.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(password == "gaurav")
   {
    cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
   	for(int a=1;a<8;a++)
	{
		Sleep(500);
		cout << "...";
	}
    cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";
      
    system("PAUSE");
    system("CLS");
   }
   else
   {
      cout << "\nAccess Aborted...\n";
      login();
   }
   return 0;
}