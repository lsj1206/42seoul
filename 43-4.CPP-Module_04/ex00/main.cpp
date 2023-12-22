/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:58:56 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/12 17:50:50 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void) {
	const Animal* meta = new Animal();
	const Animal* i = new Dog();
	const Animal* j = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;

	meta->makeSound();
	i->makeSound();
	j->makeSound();

	delete meta;
	delete i;
	delete j;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();

	meta2->makeSound();
	i2->makeSound();

	delete meta2;
	delete i2;

	return 0;
}
