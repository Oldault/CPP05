/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:17 by oldault           #+#    #+#             */
/*   Updated: 2024/05/11 11:03:19 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
  /* Bureaucrats: */
  Bureaucrat myBureaucrat("James", 20);
  std::cout << myBureaucrat << std::endl;
  Bureaucrat myBureaucrat2("Salomon", 2);
  std::cout << myBureaucrat2 << std::endl;

  /* Forms: */
  Form form1("Fire Anne Hidalgo", 5, 100);
  std::cout << form1 << std::endl;
  
  /* Signing Attempts: */
  try {
    form1.beSigned(myBureaucrat);
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << "\n\n";
  }
  std::cout << form1 << std::endl;


  try {
    form1.beSigned(myBureaucrat2);
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << "\n\n";
  }
  std::cout << form1 << std::endl;

  return 0;
}
