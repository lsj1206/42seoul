/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:59:06 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/12 15:15:48 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap frag;
	FragTrap frag2(frag);

	frag.attack("target3");
	frag.takeDamage(21);
	frag.beRepaired(99);
	frag.highFivesGuys();

	frag2.attack("target4");
	frag2.takeDamage(21);
	frag2.beRepaired(99);
	frag2.highFivesGuys();
	return 0;
}
