/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:03:10 by ssadiki           #+#    #+#             */
/*   Updated: 2022/12/20 16:40:35 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fxpt = 0;
}

Fixed::Fixed(Fixed const &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(int const i)
{
	std::cout << "Int constructor called" << std::endl;
	this->fxpt = i <<  this->bits;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->fxpt = roundf(f * (1 << this->bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fxpt = f.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->fxpt);
}

void	Fixed::setRawBits(int const raw)
{
	this->fxpt = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float) this->fxpt / (1 << this->bits));
}

int	Fixed::toInt(void) const
{
	return (this->fxpt >> this->bits);
}

std::ostream&	operator<<(std::ostream &o, Fixed const& f)
{
	o << f.toFloat();
	return (o);
}
