/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:57 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 10:29:15 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
#include <exception>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat
{
  private:
    const std::string _name;
    unsigned int _grade;

  public:
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat( void ) throw();
    
    const std::string getName( void ) const;
    int getGrade( void ) const;

    void  incrementGrade(int amount);
    void  decrementGrade(int amount);

    /* Exceptions */
    class GradeTooHighException : public std::exception
    {
      public:
        const char* what() const throw() {
          return (" Grade is too high - Maximum grade exceeded ");
        }
    };

    class GradeTooLowException : public std::exception
    {
      public:
        const char* what() const throw() {
          return (" Grade is too low - Minimum grade not met ");
        }
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
