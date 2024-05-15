/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:22:54 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/15 17:22:13 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
  return ;
}

Intern::Intern(const Intern &src)
{
  (void)src;
  return ;
}

Intern::~Intern()
{
  return ;
}

Intern& Intern::operator=(const Intern &src)
{
  (void)src;
  return *this;
}

AForm* Intern::makeForm(const std::string &name, const std::string& target)
{
  std::string availableForms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  size_t i = 0;
  
  while (i < 3 && name != availableForms[i])
    i++;

  if (i != 3)
    std::cout << FBLU(BOLD("Intern")) << FBLU(" creates ") << FBLU(name) << std::endl;
  switch (i)
  {
    case 0: return (new ShrubberyCreationForm(target));
    case 1: return (new RobotomyRequestForm(target));
    case 2: return (new PresidentialPardonForm(target));
    default: throw Intern::UnexistingFormException();
  }
}
