/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:58:56 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/11 17:36:35 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap trap("Trap1");

	trap.attack("Enemy1");
	trap.takeDamage(9);
	for (int i = 0; i < 9; i++)
		trap.beRepaired(1);
	trap.attack("Enemy1");
	trap.attack("Enemy1");
	return 0;
}
