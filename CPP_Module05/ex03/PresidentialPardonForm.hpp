#include "AForm.hpp"
#include <string>
#include <iostream>

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();
        // ! Override 
        void execute(Bureaucrat const &bureaucrat) const;
};

#endif