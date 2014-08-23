/* 
 * File:   Math.h
 * Author: Ben Jenkins
 *
 * Created on April 29, 2014, 6:30 PM
 */

#ifndef MATH_H
#define	MATH_H

namespace math {
    template<typename Type> Type max(Type t1, Type t2);
    template<typename Type> Type min(Type t1, Type t2);
}

namespace math {

    template<typename Type> Type max(Type t1, Type t2) {
        if (t1 > t2) {
            return t1;
        } else {
            return t2;
        }
    }

    template<typename Type> Type min(Type t1, Type t2) {
        if (t1 < t2) {
            return t1;
        } else {
            return t2;
        }
    }
}

#endif	/* MATH_H */

