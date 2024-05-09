/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:17 by oldault           #+#    #+#             */
/*   Updated: 2024/05/09 08:56:59 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
  try
  {
    Bureaucrat MyBureaucrat2("Lenny", 160);
    std::cout << MyBureaucrat2 << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << "Exception caught: " << e.what() << '\n';
  }
  
  try
  {
    Bureaucrat MyBureaucrat1("James", 20);
    std::cout << MyBureaucrat1 << std::endl;
    MyBureaucrat1.incrementGrade(15);
    std::cout << MyBureaucrat1 << std::endl;
    MyBureaucrat1.incrementGrade(10);
    std::cout << MyBureaucrat1 << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << "Exception caught: " << e.what() << '\n';
  }
  

  try
  {
    Bureaucrat MyBureaucrat3("Clore", 100);
    std::cout << MyBureaucrat3 << std::endl;
    MyBureaucrat3.decrementGrade(20);
    std::cout << MyBureaucrat3 << std::endl;
    MyBureaucrat3.decrementGrade(40);
    std::cout << MyBureaucrat3 << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << "Exception caught: " << e.what() << '\n';
  }
  
  return 0;
}
