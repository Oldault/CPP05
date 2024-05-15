/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:33 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 15:15:35 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
  AForm("presidential pardon", 25, 5),
  _target(target)
{
  
  return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) :
  AForm(src)
{
  return ;
}

PresidentialPardonForm::~PresidentialPardonForm() throw()
{
  return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm & src)
{
  if (this != &src) {
    AForm::operator=(src);
  }

  return *this;
}

void  pardon(const std::string& target)
{
  std::cout << "\n\t" << BWHT(" ⟢ ") << BWHT(BOLD(target))
  << BWHT(" has been pardonned by Zaphod Beeblebrox ⟢ ") << "\n\n";

  return ;
}

void  PresidentialPardonForm::performExecuteAction(Bureaucrat& b)
{
  (void)b;
  pardon(_target);

  return ;
}
