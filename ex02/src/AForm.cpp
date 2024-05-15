/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:23 by oldault           #+#    #+#             */
/*   Updated: 2024/05/10 11:15:09 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "TableFormatter.hpp"

AForm::AForm(const std::string& formName, size_t signGrade, size_t execGrade) :
  _formName(formName),
  _signed(false),
  _signGrade(signGrade),
  _execGrade(execGrade)
{
  if (signGrade < 1 || execGrade < 1) {
    throw AForm::GradeTooHighException();
  } else if (signGrade > 150 || execGrade > 150) {
    throw AForm::GradeTooLowException();
  }
  std::cout << FGRN("Form named ") << FGRN(BOLD(_formName))
  << FGRN(", sign grade: ") << FGRN(UNDL(_signGrade))
  << FGRN(", exec grade: ") << FGRN(UNDL(_execGrade))
  << FGRN(" Created.") << std::endl;

  return ;
}

AForm::AForm(const AForm &src) :
  _formName(src._formName),
  _signed(src._signed),
  _signGrade(src._signGrade),
  _execGrade(src._execGrade)
{
  return ;
}

AForm::~AForm() throw()
{
  return ;
}

AForm &AForm::operator=(const AForm &src)
{
  if (this != &src)
  {
    _signed = src._signed;
  }

  return *this;
}

std::string  AForm::getFormName( void ) const
{
  return _formName;
}

bool  AForm::isSigned( void ) const
{
  return _signed;
}
 size_t AForm::getSignGrade( void ) const
{
  return _signGrade;
}
 size_t AForm::getExecGrade( void ) const
{
  return _execGrade;
}

void AForm::beSigned(Bureaucrat& b)
{
  if (b.signForm(*this)) {
    _signed = true;
  }
}

void AForm::execute(Bureaucrat& b)
{
  if (!_signed) {
    throw AForm::FormNotSignedException();
  }
  if (b.executeForm(*this)) {
    performExecuteAction(b);
  }
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
  printHeader(os, "Data about Form", 39);
  formatTable(os, "Form Name:", formatText(form.getFormName()), 34);
  formatTable(os, "Form is signed:", (form.isSigned() ? "✅" : "❌"), 30);
  formatTable(os, "Signing Grade:", form.getSignGrade(), 30);
  formatTable(os, "Execution Grade:", form.getExecGrade(), 28);
  os << "\t+-------------------------------------+\n";

  return os;
}
