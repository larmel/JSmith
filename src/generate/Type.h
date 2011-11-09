#ifndef TYPE_H
#define TYPE_H


// Defines the variable type enums
// Must be powers of two! 
enum Type {
    UNDEFINED_T = 1, NULL_T = 2, BOOLEAN_T = 4, NUMBER_T = 8, STRING_T = 16, OBJECT_T = 32, FUNCTION_T = 64
};
 

#endif
