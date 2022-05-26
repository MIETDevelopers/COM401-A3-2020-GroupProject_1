#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>

using namespace std;

char name[30];
char id[5];
char designation[10];
int age;
int ctc;
int experience; 			

class employee{
    private:

        void waitForEnter(void){
            cout<<"\nPress enter to go back! \n";
            cin.get();
            cin.get();
        }

        void listEmployees(void){
            system("cls");
            FILE *file;
            file= fopen("data.txt", "r");
            cout<<"List of Employees:-\n";
            cout<<"\n NAME        |     ID     |     DESIGNATION\n";
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!= EOF)
                cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<designation;
            fclose(file);
            waitForEnter();
        }

        void showDetails(void){
            system("cls");
            FILE *file;
            char checkId[5];
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                if(strcmp(checkId,id)==0){
                    cout<<"\nName: "<<name;
                    cout<<"\nId: "<<id;
                    cout<<"\nDesignation: "<<designation;
                    cout<<"\nAge: "<<age;
                    cout<<"\nCTC: "<<ctc;
                    cout<<"\nExperience: "<<experience;
                }
            fclose(file);
            waitForEnter();
        }

        void editExisting(void){
            system("cls");
            char checkId[5];
            cout<<"\nEnter employee id: ";
            cin>>checkId;
            char newDesignation[10];
            cout<<"\nEnter new designation: ";
            cin>>newDesignation;
            int newCtc;
            cin>>newCtc;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF){
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, newDesignation, age, newCtc, experience );
                else
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
        }

        void addNewEmployee(void){
            system("cls");
            cout<<"\n Enter First Name of Employee: ";
            cin>>name;
            cout<<"\n Enter Employee ID [max 4 digits]: ";
            cin>>id;
            cout<<"\n Enter Designation: ";
            cin>>designation;
            cout<<"\n Enter Employee Age: ";
            cin>>age;
            cout<<"\n Enter Employee CTC: ";
            cin>>ctc;
            cout<<"\n Enter Employee Experience: ";
            cin>>experience;

            char ch;
            cout<<"\nEnter 'y' to save above information! \n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
                fclose(file);
                cout<<"\nNew Employee has been added to database!\n";
            }
            else
                addNewEmployee();
            waitForEnter();
        }

        void deleteEmployeeDetails(void){
            system("cls");
            char checkId[5];
            cout<<"\nEnter Employee Id To Remove: ";
            cin>>checkId;
            char ch;    
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='y'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nRemoved Successfully\n";
                waitForEnter();
            }
            else
                deleteEmployeeDetails();
        }


    public:
        void options(void){
        int login();
                login();
            while(true){
                system("cls");
                cout<<"\n>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<";
                cout<<"\nSelect option:";
                cout<<"\n1. To View List of Employees";
                cout<<"\n2. To View Employee Details";
                cout<<"\n3. To Modify Existing Employee Details";
                cout<<"\n4. To Add New Employee Details";
                cout<<"\n5. To Remove an Employee Details";
                cout<<"\n0. To Exit     ";
                cout<<"\nPlease Enter Your Choice: ";

                int choice;
                cin>>choice;
                switch (choice) {
                    case 0:
                    	system("CLS");
                        Sleep(10);
                        return;
                    case 1:
                        listEmployees();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addNewEmployee();
                        break;
                    case 5:
                        deleteEmployeeDetails();
                        break;
                    default:
                        cout<<"\nEnter a valid option.\n";
                        break;
                }

            }
        }

};

int main(){
    employee e;
    e.options();
    return 0;
}

int login(){
 int c;
 cout <<"\nPlease select your login type";
 cout <<"\n1. Admin \n2. New User\nEnter choice: ";
 cin>> c;
 
 if(c==1){
 
 
   string pass ="";
   string name;
   char ch;
   cout <<"\nEnter Admin Username: ";
   cin>>name;
   cout <<"\nEnter Your Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "admin@123" && name== "admin"){
       cout<< "\n";
   	for(int a=1;a<8;a++) // Change 'a<?' to how many * you want
	{
		Sleep(200);
		cout << "...";
	}
      cout << "\nAccess Granted!!\n";
      
      system("PAUSE");
      system("CLS");
   }else{
      cout << "\nAccess Aborted! Try again.\n";
      login();
   }
}

if(c==2){
	system("cls");
	cout << "\nNew Registration \nFill up deatils below\n";
            cout<<"\nEnter First Name of Employee: ";
            cin>> name;
            cout<<"\nEnter 4 digit Employee ID: ";
            cin>>id;
            cout<<"\nEnter Designation: ";
            cin>>designation;
            cout<<"\nEnter Employee Age: ";
            cin>>age;
            cout<<"\nEnter Employee CTC: ";
            cin>>ctc;
            cout<<"\nEnter Employee Experience: ";
            cin>>experience;

            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
                fclose(file);
                cout<<"\nNew Employee has been added to database!\n";
                system("cls");
                login();
    		}
    }

}