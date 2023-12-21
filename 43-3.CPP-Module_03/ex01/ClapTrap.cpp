/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:29:08 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/12 14:38:16 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), Hit_points(10), Energy_points(10), Attack_damage(0) {
	std::cout << RGB_PURPLE << "ClapTrap " << this->Name << " constructor called" << RGB_NONE << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name), Hit_points(10), Energy_points(10), Attack_damage(0) {
	std::cout << RGB_PURPLE << "ClapTrap " << this->Name << " constructor called" << RGB_NONE << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	this->Name = copy.Name;
	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
	std::cout << RGB_PURPLE << "ClapTrap copy constructor called" << RGB_NONE << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << RGB_PURPLE << "ClapTrap " << this->Name << " destructor Called" << RGB_NONE << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	this->Name = copy.Name;
	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
	std::cout << RGB_PURPLE << "ClapTrap copy assignment operator called" << RGB_NONE << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (!checkHealth() || !checkEnergy())
		return ;
	this->Energy_points--;
	std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing "
	<< this->Attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!checkHealth() || !checkEnergy())
		return ;
	for (unsigned int i = 0; i < amount; i++) {
		if (this->Hit_points == 0)
			break ;
		this->Hit_points--;
	}
	std::cout << "ClapTrap " << this->Name << " takes " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!checkHealth() || !checkEnergy())
		return ;
	this->Energy_points--;
	this->Hit_points += amount;
	std::cout << "ClapTrap " << this->Name << " repaired " << amount << " Health!" << std::endl;
}

bool ClapTrap::checkHealth() {
	if (this->Hit_points != 0)
		return (true);
	std::cout << RGB_RED << this->Name << "'s Health zero" << RGB_NONE << std::endl;
	return (false);
}

bool ClapTrap::checkEnergy() {
	if (this->Energy_points != 0)
		return (true);
	std::cout << RGB_RED << this->Name << " not enough Energy" << RGB_NONE << std::endl;
	return (false);
}

