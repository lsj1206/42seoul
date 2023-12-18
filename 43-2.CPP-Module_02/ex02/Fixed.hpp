/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:50:29 by seojulee          #+#    #+#             */
/*   Updated: 2023/12/18 17:06:52 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		static const int bits = 8;
		int RawBit;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);

		int getRawBits() const;
		void setRawBits(const int raw);

		Fixed(const int n);
		Fixed(const float n);
		int toInt() const;
		float toFloat() const;

		int operator>(const Fixed &fixed) const;
		int operator<(const Fixed &fixed) const;
		int operator>=(const Fixed &fixed) const;
		int operator<=(const Fixed &fixed) const;
		int operator==(const Fixed &fixed) const;
		int operator!=(const Fixed &fixed) const;
		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);
		static Fixed &min(Fixed &fixed_1, Fixed &fixed_2);
		static const Fixed &min(const Fixed &fixed_1, const Fixed &fixed_2);
		static Fixed &max(Fixed &fixed_1, Fixed &fixed_2);
		static const Fixed &max(const Fixed &fixed_1, const Fixed &fixed_2);
};

std::ostream &operator<<(std::ostream &str, const Fixed &n);

#endif
