/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:58:20 by ssadiki           #+#    #+#             */
/*   Updated: 2022/12/20 16:41:43 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
# include <iostream>
# include <cmath>

class Fixed{
	int					fxpt;
	static const int	bits = 8;
	public :
		Fixed(void);
		Fixed(Fixed	const &f);
		Fixed(int const i);
		Fixed(float const f);
		~Fixed(void);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed&	operator=(const Fixed& f);
		bool	operator>(Fixed const& f) const;
		bool	operator<(Fixed const& f) const;
		bool	operator>=(Fixed const& f) const;
		bool	operator<=(Fixed const& f) const;
		bool	operator==(Fixed const& f) const;
		bool	operator!=(Fixed const& f) const;
		Fixed	operator+(Fixed const& f) const;
		Fixed	operator-(Fixed const& f) const;
		Fixed	operator*(Fixed const& f) const;
		Fixed	operator/(Fixed const& f) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		static Fixed&	max(Fixed &a, Fixed &b);
		static const Fixed&	max(Fixed const& a, Fixed const& b);
		static Fixed&	min(Fixed &a, Fixed &b);
		static const Fixed&	min(Fixed const& a, Fixed const& b);
};

std::ostream&	operator<<(std::ostream &o, Fixed const& f);
#endif
