/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:23 by oldault           #+#    #+#             */
/*   Updated: 2024/05/12 10:02:01 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iomanip>
#include <string>

#define BOLDB(text) "\033[1m" << text << "\033[0m"

Form::Form(const std::string& formName, int signGrade, int execGrade) :
  _formName(formName),
  _signed(false),
  _signGrade(signGrade),
  _execGrade(execGrade)
{
  return ;
}

Form::~Form() throw()
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

void  Form::beSigned(Bureaucrat& b)
{
  _signed = b.signForm(*this);

  return ;
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

std::ostream& operator<<(std::ostream& os, const Form& form)
{
  printHeaderF(os, "Data about Form");
  formatTableF(os, "Form Name:", formatTextF(form.getFormName()), 34);
  formatTableF(os, "Form is signed:", (form.isSigned() ? "✅" : "❌"), 30);
  formatTableF(os, "Signing Grade:", form.getSignGrade(), 30);
  formatTableF(os, "Execution Grade:", form.getExecGrade(), 28);
  os << "\t+-------------------------------------+\n";

  return os;
}
