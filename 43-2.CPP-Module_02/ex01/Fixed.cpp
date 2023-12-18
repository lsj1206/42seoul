/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:50:31 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/18 16:52:37 by seojulee         ###   ########.fr       */
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

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->RawBit = (n << this->bits);
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	this->RawBit = roundf(n * 256);
}

int Fixed::toInt() const {
	return this->RawBit >> this->bits;
}

float Fixed::toFloat() const {
	return (float)this->RawBit / 256;
}

std::ostream &operator<<(std::ostream &str, const Fixed &n) {
	str << n.toFloat();
	return str;
}
