#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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

    std::cout << "EX02 : ***********************************************************************" << std::endl;
    try
    {
        std::cout << "--- Work - grade = 100 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat14", 100);
        std::cout << bureaucrat << std::endl;
        ShrubberyCreationForm shrubberyCreationForm("shrubberyCreationForm1");
        std::cout << shrubberyCreationForm << std::endl;
        shrubberyCreationForm.beSign(bureaucrat);
        std::cout << shrubberyCreationForm << std::endl;
        bureaucrat.executeForm(shrubberyCreationForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Fail - grade = 150 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat15", 150);
        std::cout << bureaucrat << std::endl;
        ShrubberyCreationForm shrubberyCreationForm("shrubberyCreationForm2");
        std::cout << shrubberyCreationForm << std::endl;
        shrubberyCreationForm.beSign(bureaucrat);
        std::cout << shrubberyCreationForm << std::endl;
        bureaucrat.executeForm(shrubberyCreationForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- NoExecute - grade = 140 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat16", 140);
        std::cout << bureaucrat << std::endl;
        ShrubberyCreationForm shrubberyCreationForm("shrubberyCreationForm3");
        std::cout << shrubberyCreationForm << std::endl;
        shrubberyCreationForm.beSign(bureaucrat);
        std::cout << shrubberyCreationForm << std::endl;
        bureaucrat.executeForm(shrubberyCreationForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Work - grade = 40 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat17", 40);
        std::cout << bureaucrat << std::endl;
        RobotomyRequestForm robotomyRequestForm("RobotomyRequestForm1");
        std::cout << robotomyRequestForm << std::endl;
        robotomyRequestForm.beSign(bureaucrat);
        std::cout << robotomyRequestForm << std::endl;
        bureaucrat.executeForm(robotomyRequestForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Fail - grade = 150 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat18", 150);
        std::cout << bureaucrat << std::endl;
        RobotomyRequestForm robotomyRequestForm("RobotomyRequestForm2");
        std::cout << robotomyRequestForm << std::endl;
        robotomyRequestForm.beSign(bureaucrat);
        std::cout << robotomyRequestForm << std::endl;
        bureaucrat.executeForm(robotomyRequestForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- NoExecute - grade = 50 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat19", 50);
        std::cout << bureaucrat << std::endl;
        RobotomyRequestForm robotomyRequestForm("RobotomyRequestForm3");
        std::cout << robotomyRequestForm << std::endl;
        robotomyRequestForm.beSign(bureaucrat);
        std::cout << robotomyRequestForm << std::endl;
        bureaucrat.executeForm(robotomyRequestForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Work - grade = 1 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat20", 1);
        std::cout << bureaucrat << std::endl;
        PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm1");
        std::cout << presidentialPardonForm << std::endl;
        presidentialPardonForm.beSign(bureaucrat);
        std::cout << presidentialPardonForm << std::endl;
        bureaucrat.executeForm(presidentialPardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Fail - grade = 150 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat21", 150);
        std::cout << bureaucrat << std::endl;
        PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm2");
        std::cout << presidentialPardonForm << std::endl;
        presidentialPardonForm.beSign(bureaucrat);
        std::cout << presidentialPardonForm << std::endl;
        bureaucrat.executeForm(presidentialPardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- NoExecute - grade = 20 ---" << std::endl;
        Bureaucrat bureaucrat("Bureaucrat22", 20);
        std::cout << bureaucrat << std::endl;
        PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm3");
        std::cout << presidentialPardonForm << std::endl;
        presidentialPardonForm.beSign(bureaucrat);
        std::cout << presidentialPardonForm << std::endl;
        bureaucrat.executeForm(presidentialPardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "EX03 : ***********************************************************************" << std::endl;

    Intern  someRandomIntern;
    Form*   form;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    form = someRandomIntern.makeForm("shrubbery creation", "Mr Garden");
    form = someRandomIntern.makeForm("presidential pardon", "Nobody");
    form = someRandomIntern.makeForm("abc def", "xxxx");

    return 0;
}
