/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:44 by oldault           #+#    #+#             */
/*   Updated: 2024/05/09 09:01:33 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) :
  _name(name)
{
  if (grade < HIGHEST_GRADE || grade > LOWEST_GRADE) {
    throw std::out_of_range("Bureaucrats grade must be between 1-150");
  }
  _grade = grade;

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

unsigned int Bureaucrat::getGrade( void ) const
{
  return _grade;
}

void  Bureaucrat::incrementGrade( unsigned int amount )
{
  if (static_cast<int>(_grade - amount) < HIGHEST_GRADE) {
    throw std::out_of_range("Highest grade only goes up to 1");
  }
  _grade -= amount;
}

void  Bureaucrat::decrementGrade( unsigned int amount )
{
  if (static_cast<int>(_grade + amount) > LOWEST_GRADE) {
    throw std::out_of_range("Lowest grade only goes down to 150");
  }
  _grade += amount;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
  os << b.getName() << ", bureaucrat grade " << b.getGrade();
  return os;
}
