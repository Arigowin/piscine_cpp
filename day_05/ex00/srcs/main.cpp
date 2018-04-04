#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "EX00 : ***********************************************************************" << std::endl;
    try
    {
        std::cout << "--- Fail - grade = 200 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat1", 200);
        std::cout << bureaucrat << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Fail - grade = -50 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat2", -50);
        std::cout << bureaucrat << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Work - grade = 10 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat3", 10);
        std::cout << bureaucrat << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Fail - grade = 1 - Increment ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat4", 1);
        std::cout << bureaucrat << std::endl;
        bureaucrat.incGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Fail - grade = 150 - Decrement ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat5", 150);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Work - grade = 20 - Increment ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat6", 20);
        std::cout << bureaucrat << std::endl;
        bureaucrat.incGrade();
        std::cout << bureaucrat << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Work - grade = 20 - Decrement ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat7", 20);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decGrade();
        std::cout << bureaucrat << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
