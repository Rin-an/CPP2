/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:03:10 by ssadiki           #+#    #+#             */
/*   Updated: 2022/12/20 16:41:27 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	this->fxpt = 0;
}

Fixed::Fixed(Fixed const &f)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(int const i)
{
	this->fxpt = i <<  this->bits;
}

Fixed::Fixed(float const f)
{
	this->fxpt = roundf(f * (1 << this->bits));
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& f)
{
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

bool	Fixed::operator>(Fixed const& f) const
{
	return (this->fxpt > f.getRawBits());
}

bool	Fixed::operator<(Fixed const& f) const
{
	return (this->fxpt < f.getRawBits());
}

bool	Fixed::operator==(Fixed const& f) const
{
	return (this->fxpt == f.getRawBits());
}

bool	Fixed::operator>=(Fixed const& f) const
{
	return (this->fxpt >= f.getRawBits());
}

bool	Fixed::operator<=(Fixed const& f) const
{
	return (this->fxpt <= f.getRawBits());
}

bool	Fixed::operator!=(Fixed const& f) const
{
	return (this->fxpt != f.getRawBits());
}

Fixed	Fixed::operator+(Fixed const& f) const
{
	Fixed	r;

	r.fxpt = this->fxpt + f.getRawBits();
	return (r);
}

Fixed	Fixed::operator-(Fixed const& f) const
{
	Fixed	r;

	r.fxpt = this->fxpt - f.getRawBits();
	return (r);
}

Fixed	Fixed::operator*(Fixed const& f) const
{
	Fixed	r(this->toFloat() * f.toFloat());

	return (r);
}

Fixed	Fixed::operator/(Fixed const& f) const
{
	Fixed	r(this->toFloat() / f.toFloat());

	return (r);
}

Fixed&	Fixed::operator++(void)
{
	++fxpt;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	f;

	f.fxpt = this->fxpt;
	++fxpt;
	return (f);
}

Fixed&	Fixed::operator--(void)
{
	--fxpt;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	f;

	f.fxpt = this->fxpt;
	--fxpt;
	return (f);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(Fixed const& a, Fixed const& b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(Fixed const& a, Fixed const& b)
{

	if (a <= b)
		return (a);
	else
		return (b);
}
