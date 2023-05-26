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
#include <sstream>
#include <filesystem>

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

  /**
   * @brief Display the student information.
   *
   */
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
              << " " << middle_name.value_or("No Middle Name")
              << " " << suffix.value_or("") << "\n";
    std::cout << "\t||    ###############&&&&&%#####  || "
              << "Gender: " << gender.value_or("No Gender") << "\n";
    std::cout << "\t||    ##############&&&&&&&###### || "
              << "Birthdate: " << birth_month.value_or("No Birth Month") << " "
              << birth_day.value_or(0) << ", " << birth_year.value_or(0) << "\n";
    std::cout << "\t||    .########&&&&&&&&&&&&#####% || "
              << "Address: " << address.value_or("No Address") << "\n";
    std::cout << "\t||     #####&&&&&&&&&&&&&&&####%# || "
              << "Year: " << year_and_section.value_or("No Year and Section") << "\n";
    std::cout << "\t||     #####&&&&&&&&&&&&&&&####   || "
              << "Course: " << course.value_or("No Course") << "\n";
    std::cout << "\t||    .#%###&&&&&&&&&&&&&&####    || "
              << "Email: " << email.value_or("No Email") << "\n";
    std::cout << "\t||        ####&&&&&&&&&&%##%&     || "
              << "Phone Number: " << phone_number.value_or("No Phone Number") << "\n";
    std::cout << "\t||       .*%%#%&&&&&&&&&#%%%*     || "
              << "Notes: " << notes.value_or("None") << "\n";
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

  /**
   * @brief Read the student information from a file. Set the instance variables to the values read from the file.
   *
   * @param filename Name of file to read the student information from. The file name is the Surname of the Student.
   */
  void read_from_file(std::string filename)
  {
    std::ifstream student_file(filename, std::ios::in);

    if (student_file.fail()) // Changed error checking method since it always returns true.
      std::cout << "Failed to open file.\n";
    else
    {
      std::string line;
      std::vector<std::string> tokens;
      tokens.reserve(15);
      while (std::getline(student_file, line))
      {
        std::istringstream iss(line);
        std::string token;
        while (std::getline(iss, token, ','))
        {
          tokens.push_back(token);
        }
      }
      id = tokens[0];
      first_name = tokens[1];
      last_name = tokens[2];
      middle_name = tokens[3];
      suffix = tokens[4];
      gender = tokens[5];
      birth_day = std::stoi(tokens[6]);
      birth_month = tokens[7];
      birth_year = std::stoi(tokens[8]);
      address = tokens[9];
      course = tokens[10];
      year_and_section = tokens[11];
      email = tokens[12];
      phone_number = tokens[13];
      notes = tokens[14];
    }
    student_file.close();
  }

  void edit_student() {
  std::string member, data;
  std::string filename;
  filename = "./Students_Info/" + last_name.value() + ".csv";
  std::cout << "Student information to edit: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, member);
  std::cout << "Data to enter: ";
  std::getline(std::cin, data);
  try
  {
    set_from_str(member, data);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  std::ofstream addStudent(filename, std::ios::out);
  if (addStudent.fail())
  {
    std::cout << "Error Creating File!"
              << "\n";
    addStudent.close();
    throw std::runtime_error("Error Creating File!");
  }

  addStudent << id.value_or("") << "," << first_name.value_or("") << "," << last_name.value_or("") << "," << middle_name.value_or("") << "," << suffix.value_or("") << "," << gender.value_or("") << "," << birth_day.value() << "," << birth_month.value_or("") << "," << birth_year.value() << "," << address.value_or("") << "," << course.value_or("") << "," << year_and_section.value_or("") << "," << email.value_or("") << "," << phone_number.value_or("") << "," << notes.value_or("") << std::endl;

  std::cout << "Student edited successfully.\n";
}
};

/**
 * @brief Write the student information to a file.
 *
 * File is formatted as follows: id, first_name, last_name, middle_name, suffix, gender, birth_day, birth_month, birth_year, address, course, year_and_section, email, phone_number, notes
 */
