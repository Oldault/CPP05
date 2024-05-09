/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:57 by oldault           #+#    #+#             */
/*   Updated: 2024/05/09 10:25:35 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.h"
#include "Exceptions.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat : public std::exception
{
  private:
    const std::string _name;
    unsigned int _grade;

  public:
    Bureaucrat(const std::string& name, unsigned int grade);
    ~Bureaucrat( void ) throw();
    
    const std::string getName( void ) const;
    unsigned int getGrade( void ) const;
    void  incrementGrade(unsigned int amount);
    void  decrementGrade(unsigned int amount);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

