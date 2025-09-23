#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

int main()
{
    std::cout << "== Setup bureaucrats ==" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat senior("Senior", 25);
    Bureaucrat mid("Mid", 50);
    Bureaucrat junior("Junior", 140);

    std::cout << boss << std::endl;
    std::cout << senior << std::endl;
    std::cout << mid << std::endl;
    std::cout << junior << std::endl;

    std::cout << "\n== Create forms ==" << std::endl;
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n== Test signing attempts ==" << std::endl;

    boss.signForm(shrub);    // should sign
    mid.signForm(robo);      // should fail (mid grade too low for robo sign)
    senior.signForm(robo);   // should sign
    junior.signForm(pardon); // should fail (too low)

    std::cout << "\n== State after signing ==" << std::endl;
    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n== Test executing forms ==" << std::endl;

    try
    {
        boss.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "execute shrub failed: " << e.what() << std::endl;
    }

    try
    {
        mid.executeForm(robo);
    }
    catch (std::exception &e)
    {
        std::cout << "execute robo by mid failed: " << e.what() << std::endl;
    }

    try
    {
        senior.executeForm(robo);
    }
    catch (std::exception &e)
    {
        std::cout << "execute robo by senior failed: " << e.what() << std::endl;
    }

    try
    {
        boss.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "execute pardon failed: " << e.what() << std::endl;
    }

    std::cout << "\n== Done tests ==" << std::endl;
    return 0;
}
