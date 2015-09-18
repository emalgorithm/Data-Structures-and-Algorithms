/* 
 * File:   container.h
 * Author: ema
 *
 * Created on September 18, 2015, 4:36 PM
 */

#ifndef CONTAINER_H
#define	CONTAINER_H

#include <stddef.h>

class Container {
public:
    Container(size_t maxSize = 50000000);
    size_t size();
    bool empty();
    bool full();
    
protected:
    size_t sizeValue;
    
private:
    size_t maxSize;
};



#endif	/* CONTAINER_H */

