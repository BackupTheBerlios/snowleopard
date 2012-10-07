/*==============================================================================
  Snow Leopard Standard C++ Library
  
  Copyright (C) 2008-2012 Roel Sergeant
  
  This program is free software: you can redistribute it and/or modify it under
  the terms of the GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option) any
  later version
  
  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
  details.
  
  You should have received a copy of the GNU General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>
  ============================================================================*/

//------------------------------------------------------------------------------
// auto_ptr.ipp
//------------------------------------------------------------------------------
// Standard memory -> auto_ptr implementation
//
// NOTE: 
//   If the compiler supports export, this is compiled into the standard 
//   library. If not it is included in the <memory> header.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// struct auto_ptr_ref constructor
template<typename Y> std::auto_ptr_ref<Y>::auto_ptr_ref(Y* rhs) : ptr(rhs) {
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr constructor
template<typename T> std::auto_ptr<T>::auto_ptr(T* rhs) noexcept : ptr(rhs) {
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr copy constructor
template<typename T>
std::auto_ptr<T>::auto_ptr(std::auto_ptr<T>& rhs) noexcept
    : ptr (rhs.release()) {
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr copy constructor with conversion
template<typename T>
template<typename U>
std::auto_ptr<T>::auto_ptr(std::auto_ptr<U>& rhs) noexcept
    : ptr(rhs.release()) {
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr assignment operator
template<typename T>
std::auto_ptr<T>& std::auto_ptr<T>::operator=(std::auto_ptr<T>& rhs) noexcept {
  reset(rhs.release());
  return *this;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr assignment operator with conversion
template<typename T>
  template<typename U>
std::auto_ptr<T>& std::auto_ptr<T>::operator=(std::auto_ptr<U>& rhs) noexcept {
  reset(release());
  return *this;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr destructor
template<typename T>
std::auto_ptr<T>::~auto_ptr() noexcept {
  delete ptr;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr copy and conversion
template<typename T>
std::auto_ptr<T>::auto_ptr(std::auto_ptr_ref<T> rhs) noexcept
    : ptr (rhs.ptr) {
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr assignment and conversion
template<typename T>
std::auto_ptr<T>& std::auto_ptr<T>::operator=(
    std::auto_ptr_ref<T> rhs
                                              ) noexcept {
  ptr(rhs.ptr);
  return *this;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr conversion operator auto_ptr_ref
template<typename T>
  template<typename U>
std::auto_ptr<T>::operator std::auto_ptr_ref<U>() noexcept {
  return auto_ptr_ref<U>(release());
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr conversion operator auto_ptr
template<typename T>
  template<typename U>
std::auto_ptr<T>::operator std::auto_ptr<U>() noexcept {
  return auto_ptr<U>(release());
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr get
template<typename T>
T* std::auto_ptr<T>::get() const noexcept {
  return ptr;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr indirection operator
template<typename T>
T& std::auto_ptr<T>::operator*() const noexcept {
  return *ptr;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr class member access operator
template<typename T>
T* std::auto_ptr<T>::operator->() const noexcept {
  return ptr;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr release
template<typename T>
T* std::auto_ptr<T>::release() noexcept {
  T* tmp(ptr);
  ptr = 0;
  return tmp;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// class auto_ptr reset
template<typename T>
void std::auto_ptr<T>::reset (T* rhs) noexcept {
  if(ptr != rhs) {
    delete ptr;
    ptr = rhs;
  }
}
//------------------------------------------------------------------------------

//-<EOF>
