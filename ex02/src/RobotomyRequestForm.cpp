/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:33 by oldault           #+#    #+#             */
/*   Updated: 2024/05/11 14:24:36 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Exceptions.hpp"

#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
  AForm("robotomy request", 72, 45),
  _target(target)
{
  srand(time(0));
  
  return ;
}

RobotomyRequestForm::~RobotomyRequestForm() throw()
{
  return ;
}

void  drillAway(const std::string& target)
{
  std::cout << BOLD(ITAL("💥 BRRRrrrrriiiiiiin zing Zing 💥")) << std::endl;
  if (rand() <= RAND_MAX / 2) {
    std::cout << BOLD( << target << ) << " has been Robotomized successfully 👍🏻" << std::endl;
  } else {
    std::cout << BOLD( << target << ) << " died during Robotomization 🫡" << std::endl;
  }

  return ;
}

void  RobotomyRequestForm::beSigned(Bureaucrat& b)
{
  b.signForm(*this);
    
  return ;
}

void RobotomyRequestForm::execute(const Bureaucrat& b)
{
  if (!isSigned()) {
    throw FormNotSignedException();
  } else if (!canBeExecuted(b)) {
    throw GradeTooLowException();
  }

  drillAway(_target);

  return ;
}
