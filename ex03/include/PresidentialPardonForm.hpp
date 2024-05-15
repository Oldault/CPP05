/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:49 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 17:14:08 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"

class PresidentialPardonForm : 
  public AForm
{
  private:
    const std::string _target;

  public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    ~PresidentialPardonForm() throw();

    PresidentialPardonForm &operator=(const PresidentialPardonForm & src);

  protected:
    virtual void performExecuteAction(Bureaucrat& b);
};

#endif // __PRESIDENTIALPARDONFORM_H__