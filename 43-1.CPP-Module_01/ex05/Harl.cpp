/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:01:13 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/14 18:38:27 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	std::cout << RGB_PURPLE << "Constructor Called!" << RGB_NONE << std::endl;
}

Harl::~Harl() {
	std::cout << RGB_PURPLE << "Destructor Called!" << RGB_NONE << std::endl;
}

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
	 << " I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money."
	<< " You didn’t put enough bacon in my burger!"
	<< " If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free."
	<< " I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*f[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levelList[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4 ; i++) {
		if (!level.compare(levelList[i])) {
			(this->*f[i])();
			return ;
		}
	}
	std::cout << RGB_RED << "Invalid level" << RGB_NONE << std::endl;
}
