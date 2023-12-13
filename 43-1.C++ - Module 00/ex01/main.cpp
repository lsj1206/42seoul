/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:57:05 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/05 17:00:38 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
	PhoneBook	pb;
	std::string	line;

	std::cout << RGB_PURPLE << "* Welcome C++ PhoneBook *" << RGB_NONE << std::endl;
	while(std::getline(std::cin, line))
	{
		if (line == "EXIT")
			pb.EXIT();
		else if (line == "ADD")
			pb.ADD();
		else if (line == "SEARCH")
			pb.SEARCH();
	}
	if (std::cin.eof())
		std::exit(0);
	return 0;
}
