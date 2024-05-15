/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:49 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 17:14:05 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"

class RobotomyRequestForm : 
  public AForm
{
  private:
    const std::string _target;

  public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &src);
    ~RobotomyRequestForm() throw();

    RobotomyRequestForm &operator=(const RobotomyRequestForm & src);

  protected:
    virtual void performExecuteAction(Bureaucrat& b);
};

#endif // __ROBOTOMYREQUESTFORM_H__