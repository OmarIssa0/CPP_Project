#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>
int main() {
  Intern intern;
 
  AForm *form1 = intern.makeForm("shrubbery creation", "home");
  AForm *form2 = intern.makeForm("robotomy request", "Bender");
  AForm *form3 = intern.makeForm("presidential pardon", "Ford");
  AForm *form4 = intern.makeForm("invalid form", "Nobody");
 
  delete form1;
  delete form2;
  delete form3;
  delete form4;
 
  return 0;
}