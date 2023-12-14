/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:58:27 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/07 12:53:03 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileManager.hpp"

int err_handler(std::string msg){
	std::cerr << msg << std::endl;
	return 1;
}

int main(int ac, char **av) {
	if (ac != 4)
		return (err_handler("Wrong Arguments"));

	FileManager filemanager(av[1], av[2], av[3]);

	if (filemanager.checkArg())
		return (err_handler("Wrong Arguments"));
	if (filemanager.getFile())
		return (err_handler("File Open Error"));
	filemanager.stringReplace();
	return 0;
}
