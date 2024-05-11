/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:44 by oldault           #+#    #+#             */
/*   Updated: 2024/05/11 11:14:26 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
  << FGRN(BOLD( << _name << )) << FGRN(", grade: ")
  << FGRN(UNDL( << _grade << )) << FGRN(" Created.") << std::endl;

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

int Bureaucrat::getGrade( void ) const
{
  return _grade;
}

void  Bureaucrat::incrementGrade( int amount )
{
  if (static_cast<int>(_grade - amount) < HIGHEST_GRADE) {
    throw GradeTooHighException();
  }
  std::cout << FCYN(BOLD( << _name << )) << FCYN("\'s grade: (++) ")
  << FCYN(ITAL( << (_grade) << " -> " << (_grade - amount) << ))
  << std::endl;

  _grade -= amount;
}

void  Bureaucrat::decrementGrade( int amount )
{
  if (static_cast<int>(_grade + amount) > LOWEST_GRADE) {
    throw GradeTooLowException();
  }
  std::cout << FCYN(BOLD( << _name << )) << FCYN("\'s grade: (--) ")
  << FCYN(ITAL( << (_grade) << " -> " << (_grade + amount) << ))
  << std::endl;

  _grade += amount;
}

bool  Bureaucrat::signForm(AForm& form)
{
  if (_grade > form.getSignGrade()) {
    std::cerr << FRED(BOLD( << _name << )) << FRED(", couldn't sign \"") << FRED(UNDL( << form.getFormName() << )) << FRED("\". Because: ")<< std::endl;
    throw GradeTooLowException();
    return false;
  }
  std::cout << FGRN(BOLD( << _name << )) << FGRN(", successfully signed ") << FGRN(UNDL( << form.getFormName() << )) << std::endl;
  return true;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
  os << FMAG(BOLD( << b.getName() << )) << FMAG(", bureaucrat grade ") << FMAG(UNDL( << b.getGrade() << ));
  return os;
}
