/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:01:09 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/14 18:38:33 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# define RGB_NONE "\033[0m"
# define RGB_RED "\033[0;31m"
# define RGB_PURPLE "\033[0;35m"

# include <string>
# include <iostream>

class Harl {
	private:
		void debug();
		void info();
		void warning();
		void error();
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif
