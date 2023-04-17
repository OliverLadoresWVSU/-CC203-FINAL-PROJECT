# To-do for CC203 Project

## Student Management System

### Oliver

- [ ] Make a class representing a student.
    - [ ] Define its members.
    - [ ] Constructor takes a name and ID.
    - [ ] Other fields/values are optional `std::optional`.
    - [ ] Export as module.
- [ ] Create a file reader.
    - [ ] Reads the students from a directory (Each student has its own text file *student*.txt).
    - [ ] Parses it into a vector of students.

~Add additional ideas after this line~

### Dhominick

1. Student Management System Backend
    - [ ]  Class for the Name for the Student
    - [ ]  Define the Functions to Call for the Students
    - [ ] Define a Unique Identifier for the Students based on their ID
        - [ ] Define an ID Pattern Reading using CString
2. Features for the Program
    - [ ] Grades
    - [ ] Attendance
    - [ ] Calendar System for the Year
3. Security
    - [ ] Username & Password
    - [ ] Automatic Detect the Type of User based on the Credentials


### Cristopher

1. Login
    - [ ] Student or Administrator
    - [ ] Credentials
    - [ ] Credentials should be correct as read in the credential file
2. Add or View Students
    - [ ] Add Students will direct to create new student and their credentials will be filled up. then, saved onto a .txt file
    - [ ] View Students will direct to the Student Management System
    - [ ] These mechanics will be exclusive for the Administrator
3. Mechanics for Student Management System
    - [ ] Student can only view their own student credentials
    - [ ] Adminsitrator may edit the student credentials and View more than 1 student account

## Style Guide

- Two space indentation (can set it in VSCode, ask Ollie).
- (Up for contention) Trailing function return type. <mark> Probably after finishing the core concept? </mark>

## Student File Format

In student file (ignoring[], prefixed with * is required):

[ID]
[Name]
[Gender]
[Year]
[Course]
[Email]
[Mobile Number]
[Section]
[Notes]

