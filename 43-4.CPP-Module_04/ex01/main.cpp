/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:58:56 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/12 19:00:36 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	Animal* animals[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
		}
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}
	return 0;
}
