/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:29:13 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/20 16:21:17 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define RGB_NONE "\033[0m"
# define RGB_RED "\033[0;31m"
# define RGB_PURPLE "\033[0;35m"

#include <iostream>

class	ClapTrap {
	protected :
		std::string Name;
		unsigned int Hit_points;
		unsigned int Energy_points;
		unsigned int Attack_damage;
	public :
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		virtual ~ClapTrap();
		ClapTrap& operator=(const ClapTrap& copy);
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		bool checkHealth();
		bool checkEnergy();
};

#endif
