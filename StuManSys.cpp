// ## Using a temporary filename in order to conceptualize the initial idea of
// the program.
// ## Based on the ideas I made while riding the jeepney

#include <cstring>
#include <fstream>
#include <iostream>
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

int main() {
  PromptActions(PromptUI());
  return 0;
}

int PromptUI() {
  int choice;
  cout << "\t\t\t\t\t------------------------------------" << '\n';
  cout << "\t\t\t\t\t\tStudent Management System" << '\n';
  cout << "\t\t\t\t\t------------------------------------" << '\n';
  cout << "\t\t\t\t\t+ 1. Add Student\t\t   +" << '\n';
  cout << "\t\t\t\t\t+ 2. View Student\t\t   +" << '\n';
  cout << "\t\t\t\t\t+ 3. Edit Student\t\t   +" << '\n';
  cout << "\t\t\t\t\t+ 4. Delete Student\t\t   +" << '\n';
  cout << "\t\t\t\t\t+ 5. Exit\t\t\t   +" << '\n';
  cout << "\t\t\t\t\t------------------------------------" << '\n';
  cout << "\t\t\t\t\tAction: $ ";
  cin >> choice;
  return choice;
}

void ViewStudent(string Student_ID) {
  cout << "\t\t\t\t\t------------------------------------" << '\n';
  cout << "\t\t\t\t\t\tStudent Information" << '\n';
  cout << "\t\t\t\t\t------------------------------------" << '\n';

  cout << "\t||            ,%#####%,           || " << '\n';
  cout << "\t||       *###############%        || " << '\n';
  cout << "\t||     %#####################%    || " << '\n';
  cout << "\t||    %#################&&#####   || "
       << "Name: " << '\n';
  cout << "\t||    ###############&&&&&%#####  || "
       << "Gender: " << '\n';
  cout << "\t||    .########&&&&&&&&&&&&#####% || "
       << "Year: " << '\n';
  cout << "\t||     #####&&&&&&&&&&&&&&&####%# || "
       << "Course: " << '\n';
  cout << "\t||     #####&&&&&&&&&&&&&&&####   || "
       << "Email: " << '\n';
  cout << "\t||    .#%###&&&&&&&&&&&&&&####    || "
       << "Mobile No.: " << '\n';
  cout << "\t||        ####&&&&&&&&&&%##%&     || "
       << "Section: " << '\n';
  cout << "\t||           #%&%%&&%%%%%         || "
       << "School ID: " << '\n';
  cout << "\t||       .*%%#%&&&&&&&&&#%%%*     || "
       << "Notes: " << '\n';
  cout << "\t|| &%#####%####&&&&&&&&&###%######|| " << '\n';
  cout << "\t||    %%#%%####%&&&&&&&#####%###% || " << '\n';
  cout << "\t||       %##%###%&&&&&######%%    || " << '\n';
}

void PromptActions(int choice) {

  switch (choice) {
  case 1:
    cout << "Add Student" << '\n';
    // GetStudentInfo();
    break;
  case 2:
    cout << "View Student" << '\n';
    // ReadStudentInfo(2);
    ViewStudent("M01235");
    break;
  case 3:
    cout << "Edit Student" << '\n';
    break;
  case 4:
    cout << "Delete Student" << '\n';
    break;
  case 5:
    cout << "Exit" << '\n';
    break;
  default:
    break;
  }
}
