/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:49 by oldault           #+#    #+#             */
/*   Updated: 2024/05/14 17:34:10 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : 
  public AForm
{
  private:
    const std::string _target;

  public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm() throw();

  protected:
    virtual void performExecuteAction(Bureaucrat& b);
};
