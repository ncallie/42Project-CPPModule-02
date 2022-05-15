/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:19:20 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/26 14:19:22 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.h"

/*Constructors and operators*/
Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->rawBits = 0;
}

Fixed::Fixed(const int v_int) {
    std::cout << "Int constructor called"<< std::endl;
    this->rawBits = v_int << bits;
}

Fixed::Fixed(const float v_float) {
    std::cout << "Float constructor called"<< std::endl;
    this->rawBits = ((int)(roundf)(v_float * (1 << bits)));
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called"<< std::endl;
    this->rawBits = other.rawBits;
}

/*Operators*/
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called"<< std::endl;
    this->rawBits = other.getRawBits();
    return *this;
}

/*Destructors*/
Fixed::~Fixed() {
    std::cout << "Destructor called"<< std::endl;
}

/*Set*/
void Fixed::setRawBits(const int rawBits) {
    std::cout << "setRawBits member function called"<< std::endl;
    this->rawBits = rawBits;
}

/*Get*/
int Fixed::getRawBits() const {
    return this->rawBits;
}

/*Subject*/
float Fixed::toFloat(void) const {
    return ((float) rawBits / (1 << bits));
}

int Fixed::toInt(void) const {
    return ((int)(roundf)((float)rawBits / (1 << bits)));
}


std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed) {
    ostream << fixed.toFloat();
    return ostream;
}