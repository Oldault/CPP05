/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:17 by oldault           #+#    #+#             */
/*   Updated: 2024/05/08 10:05:36 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
  Bureaucrat James("James", 20);

  std::cout << James.getName() << std::endl;
  std::cout << James.getGrade() << std::endl;
  James.decrementGrade(20);
  James.incrementGrade(10);
  std::cout << James.getGrade() << std::endl;
  
  return 0;
}
