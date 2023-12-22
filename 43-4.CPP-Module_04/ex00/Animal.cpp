/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:24:46 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/12 18:09:04 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = copy.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}
