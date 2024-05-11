/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:33 by oldault           #+#    #+#             */
/*   Updated: 2024/05/11 11:23:25 by oldault          ###   ########.fr       */
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
  std::ofstream shrubFile;
  shrubFile.open(_target + "_shrubbery");
  
  shrubFile << "🌳🌴🌲\n";
  shrubFile.close();
  
  return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm() throw()
{
  return ;
}

void  ShrubberyCreationForm::beSigned(Bureaucrat& b)
{
  if (b.getGrade() <= getSignGrade())
  {
    b.signForm(*this);
    setToSigned();
  }
  else
  {
    throw GradeTooLowException();
  }
  
  return ;
}
