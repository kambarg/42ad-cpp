/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 04:20:49 by gkambarb          #+#    #+#             */
/*   Updated: 2026/05/14 04:20:52 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
	: _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form(void)
{
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Grade too high!";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Grade too low!";
}

const std::string &Form::getName(void) const
{
	return _name;
}

bool Form::getIsSigned(void) const
{
	return _signed;
}

int Form::getGradeToSign(void) const
{
	return _gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName()
		<< ", sign grade " << form.getGradeToSign()
		<< ", execute grade " << form.getGradeToExecute()
		<< ", " << (form.getIsSigned() ? "signed" : "not signed");
	return out;
}
