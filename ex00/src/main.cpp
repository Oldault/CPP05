/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:17 by oldault           #+#    #+#             */
/*   Updated: 2024/05/09 10:54:54 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
  std::cout << std::endl;

  /* Too "low" of a grade constructor */
  try
  {
    Bureaucrat MyBureaucrat1("Lenny", 160);
    std::cout << MyBureaucrat1 << std::endl;
  }
  catch(const std::exception& e) {
    std::cerr << FRED("Exception caught: ") << e.what() << "\n\n";
  }
  
  /* Too "high" of a grade constructor */
  try
  {
    Bureaucrat MyBureaucrat11("Ynnel", -20);
    std::cout << MyBureaucrat11 << std::endl;
  }
  catch(const std::exception& e) {
    std::cerr << FRED("Exception caught: ") << e.what() << "\n\n";
  }
  
  /* Too big of an incrementation */
  try
  {
    Bureaucrat MyBureaucrat2("James", 20);
    std::cout << MyBureaucrat2 << std::endl;

    MyBureaucrat2.incrementGrade(15);
    std::cout << MyBureaucrat2 << std::endl;

    MyBureaucrat2.incrementGrade(10);
    std::cout << MyBureaucrat2 << std::endl;
  }
  catch(const std::exception& e) {
    std::cerr << FRED("Exception caught: ") << e.what() << "\n\n";
  }
  
  /* Too big of a decrementation */
  try
  {
    Bureaucrat MyBureaucrat21("Clore", 100);
    std::cout << MyBureaucrat21 << std::endl;

    MyBureaucrat21.decrementGrade(20);
    std::cout << MyBureaucrat21 << std::endl;

    MyBureaucrat21.decrementGrade(40);
    std::cout << MyBureaucrat21 << std::endl;
  }
  catch(const std::exception& e) {
    std::cerr << FRED("Exception caught: ") << e.what() << "\n\n";
  }
  
  return 0;
}
