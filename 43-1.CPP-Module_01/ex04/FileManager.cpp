/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:54:17 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/07 14:35:37 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileManager.hpp"

FileManager::FileManager(std::string name, std::string s1, std::string s2) {
	std::cout << RGB_PURPLE << "Constructor Called!" << RGB_NONE << std::endl;
	this->filename = name;
	this->s1 = s1;
	this->s2 = s2;
}

FileManager::~FileManager() {
	i_file.close();
	o_file.close();
	std::cout << RGB_PURPLE << "Destructor Called!" << RGB_NONE << std::endl;
}

int FileManager::checkArg() {
	if (filename.size() == 0 || s1.size() == 0 || s2.size() == 0)
		return 1;
	else
		return 0;
}

int FileManager::getFile() {
	i_file.open(filename.c_str());
	if (!i_file.is_open())
		return 1;
	o_file.open(filename.append(".replace").c_str());
	if (!o_file.is_open()) {
		i_file.close();
		return 1;
	}
	return 0;
}

void FileManager::stringReplace() {
	std::string line;
	std::size_t found = 0;

	while(getline(this->i_file, line)) {
		found = line.find(this->s1, 0);
		while (found != std::string::npos) {
			line.erase(found, this->s1.length());
			line.insert(found, this->s2);
			found = line.find(this->s1, found + this->s2.length());
		}
		this->o_file << line << "\n";
	}
}
