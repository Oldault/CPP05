/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:33 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 15:18:49 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
  AForm("robotomy request", 72, 45),
  _target(target)
{
  srand(time(0));
  
  return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) :
  AForm(src)
{
  return ;
}

RobotomyRequestForm::~RobotomyRequestForm() throw()
{
  return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm & src)
{
  if (this != &src) {
    AForm::operator=(src);
  }

  return *this;
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

void RobotomyRequestForm::performExecuteAction(Bureaucrat& b)
{
  (void)b;
  drillAway(_target);

  return ;
}
