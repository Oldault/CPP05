/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:49 by oldault           #+#    #+#             */
/*   Updated: 2024/05/11 14:07:00 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm : 
  virtual public AForm
{
  private:
    const std::string _target;

  public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm() throw();

    void  beSigned(Bureaucrat& b);
    void  execute(const Bureaucrat& b);
};
