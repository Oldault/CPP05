/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:23 by oldault           #+#    #+#             */
/*   Updated: 2024/05/10 11:15:09 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iomanip>
#include <string>

#define BOLDB(text) "\033[1m" << text << "\033[0m"

AForm::AForm(const std::string& formName, int signGrade, int execGrade) :
  _formName(formName),
  _signed(false),
  _signGrade(signGrade),
  _execGrade(execGrade)
{
  return ;
}

AForm::~AForm() throw()
{
  return ;
}

std::string  AForm::getFormName( void ) const
{
  return _formName;
}

bool  AForm::isSigned( void ) const
{
  return _signed;
}

int AForm::getSignGrade( void ) const
{
  return _signGrade;
}

int AForm::getExecGrade( void ) const
{
  return _execGrade;
}

void AForm::setToSigned( void )
{
  _signed = true;
}

std::string AFormatText(const std::string& text)
{
	unsigned int maxLen = 18;
  return text.size() > maxLen ? text.substr(0, maxLen - 1) + '.' : text;
}

std::ostream& AFormatTable(std::ostream& os, const std::string& left, const std::string& right, int w)
{
  os << "\t| " << std::left << std::setw(5) << BOLDB(left)
    << std::right << std::setw(w) << right << " |" << std::endl;
  
  return os;
}

std::ostream& AFormatTable(std::ostream& os, const std::string& left, int right, int w)
{
  os << "\t| " << std::left << std::setw(5) << BOLDB(left)
    << std::right << std::setw(w) << right << " |" << std::endl;
  
  return os;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
  os << "\n\t+--------------------------------------+\n";
  AFormatTable(os, "Form Name:", AFormatText(AForm.getFormName()), 25);
  AFormatTable(os, "Form is signed:", (AForm.isSigned() ? "✅" : "❌"), 21);
  AFormatTable(os, "Signing Grade:", AForm.getSignGrade(), 21);
  AFormatTable(os, "Execution Grade:", AForm.getExecGrade(), 19);
  os << "\t+--------------------------------------+\n\n";

  return os;
}
