/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:58:20 by ssadiki           #+#    #+#             */
/*   Updated: 2022/12/16 18:52:31 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
# include <iostream>

class Fixed{
	int					fxpt;
	static const int	bits = 8;
	public :
		Fixed(void);
		Fixed(Fixed	&f);
		Fixed&	operator= (const Fixed& f);
		~Fixed(void);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
#endif
