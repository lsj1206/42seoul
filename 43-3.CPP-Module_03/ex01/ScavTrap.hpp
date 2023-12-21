/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:39 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/20 16:24:02 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# define RGB_GREEN "\033[0;32m"
# define RGB_CYAN "\033[0;36m"

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	protected:
		bool Guardgate_mode;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& copy);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap& copy);
		void attack(const std::string& target);
		void guardGate();
};

#endif
