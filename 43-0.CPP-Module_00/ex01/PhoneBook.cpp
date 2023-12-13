/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:57:23 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/05 17:01:18 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : idx(0) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::length_handler(std::string str) {
	if (str.length() > 10)
	{
		std::string new_str = str.substr(0, 9);
		new_str += ".";
		return new_str;
	}
	return str;
}

void PhoneBook::print_phonebook() {
	std::cout << RGB_PURPLE <<
	std::setw(10) << "Index" << "|" <<
	std::setw(10) << "First Name" << "|" <<
	std::setw(10) << "Last Name" << "|" <<
	std::setw(10) << "Nickname" << RGB_NONE << std::endl;
	for(int i = 0; i < 8; i++)
	{
		if (contacts[i].output_first_name().size() == 0)
			break ;
		std::cout << std::setw(10) << (i + 1) << "|" <<
		std::setw(10) << length_handler(contacts[i].output_first_name()) << "|" <<
		std::setw(10) << length_handler(contacts[i].output_last_name()) << "|" <<
		std::setw(10) << length_handler(contacts[i].output_nickname()) << std::endl;
	}
}

void PhoneBook::SEARCH() {
	std::string	line;
	int	Index = 0;

	print_phonebook();
	std::cout<< std::endl << "Input  Index : ";
	std::getline(std::cin, line);
	if (std::cin.eof())
		std::exit(0);
	std::istringstream i_str(line);
	if (i_str >> Index && (0 < Index && Index < 9)) {
		if (contacts[Index - 1].output_first_name().size() != 0)
		{
			std::cout << "  First Name : " << contacts[Index - 1].output_first_name() << std::endl;
			std::cout << "   Last Name : " << contacts[Index - 1].output_last_name() << std::endl;
			std::cout << "    NickName : " << contacts[Index - 1].output_nickname() << std::endl;
			std::cout << "Phone Number : " << contacts[Index - 1].output_phone() << std::endl;
			std::cout << "      Secret : " << contacts[Index - 1].output_secret() << std::endl;
			return ;
		}
	}
	std::cout << "Error : Invalid input" << std::endl;
	return ;
}

std::string PhoneBook::str_vaild() {
	std::string	str;

	std::getline(std::cin, str);
	if (std::cin.eof())
		std::exit(0);
	if(str.empty())
	{
		std::cout << RGB_RED << "    Required input : " << RGB_NONE;
		str = str_vaild();
	}
	return str;
}

void PhoneBook::ADD() {
	std::string	line;

	if(idx > 7)
		idx = 0;
 	std::cout << "  Input First Name : ";
	contacts[idx].input_first_name(str_vaild());
	std::cout << "   Input Last Name : ";
	contacts[idx].input_last_name(str_vaild());
	std::cout << "    Input Nickname : ";
	contacts[idx].input_nickname(str_vaild());
	std::cout << "Input Phone Number : ";
	contacts[idx].input_phone(str_vaild());
	std::cout << "      Input Secret : ";
	contacts[idx].input_secret(str_vaild());
	++this->idx;
	return ;
}

void PhoneBook::EXIT() {
	std::exit(0);
}
