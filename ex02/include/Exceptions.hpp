/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:53:05 by oldault           #+#    #+#             */
/*   Updated: 2024/05/11 14:35:24 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>

class GradeTooHighException : public std::exception
{
  public:
    virtual const char* what() const throw() {
      return BRED(" Grade is too high - Maximum grade exceeded ");
    }
};

class GradeTooLowException : public std::exception
{
  public:
    virtual const char* what() const throw() {
      return BRED(" Grade is too low - Minimum grade not met ");
    }
};

class FormNotSignedException : public std::exception
{
  public:
    virtual const char* what() const throw() {
      return BRED(" The Form is not Signed yet - Please sign it before continuing ");
    }
};

