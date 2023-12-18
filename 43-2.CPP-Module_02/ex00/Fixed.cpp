/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:50:31 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/16 17:06:13 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->RawBit = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor Called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(copy.getRawBits());
}

Fixed& Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->setRawBits(copy.getRawBits());
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->RawBit;
}

void Fixed::setRawBits(const int raw) {
	this->RawBit = raw;
}
