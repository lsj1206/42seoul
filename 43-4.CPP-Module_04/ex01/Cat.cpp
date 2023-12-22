/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:36:11 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/12 18:32:40 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << RGB_B_ORANGE << "Cat constructor called" << RGB_NONE << std::endl;
}

Cat::Cat(const Cat& copy) {
	this->brain = new Brain();
	*this = copy;
	std::cout << RGB_B_ORANGE << "Cat copy constructor called" << RGB_NONE << std::endl;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << RGB_B_ORANGE << "Cat destructor called" << RGB_NONE << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	if (this != &copy) {
		this->type = copy.type;
		*this->brain = *copy.brain;
	}
	std::cout << RGB_B_ORANGE << "Dog copy assignment operator called" << RGB_NONE << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << RGB_B_ORANGE << "Meow~" << RGB_NONE << std::endl;
}
