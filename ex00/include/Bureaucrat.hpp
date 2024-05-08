/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:57 by oldault           #+#    #+#             */
/*   Updated: 2024/05/08 10:02:50 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.h"
#include <iostream>
#include <string>

class Bureaucrat
{
  private:
    const std::string _name;
    unsigned int _grade;

  public:
    Bureaucrat(const std::string& name, unsigned int grade);
    ~Bureaucrat( void );
    
    const std::string getName( void ) const;
    unsigned int getGrade( void ) const;
    void  incrementGrade(unsigned int amount);
    void  decrementGrade(unsigned int amount);
};
