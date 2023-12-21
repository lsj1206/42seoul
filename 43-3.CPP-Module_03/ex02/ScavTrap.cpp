/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:35 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/19 16:22:39 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	this->Guardgate_mode = false;
	std::cout << RGB_CYAN << "ScavTrap " << "Default" << " constructor called" << RGB_NONE << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	this->Guardgate_mode = false;
	std::cout << RGB_CYAN << "ScavTrap " << name << " constructor called" << RGB_NONE << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	std::cout << RGB_CYAN << "ScavTrap " << copy.Name << "copy constructor called" << RGB_NONE << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << RGB_CYAN << "ScavTrap " << this->Name << " destructor called" << RGB_NONE << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
	this->Name = copy.Name;
	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
	this->Guardgate_mode = copy.Guardgate_mode;
	std::cout << RGB_CYAN << "ScavTrap copy assignment operator called" << RGB_NONE << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (!checkHealth() || !checkEnergy())
		return ;
	this->Energy_points--;
	std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing "
	<< this->Attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	if (!checkHealth() || !checkEnergy())
		return ;
	this->Guardgate_mode = true;
	std::cout << "ScavTrap " << this->Name << " has entered Gatekeeper mode" << std::endl;
}
