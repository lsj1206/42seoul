/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:36:14 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/22 14:20:08 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << RGB_B_GREEN << "Dog constructor called" << RGB_NONE << std::endl;
}

Dog::Dog(const Dog& copy) {
	this->brain = new Brain();
	*this = copy;
	std::cout << RGB_B_GREEN << "Dog copy constructor called" << RGB_NONE << std::endl;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << RGB_B_GREEN << "Dog destructor called" << RGB_NONE << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	if (this != &copy) {
		this->type = copy.type;
		*this->brain = *copy.brain;
	}
	std::cout << RGB_B_GREEN << "Dog copy assignment operator called" << RGB_NONE << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << RGB_B_GREEN << "Wall Wall!!! Wall Wall!!!" << RGB_NONE << std::endl;
}
