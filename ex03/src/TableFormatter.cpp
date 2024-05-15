/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TableFormatter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:28:05 by svolodin          #+#    #+#             */
/*   Updated: 2024/05/15 14:46:49 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TableFormatter.hpp"

std::string formatText(const std::string& text)
{
	size_t maxLen = 18;
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

std::ostream& printHeader(std::ostream& os, std::string title, int w)
{
  std::ios init(NULL);
  init.copyfmt(std::cout);

  os << "\t+" << std::setfill('-') << std::setw(w) << "+\n";
  os << "\t|\t" << BOLD(title) << std::setfill(' ') << std::setw(w - title.size() - 7) << "|\n";
  os << "\t+" << std::setfill('-') << std::setw(w) << "+\n";

  std::cout.copyfmt(init);

  return os;
}
