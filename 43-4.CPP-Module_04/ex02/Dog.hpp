/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:36:17 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/21 13:30:32 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog& copy);
		~Dog();
		Dog& operator=(const Dog& copy);
		void makeSound() const;
		std::string getType() const;
};

#endif
