/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:58:20 by ssadiki           #+#    #+#             */
/*   Updated: 2022/12/20 16:39:37 by ssadiki          ###   ########.fr       */
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
};

std::ostream&	operator<<(std::ostream &o, Fixed const& f);
#endif
