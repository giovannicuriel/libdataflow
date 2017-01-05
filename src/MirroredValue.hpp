#ifndef MIRRORED_VALUE_HPP
#define MIRRORED_VALUE_HPP


/**
 * Class representing variables that are mirrored.
 * 
 * These 'mirrored values' are variables that can be mirrored, i.e., 
 * associated with one another so that they contain their own local 
 * variable that is equal to their mirrored pair. This way, the 
 * possibility of invalid memory access by different task is decreased
 * to a minimum.
 * 
 * How to use it:
 * Let's say we have two variables:
 * 
 * MirroredValue<int> a;
 * MirroredValue<int> b;
 * 
 * And we associate them:
 * 
 * a.setReflection(b);
 * 
 * There are two ways to set and retrieve their values:
 * 
 * b() = 10; // We are changing b's value
 *
 * std::cout << *a << std::endl; // we are updating (copying its value
 *                               // from its reflection) and reading
 *                               // its value
 * 
 * std::cout << a() << std::endl; // we are just reading its value
 * 
 * 
 * You can think of this as a "lazy pointer with local storage"
 */
template<typename T> 
class MirroredValue {
public:
    MirroredValue() : mValue() { mReflection = nullptr; };
    MirroredValue(const MirroredValue &) = delete;
    MirroredValue(MirroredValue &&) = default;
    MirroredValue(T value);
    virtual ~MirroredValue();
    MirroredValue & operator=(const MirroredValue &) = delete;
    MirroredValue & operator=(T value);
    T & operator*();
    T & operator()();
    
    /**
     * Set its reflection.
     */
    void setReflection(MirroredValue & reflection);
protected:
    T mValue;
    MirroredValue * mReflection;
};

template<typename T>
MirroredValue<T>::~MirroredValue() {
    if (mReflection != nullptr) {
        mReflection->mReflection = nullptr;
    }
    mReflection = nullptr;
}

template<typename T>
MirroredValue<T>::MirroredValue(T value) {
    mValue = value;
    mReflection = nullptr;
}

template<typename T>
MirroredValue<T> & MirroredValue<T>::operator=(T value) {
    mValue = value;
    return *this;
};

template<typename T>
T & MirroredValue<T>::operator()() {
    return mValue;
}

template<typename T>
T & MirroredValue<T>::operator*() {
    if (mReflection != nullptr) {
        mValue = mReflection->mValue;
    };
    return mValue;
};

template<typename T>
void MirroredValue<T>::setReflection(MirroredValue<T> & reflection) {
    mReflection = &reflection;
    reflection.mReflection = this;
};
#endif
