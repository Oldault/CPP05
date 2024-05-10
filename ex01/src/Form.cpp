/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:23 by oldault           #+#    #+#             */
/*   Updated: 2024/05/10 10:16:03 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iomanip>
#include <string>

#define BOLDB(text) "\033[1m" << text << "\033[0m"

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


std::string formatText(const std::string& text)
{
	unsigned int maxLen = 18;
  return text.size() > maxLen ? text.substr(0, maxLen - 1) + '.' : text;
}

std::ostream& formatTable(std::ostream& os, const std::string& left, const std::string& right, int w)
{
  os << "\t| " << std::left << std::setw(5) << BOLDB(left)
    << std::right << std::setw(w) << right << " |" << std::endl;
  
  return os;
}

std::ostream& formatTable(std::ostream& os, const std::string& left, int right, int w)
{
  os << "\t| " << std::left << std::setw(5) << BOLDB(left)
    << std::right << std::setw(w) << right << " |" << std::endl;
  
  return os;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
  os << "\t+--------------------------------------+\n";
  formatTable(os, "Form Name:", formatText(form.getFormName()), 25);
  formatTable(os, "Form is signed:", (form.isSigned() ? "✅" : "❌"), 21);
  formatTable(os, "Signing Grade:", form.getSignGrade(), 21);
  formatTable(os, "Execution Grade:", form.getExecGrade(), 19);
  os << "\t+--------------------------------------+" << std::endl;

  return os;
}
