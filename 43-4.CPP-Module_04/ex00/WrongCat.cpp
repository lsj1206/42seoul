/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:32:51 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/12 18:09:34 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << RGB_B_RED << "WrongCat constructor called" << RGB_NONE << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) {
	*this = copy;
	std::cout << RGB_B_RED << "WrongCat copy constructor called" << RGB_NONE << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << RGB_B_RED << "WrongCat destructor called" << RGB_NONE << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	this->type = copy.type;
	std::cout << RGB_B_RED << "WrongCat copy assignment operator called" << RGB_NONE << std::endl;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << RGB_B_RED << "WrongCat Sound" << " Meow~" << RGB_NONE << std::endl;
}
