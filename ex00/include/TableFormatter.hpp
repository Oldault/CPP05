/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TableFormatter.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:26:46 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/15 10:28:20 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLEFORMATTER_HPP
#define TABLEFORMATTER_HPP

#include "Colors.hpp"
#include <iostream>
#include <iomanip>
#include <string>

std::string formatText(const std::string &text);
std::ostream &formatTable(std::ostream &os, const std::string &left, const std::string &right, int w);
std::ostream &formatTable(std::ostream &os, const std::string &left, int right, int w);
std::ostream &printRow(std::ostream &os, const std::string &left, const std::string &right, int w);
std::ostream &printHeader(std::ostream &os, std::string title);

#endif // TABLEFORMATTER_HPP
