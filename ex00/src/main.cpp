/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:17 by oldault           #+#    #+#             */
/*   Updated: 2024/05/08 10:23:14 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
  Bureaucrat MyBureaucrat("James", 20);

  std::cout << MyBureaucrat << std::endl;
  MyBureaucrat.decrementGrade(20);
  std::cout << MyBureaucrat << std::endl;
  MyBureaucrat.incrementGrade(10);
  std::cout << MyBureaucrat << std::endl;
  
  return 0;
}
