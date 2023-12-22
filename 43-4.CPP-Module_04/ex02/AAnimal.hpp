/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:24:49 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/22 14:19:53 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# define RGB_NONE "\033[0m"
# define RGB_B_GREEN "\033[1;32m"
# define RGB_B_ORANGE "\033[1;34m"

# include <iostream>
# include <string>

class AAnimal {
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const AAnimal& copy);
		virtual ~AAnimal();
		AAnimal& operator=(const AAnimal& copy);
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif
