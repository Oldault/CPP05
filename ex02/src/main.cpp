/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:39:17 by oldault           #+#    #+#             */
/*   Updated: 2024/05/11 14:33:46 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    Bureaucrat john("John", 150); // Low grade, may not be able to sign or execute anything
    Bureaucrat jane("Jane", 45);  // Mid-level grade, should be able to sign and execute middle level forms
    Bureaucrat boss("Boss", 5);   // High grade, should be able to sign and execute all forms

    // Initialize forms with the required grades
    ShrubberyCreationForm shrubForm("garden");
    RobotomyRequestForm robotForm("R2D2");
    PresidentialPardonForm pardonForm("Alice");
    std::cout << shrubForm;
    std::cout << robotForm;
    std::cout << pardonForm;


    // Test signing and execution of forms
    try {
        shrubForm.beSigned(john);
        shrubForm.execute(john);
    } catch (std::exception& e) {
        std::cout << "John: " << e.what() << std::endl;
    }

    try {
        robotForm.beSigned(jane);
        robotForm.execute(jane);
    } catch (std::exception& e) {
        std::cout << "Jane: " << e.what() << std::endl;
    }

    try {
        pardonForm.beSigned(boss);
        pardonForm.execute(boss);
    } catch (std::exception& e) {
        std::cout << "Boss: " << e.what() << std::endl;
    }


    std::cout << shrubForm;
    std::cout << robotForm;
    std::cout << pardonForm;
    return 0;
}