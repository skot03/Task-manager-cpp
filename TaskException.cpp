#include "TaskException.h"

// Definicja konstruktora i destruktora
VectorIndexException::VectorIndexException(const std::string& message, int index) : std::runtime_error(message), index(index) {}
VectorIndexException::~VectorIndexException() {}

// Definicja metody get_index
int VectorIndexException::get_index() const {
    return index;
}
