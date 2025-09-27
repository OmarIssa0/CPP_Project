#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat junior("Junior", 120);
    Bureaucrat mid("MidLevel", 50);

    std::cout << "\n=== staff ===\n";
    std::cout << boss << std::endl;
    std::cout << mid << std::endl;
    std::cout << junior << std::endl;

    Form topSecret("TopSecret", false, 5, 10);
    Form standard("StandardForm", false, 50, 50);
    Form easy("EasyForm", false, 150, 150);

    std::cout << "\n=== Form before sign ===\n";
    std::cout << topSecret << std::endl;
    std::cout << standard << std::endl;
    std::cout << easy << std::endl;

    std::cout << "\n=== Test Sign Form ===\n";

    // Done
    boss.signForm(topSecret);
    // X
    mid.signForm(topSecret);
    mid.signForm(standard);
    junior.signForm(easy);

    std::cout << "\n=== Form After Sign ===\n";
    std::cout << topSecret << std::endl;
    std::cout << standard << std::endl;
    std::cout << easy << std::endl;

    try
    {
        Bureaucrat invalid("Invalid", 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat tooLow("TooLow", 200);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
