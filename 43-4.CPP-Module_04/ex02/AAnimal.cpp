/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:24:46 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/22 18:50:14 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal") {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& copy) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	this->type = copy.type;
	return *this;
}

void AAnimal::makeSound() const {
	std::cout << "AAnimal Sound" << std::endl;
}

std::string AAnimal::getType() const {
	return this->type;
}
