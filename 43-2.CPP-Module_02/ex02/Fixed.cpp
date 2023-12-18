/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:50:31 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/18 17:12:01 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
Fixed::Fixed() : RawBit(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	//std::cout << "Destructor Called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	//std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(copy.getRawBits());
}

Fixed& Fixed::operator=(const Fixed &copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->setRawBits(copy.getRawBits());
	return *this;
}

int Fixed::getRawBits() const {
	return this->RawBit;
}

void Fixed::setRawBits(const int raw) {
	this->RawBit = raw;
}

Fixed::Fixed(const int n) {
	this->RawBit = (n << this->bits);
}

Fixed::Fixed(const float n) {
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

int Fixed::operator>(const Fixed &fixed) const {
	return this->RawBit > fixed.getRawBits();
}

int Fixed::operator<(const Fixed &fixed) const {
	return this->RawBit < fixed.getRawBits();
}

int Fixed::operator>=(const Fixed &fixed) const {
	return this->RawBit >= fixed.getRawBits();
}

int Fixed::operator<=(const Fixed &fixed) const {
	return this->RawBit <= fixed.getRawBits();
}

int Fixed::operator==(const Fixed &fixed) const {
	return this->RawBit == fixed.getRawBits();
}

int Fixed::operator!=(const Fixed &fixed) const {
	return this->RawBit != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	return this->toFloat() + fixed.toFloat();
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	return this->toFloat() - fixed.toFloat();
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	return this->toFloat() * fixed.toFloat();
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	return this->toFloat() / fixed.toFloat();
}

Fixed Fixed::operator++() { //++n
	this->RawBit++;
	return *this;
}

Fixed Fixed::operator++(int) { // n++
	Fixed tmp;
	tmp.RawBit = this->RawBit;
	this->RawBit++;
	return tmp;
}

Fixed Fixed::operator--() { // ++n
	this->RawBit--;
	return *this;
}

Fixed Fixed::operator--(int) { // n++
	Fixed tmp;
	tmp.RawBit = this->RawBit;
	this->RawBit--;
	return tmp;
}

Fixed &Fixed::min(Fixed &fixed_1, Fixed &fixed_2) {
	if (fixed_1 < fixed_2)
		return fixed_1;
	else
		return fixed_2;
}

const Fixed &Fixed::min(const Fixed &fixed_1, const Fixed &fixed_2) {
	if (fixed_1 < fixed_2)
		return fixed_1;
	else
		return fixed_2;
}

Fixed &Fixed::max(Fixed &fixed_1, Fixed &fixed_2) {
	if (fixed_1 > fixed_2)
		return fixed_1;
	else
		return fixed_2;
}

const Fixed &Fixed::max(const Fixed &fixed_1, const Fixed &fixed_2) {
	if (fixed_1 > fixed_2)
		return fixed_1;
	else
		return fixed_2;
}
