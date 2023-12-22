/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:24:49 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/19 15:46:22 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define RGB_NONE "\033[0m"
# define RGB_B_GREEN "\033[1;32m"
# define RGB_B_ORANGE "\033[1;34m"

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& copy);
		virtual ~Animal();
		Animal& operator=(const Animal& copy);
		virtual void makeSound() const;
		std::string getType() const;
};

#endif
