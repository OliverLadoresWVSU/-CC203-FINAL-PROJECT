
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>

// using namespace std;

class Identification{
    private:
        std::string First_Name;
        std::string Middle_Name;
        std::string Last_Name;
        std::string Address;
        int ContactNumber;
        std::string Blood_Type;
        std::string Gender;
        std::string Sex;
        int Age;
        int Month_of_Birth;
        int Day_of_Birth;
        int Year_of_Birth;
        std::string DateofBirth;
        int Year_of_Admission;
        std::string ID;
    
    public:
        // Constructors
        Identification(){
            First_Name = "";
            Middle_Name = "";
            Last_Name = "";
            Blood_Type = "O";
            Address = "";
            ContactNumber = 0;
            Gender = "";
            Sex = "";
            Age = 0;
            Month_of_Birth = 0;
            Day_of_Birth = 0;
            Year_of_Birth = 0;
            Year_of_Admission = 0;
            ID = "";
        }
        Identification(
        std::string First_Name,
        std::string Middle_Name,
        std::string Last_Name,
        std::string Blood_Type,
        std::string Gender,
        std::string Sex){
            this -> First_Name = First_Name;
            this -> Middle_Name = Middle_Name;
            this -> Last_Name = Last_Name;
            this -> Blood_Type = Blood_Type;
            this -> Gender = Gender;
            this -> Sex = Sex;
        }
        // Getters
        std::string getFirst_Name() { return First_Name; }
        std::string getMiddle_Name() { return Middle_Name; }
        std::string getLast_Name() { return Last_Name; }
        std::string getBlood_Type() { return Blood_Type; }
        std::string getGender() { return Gender; }
        std::string getSex() { return Sex; }
        int getContactNumber() { return ContactNumber; }
        std::string getAddress() { return Address; }
        std::string getFullName() { return First_Name + " " + Middle_Name + " " + Last_Name; }
        // std::string getInitials() { return First_Name[0] + Middle_Name[0] + Last_Name[0]; }
        std::string getDateofBirth() { return DateofBirth; }
        int getAge() { return Age; }
        int getMonth_of_Birth() { return Month_of_Birth; }
        int getDay_of_Birth() { return Day_of_Birth; }
        int getYear_of_Birth() { return Year_of_Birth; }
        int getYear_of_Admission() { return Year_of_Admission; }
        std::string getID() { return ID; }


        
        // Setters
        void setFirst_Name(std::string name) { First_Name = name; }
        void setMiddle_Name(std::string name) { Middle_Name = name; }
        void setLast_Name(std::string name) { Last_Name = name; }
        void setBlood_Type(std::string type) { Blood_Type = type; }
        void setGender(std::string gender) { Gender = gender; }
        void setSex(std::string sex) { Sex = sex; }
        void setContactNumber(int number) { ContactNumber = number; }
        void setAddress(std::string address) { Address = address; }
        void setDateofBirth(int month, int day, int year) { 
            Month_of_Birth = month;
            Day_of_Birth = day;
            Year_of_Birth = year;
            DateofBirth = std::to_string(Month_of_Birth) + " " + std::to_string(Day_of_Birth) + " " + std::to_string(Year_of_Birth);
        }
        void setAge(int age) { Age = age; }
        void setAge(int month, int day, int year) { 
            Month_of_Birth = month;
            Day_of_Birth = day;
            Year_of_Birth = year;
            Age = 2021 - Year_of_Birth;
        }
        // void setAge(int age) { Age = age; }
        void setInitials() { First_Name[0] + Middle_Name[0] + Last_Name[0]; }
        void setFullName() { First_Name + " " + Middle_Name + " " + Last_Name; }
        void setYear_of_Admission(int year) { Year_of_Admission = year; }
        void setID(std::string id) { ID = id; }
};

