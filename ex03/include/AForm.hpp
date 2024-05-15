/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:57:20 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 17:14:15 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <string>

class Bureaucrat;
class AForm
{
  private:
    const std::string _formName;
    bool  _signed;
    const size_t _signGrade;
    const size_t _execGrade;
  
  public:
    AForm(const std::string& formName, size_t signGrade, size_t execGrade);
    AForm(const AForm &src);
    virtual ~AForm() throw();

    AForm &operator=(const AForm &src);

    std::string  getFormName( void ) const;
    bool  isSigned( void ) const;
    size_t getSignGrade( void ) const;
    size_t getExecGrade( void ) const;
    
    void  beSigned(Bureaucrat& b);
    void  execute(Bureaucrat& b);
    
    /* Exceptions */
    class GradeTooHighException : public std::exception
    {
      public:
        const char *what() const throw() {
          return (" Grade is too high - Maximum grade exceeded ");
        }
    };
    class GradeTooLowException : public std::exception
    {
      public:
        const char *what() const throw() {
          return (" Grade is too low - Minimum grade not met ");
        }
    };
    class FormNotSignedException : public std::exception
    {
      public:
        const char *what() const throw() {
          return (" The Form is not Signed yet - Please sign it before continuing ");
        }
    };

  protected:
    virtual void performExecuteAction(Bureaucrat& b) = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif // __AFORM_H__