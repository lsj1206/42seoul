/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:58:36 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/22 18:50:41 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << RGB_CYAN << "Brain constructor called" << RGB_NONE << std::endl;
}

Brain::Brain(const Brain& copy) {
	*this = copy;
	std::cout << RGB_CYAN << "Brain copy constructor called" << RGB_NONE << std::endl;
}

Brain::~Brain() {
	std::cout << RGB_CYAN << "Brain destructor called" << RGB_NONE << std::endl;
}

Brain& Brain::operator=(const Brain& copy) {
	if (this != &copy) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	std::cout << RGB_CYAN << "Brain copy assignment operator called" << RGB_NONE << std::endl;
	return *this;
}

void Brain::setIdea(int idx, std::string idea) {
	// 인덱스 범위 처리
	this->ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const {
	// 인덱스 범위 처리
	return this->ideas[idx];
}
