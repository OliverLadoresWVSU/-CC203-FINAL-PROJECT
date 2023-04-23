//! This is the implementation for the Student class.

#include <string>

class Student {
private:
  unsigned int id, phone_number;
  std::string name, gender, course, email, year_and_section, notes;

public:
  //! Constructor for Student class.
  Student(const unsigned int idInput, const unsigned int phone_numberInput,
          const std::string nameInput, const std::string genderInput,
          const std::string courseInput, const std::string emailInput,
          const std::string year_and_sectionInput, const std::string notesInput)
      : id(idInput), phone_number(phone_numberInput), name(nameInput),
        gender(genderInput), course(courseInput), email(emailInput),
        year_and_section(year_and_sectionInput), notes(notesInput) {}
};

auto main() -> int { return 0; }
