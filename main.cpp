/*
Project info
Employee Payroll System:
 - Design classes for employees, departments, and payrolls, HR.
 - Implement functionalities like calculating salaries, adding new employees,
and displaying payroll information.
*/
#include <iostream>
#include <string>

using namespace std;

// Declaring the classes in case needed
class Departments;
class Payroll;
class HR;

class Employee {
public:
  string name;
  int id;
  string department;
  string email;
  double payrate;

  Employee *next;
  static Employee *head;

  // constructor with parameters
  Employee(string name, int id, string email, double payrate,
           string department = "none")
      : name(name), id(id), department(department), email(email),
        payrate(payrate), next(nullptr) {
    this->next = head;
    head = this;
    cout << "\nEmployee " << name << " added successfully" << endl;
  }

  // destructor
  ~Employee() {
    // cout << "\nEmployee " << name << " removed successfully" << endl;

    if (this == head) {
      head = head->next;
    } else {
      Employee *current = head;
      while (current != nullptr && current->next != this) {
        current = current->next;
      }
      if (current != nullptr) {
        current->next = this->next;
      }
    }
  }

  // Getter for all property
  string getName() { return name; }
  int getId() { return id; }
  string getDepartment() { return department; }
  string getEmail() { return email; }
  double getPayrate() { return payrate; }
  // Setter for all property
  void setName(string name) { this->name = name; }
  void setId(int id) { this->id = id; }
  void setDepartment(string department) { this->department = department; }
  void setEmail(string email) { this->email = email; }
  void setPayrate(double payrate) { this->payrate = payrate; }

  // Function to display employee details
  void personal_Information() {
    cout << endl;
    cout << "Employee personal Information: " << endl;
    cout << "   Name: " << name << endl;
    cout << "   ID: " << id << endl;
    cout << "   Deparment: " << department << endl;
    cout << "   Email: " << email << endl;
    cout << "   Payrate: " << payrate << endl;
  }

  // Functoin to display basic emplyee information
  void employee_Information() {
    cout << "-  ID: " << id << endl;
    cout << "   Name: " << name << endl;
    cout << "   Deparment: " << department << endl;
  }
};

// Initialize the static head pointer
Employee *Employee::head = nullptr;

class Departments {
public:
  // add employee to department
  void addEmployeeToDepartment(Employee &employee, string dept) {
    cout << "\nAssigning employee " << employee.name
         << " to department: " << dept << endl;
    employee.department = dept;
  }
};

class HR {
public:
  static void employeeList() {
    Employee *current = Employee::head;
    cout << endl;
    cout << "Employee List: " << endl;
    while (current != nullptr) {
      current->employee_Information();//call from employee class
      cout << endl;
      current = current->next;
    }
  }
};

class Payroll {
public:
  // Calculate salary by multiplying payrate and hours worked
  void calculateSalary(Employee &emp, int hoursWorked) {

    double newSalary = emp.getPayrate() * hoursWorked;
    cout << "\nPayroll Information:\n";
    emp.employee_Information();
    cout << "   Working hours: " << hoursWorked << endl;
    cout << "   Monthly Salary: " << newSalary << endl;
  }
};

int main() {
  Payroll payroll;
  Departments depts;
  HR hr;
  
  Employee emp1("Ema", 1, "ema@example.com", 200);
  Employee emp3("Rafay", 2, "rafay@example.com", 250);
  Employee emp4("Tuhin", 3, "tuhin@example.com", 200);
  Employee emp2("Tasmim", 4, "tasmim@example.com", 300);
  
  depts.addEmployeeToDepartment(emp1, "IT");//adding employee to a department

  emp1.personal_Information();//printing employee information

  payroll.calculateSalary(emp1, 40);//calculating salary of employee 1

  hr.employeeList();//printing employee list
  
  return 0;
}