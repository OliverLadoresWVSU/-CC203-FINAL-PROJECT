/**
 * @file student.cpp
 * @author Oliver Ladores (oliver.ladores@wvsu.edu.ph) Dhominick John S. Billena (Wla lng for clout)
 * @brief Implementation for Student class to be used with file parsing and data
 * manipulation. Note that this only compiles with the flag -std=c++20 (C++20)
 * @version 0.2
 * @date 2023-04-23
 *
 *
 */

#include <optional>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>

typedef unsigned int uint;

class Student
{
private:
  std::optional<std::string> id, last_name, first_name, middle_name, suffix, gender, birth_month, address, course, year_and_section, email,
      phone_number, notes;
  std::optional<uint> birth_day, birth_year;

public:
  /**
   * @brief Construct a new Student object.
   *
   * All arguments default to std::nullopt when no input is given.
   */
  Student(const std::optional<std::string> idInput = std::nullopt,
          const std::optional<std::string> last_nameInput = std::nullopt,
          const std::optional<std::string> first_nameInput = std::nullopt,
          const std::optional<std::string> middle_nameInput = std::nullopt,
          const std::optional<std::string> suffixInput = std::nullopt,
          const std::optional<std::string> genderInput = std::nullopt,
          const std::optional<uint> birth_dayInput = std::nullopt,
          const std::optional<std::string> birth_monthInput = std::nullopt,
          const std::optional<uint> birth_yearInput = std::nullopt,
          const std::optional<std::string> addressInput = std::nullopt,
          const std::optional<std::string> courseInput = std::nullopt,
          const std::optional<std::string> year_and_sectionInput = std::nullopt,
          const std::optional<std::string> emailInput = std::nullopt,
          const std::optional<std::string> phone_numberInput = std::nullopt,
          const std::optional<std::string> notesInput = std::nullopt)
      : id(idInput), last_name(last_nameInput), first_name(first_nameInput), middle_name(middle_nameInput), suffix(suffixInput), gender(genderInput),
        birth_day(birth_dayInput), birth_month(birth_monthInput), birth_year(birth_yearInput), address(addressInput), course(courseInput),
        year_and_section(year_and_sectionInput), email(emailInput),
        phone_number(phone_numberInput), notes(notesInput) {}

  /**
   * @brief Sets the members based on the arguments. We have to implement it this way cause we want to access the private members.
   *
   * @param member The member to modify.
   * @param data The data to set the member to.
   */
  void set_from_str(std::string member, std::optional<std::string> data)
  {
    std::size_t pos{};
    if (member.compare("id") == 0)
      id = data;
    else if (member.compare("last_name") == 0)
      last_name = data;
    else if (member.compare("first_name") == 0)
      first_name = data;
    else if (member.compare("middle_name") == 0)
      middle_name = data;
    else if (member.compare("suffix") == 0)
      suffix = data;
    else if (member.compare("gender") == 0)
      gender = data;
    else if (member.compare("birth_day") == 0)
      birth_day = std::stoi(data.value(), &pos, 10);
    else if (member.compare("birth_month") == 0)
      birth_month = data;
    else if (member.compare("birth_year") == 0)
      birth_year = std::stoi(data.value(), &pos, 10);
    else if (member.compare("address") == 0)
      address = data;
    else if (member.compare("course") == 0)
      course = data;
    else if (member.compare("year_and_section") == 0)
      year_and_section = data;
    else if (member.compare("email") == 0)
      email = data;
    else if (member.compare("phone_number") == 0)
      phone_number = data;
    else if (member.compare("notes") == 0)
      notes = data;
    else
      throw std::invalid_argument("Invalid member name.");
  }

  /**
   * @brief Get the member from the string. Helpful for parsing.
   *
   * @param member Get the member from the string.
   * @return std::optional&lang;std::string&rang; Return the member as a string.
   */
  auto get_from_str(std::string member) -> std::optional<std::string>
  {
    if (member.compare("id") == 0)
      return id;
    else if (member.compare("last_name") == 0)
      return last_name;
    else if (member.compare("first_name") == 0)
      return first_name;
    else if (member.compare("middle_name") == 0)
      return middle_name;
    else if (member.compare("suffix") == 0)
      return suffix;
    else if (member.compare("gender") == 0)
      return gender;
    else if (member.compare("birth_day") == 0)
      return std::to_string(birth_day.value());
    else if (member.compare("birth_month") == 0)
      return birth_month;
    else if (member.compare("birth_year") == 0)
      return std::to_string(birth_year.value());
    else if (member.compare("address") == 0)
      return address;
    else if (member.compare("course") == 0)
      return course;
    else if (member.compare("year_and_section") == 0)
      return year_and_section;
    else if (member.compare("email") == 0)
      return email;
    else if (member.compare("phone_number") == 0)
      return phone_number;
    else if (member.compare("notes") == 0)
      return notes;
    else
      throw std::invalid_argument("Invalid member name.");
  }

