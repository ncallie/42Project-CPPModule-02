/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:19:38 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/26 14:19:42 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.h"

/*Constructors and operators*/
Fixed::Fixed() {
    this->rawBits = 0;
}

Fixed::Fixed(const int v_int) {
    this->rawBits = v_int << bits;
}

Fixed::Fixed(const float v_float) {
    this->rawBits = ((int)roundf(v_float * (1 << bits)));
}

Fixed::Fixed(const Fixed &other) {
    this->rawBits = other.getRawBits();
}

Fixed &Fixed::operator  =   (const Fixed &other) {
    this->rawBits = other.getRawBits();
    return *this;
}

/*Destructors*/
Fixed::~Fixed() {
}

/*arithmetic operators*/
Fixed Fixed::operator   +   (const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator   -   (const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator   *   (const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->getRawBits() * other.getRawBits()) >> bits);
    return result;
}

Fixed Fixed::operator   /   (const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->getRawBits() / other.getRawBits()) << bits);
    return result;
}

/*comparison operators*/

bool Fixed::operator    ==  (const Fixed &other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator    !=  (const Fixed &other) const {
    return this->getRawBits() != other.getRawBits();
}

bool Fixed::operator    <=  (const Fixed &other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator    >=  (const Fixed &other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator    >  (const Fixed &other) const {
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator    <  (const Fixed &other) const {
    return (this->getRawBits() < other.getRawBits());
}

/*increment/decrement*/
Fixed &Fixed::operator++() {
    this->rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->rawBits++;
    return temp;
}

Fixed &Fixed::operator--() {
    this->rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->rawBits--;
    return temp;
}

/*max/min*/
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return a > b ? a : b;
}
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a > b ? b : a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return a > b ? b : a;
}

/*Set*/
void Fixed::setRawBits(const int rawBits) {
    this->rawBits = rawBits;
}

/*Get*/
int Fixed::getRawBits() const {
    return this->rawBits;
}

/*Convert*/
float Fixed::toFloat(void) const {
    return ((float)rawBits / (1 << bits));
}

int Fixed::toInt(void) const {
    return rawBits >> bits;
}


std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed) {
    ostream << fixed.toFloat();
    return ostream;
}