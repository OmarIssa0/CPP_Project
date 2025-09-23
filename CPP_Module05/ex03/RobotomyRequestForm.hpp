#include "AForm.hpp"
#include <string>
#include <iostream>

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();
        // ! Override 
        void execute(Bureaucrat const &bureaucrat) const;
};

#endif