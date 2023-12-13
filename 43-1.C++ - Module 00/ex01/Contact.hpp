/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:57:12 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/05 17:00:24 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <sstream>
# include <string>

# define RGB_NONE "\033[0m"
# define RGB_RED "\033[0;31m"
# define RGB_PURPLE "\033[0;35m"

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone;
		std::string secret;
	public:
		void input_first_name(std::string str);
		void input_last_name(std::string str);
		void input_nickname(std::string str);
		void input_phone(std::string str);
		void input_secret(std::string str);
		std::string output_first_name();
		std::string output_last_name();
		std::string output_nickname();
		std::string output_phone();
		std::string output_secret();
};

#endif
