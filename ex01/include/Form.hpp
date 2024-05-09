/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:57:20 by oldault           #+#    #+#             */
/*   Updated: 2024/05/09 22:05:17 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Form
{
  private:
    const std::string _formName;
    bool  _signed;
    const int _signGrade;
    const int _execGrade;
  
  public:
    Form(const std::string formName, const int signGrade, const int execGrade);
    ~Form();

    std::string  getFormName( void ) const;
    bool  isSigned( void ) const;
    int getSignGrade( void ) const;
    int getExecGrade( void ) const;

    void  beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& form);
