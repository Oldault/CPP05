/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:44 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 14:50:58 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "TableFormatter.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
  _name(name)
{
  std::cout << FGRN("Trying to create a Bureaucrat named ")
  << FGRN(BOLD( name )) << FGRN(", grade: ")
  << FGRN(UNDL( grade )) << std::endl;
  
  if (grade < HIGHEST_GRADE) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > LOWEST_GRADE) {
    throw Bureaucrat::GradeTooLowException();
  }
  _grade = grade;

  return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) :
  _name(src._name),
  _grade(src._grade)
{
  return ;
}

Bureaucrat::~Bureaucrat( void ) throw()
{
  return ;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &src)
{
  if (this != &src)
  {
    _grade = src._grade;
  }

  return *this;
}

const std::string Bureaucrat::getName( void ) const
{
  return _name;
}

int Bureaucrat::getGrade( void ) const
{
  return _grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
  printHeader(os, "Data about Bureaucrat", 33);
  formatTable(os, "Name", b.getName(), 34);
  formatTable(os, "Grade", b.getGrade(), 33);
  os << "\t+-------------------------------+\n";
  
  return os;
}


void  Bureaucrat::incrementGrade( int amount )
{
  if (static_cast<int>(_grade - amount) < HIGHEST_GRADE) {
    throw Bureaucrat::GradeTooHighException();
  }
  std::ostringstream o;
  o << "(--) " << _grade << " -> " << (_grade - amount);

  printHeader(std::cout, "Grade incrementation", 33);
  formatTable(std::cout, "Name", getName(), 34);
  printRow(std::cout, "Grade", o.str(), 33);
  std::cout << "\t+-------------------------------+\n";
  _grade -= amount;
}

void  Bureaucrat::decrementGrade( int amount )
{
  if (static_cast<int>(_grade + amount) > LOWEST_GRADE) {
    throw Bureaucrat::GradeTooLowException();
  }
  std::ostringstream o;
  o << "(++) " << _grade << " -> " << (_grade + amount);

  printHeader(std::cout, "Grade decrementation", 33);
  formatTable(std::cout, "Name", getName(), 34);
  printRow(std::cout, "Grade", o.str(), 33);
  std::cout << "\t+-------------------------------+\n";

  _grade += amount;
}

bool  Bureaucrat::signForm(Form& form)
{
  if (_grade > form.getSignGrade())
  {
    std::cerr << FRED(BOLD(_name)) << FRED(", couldn't sign \"") << FRED(UNDL( form.getFormName())) << FRED("\". Because: ")<< std::endl;
    throw Bureaucrat::GradeTooLowException();
  }
  std::cout << FGRN(BOLD(_name)) << FGRN(", successfully signed ") << FGRN(UNDL(form.getFormName())) << std::endl;
  return true;
}