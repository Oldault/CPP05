/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:33 by oldault           #+#    #+#             */
/*   Updated: 2024/05/14 16:00:14 by svolodin         ###   ########.fr       */
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
  std::cout << "\n\t" << BOLD(ITAL("💥 BRRRrrrrriiiiiiin zing Zing 💥")) << "\n\t";
  if (rand() < RAND_MAX / 2) {
    std::cout << BOLD(target) << " has been Robotomized successfully 👍🏻\n" << std::endl;
  } else {
    std::cout << BOLD(target) << " died during Robotomization 🫡\n" << std::endl;
  }

  return ;
}

void  RobotomyRequestForm::beSigned(Bureaucrat& b)
{
  if (b.signForm(*this)) {
    setToSigned();
  }
    
  return ;
}

void RobotomyRequestForm::execute(const Bureaucrat& b)
{
  if (!isSigned()) {
    throw FormNotSignedException();
  } else if (!canBeExecuted(b)) {
    throw GradeTooLowException();
  }
  std::cout << FGRN(BOLD(b.getName()))
  << FGRN(", is now executing ")
  << FGRN(UNDL(getFormName())) << std::endl;
  drillAway(_target);

  return ;
}
