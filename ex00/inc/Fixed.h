/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:18:48 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/26 14:18:51 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_FIXED_H
#define EX00_FIXED_H

#include <iostream>

class Fixed {
private:
    int rawBits;
    static const int bits = 8;

public:
    Fixed(int rawBits);
    Fixed();
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed & operator = (const Fixed &other);
    int getRawBits() const;

};



#endif //EX00_FIXED_H
