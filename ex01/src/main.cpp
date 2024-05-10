/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:17 by oldault           #+#    #+#             */
/*   Updated: 2024/05/10 10:16:16 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
  std::cout << std::endl;

  Form form1("Fire Anne Hidalgo", 5, 100);
  std::cout << form1 << std::endl;

  std::cout << std::endl;

  Form form2("Eat a lot of bolognese", 50, 90);
  std::cout << form2 << std::endl;

  std::cout << std::endl;

  Form form3("cheese", 50, 90);
  std::cout << form3 << std::endl;

  std::cout << std::endl;

  return 0;
}
