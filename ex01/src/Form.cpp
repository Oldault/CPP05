/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:23 by oldault           #+#    #+#             */
/*   Updated: 2024/05/09 22:05:31 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string formName, const int signGrade, const int execGrade) :
  _formName(formName),
  _signed(false),
  _signGrade(signGrade),
  _execGrade(execGrade)
{
  return ;
}

Form::~Form()
{
  return ;
}

std::string  Form::getFormName( void ) const
{
  return _formName;
}

bool  Form::isSigned( void ) const
{
  return _signed;
}

int Form::getSignGrade( void ) const
{
  return _signGrade;
}

int Form::getExecGrade( void ) const
{
  return _execGrade;
}

void  Form::beSigned(const Bureaucrat& b)
{
  if (b.getGrade() > _signGrade) {
    throw GradeTooLowException();
  }
  _signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
  os << "Form Name: " << form.getFormName() << ". ";
  if (form.isSigned()) {
    os << " Already signed.";
  } else {
    os << " Not yet signed.";
  }
  os << " Requires a Bureaucrat of Grade: " << form.getSignGrade() << " to be Signed.";
  os << " And a Grade of: " << form.getExecGrade() << " to be executed." << std::endl;

  return os;
}
