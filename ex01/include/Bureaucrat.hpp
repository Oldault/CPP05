/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:57 by oldault           #+#    #+#             */
/*   Updated: 2024/05/12 09:49:59 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.hpp"
#include "Exceptions.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Form;
class Bureaucrat : public std::exception
{
  private:
    const std::string _name;
    int _grade;

  public:
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat( void ) throw();
    
    const std::string getName( void ) const;
    int getGrade( void ) const;
    void  incrementGrade(int amount);
    void  decrementGrade(int amount);

    bool  signForm(Form& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