void prompt_student() // Accessed Parameters from the Student Class no filename needed since the file name would be the student's last name.
{
  std::string idInput, first_nameInput, middle_nameInput, last_nameInput, genderInput, year_and_sectionInput, courseInput, emailInput, phone_numberInput, notesInput, birth_dayInput, birth_monthInput, birth_yearInput, addressInput, suffixInput, filename;
  bool is_finished = 0;

  // Prompt the user for the student's information.
  while (!is_finished)
  {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the Student's ID: ";
    std::getline(std::cin, idInput); // Error when trying to write
    std::cout << "Enter the Student's First Name: ";
    std::getline(std::cin, first_nameInput);
    std::cout << "Enter the Student's Middle Name: ";
    std::getline(std::cin, middle_nameInput);
    std::cout << "Enter the Student's Last Name: ";
    std::getline(std::cin, last_nameInput); // Since using getline allows spaces, why not just use enter full name with Spaces?
    std::cout << "Enter the Student's Suffix: ";
    std::getline(std::cin, suffixInput);
    std::cout << "Enter the Student's Gender: ";
    std::getline(std::cin, genderInput);
    std::cout << "Enter the Student's Birth Day: ";
    std::getline(std::cin, birth_dayInput);
    std::cout << "Enter the Student's Birth Month: ";
    std::getline(std::cin, birth_monthInput);
    std::cout << "Enter the Student's Birth Year: ";
    std::getline(std::cin, birth_yearInput);
    std::cout << "Enter the Student's Address: ";
    std::getline(std::cin, addressInput);
    std::cout << "Enter the Student's Course: ";
    std::getline(std::cin, courseInput);
    std::cout << "Enter the Student's Year and Section: ";
    std::getline(std::cin, year_and_sectionInput);
    std::cout << "Enter the Student's Email: ";
    std::getline(std::cin, emailInput);
    std::cout << "Enter the Student's Phone Number: ";
    std::getline(std::cin, phone_numberInput);
    std::cout << "Enter the Student's Notes: ";
    std::getline(std::cin, notesInput);
    is_finished = 1;
  }

  // Open the file to write to.
  // filename = last_nameInput + ".csv";
  if (!std::filesystem::exists("./Students_Info"))
  {
    std::filesystem::create_directories("./Students_Info");
  }
  filename = "./Students_Info/" + last_nameInput + ".csv";
  std::ofstream addStudent(filename, std::ios::app);
  if (addStudent.fail())
  {
    std::cout << "Error Creating File!"
              << "\n";
    addStudent.close();
    throw std::runtime_error("Error Creating File!");
  }

  // Write the student's information to the file, pero dw no need na run mn ang delims pay? since automatic na si CSV ga input ka file name na .csv
  addStudent << idInput << "," << first_nameInput << "," << last_nameInput << "," << middle_nameInput << "," << suffixInput << "," << genderInput << "," << birth_dayInput << "," << birth_monthInput << "," << birth_yearInput << "," << addressInput << "," << courseInput << "," << year_and_sectionInput << "," << emailInput << "," << phone_numberInput << "," << notesInput << std::endl;

  std::cout << "Student added successfully. Saved as " << last_nameInput << ".csv in ./Students_Info."
            << "\n";
  addStudent.close();
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
  // auto None = std::nullopt;
  // auto Ollie = Student("2022M0012", None, "Oliver", "Paracale", None, "Male", 12, "January", 2000, None, None, None, None, None, None);
  // auto Manuel = Student();

  // auto StudentObj = Student();
  Student StudentObj;

  // Variable Declarations
  int choice;
  std::string filename;

  // Ollie.set_from_str("id", "2022M1111");
  // Manuel.set_from_str("first_name", "John Manuel Carado");
  // Ollie.set_from_str("last_name", "Ladores");
  // std::cout << Ollie.get_from_str("last_name").value_or("No value here.") << std::endl;
  // try
  // {
  //   Ollie.set_from_str("invalid", "This should throw an error.");
  // }
  // catch (std::invalid_argument &e)
  // {
  //   std::cout << e.what() << std::endl;
  // }
  // Ollie.display();
  // return 0;

  // Create the Actual File Object and Reading of the File
  choice = PromptUI();
  switch (choice)
  {
  case 1:
    prompt_student();
    break;
  case 2:
    std::cout << "Student Name to Access: ";
    std::cin >> filename;
    filename = "./Students_Info/" + filename + ".csv";
    StudentObj.read_from_file(filename);
    StudentObj.display();
    break;
  case 3:
    std::cout << "Student Name to Edit: ";
    std::cin >> filename;
    filename = "./Students_Info/" + filename + ".csv";
    StudentObj.read_from_file(filename);
    StudentObj.display();
    StudentObj.edit_student();
    StudentObj.display();
    break;
  case 4:
    std::cout << "Student Name to Delete: ";
    std::cin >> filename;
    filename = "./Students_Info/" + filename + ".csv";
    if(std::filesystem::remove(filename))
    {
      std::cout << "Student successfully deleted.";
    }
    else
    {
      std::cout << "Student unsuccessfully deleted";
    }
    
    break;
  case 5:
    std::cout << "Exiting..."
              << "\n";
    break;
  default:
    std::cout << "Invalid Input!"
              << "\n";
    break;
  }
}
