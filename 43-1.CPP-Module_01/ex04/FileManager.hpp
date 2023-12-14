/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:54:11 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/07 14:35:29 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEMANAGER_HPP
# define FILEMANAGER_HPP

# define RGB_NONE "\033[0m"
# define RGB_RED "\033[0;31m"
# define RGB_PURPLE "\033[0;35m"

# include <iostream>
# include <fstream>
# include <string>

class FileManager {
	private :
		std::string filename;
		std::string s1;
		std::string s2;
		std::ifstream i_file;
		std::ofstream o_file;
	public :
		FileManager(std::string name, std::string s1, std::string s2);
		~FileManager();
		int checkArg();
		int getFile();
		void stringReplace();
};

#endif
