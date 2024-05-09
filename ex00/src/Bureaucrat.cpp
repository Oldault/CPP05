/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:44 by oldault           #+#    #+#             */
/*   Updated: 2024/05/09 10:22:16 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) :
  _name(name)
{
  std::cout << FGRN("Trying to create a Bureaucrat named ")
  << FGRN(BOLD( << name << )) << FGRN(", grade: ")
  << FGRN(UNDL( << grade << )) << std::endl;
  
  if (grade < HIGHEST_GRADE) {
    throw GradeTooHighException();
  } else if (grade > LOWEST_GRADE) {
    throw GradeTooHighException();
  }
  _grade = grade;
  std::cout << FGRN("\t↳ Bureaucrat " << BOLD( << _name << )) << FGRN(" Created.") << std::endl;

  return ;
}

Bureaucrat::~Bureaucrat( void ) throw()
{
  // std::cout << FYEL("Bureaucrat ") << FYEL(BOLD( << _name << ))
  // << FYEL(" was destroyed 😇") << std::endl;

  return ;
}

const std::string Bureaucrat::getName( void ) const
{
  return _name;
}

unsigned int Bureaucrat::getGrade( void ) const
{
  return _grade;
}

void  Bureaucrat::incrementGrade( unsigned int amount )
{
  if (static_cast<int>(_grade - amount) < HIGHEST_GRADE) {
    throw GradeTooHighException();
  }
  std::cout << FCYN(BOLD( << _name << )) << FCYN("\'s grade: (++) ")
  << FCYN(ITAL( << (_grade) << " -> " << (_grade - amount) << ))
  << std::endl;

  _grade -= amount;
}

void  Bureaucrat::decrementGrade( unsigned int amount )
{
  if (static_cast<int>(_grade + amount) > LOWEST_GRADE) {
    throw GradeTooLowException();
  }
  std::cout << FCYN(BOLD( << _name << )) << FCYN("\'s grade: (--) ")
  << FCYN(ITAL( << (_grade) << " -> " << (_grade + amount) << ))
  << std::endl;

  _grade += amount;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
  os << FMAG(BOLD( << b.getName() << )) << FMAG(", bureaucrat grade ") << FMAG(UNDL( << b.getGrade() << ));
  return os;
}
