#include "Bureaucrat.hpp"
#include "Form.hpp"

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

    std::cout << "EX01 : ***********************************************************************" << std::endl;
    try
    {
        std::cout << "--- Fail - grade = 20, gradeSign = 5, gradeExecut = 5 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat8", 20);
        std::cout << bureaucrat << std::endl;
        Form form("Form1", 5, 5);
        std::cout << form << std::endl;
        form.beSign(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Work - grade = 1, gradeSign = 5, gradeExecut = 5 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat9", 1);
        std::cout << bureaucrat << std::endl;
        Form form("Form2", 5, 5);
        std::cout << form << std::endl;
        form.beSign(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Fail - grade = 1, gradeSign = -50, gradeExecut = 5 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat10", 1);
        std::cout << bureaucrat << std::endl;
        Form form("Form3", -50, 5);
        std::cout << form << std::endl;
        form.beSign(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Fail - grade = 1, gradeSign = 200, gradeExecut = 5 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat11", 1);
        std::cout << bureaucrat << std::endl;
        Form form("Form4", 200, 5);
        std::cout << form << std::endl;
        form.beSign(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Fail - grade = 1, gradeSign = 5, gradeExecut = -50 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat12", 1);
        std::cout << bureaucrat << std::endl;
        Form form("Form5", 5, -50);
        std::cout << form << std::endl;
        form.beSign(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Fail - grade = 1, gradeSign = 5, gradeExecut = 200 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat13", 1);
        std::cout << bureaucrat << std::endl;
        Form form("Form6", 5, 200);
        std::cout << form << std::endl;
        form.beSign(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
