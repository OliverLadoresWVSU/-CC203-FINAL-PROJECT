/**
 * @file student.cpp
 * @author Oliver Ladores (oliver.ladores@wvsu.edu.ph)
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
    std::cout << "\t\t\t\t\t------------------------------------" << "\n";
    std::cout << "\t\t\t\t\t\tStudent Information" << "\n";
    std::cout << "\t\t\t\t\t------------------------------------" << "\n";
    std::cout << "\t||            ,%#####%,           || " << "\n";
    std::cout << "\t||       *###############%        || " << "\n";
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
    std::cout << "\t||       .*%%#%&&&&&&&&&#%%%*     || " << "\n";
    std::cout << "\t||           #%&%%&&%%%%%         || " << "\n";
    std::cout << "\t|| &%#####%####&&&&&&&&&###%######|| " << "\n";
    std::cout << "\t||    %%#%%####%&&&&&&&#####%###% || " << "\n";
    std::cout << "\t||       %##%###%&&&&&######%%    || " << "\n";
    std::cout << "\t||           %###%&&&####%        || " << "\n";
  }
};

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
