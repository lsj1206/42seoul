/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:58:27 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/04 16:28:32 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
	std::string A = "HI THIS IS BRAIN";
	std::string* stringPTR = &A;
	std::string& stringREF = A;

	std::cout << "\033[0;32m" << "String    Address : " << &A << std::endl;
	std::cout << "\033[0;34m" << "StringPTR Address : " << stringPTR << std::endl;
	std::cout << "\033[0;36m" << "StringREF Address : " << &stringREF << std::endl;
	std::cout << "\033[0;0m"<< std::endl;
	std::cout << "\033[0;32m" << "String    Value : " << A << std::endl;
	std::cout << "\033[0;34m" << "StringPTR Value : " << *stringPTR << std::endl;
	std::cout << "\033[0;36m" << "StringREF Value : " << stringREF << std::endl;
	std::cout << "\033[0;0m"<< std::endl;
	return 0;
}
