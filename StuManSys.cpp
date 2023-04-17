// ## Using a temporary filename in order to conceptualize the initial idea of the program.
// ## Based on the ideas I made while riding the jeepney

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;    

// ## Things Needed to Do:
// ## 1. Create a file and name the file using the name of the student
// ## 2. Create a folder and name the folder using the name of the student
// ## 3. Create the list of features needed for the program
//       ## 3.1 UI for Accessing the Program
// ## Ui Functions
int PromptUI();
void PromptActions(int choice);

int PromptUI(){
    int choice;
    cout << "\t\t\t\t\t------------------------------------" << endl;
    cout << "\t\t\t\t\t\tStudent Management System" << endl;
    cout << "\t\t\t\t\t------------------------------------" << endl;
    cout << "\t\t\t\t\t+ 1. Add Student\t\t   +" << endl;
    cout << "\t\t\t\t\t+ 2. View Student\t\t   +" << endl;
    cout << "\t\t\t\t\t+ 3. Edit Student\t\t   +" << endl;
    cout << "\t\t\t\t\t+ 4. Delete Student\t\t   +" << endl;
    cout << "\t\t\t\t\t+ 5. Exit\t\t\t   +" << endl;
    cout << "\t\t\t\t\t------------------------------------" << endl;
    cout << "\t\t\t\t\tAction: $ ";
    cin >> choice;
    return choice;  
}

void ViewStudent(string Student_ID){
    cout << "\t\t\t\t\t------------------------------------" << endl;
    cout << "\t\t\t\t\t\tStudent Information" << endl;
    cout << "\t\t\t\t\t------------------------------------" << endl;

    cout << "Female" << endl;                    
    cout << "\t||            ,%#####%,           || " << endl;    
    cout << "\t||       *###############%        || " << endl;    
    cout << "\t||     %#####################%    || " << endl;    
    cout << "\t||    %#################&&#####   || " << "Name: "<< endl;    
    cout << "\t||    ###############&&&&&%#####  || " << "Gender: "<< endl;    
    cout << "\t||    .########&&&&&&&&&&&&#####% || " << "Year: "<< endl;    
    cout << "\t||     #####&&&&&&&&&&&&&&&####%# || " << "Course: "<< endl;    
    cout << "\t||     #####&&&&&&&&&&&&&&&####   || " << "Email: "<< endl;    
    cout << "\t||    .#%###&&&&&&&&&&&&&&####    || " << "Mobile No.: "<< endl;    
    cout << "\t||        ####&&&&&&&&&&%##%&     || " << "Section: "<< endl;    
    cout << "\t||           #%&%%&&%%%%%         || " << "Placeholder: "<< endl;    
    cout << "\t||       .*%%#%&&&&&&&&&#%%%*     || " << "Placeholder: "<< endl;    
    cout << "\t|| &%#####%####&&&&&&&&&###%######|| " << endl;    
    cout << "\t||    %%#%%####%&&&&&&&#####%###% || " << endl;    
    cout << "\t||       %##%###%&&&&&######%%    || " << endl;    

    cout << "Male" << endl;

    cout << "\t||            #########           || " << endl;    
    cout << "\t||          ###%%%%%%%###         || " << endl;
    cout << "\t||         ###%%%%%%#####         || " << endl;
    cout << "\t||        ###%%%%%%#######        || " << endl;
    cout << "\t||        ##%%%%%#########        || " << endl;
    cout << "\t||        ###############         || " << endl;
    cout << "\t||          ############          || " << endl;
    cout << "\t||           ##########           || " << endl;
    cout << "\t||          ############          || " << endl;
    cout << "\t||      *#################*       || " << endl;
    cout << "\t|| ############################   || " << endl;
    cout << "\t|| ############################## || " << endl;
    cout << "\t||  ############################# || " << endl;
    cout << "\t||   ###########################  || " << endl;
    cout << "\t||    #########################   || " << endl;

}

void PromptActions(int choice){
    
    switch (choice)
    {
    case 1:
        cout << "Add Student" << endl;
        GetStudentInfo();
        break;
    case 2:
        cout << "View Student" << endl;
        ReadStudentInfo(2);
        ViewStudent("M01235");
        cin >> choice;
        break;
    case 3:
        cout << "Edit Student" << endl;
        break;
    case 4:
        cout << "Delete Student" << endl;
        break;
    case 5:
        cout << "Exit" << endl;
        break;
    default:
        break;
    }
}