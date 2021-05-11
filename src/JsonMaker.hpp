#ifndef JSONMAKER_HPP
#define JSONMAKER_HPP

#include <Arduino.h>
#include <string.h>

String toString(float _type){
    String _str = std::to_string(_type);
    return _str;
}


#endif