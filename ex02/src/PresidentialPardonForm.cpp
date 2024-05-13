/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:33 by oldault           #+#    #+#             */
/*   Updated: 2024/05/11 14:25:21 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Exceptions.hpp"

#include <cstdlib>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
  AForm("presidential pardon", 25, 5),
  _target(target)
{
  srand(time(0));
  
  return ;
}

PresidentialPardonForm::~PresidentialPardonForm() throw()
{
  return ;
}

void  pardon(const std::string& target)
{
  std::cout << BOLD( << target << ) << " has been pardonned by Zaphod Beeblebrox" << std::endl;

  return ;
}

void  PresidentialPardonForm::beSigned(Bureaucrat& b)
{
  b.signForm(*this);
  
  return ;
}

void  PresidentialPardonForm::execute(const Bureaucrat& b)
{
  if (!isSigned()) {
    throw FormNotSignedException();
  } else if (!canBeExecuted(b)) {
    throw GradeTooLowException();
  }

  pardon(_target);

  return ;
}
