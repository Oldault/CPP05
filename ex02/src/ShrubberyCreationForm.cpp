/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:33 by oldault           #+#    #+#             */
/*   Updated: 2024/05/11 14:23:51 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
  AForm("shrubbery creation", 145, 137),
  _target(target)
{ 
  return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm() throw()
{
  return ;
}

void  growShrubs(const std::string& target)
{
  std::ofstream shrubFile;
  shrubFile.open(target + "_shrubbery");

  shrubFile << "🌳🌴🌲\n";
  shrubFile.close();

  return ;
}

void  ShrubberyCreationForm::beSigned(Bureaucrat& b)
{
  b.signForm(*this);
  
  return ;
}

void  ShrubberyCreationForm::execute(const Bureaucrat& b)
{
  if (!isSigned()) {
    throw FormNotSignedException();
  } else if (!canBeExecuted(b)) {
    throw GradeTooLowException();
  }
  growShrubs(_target);
  
  return ;
}