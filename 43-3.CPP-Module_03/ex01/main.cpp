/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:59:06 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/12 14:59:05 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav;

	scav.attack("Enemy2");
	scav.guardGate();
	scav.takeDamage(90);
	// for (int i = 0; i < 9; i++)
	// 	scav.beRepaired(1);
	scav.takeDamage(11);
	scav.attack("Enemy2");
	return 0;
}
