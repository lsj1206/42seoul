/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:36:11 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/22 14:23:36 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << RGB_B_ORANGE << "Cat constructor called" << RGB_NONE << std::endl;
}

Cat::Cat(const Cat& copy) {
	std::cout << RGB_B_ORANGE << "Cat copy constructor called" << RGB_NONE << std::endl;
	this->type = copy.type;
}

Cat::~Cat() {
	std::cout << RGB_B_ORANGE << "Cat destructor called" << RGB_NONE << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	this->type = copy.type;
	std::cout << RGB_B_ORANGE << "Cat copy assignment operator called" << RGB_NONE << std::endl;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << RGB_B_ORANGE << "Meow~" << RGB_NONE << std::endl;
}
