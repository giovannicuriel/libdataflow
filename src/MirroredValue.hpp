#ifndef MIRRORED_VALUE_HPP
#define MIRRORED_VALUE_HPP
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
