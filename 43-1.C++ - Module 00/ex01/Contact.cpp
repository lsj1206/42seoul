/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:57:18 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/05 17:00:17 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::input_first_name(std::string str) {
	this->first_name = str;
}

void Contact::input_last_name(std::string str) {
	this->last_name = str;
}

void Contact::input_nickname(std::string str) {
	this->nickname = str;
}

void Contact::input_phone(std::string str) {
	this->phone = str;
}

void Contact::input_secret(std::string str) {
	this->secret = str;
}

std::string Contact::output_first_name() {
	return this->first_name;
}

std::string Contact::output_last_name() {
	return this->last_name;
}

std::string Contact::output_nickname() {
	return this->nickname;
}

std::string Contact::output_phone() {
	return this->phone;
}

std::string Contact::output_secret() {
	return this->secret;
}
