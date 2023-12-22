/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:36:14 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/12 18:09:19 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << RGB_B_GREEN << "Dog constructor called" << RGB_NONE << std::endl;
}

Dog::Dog(const Dog& copy) {
	std::cout << RGB_B_GREEN << "Dog copy constructor called" << RGB_NONE << std::endl;
	*this = copy;
}

Dog::~Dog() {
	std::cout << RGB_B_GREEN << "Dog destructor called" << RGB_NONE << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	this->type = copy.type;
	std::cout << RGB_B_GREEN << "Dog copy assignment operator called" << RGB_NONE << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << RGB_B_GREEN << "Wall Wall!!! Wall Wall!!!" << RGB_NONE << std::endl;
}
