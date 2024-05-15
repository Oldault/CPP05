/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:57 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 17:12:52 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include "Colors.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
#include <exception>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class AForm;
class Bureaucrat
{
  private:
    const std::string _name;
    size_t _grade;

  public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat(void) throw();

    Bureaucrat &operator=(const Bureaucrat &src);

    const std::string getName(void) const;
    int getGrade(void) const;

    void incrementGrade(int amount);
    void decrementGrade(int amount);

    bool  signForm(AForm& form);
    bool  executeForm(AForm& form);

    /* Exceptions */
    class GradeTooHighException : public std::exception
    {
    public:
      const char *what() const throw() {
        return (" Grade is too high - Maximum grade exceeded ");
      }
    };

    class GradeTooLowException : public std::exception
    {
    public:
      const char *what() const throw() {
        return (" Grade is too low - Minimum grade not met ");
      }
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // __BUREAUCRAT_H__