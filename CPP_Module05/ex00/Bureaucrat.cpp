#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

Bureaucrat::Bureaucrat() : name(""), grade(150)
{
    //std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string n, int num) : name(n), grade(num)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

const std::string &Bureaucrat::getName() const
{
    return this->name;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    --this->grade;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    ++this->grade;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}
