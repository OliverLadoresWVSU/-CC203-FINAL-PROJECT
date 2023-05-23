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

class Student {
private:
  std::optional<std::string> id, last_name, first_name, middle_name, suffix, gender, course, year_and_section, email,
      phone_number, notes;

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
          const std::optional<std::string> courseInput = std::nullopt,
          const std::optional<std::string> year_and_sectionInput = std::nullopt,
          const std::optional<std::string> emailInput = std::nullopt,
          const std::optional<std::string> phone_numberInput = std::nullopt,
          const std::optional<std::string> notesInput = std::nullopt)
      : id(idInput), last_name(last_nameInput), first_name(first_nameInput), middle_name(middle_nameInput), suffix(suffixInput), gender(genderInput), course(courseInput),
        year_and_section(year_and_sectionInput), email(emailInput),
        phone_number(phone_numberInput), notes(notesInput) {}

  /**
   * @brief Sets the members based on the arguments. We have to implement it this way cause we want to access the private members.
   *
   * @param member The member to modify.
   * @param data The data to set the member to.
   */
  void set(std::string member, std::optional<std::string> data) {
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

  auto get(std::string member) -> std::optional<std::string> {
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
};

auto main() -> int {
  auto None = std::nullopt;
  auto Ollie = Student("2022M0012", None, "Oliver");
  auto Manuel = Student();

  Ollie.set("id", "2022M1111");
  Manuel.set("first_name", "John Manuel Carado");
  // Ollie.set("last_name", "Ladores");
  std::cout << Ollie.get("last_name").value_or("No value here.") << std::endl;
  try {
    Ollie.set("invalid", "This should throw an error.");
  } catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
