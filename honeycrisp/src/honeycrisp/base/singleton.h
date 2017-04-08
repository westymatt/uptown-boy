#pragma once

#include <memory>

template <typename T> class Singleton {
public:
  static T *GetInstance();
  static void destroy();

private:
  Singleton(Singleton const &){};
  Singleton &operator=(Singleton const &){};

protected:
  static T *instance_;

  Singleton() { this->instance_ = static_cast<T *>(this); };
  ~Singleton(){};
};

template <typename T> T *Singleton<T>::instance_ = 0;

template <typename T> T *Singleton<T>::GetInstance() {
  if (!instance_) {
    Singleton<T>::instance_ = new T();
  }

  return instance_;
}

template <typename T> void Singleton<T>::destroy() {
  delete Singleton<T>::instance_;
  Singleton<T>::instance_ = nullptr;
}