class Student: public Identification{
    private:
        std::string section;
        std::string course;
        int GPA;
        std::string subjects[20];
    public:
        // Constructors
        Student(){
            section = "";
            course = "";
            GPA = 0;
            for(int i = 0; i < 20; i++){
                subjects[i] = "";
            }
        }
        Student(
        std::string section,
        std::string course,
        int GPA){
            Identification();
            this -> section = section;
            this -> course = course;
            this -> GPA = GPA;
        }
        // Getters
        std::string getSection() { return section; }
        std::string getCourse() { return course; }
        int getGPA() { return GPA; }
        std::string getSubjects(int index) { return subjects[index]; }
        // Setters
        void setSection(std::string section) { this -> section = section; }
        void setCourse(std::string course) { this -> course = course; }
        void setGPA(int GPA) { this -> GPA = GPA; }
        void setSubjects(std::string subject, int index) { subjects[index] = subject; }
    
};

// Function Prototypes and Declarations
void CreateStudentID(Student student);
void AddStudent(Student student);
void SearchStudent(Student check_student);
int PromptUI();
void ViewStudent();
void ReadStudent(Student student);

int main(){
    Student std1;
    int choice;
    // choice = PromptUI();
    AddStudent(std1);
    ReadStudent(std1);
    return 0;
}

void CreateStudentID(Student student){
    // Prerequisites:
        // Create an ID for the Student Based on their Information
    std::ostringstream ID;
    ID << student.getYear_of_Admission() << student.getFirst_Name()[0] << student.getMiddle_Name()[0] << student.getLast_Name()[0] << student.getBlood_Type()[0] << student.getGender()[0] << student.getSex()[0];
    student.setID(ID.str());
    std::cout << student.getID() << "\n";
}

void AddStudent(Student student) {
    // Prerequisites:
        // Create a Student Object
        // Create a Student ID
        // Create a Student File

    // Create the variables
    std::string Name, First_Name, Middle_Name, Last_Name, sex, blood_type;

    // Create a cout that ask for the student information and store it in the class
    std::cout << "Enter the student's first name: " << "\n";
    std::cin >> First_Name;
    std::cout << "Enter the student's middle name: " << "\n";
    std::cin >> Middle_Name;
    std::cout << "Enter the student's last name: " << "\n";
    std::cin >> Last_Name;
    std::cout << "Enter the Student's Sex: " << "\n";
    std::cin >> sex;
    std::cout << "Enter the student's blood type: " << "\n";
    std::cin >> blood_type;

    // Setters
    student.setFirst_Name(First_Name);
    student.setMiddle_Name(Middle_Name);
    student.setLast_Name(Last_Name);
    student.setSex(sex);
    student.setBlood_Type(blood_type);

	std::ofstream addStudent("StudentInfo.txt", std::ios::app);
	addStudent<< student.getFirst_Name() << " " << student.getMiddle_Name() << " " << student.getLast_Name() << " " << student.getBlood_Type() << " " << student.getGender() << " " << student.getSex() << std::endl;
	std::cout << "Student added successfully" << "\n";
	addStudent.close();
}

void ReadStudent(Student student){

    std::string Name, First_Name, Middle_Name, Last_Name, sex, blood_type;

    // Variables needed to read the file

    std::ifstream readStudent("StudentInfo.txt");
    while(readStudent >> First_Name >> Middle_Name >> Last_Name >> sex >> blood_type){
        student.setFirst_Name(First_Name);
        student.setMiddle_Name(Middle_Name);
        student.setLast_Name(Last_Name);
        student.setSex(sex);
        student.setBlood_Type(blood_type);
    }
    // Print all of the values
    std::cout << student.getFirst_Name() << " " << student.getMiddle_Name() << " " << student.getLast_Name() << " " << student.getBlood_Type() << " " << student.getGender() << " " << student.getSex() << std::endl;
}