  void display()
  {
    std::cout << "\t\t\t\t\t------------------------------------"
              << "\n";
    std::cout << "\t\t\t\t\t\tStudent Information"
              << "\n";
    std::cout << "\t\t\t\t\t------------------------------------"
              << "\n";
    std::cout << "\t||            ,%#####%,           || "
              << "\n";
    std::cout << "\t||       *###############%        || "
              << "\n";
    std::cout << "\t||     %#####################%    || "
              << "ID: " << id.value_or("No ID") << "\n";
    std::cout << "\t||    %#################&&#####   || "
              << "Name: " << last_name.value_or("No Last Name")
              << ", " << first_name.value_or("No First Name")
              << " " << middle_name.value_or("No Middle Name") << "\n";
    std::cout << "\t||    ###############&&&&&%#####  || "
              << "Gender: " << gender.value_or("No Gender") << "\n";
    std::cout << "\t||    ##############&&&&&&&###### || "
              << "Birthdate: " << birth_month.value_or("No Birth Month") << " "
              << birth_day.value_or(0) << ", " << birth_year.value_or(0) << "\n";
    std::cout << "\t||    .########&&&&&&&&&&&&#####% || "
              << "Year: " << year_and_section.value_or("No Year and Section") << "\n";
    std::cout << "\t||     #####&&&&&&&&&&&&&&&####%# || "
              << "Course: " << course.value_or("No Course") << "\n";
    std::cout << "\t||     #####&&&&&&&&&&&&&&&####   || "
              << "Email: " << email.value_or("No Email") << "\n";
    std::cout << "\t||    .#%###&&&&&&&&&&&&&&####    || "
              << "Phone Number: " << phone_number.value_or("No Phone Number") << "\n";
    std::cout << "\t||        ####&&&&&&&&&&%##%&     || "
              << "Notes: " << notes.value_or("None") << "\n";
    std::cout << "\t||       .*%%#%&&&&&&&&&#%%%*     || "
              << "\n";
    std::cout << "\t||           #%&%%&&%%%%%         || "
              << "\n";
    std::cout << "\t|| &%#####%####&&&&&&&&&###%######|| "
              << "\n";
    std::cout << "\t||    %%#%%####%&&&&&&&#####%###% || "
              << "\n";
    std::cout << "\t||       %##%###%&&&&&######%%    || "
              << "\n";
    std::cout << "\t||           %###%&&&####%        || "
              << "\n";
  }

  //! TODO: Add a function that will add student from file.
  void add_student_from_file()
  {
    std::ifstream student_file;

    student_file.open("student.txt", std::ios::app);
  }
};

/**
 * @brief Write the student information to a file.
 *
 * @param filename The filename of the file to write to. Preferably in .csv format.
 */
void add_student_prompt(std::string filename)
{
  // Prerequisites:
  // Create a Student Object
  // Create a Student ID
  // Create a Student File

  // Create the variables
  std::string first_nameInput, middle_nameInput, last_nameInput, gender_Input, year_and_sectionInput, courseInput, emailInput, phone_numberInput, notesInput, birth_dayInput, birth_monthInput, birth_yearInput, addressInput, suffixInput;
  bool is_finished = 0;

  // Create a cout that ask for the student information and store it in the class
  while (!is_finished)
  {
    std::cout << "Enter the Student's First Name: ";
    std::cin >> first_nameInput;
    std::cout << "Enter the Student's Middle Name: ";
    std::cin >> middle_nameInput;
    std::cout << "Enter the Student's Last Name: ";
    std::cin >> last_nameInput;
    std::cout << "Enter the Student's Gender: ";
    std::cin >> gender_Input;
    std::cout << "Enter the Student's Birth Day: ";
    std::cin >> birth_dayInput;
    std::cout << "Enter the Student's Birth Month: ";
    std::cin >> birth_monthInput;
    std::cout << "Enter the Student's Birth Year: ";
    std::cin >> birth_yearInput;
    std::cout << "Enter the Student's Address: ";
    std::cin >> addressInput;
    std::cout << "Enter the Student's Course: ";
    std::cin >> courseInput;
    std::cout << "Enter the Student's Year and Section: ";
    std::cin >> year_and_sectionInput;
    std::cout << "Enter the Student's Email: ";
    std::cin >> emailInput;
    std::cout << "Enter the Student's Phone Number: ";
    std::cin >> phone_numberInput;
    std::cout << "Enter the Student's Notes: ";
    std::cin >> notesInput;
    is_finished = 1;
  }
  // Setter Functions

  // Input Error Checking; If the user input 0, then the program will not change the value of the variable
  // Create a file that will store the student information
  std::ofstream addStudent(filename, std::ios::app);
  if (addStudent.fail())
  {
    std::cout << "Error Creating File!"
              << "\n";
    exit(1);
  }
  // Here goes the setters for the functions
  // addStudent << student.get_from_str().value() << std::endl;

  // Write variables to the file
  addStudent << first_nameInput << ", " << last_nameInput << ", " << middle_nameInput << ", " << suffixInput << ", " << gender_Input << ", " << birth_dayInput << ", " << birth_monthInput << ", " << birth_yearInput << ", " << addressInput << ", " << courseInput << ", " << year_and_sectionInput << ", " << emailInput << ", " << phone_numberInput << ", " << notesInput << std::endl;

  std::cout << "Student added successfully"
            << "\n";
  addStudent.close();
}


