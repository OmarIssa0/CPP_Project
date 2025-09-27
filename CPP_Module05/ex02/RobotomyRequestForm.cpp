#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <stdexcept>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm Parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
    if (!this->getIsSigned())
        throw AForm::AFormNotSignedException();
    if (bureaucrat.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Bzzzz... drilling noises for " << this->target << std::endl;
}
