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

bool  AForm::canBeSigned(Bureaucrat& b)
{
  return (b.getGrade() >= getSignGrade());
}

bool  AForm::canBeExecuted(const Bureaucrat& b)
{
  return (b.getGrade() >= getExecGrade());
}



std::string formatTextF(const std::string& text)
{
	unsigned int maxLen = 18;
  return text.size() > maxLen ? text.substr(0, maxLen - 1) + '.' : text;
}

std::ostream& formatTableF(std::ostream& os, const std::string& left, const std::string& right, int w)
{
  os << "\t| " << std::left << std::setw(5) << BOLD(left)
    << std::right << std::setw(w) << FCYN(right) << " |" << std::endl;
  
  return os;
}

std::ostream& formatTableF(std::ostream& os, const std::string& left, int right, int w)
{
  os << "\t| " << std::left << std::setw(5) << BOLD(left)
    << std::right << std::setw(w) << FCYN(right) << " |" << std::endl;
  
  return os;
}

std::ostream& printHeaderF(std::ostream& os, std::string title)
{
  os << "\t+-------------------------------------+\n";
  os << "\t|\t" << FCYN(BOLD(title)) << "\t\t      |\n";
  os << "\t+-------------------------------------+\n";

  return os;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
  printHeaderF(os, "Data about Form");
  formatTableF(os, "Form Name:", formatTextF(form.getFormName()), 34);
  formatTableF(os, "Form is signed:", (form.isSigned() ? "✅" : "❌"), 30);
  formatTableF(os, "Signing Grade:", form.getSignGrade(), 30);
  formatTableF(os, "Execution Grade:", form.getExecGrade(), 28);
  os << "\t+-------------------------------------+\n";

  return os;
}
