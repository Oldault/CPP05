/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:44 by oldault           #+#    #+#             */
/*   Updated: 2024/05/14 17:31:35 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iomanip>
#include <string>
#include <iostream>
#include <sstream>

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
  _name(name)
{ 
  if (grade < HIGHEST_GRADE) {
    throw GradeTooHighException();
  } else if (grade > LOWEST_GRADE) {
    throw GradeTooLowException();
  }
  _grade = grade;

  std::cout << FGRN("Bureaucrat named ")
  << FGRN(BOLD(_name)) << FGRN(", grade: ")
  << FGRN(UNDL(_grade)) << FGRN(" Created.") << std::endl;

  return ;
}

Bureaucrat::~Bureaucrat( void ) throw()
{
  return ;
}

const std::string Bureaucrat::getName( void ) const
{
  return _name;
}

int Bureaucrat::getGrade( void ) const
{
  return _grade;
}

bool  Bureaucrat::signForm(AForm& form)
{
  if (_grade > form.getSignGrade())
  {
    std::cerr << FRED(BOLD(_name)) << FRED(", couldn't sign \"") << FRED(UNDL( form.getFormName())) << FRED("\". Because: ")<< std::endl;
    throw GradeTooLowException();
  }
  std::cout << FGRN(BOLD(_name)) << FGRN(", successfully signed ") << FGRN(UNDL(form.getFormName())) << std::endl;
  return true;
}

bool  Bureaucrat::executeForm(AForm& form)
{
  if (_grade > form.getExecGrade())
  {
    std::cerr << FRED(BOLD(_name)) << FRED(", couldn't execute \"") << FRED(UNDL( form.getFormName())) << FRED("\". Because: ")<< std::endl;
    throw GradeTooLowException();
  }
  std::cout << FGRN(BOLD(_name)) << FGRN(", successfully executed ") << FGRN(UNDL(form.getFormName())) << std::endl;
  return true;
}

std::string formatText(const std::string& text)
{
	unsigned int maxLen = 18;
  return text.size() > maxLen ? text.substr(0, maxLen - 1) + '.' : text;
}

std::ostream& formatTable(std::ostream& os, const std::string& left, const std::string& right, int w)
{
  os << "\t| " << std::left << std::setw(5) << BOLD(left)
    << std::right << std::setw(w) << FMAG(right) << " |" << std::endl;
  
  return os;
}

std::ostream& formatTable(std::ostream& os, const std::string& left, int right, int w)
{
  os << "\t| " << std::left << std::setw(5) << BOLD(left)
    << std::right << std::setw(w) << FMAG(right) << " |" << std::endl;
  
  return os;
}

std::ostream& printRow(std::ostream& os, const std::string& left, const std::string& right, int w)
{
  formatTable(os, left, right, w);

  return os;
}

std::ostream& printHeader(std::ostream& os, std::string title)
{
  os << "\t+-------------------------------+\n";
  os << "\t|\t" << FMAG(BOLD(title)) << "\t|\n";
  os << "\t+-------------------------------+\n";

  return os;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
  printHeader(os, "Data about Bureaucrat");
  formatTable(os, "Name", b.getName(), 34);
  formatTable(os, "Grade", b.getGrade(), 33);
  os << "\t+-------------------------------+\n";
  
  return os;
}


void  Bureaucrat::incrementGrade( int amount )
{
  if (static_cast<int>(_grade - amount) < HIGHEST_GRADE) {
    throw GradeTooHighException();
  }
  std::ostringstream o;
  o << "(--) " << _grade << " -> " << (_grade - amount);

  printHeader(std::cout, "Grade incrementation");
  formatTable(std::cout, "Name", getName(), 34);
  printRow(std::cout, "Grade", o.str(), 33);
  std::cout << "\t+-------------------------------+\n";
  _grade -= amount;
}

void  Bureaucrat::decrementGrade( int amount )
{
  if (static_cast<int>(_grade + amount) > LOWEST_GRADE) {
    throw GradeTooLowException();
  }
  std::ostringstream o;
  o << "(++) " << _grade << " -> " << (_grade + amount);

  printHeader(std::cout, "Grade decrementation");
  formatTable(std::cout, "Name", getName(), 34);
  printRow(std::cout, "Grade", o.str(), 33);
  std::cout << "\t+-------------------------------+\n";

  _grade += amount;
}