/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:33 by oldault           #+#    #+#             */
/*   Updated: 2024/05/14 17:35:32 by svolodin         ###   ########.fr       */
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

void  PresidentialPardonForm::performExecuteAction(Bureaucrat& b)
{
  (void)b;
  pardon(_target);

  return ;
}
