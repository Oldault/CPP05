/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TableFormatter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:28:05 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/15 10:28:08 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TableFormatter.hpp"

std::string formatText(const std::string& text)
{
	unsigned int maxLen = 18;
  return text.size() > maxLen ? text.substr(0, maxLen - 1) + '.' : text;
}

std::ostream& formatTable(std::ostream& os, const std::string& left, const std::string& right, int w)
{
  os << "\t| " << std::left << std::setw(5) << BOLD(left)
    << std::right << std::setw(w) << FMAG(right) << " |" << std::endl;
  
  return os;
}

std::ostream& formatTable(std::ostream& os, const std::string& left, int right, int w)
{
  os << "\t| " << std::left << std::setw(5) << BOLD(left)
    << std::right << std::setw(w) << FMAG(right) << " |" << std::endl;
  
  return os;
}

std::ostream& printRow(std::ostream& os, const std::string& left, const std::string& right, int w)
{
  formatTable(os, left, right, w);

  return os;
}

std::ostream& printHeader(std::ostream& os, std::string title)
{
  os << "\t+-------------------------------+\n";
  os << "\t|\t" << BOLD(title) << "\t|\n";
  os << "\t+-------------------------------+\n";

  return os;
}
