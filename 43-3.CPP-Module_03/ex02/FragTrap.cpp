/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:12:47 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/19 16:22:51 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << RGB_ORANGE << "FragTrap " << "Default" << " constructor called" << RGB_NONE << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << RGB_ORANGE << "FragTrap " << this->Name << " constructor called" << RGB_NONE << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	std::cout << RGB_ORANGE << "FragTrap " << this->Name << " copy constructor called" << RGB_NONE << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << RGB_ORANGE << "FragTrap " << this->Name << " destructor called" << RGB_NONE << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
	this->Name = copy.Name;
	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
	std::cout << RGB_ORANGE << "FragTrap " << this->Name << " copy assignment operator called" << RGB_NONE << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys() {
	if (!checkHealth() || !checkEnergy())
		return ;
	std::cout << "FragTrap " << this->Name << " high fives guys!" << std::endl;
}
