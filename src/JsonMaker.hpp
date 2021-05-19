#ifndef JSONMAKER_HPP
#define JSONMAKER_HPP

#include <Arduino.h>
#include <string.h>
#include <stdio.h>

char* toString(float _value){
    char str_value[16];
    sprintf(str_value,"%.2fC", _value);
    
    return str_value;
}


#endif