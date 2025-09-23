#include <iostream>
#include <string>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &n)
    : AForm("ShrubberyCreationForm", 145, 137), target(n) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
    if (!this->getIsSigned())
        throw AForm::AFormNotSignedException();
    if (bureaucrat.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream ofs((this->target + "_shrubbery").c_str());
    if (!ofs)
        return; // fail silently or could throw

    ofs << "       _-_       " << std::endl;
    ofs << "    /~~   ~~\\    " << std::endl;
    ofs << " /~~         ~~\\ " << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\ //  ~" << std::endl;
    ofs << "_- -   | | _- _" << std::endl;
    ofs << "  _ -  | |   -_" << std::endl;
    ofs << "      // \\\\" << std::endl;

    ofs.close();
}