// void ViewStudent(){
//     std::ifstream view("StudentInfo.txt");
//     std::string name, address, ID;
//     std::cout << " Enter the student's SSN to search about him/her: " << "\n";
//     std::cin >> ID;
//     while (view >> ID >> name >> address)
//     {
//         if (ID == ID)
//         {
//             std::cout << "Student's name: " << name << "\n";
//             std::cout << "Student's address: " << address << "\n";
//             break;
//         }
//         else
//         {
//             std::cout<< " Student is not found!!" << "\n";

//         }
//     }
//     view.close();
// }


// void SearchStudent(Student check_student) {
// 	std::ifstream search("StudentInfo.txt");
// 	std:: string name, address, ID;
// 	std::cout << " Enter the student's SSN to search about him/her: " << "\n";
// 	std::cin >> ID;
// 	while (search >> check_student.getID() >> check_student.getLast_Name())
// 	{
// 			if (check_student.getID() == ID)
// 			{
//                 ViewStudent();
// 				break;
// 			}
//             else
//             {
//                 std::cout<< " Student is not found!!" << "\n";

//             }
// 	search.close();
// }}

int PromptUI(){
    int choice;
    std::cout<< "\t\t\t\t\t------------------------------------" << "\n";
    std::cout<< "\t\t\t\t\t\tStudent Management System" << "\n";
    std::cout<< "\t\t\t\t\t------------------------------------" << "\n";
    std::cout<< "\t\t\t\t\t+ 1. Add Student\t\t   +" << "\n";
    std::cout<< "\t\t\t\t\t+ 2. View Student\t\t   +" << "\n";
    std::cout<< "\t\t\t\t\t+ 3. Edit Student\t\t   +" << "\n";
    std::cout<< "\t\t\t\t\t+ 4. Delete Student\t\t   +" << "\n";
    std::cout<< "\t\t\t\t\t+ 5. Exit\t\t\t   +" << "\n";
    std::cout<< "\t\t\t\t\t------------------------------------" << "\n";
    std::cout<< "\t\t\t\t\tAction: $ ";
    std::cin >> choice;
    return choice;  
}

void ViewStudent(){
    std::cout<< "\t\t\t\t\t------------------------------------" << "\n";
    std::cout<< "\t\t\t\t\t\tStudent Information" << "\n";
    std::cout<< "\t\t\t\t\t------------------------------------" << "\n";

    std::cout<< "Female" << "\n";                    
    std::cout<< "\t||            ,%#####%,           || " << "\n";    
    std::cout<< "\t||       *###############%        || " << "\n";    
    std::cout<< "\t||     %#####################%    || " << "\n";    
    std::cout<< "\t||    %#################&&#####   || " << "Name: "<< "\n";    
    std::cout<< "\t||    ###############&&&&&%#####  || " << "Gender: "<< "\n";    
    std::cout<< "\t||    .########&&&&&&&&&&&&#####% || " << "Year: "<< "\n";    
    std::cout<< "\t||     #####&&&&&&&&&&&&&&&####%# || " << "Course: "<< "\n";    
    std::cout<< "\t||     #####&&&&&&&&&&&&&&&####   || " << "Email: "<< "\n";    
    std::cout<< "\t||    .#%###&&&&&&&&&&&&&&####    || " << "Mobile No.: "<< "\n";    
    std::cout<< "\t||        ####&&&&&&&&&&%##%&     || " << "Section: "<< "\n";    
    std::cout<< "\t||           #%&%%&&%%%%%         || " << "Placeholder: "<< "\n";    
    std::cout<< "\t||       .*%%#%&&&&&&&&&#%%%*     || " << "Placeholder: "<< "\n";    
    std::cout<< "\t|| &%#####%####&&&&&&&&&###%######|| " << "\n";    
    std::cout<< "\t||    %%#%%####%&&&&&&&#####%###% || " << "\n";    
    std::cout<< "\t||       %##%###%&&&&&######%%    || " << "\n";    
    std::cout<< "\t||           %###%&&&####%        || " << "\n";
}