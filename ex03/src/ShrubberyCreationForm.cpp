/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:33 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 15:19:09 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
  AForm("shrubbery creation", 145, 137),
  _target(target)
{ 
  return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) :
  AForm(src)
{
  return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm() throw()
{
  return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & src)
{
  if (this != &src) {
    AForm::operator=(src);
  }

  return *this;
}

void  growShrubs(const std::string& target)
{
  std::ofstream shrubFile;
  std::string filename = target + "_shrubbery";
  
  shrubFile.open(filename.c_str());
  shrubFile << "🌳🌴🌲\n";
  shrubFile.close();

  std::cout << "\n\t" << BWHT(" 🌿 ") << BWHT(BOLD(target))
  << BWHT(" has been filled with shrubs 🌿 ") << "\n\n";


  return ;
}

void  ShrubberyCreationForm::performExecuteAction(Bureaucrat& b)
{
  (void)b;
  growShrubs(_target);
  
  return ;
}