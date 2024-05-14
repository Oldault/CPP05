/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:33 by oldault           #+#    #+#             */
/*   Updated: 2024/05/14 15:58:46 by svolodin         ###   ########.fr       */
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
  std::cout << "\n\t" << BWHT(" ⟢ ") << BWHT(BOLD(target))
  << BWHT(" has been pardonned by Zaphod Beeblebrox ⟢ ") << "\n\n";

  return ;
}

void  PresidentialPardonForm::beSigned(Bureaucrat& b)
{
  if (b.signForm(*this)) {
    setToSigned();
  }

  return ;
}

void  PresidentialPardonForm::execute(const Bureaucrat& b)
{
  if (!isSigned()) {
    throw FormNotSignedException();
  } else if (!canBeExecuted(b)) {
    throw GradeTooLowException();
  }
  std::cout << FGRN(BOLD(b.getName()))
  << FGRN(", is now executing ")
  << FGRN(UNDL(getFormName())) << std::endl;
  
  pardon(_target);

  return ;
}
