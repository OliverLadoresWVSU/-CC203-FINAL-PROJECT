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

class Student {
private:
  std::optional<std::string> id, name, gender, course, year_and_section, email,
      phone_number, notes;

public:
  /**
   * @brief Construct a new Student object.
   *
   * All arguments default to std::nullopt when no input is given.
   */
  Student(const std::optional<std::string> idInput = std::nullopt,
          const std::optional<std::string> nameInput = std::nullopt,
          const std::optional<std::string> genderInput = std::nullopt,
          const std::optional<std::string> courseInput = std::nullopt,
          const std::optional<std::string> year_and_sectionInput = std::nullopt,
          const std::optional<std::string> emailInput = std::nullopt,
          const std::optional<std::string> phone_numberInput = std::nullopt,
          const std::optional<std::string> notesInput = std::nullopt)
      : id(idInput), name(nameInput), gender(genderInput), course(courseInput),
        year_and_section(year_and_sectionInput), email(emailInput),
        phone_number(phone_numberInput), notes(notesInput) {}

  /**
   * @brief Sets the members based on the arguments.
   *
   * @param member The member to modify.
   * @param data The data to set the member to.
   */
  void set(std::string member, std::optional<std::string> data) {
    if (member.compare("id") == 0)
      id = data;
    else if (member.compare("name") == 0)
      name = data;
  }
};

auto main() -> int {
  auto Ollie = Student("2022M0012", "Oliver Ladores", "Male");
  auto Manuel = Student();

  Ollie.set("id", "2022M1111");
  Manuel.set("name", "John Manuel Carado");
  return 0;
}
