/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:23 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 14:41:21 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "TableFormatter.hpp"

Form::Form(const std::string& formName, size_t signGrade, size_t execGrade) :
  _formName(formName),
  _signed(false),
  _signGrade(signGrade),
  _execGrade(execGrade)
{
  if (signGrade < 1 || execGrade < 1) {
    throw Form::GradeTooHighException();
  } else if (signGrade > 150 || execGrade > 150) {
    throw Form::GradeTooLowException();
  }

  return ;
}

Form::Form(const Form &src) :
  _formName(src._formName),
  _signed(src._signed),
  _signGrade(src._signGrade),
  _execGrade(src._execGrade)
{
  return ;
}

Form::~Form() throw()
{
  return ;
}

const Form &Form::operator==(const Form &src)
{
  if (this != &src)
  {
    _signed = src._signed;
  }

  return *this;
}

std::string  Form::getFormName( void ) const
{
  return _formName;
}

bool  Form::isSigned( void ) const
{
  return _signed;
}

size_t Form::getSignGrade( void ) const
{
  return _signGrade;
}

size_t Form::getExecGrade( void ) const
{
  return _execGrade;
}

void  Form::beSigned(Bureaucrat& b)
{
  _signed = b.signForm(*this);

  return ;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
  printHeader(os, "Data about Form", 39);
  formatTable(os, "Form Name:", formatText(form.getFormName()), 34);
  formatTable(os, "Form is signed:", (form.isSigned() ? "✅" : "❌"), 30);
  formatTable(os, "Signing Grade:", form.getSignGrade(), 30);
  formatTable(os, "Execution Grade:", form.getExecGrade(), 28);
  os << "\t+-------------------------------------+\n";

  return os;
}
