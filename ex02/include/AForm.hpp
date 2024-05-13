/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:57:20 by oldault           #+#    #+#             */
/*   Updated: 2024/05/11 14:20:45 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <string>

class Bureaucrat;

class AForm : public std::exception
{
  private:
    const std::string _formName;
    bool  _signed;
    const int _signGrade;
    const int _execGrade;
  
  public:
    AForm(const std::string& formName, int signGrade, int execGrade);
    virtual ~AForm() throw();

    std::string  getFormName( void ) const;
    bool  isSigned( void ) const;
    int getSignGrade( void ) const;
    int getExecGrade( void ) const;

    void  setToSigned( void );

    bool  canBeSigned(Bureaucrat& b);
    bool  canBeExecuted(const Bureaucrat& b);
    
    virtual void  beSigned(Bureaucrat& b) = 0;
    virtual void  execute(const Bureaucrat& b) = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
