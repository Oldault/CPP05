/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:17 by oldault           #+#    #+#             */
/*   Updated: 2024/05/11 11:24:08 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
  /* Bureaucrats: */
  Bureaucrat myBureaucrat("James", 146);
  Bureaucrat myBureaucrat2("Salomon", 2);
  std::cout << myBureaucrat << std::endl;
  std::cout << myBureaucrat2 << std::endl;
  
  ShrubberyCreationForm form1("Goji");
  std::cout << form1;

  try {
    form1.beSigned(myBureaucrat);
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << form1;
   
  try {
    form1.beSigned(myBureaucrat2);
  }
  catch(const std::exception& e){
    std::cerr << e.what() << '\n';
  }
  std::cout << form1;

  return 0;
}