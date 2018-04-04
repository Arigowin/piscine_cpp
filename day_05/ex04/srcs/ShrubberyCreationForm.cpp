#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
{
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned() || this->getGradeExecut() < executor.getGrade())
        return false;

    std::ofstream file(this->_target + "_shrubbery");

    file << "              _{\\ _{\\{\\/}/}/}__";
    file << "\n             {/{/\\}{/{/\\}(\\}{/\\} _";
    file << "\n            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _";
    file << "\n         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}";
    file << "\n        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}";
    file << "\n       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}";
    file << "\n      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}";
    file << "\n      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}";
    file << "\n     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}";
    file << "\n      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}";
    file << "\n       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)";
    file << "\n      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}";
    file << "\n       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}";
    file << "\n         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}";
    file << "\n          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)";
    file << "\n            {/{/{\\{\\/}{/{\\{\\{\\(_)/}";
    file << "\n             {/{\\{\\{\\/}/}{\\{\\\\}/}";
    file << "\n              {){/ {\\/}{\\/} \\}\\}";
    file << "\n              (_)  \\.-'.-/";
    file << "\n          __...--- |'-.-'| --...__";
    file << "\n   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__";
    file << "\n -\"    ' .  . '    |.'-._| '  . .  '   . ' \"";
    file << "\n .  '-  '    .--'  | '-.'|    .  '  . '";
    file << "\n          ' ..     |'-_.-|";
    file << "\n  .  '  .       _.-|-._ -|-._  .  '  .";
    file << "\n              .'   |'- .-|   '.";
    file << "\n  ..-'   ' .  '.   `-._.-´   .'  '  - .";
    file << "\n   .-' '        '-._______.-'     '  .";
    file << "\n        .      ~,";
    file << "\n    .       .   ,.    .    ' '-.\n";
    file.close();

    return true;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    (void)rhs;
    return *this;
}
