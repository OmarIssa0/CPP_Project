#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("") {};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &n)
    : AForm("ShrubberyCreationForm", 145, 137), target(n) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {};

ShrubberyCreationForm &operator(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat)
{
}