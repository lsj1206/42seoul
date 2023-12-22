/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:58:31 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/12 18:52:45 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# define RGB_NONE "\033[0m"
# define RGB_CYAN "\033[0;36m"

# include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& copy);
		~Brain();
		Brain& operator=(const Brain& copy);
		void setIdea(int idx, std::string idea);
		std::string getIdea(int idx) const;
};

#endif
