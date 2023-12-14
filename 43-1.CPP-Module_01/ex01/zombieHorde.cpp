/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:21:22 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/04 15:35:55 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return NULL;
	Zombie *zombies = new(std::nothrow) Zombie[N];
	if (zombies == NULL)
		return NULL;
	for (int i = 0; i < N; i++)
	{
		zombies[i].SetName(name);
		zombies[i].announce();
	}
	return zombies;
}
