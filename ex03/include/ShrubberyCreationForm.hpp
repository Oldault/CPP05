/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:24:49 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 17:14:24 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"

class ShrubberyCreationForm : 
  public AForm
{
  private:
    const std::string _target;

  public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    ~ShrubberyCreationForm() throw();

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm & src);

  protected:
    virtual void performExecuteAction(Bureaucrat& b);
};

#endif // __SHRUBBERYCREATIONFORM_H__