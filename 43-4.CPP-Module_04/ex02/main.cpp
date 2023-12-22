/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:58:56 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/22 14:21:10 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {

	const AAnimal* dog = new Dog();
	std::cout << "[" << dog->getType() << "]" << std::endl;
	dog->makeSound();
	delete dog;

	const AAnimal* cat = new Cat();
	std::cout << "[" << cat->getType() << "]" <<  std::endl;
	cat->makeSound();
	delete cat;

	// AAnimal animal;
	// animal.makeSound();
	return 0;
}
