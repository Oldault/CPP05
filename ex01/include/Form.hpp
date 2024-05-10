/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:57:20 by oldault           #+#    #+#             */
/*   Updated: 2024/05/10 11:01:47 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat;
class Form : public std::exception
{
  private:
    const std::string _formName;
    bool  _signed;
    const int _signGrade;
    const int _execGrade;
  
  public:
    Form(const std::string& formName, int signGrade, int execGrade);
    ~Form() throw();

    std::string  getFormName( void ) const;
    bool  isSigned( void ) const;
    int getSignGrade( void ) const;
    int getExecGrade( void ) const;

    void  beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& form);
