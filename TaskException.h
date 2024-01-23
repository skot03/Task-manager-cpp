#pragma once

#include <stdexcept> 

class VectorIndexException : public std::runtime_error {
private:
    int index;
public:
    VectorIndexException(const std::string& message, int index);
    ~VectorIndexException();

    int get_index() const;
};