//! TODO: This needs to be updated to match the new file format.
void ReadStudent(Student student)
{

  std::string first_nameInput, middle_nameInput, last_nameInput, gender_Input, blood_typeInput, year_and_sectionInput, courseInput, emailInput, phone_numberInput, notesInput, birth_monthInput, birth_yearInput, addressInput, suffixInput;

  // std::string last_name, first_name, middle_name, suffix, gender, birth_day, birth_month, birth_year, address, course, year_and_section, email, phone_number, notes;

  // Variables needed to read the file

  std::ifstream readStudent("StudentInfo.txt");
  while (readStudent >> first_nameInput >> last_nameInput >> middle_nameInput >> suffixInput >> gender_Input >> birth_monthInput >> birth_yearInput >> addressInput >> courseInput >> year_and_sectionInput >> emailInput >> phone_numberInput >> notesInput)
  {
    student.set_from_str("first_name", first_nameInput);
    student.set_from_str("last_name", last_nameInput);
    student.set_from_str("middle_name", middle_nameInput);
    student.set_from_str("suffix", suffixInput);
    student.set_from_str("gender", gender_Input);
    student.set_from_str("birth_month", birth_monthInput);
    student.set_from_str("birth_year", birth_yearInput);
    student.set_from_str("address", addressInput);
    student.set_from_str("course", courseInput);
    student.set_from_str("year_and_section", year_and_sectionInput);
    student.set_from_str("email", emailInput);
    student.set_from_str("phone_number", phone_numberInput);
    student.set_from_str("notes", notesInput);
  } // Courtesy of Lem
    // Print all of the values
    // std::cout << student.getFirst_Name() << " " << student.getMiddle_Name() << " " << student.getLast_Name() << " " << student.getBlood_Type() << " " << student.getGender() << " " << student.getSex() << std::endl;
}

//! TODO: This may need to be refactored later.
int PromptUI()
{
  int choice;
  std::cout << "\t\t\t\t\t------------------------------------"
            << "\n";
  std::cout << "\t\t\t\t\t\tStudent Management System"
            << "\n";
  std::cout << "\t\t\t\t\t------------------------------------"
            << "\n";
  std::cout << "\t\t\t\t\t+ 1. Add Student\t\t   +"
            << "\n";
  std::cout << "\t\t\t\t\t+ 2. View Student\t\t   +"
            << "\n";
  std::cout << "\t\t\t\t\t+ 3. Edit Student\t\t   +"
            << "\n";
  std::cout << "\t\t\t\t\t+ 4. Delete Student\t\t   +"
            << "\n";
  std::cout << "\t\t\t\t\t+ 5. Exit\t\t\t   +"
            << "\n";
  std::cout << "\t\t\t\t\t------------------------------------"
            << "\n";
  std::cout << "\t\t\t\t\tAction: $ ";
  std::cin >> choice;
  return choice;
}

auto main() -> int
{
  auto None = std::nullopt;
  auto Ollie = Student("2022M0012", None, "Oliver", "Paracale", None, "Male", 12, "January", 2000, None, None, None, None, None, None);
  auto Manuel = Student();

  Ollie.set_from_str("id", "2022M1111");
  Manuel.set_from_str("first_name", "John Manuel Carado");
  Ollie.set_from_str("last_name", "Ladores");
  std::cout << Ollie.get_from_str("last_name").value_or("No value here.") << std::endl;
  try
  {
    Ollie.set_from_str("invalid", "This should throw an error.");
  }
  catch (std::invalid_argument &e)
  {
    std::cout << e.what() << std::endl;
  }
  Ollie.display();
  return 0;
}
