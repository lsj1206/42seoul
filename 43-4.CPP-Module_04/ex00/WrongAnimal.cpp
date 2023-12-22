/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:32:45 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/12 18:09:26 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << RGB_B_PURPLE << "WrongAnimal constructor called" << RGB_NONE << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	*this = copy;
	std::cout << RGB_B_PURPLE << "WrongAnimal copy constructor called" << RGB_NONE << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RGB_B_PURPLE << "WrongAnimal destructor called" << RGB_NONE << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	this->type = copy.type;
	std::cout << RGB_B_PURPLE << "WrongAnimal copy assignment operator called" << RGB_NONE << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << RGB_B_PURPLE << "WrongAnimal Sound" << RGB_NONE << std::endl;
}
