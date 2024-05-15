/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:57:20 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 14:32:03 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat;
class Form
{
  private:
    const std::string _formName;
    bool  _signed;
    const size_t _signGrade;
    const size_t _execGrade;
  
  public:
    Form(const std::string& formName, size_t signGrade, size_t execGrade);
    Form(const Form &src);
    ~Form() throw();

    const Form &operator==(const Form &src);

    std::string  getFormName( void ) const;
    bool  isSigned( void ) const;
    size_t getSignGrade( void ) const;
    size_t getExecGrade( void ) const;

    void  beSigned(Bureaucrat& b);

    /* Exceptions */
    class GradeTooHighException : public std::exception
    {
    public:
      const char *what() const throw()
      {
        return (" Grade is too high - Maximum grade exceeded ");
      }
    };

    class GradeTooLowException : public std::exception
    {
    public:
      const char *what() const throw()
      {
        return (" Grade is too low - Minimum grade not met ");
      }
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);
