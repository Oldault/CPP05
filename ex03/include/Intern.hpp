/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:18:08 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/15 17:19:54 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
  public:
    Intern();
    Intern(const Intern &src);
    ~Intern();

    Intern &operator=(const Intern &src);

    AForm* makeForm(const std::string &name, const std::string& target);
    
    class UnexistingFormException : public std::exception
    {
      public:
        const char *what() const throw() {
          return (" That Form doesn't exist - Please try again ");
        }
    };
};



#endif // __INTERN_H__