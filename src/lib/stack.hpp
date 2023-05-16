#ifndef STACK_HPP
#define STACK_HPP

#include <exception>

// simple exception class
class StackException : public std::exception
{
    private:
        const char *msg;
        StackException(){}; // no default constructor

    public:
        explicit StackException(const char *s)  throw(): msg(s){ }
        const char *what() const throw() {return msg;}

};

// simple fixed-size LIFO stack template
template <typename T>
class Stack
{
    private:
        static const int defaultSize = 10;
        static const int maxSize = 1000;
        int m_size;
        int m_top;
        T *stackPtr;

    public:
        explicit Stack(int s = defaultSize);
        ~Stack() {delete[] stackPtr;}
        T &push(const T &);
        T &pop();
        bool isEmpty() const
        {
            return m_top < 0;
        }

        bool isFull() const
        {
            return m_top >= m_size - 1;
        }

        int top() const
        {
            return m_top;
        }

        int size() const
        {
            return m_size;
        }
};

// Stack<T> constructor
template <typename T>
Stack<T>::Stack(int s)
{
    if(s > maxSize || s < 1) throw StackException("invalid stack size");
    else m_size = s;
    stackPtr = new T[m_size];
    m_top = -1;
}

template <typename T>
T &Stack<T>::push(const T &i)
{
    if(isFull()) throw StackException("stack full");
    return stackPtr[++m_top] = i;
}

template <typename T>
T &Stack<T>::pop()
{
    if(isEmpty()) throw StackException("stack empty");
    return stackPtr[m_top--];
}

#endif