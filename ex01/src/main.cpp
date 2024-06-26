/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:17 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 14:50:06 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{ 
  /* Invalid sign/exec grade */
  try {
    Form form1("Fire Anne Hidalgo", 500, 200);
  }
  catch (const std::exception& e) {
    std::cerr << BRED(e.what()) << "\n\n";
  }

  /* Bureaucrats: */
  Bureaucrat midLevelBur("James", 20);
  std::cout << midLevelBur << std::endl;
  Bureaucrat highLevelBur("Salomon", 2);
  std::cout << highLevelBur << std::endl;

  /* Forms: */
  Form form1("Fire Anne Hidalgo", 5, 100);
  std::cout << form1 << std::endl;
  
  /* Signing Attempts: */
  try {
    form1.beSigned(midLevelBur);
  }
  catch (const std::exception& e) {
    std::cerr << BRED(e.what()) << "\n\n";
  }
  std::cout << form1 << std::endl;


  try {
    form1.beSigned(highLevelBur);
  }
  catch (const std::exception& e) {
    std::cerr << BRED(e.what()) << "\n\n";
  }
  std::cout << form1 << std::endl;

  return 0;
}
