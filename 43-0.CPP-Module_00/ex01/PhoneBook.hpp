/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:57:28 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/05 17:02:02 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int idx;
	public:
		PhoneBook();
		~PhoneBook();
		void EXIT();
		void ADD();
		void SEARCH();
		void print_phonebook();
		std::string str_vaild();
		std::string length_handler(std::string str);
};

#endif
