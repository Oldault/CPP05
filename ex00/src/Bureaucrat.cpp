/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:44 by oldault           #+#    #+#             */
/*   Updated: 2024/05/08 10:22:30 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) :
  _name(name),
  _grade(grade)
{
  return ;
}

Bureaucrat::~Bureaucrat( void )
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
  _grade = _grade - amount;
}

void  Bureaucrat::decrementGrade( unsigned int amount )
{
  _grade = _grade + amount;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
  os << b.getName() << ", bureaucrat grade " << b.getGrade();
  return os;
}
