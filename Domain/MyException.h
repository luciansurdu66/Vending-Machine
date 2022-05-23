//
// Created by lucia on 5/18/2022.
//

#ifndef LAB09_10_MYEXCEPTION_H
#define LAB09_10_MYEXCEPTION_H
#include <exception>

class MyException : public std::exception {
private:
    const char *message;
public:
    /**
     * Constructor
     * @param message: exception message
     */
    MyException(const char *message) : message(message) {}

    /**
     * Getter for exception message
     * @return: exception message
     */
    const char *what() const noexcept override {
        return message;
    }
};
#endif //LAB09_10_MYEXCEPTION_H
