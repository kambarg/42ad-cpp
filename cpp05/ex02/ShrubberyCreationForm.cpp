#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

static void writeTree(std::ofstream &out)
{
	out << "               ###\n";
	out << "              #o###\n";
	out << "            #####o###\n";
	out << "           #o#\\#|#/###\n";
	out << "            ###\\|/#o#\n";
	out << "             # }|{  #\n";
	out << "               }|{\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExecution(executor);
	std::ofstream out((_target + "_shrubbery").c_str());
	if (!out)
		return;
	writeTree(out);
}
