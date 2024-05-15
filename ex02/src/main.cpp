/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:17 by oldault           #+#    #+#             */
/*   Updated: 2024/05/15 15:09:13 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    Bureaucrat john("John", 150);
    Bureaucrat jane("Jane", 45);
    Bureaucrat boss("Boss", 5);

    ShrubberyCreationForm shrubForm("garden");
    RobotomyRequestForm robotForm("R2D2");
    PresidentialPardonForm pardonForm("Alice");
    std::cout << shrubForm;
    std::cout << robotForm;
    std::cout << pardonForm;


    try {
        shrubForm.beSigned(john);
        shrubForm.execute(john);
    } catch (std::exception& e) {
        std::cout << BRED(e.what()) << std::endl;
    }

    try {
        robotForm.beSigned(jane);
        robotForm.execute(jane);
    } catch (std::exception& e) {
        std::cout << BRED(e.what()) << std::endl;
    }

    try {
        pardonForm.beSigned(boss);
        pardonForm.execute(boss);
    } catch (std::exception& e) {
        std::cout << BRED(e.what()) << std::endl;
    }


    std::cout << shrubForm;
    std::cout << robotForm;
    std::cout << pardonForm;
    return 0;
}