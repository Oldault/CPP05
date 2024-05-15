/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:44 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 10:29:01 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "TableFormatter.hpp"

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
  std::cout << FGRN("\t↳ Bureaucrat ") << FGRN(BOLD(_name)) << FGRN(" Created.") << std::endl;

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
    throw Bureaucrat::GradeTooHighException();
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
    throw Bureaucrat::GradeTooLowException();
  }
  std::ostringstream o;
  o << "(++) " << _grade << " -> " << (_grade + amount);

  printHeader(std::cout, "Grade decrementation");
  formatTable(std::cout, "Name", getName(), 34);
  printRow(std::cout, "Grade", o.str(), 33);
  std::cout << "\t+-------------------------------+\n";

  _grade += amount;
}