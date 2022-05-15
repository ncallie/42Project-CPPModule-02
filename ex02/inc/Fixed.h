/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:19:33 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/26 14:19:35 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_FIXED_H
#define EX02_FIXED_H


#include <iostream>
#include <cmath>
class Fixed {
private:
    int rawBits;
    const static int bits = 8;

public:
    /*Constructors and operator =*/
    Fixed();
    Fixed(const int v_int);
    Fixed(const float v_float);
    Fixed(const Fixed &other);
    Fixed & operator = (const Fixed &other);

    /*Destructors*/
    ~Fixed();

    /*arithmetic operators*/
    Fixed operator + (const Fixed &other) const;
    Fixed operator - (const Fixed &other) const;
    Fixed operator * (const Fixed &other) const;
    Fixed operator / (const Fixed &other) const;

    /*comparison operators*/
    bool operator == (const Fixed &other) const;
    bool operator != (const Fixed &other) const;
    bool operator <= (const Fixed &other) const;
    bool operator >= (const Fixed &other) const;
    bool operator > (const Fixed &other) const;
    bool operator < (const Fixed &other) const;

    /*increment/decrement*/
    Fixed &operator ++();
    Fixed operator ++(int);
    Fixed &operator --();
    Fixed operator --(int);

    /*max/min*/
    Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    /*Set*/
    void setRawBits(const int rawBits);

    /*Get*/
    int getRawBits() const;

    /*Convert*/
    float toFloat( void ) const;
    int toInt( void ) const;

};

std::ostream& operator<<(std::ostream &ostream, const Fixed &fixed);



#endif //EX02_FIXED_H
