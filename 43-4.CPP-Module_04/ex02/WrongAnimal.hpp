/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:32:49 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/19 15:46:09 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# define RGB_NONE "\033[0m"
# define RGB_B_RED "\033[1m\033[31m"
# define RGB_B_PURPLE "\033[1m\033[35m"

# include <iostream>
# include <string>

class WrongAnimal {
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& copy);
		void makeSound() const;
};

#endif
