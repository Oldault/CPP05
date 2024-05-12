/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:53:05 by oldault           #+#    #+#             */
/*   Updated: 2024/05/12 08:06:04 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include "Colors.hpp"

class GradeTooHighException : public std::exception
{
  public:
    virtual const char* what() const throw() {
      static std::string msg = BRED(" Grade is too high - Maximum grade exceeded ");
      return msg.c_str();
    }
};

class GradeTooLowException : public std::exception
{
  public:
    virtual const char* what() const throw() {
      static std::string msg = BRED(" Grade is too low - Minimum grade not met ");
      return msg.c_str();
    }
};
