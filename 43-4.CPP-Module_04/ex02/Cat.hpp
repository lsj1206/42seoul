/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:36:13 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/20 18:13:54 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain* brain;
	public:
		Cat();
		Cat(const Cat& copy);
		~Cat();
		Cat &operator=(const Cat& copy);
		void makeSound() const;
		std::string getType() const;
};

#endif
