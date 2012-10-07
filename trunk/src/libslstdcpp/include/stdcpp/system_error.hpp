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
// system_error.hpp
//------------------------------------------------------------------------------
// Standard system error implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_SYSTEM_ERROR_HPP__
#define __SL_STDCPP_IMPL_SYSTEM_ERROR_HPP__

#include <cerrno>
#include <cstddef>
#include <functional>
#include <stdexcept>
#include <string>
#include <type_traits>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // Forward definitions
  class error_category;
  class error_code;
  class error_condition;
  class system_error;
  enum class errc;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // error_category class
  class error_category {
  public:
    error_category(const error_category&) = delete;
    virtual ~error_category() noexcept;

    error_category& operator=(const error_category&) = delete;

    virtual const char* name() const noexcept = 0;
    virtual string message(int ev) const = 0;

    virtual error_condition default_error_condition(int ev) const noexcept;

    virtual bool equivalent(
			    int code, 
			    const error_condition& condition
                            ) const noexcept;  
    virtual bool equivalent(
			    const error_code& code, 
			    int condition
                            ) const noexcept;
    
    bool operator==(const error_category& rhs) const noexcept;
    bool operator!=(const error_category& rhs) const noexcept;
    bool operator<(const error_category& rhs) const noexcept;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Error category objects
  const error_category& generic_category() noexcept;
  const error_category& system_category() noexcept;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // error_code class
  class error_code {
  public:
    error_code() noexcept;
    error_code(int val, const error_category& cat) noexcept;
    template<typename ErrorCodeNum>
    error_code(ErrorCodeNum e) noexcept;

    void assign(int val, const error_category& cat) noexcept;
    template<typename ErrorCodeNum>
    error_code& operator=(ErrorCodeNum e) noexcept;
    void clear() noexcept;

    int value() const noexcept;
    const error_category& category() const noexcept;
    string message() const;

    error_condition default_error_condition() const noexcept;

    explicit operator bool() const noexcept;

  private:
    int value_;
    const error_category* category_;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Non member functions
  error_code make_error_code(errc e) noexcept;
  bool operator<(const error_code& lhs, const error_code& rhs) noexcept;

  template<typename charT, class traits>
  basic_ostream<charT, traits>& operator<<(
					   basic_ostream<charT,traits>& os,
					   const error_code& ec
                                           );
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // error_condition class
  class error_condition {
  public:
    error_condition() noexcept;
    error_condition(int val, const error_category& cat) noexcept;
    template<typename ErrorConditionNum>
    error_condition(ErrorConditionNum e) noexcept;

    void assign(int val, const error_category& cat) noexcept;
    template<typename ErrorConditionNum>
    error_condition& operator=(ErrorConditionNum e) noexcept;
    void clear() noexcept;

    int value() noexcept;
    const error_category& category() const noexcept;
    string message() const;

    explicit operator bool() const noexcept;
    
  private:
    int value_;
    const error_category* category_;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Non member functions
  bool operator<(
		 const error_condition& lhs, 
		 const error_condition& rhs
                 ) noexcept;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // system_error class
  class system_error : public runtime_error {
  public:
    system_error(error_code ec, const string& what_arg);
    system_error(error_code ec, const char* what_arg);
    system_error(error_code ec);
    system_error(int ev, const error_category& cat, const string& what_arg);
    system_error(int ev, const error_category& cat, const char* what_arg);

    const error_code& code() const noexcept;
    const char* what() const noexcept;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // is_error_code_enum template
  template<class T>
  struct is_error_code_enum : public false_type {
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // is_error_condition_enum template
  template<typename T>
  struct is_error_condition_enum : public false_type {
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // errc enum class
  enum class errc {
    address_family_not_supported = EAFNOSUPPORT,
      address_in_use = EADDRINUSE,
      address_not_available = EADDRNOTAVAIL,
      already_connected = EISCONN,
      argument_list_too_long = E2BIG,
      argument_out_of_domain = EDOM,
      bad_address = EFAULT,
      bad_file_descriptor = EBADF,
      bad_message = EBADMSG,
      broken_pipe = EPIPE,
      connection_aborted = ECONNABORTED,
      connection_already_in_progress = EALREADY,
      connection_refused = ECONNREFUSED,
      connection_reset = ECONNRESET,
      cross_device_link = EXDEV,
      destination_address_required = EDESTADDRREQ,
      device_or_resource_busy = EBUSY,
      directory_not_empty = ENOTEMPTY,
      executable_format_error = ENOEXEC,
      file_exists = EEXIST,
      file_too_large = EFBIG,
      filename_too_long = ENAMETOOLONG,
      function_not_supported = ENOSYS,
      host_unreachable = EHOSTUNREACH,
      identifier_removed = EIDRM,
      illegal_byte_sequence = EILSEQ,
      inappropriate_io_control_operation = ENOTTY,
      interrupted = EINTR,
      invalid_argument = EINVAL,
      invalid_seek = ESPIPE,
      io_error = EIO,
      is_a_directory = EISDIR,
      message_size = EMSGSIZE,
      network_down = ENETDOWN,
      network_reset = ENETRESET,
      network_unreachable = ENETUNREACH,
      no_buffer_space = ENOBUFS,
      no_child_process = ECHILD,
      no_link = ENOLINK,
      no_lock_available = ENOLCK,
      no_message_available = ENODATA,
      no_message = ENOMSG,
      no_protocol_option = ENOPROTOOPT,
      no_space_on_device = ENOSPC,
      no_stream_resources = ENOSR,
      no_such_device_or_address = ENXIO,
      no_such_device = ENODEV,
      no_such_file_or_directory = ENOENT,
      no_such_process = ESRCH,
      not_a_directory = ENOTDIR,
      not_a_socket = ENOTSOCK,
      not_a_stream = ENOSTR,
      not_connected = ENOTCONN,
      not_enough_memory = ENOMEM,
      not_supported = ENOTSUP,
      operation_canceled = ECANCELED,
      operation_in_progress = EINPROGRESS,
      operation_not_permitted = EPERM,
      operation_not_supported = EOPNOTSUPP,
      operation_would_block = EWOULDBLOCK,
      owner_dead = EOWNERDEAD,
      permission_denied = EACCES,
      protocol_error = EPROTO,
      protocol_not_supported = EPROTONOSUPPORT,
      read_only_file_system = EROFS,
      resource_deadlock_would_occur = EDEADLK,
      resource_unavailable_try_again = EAGAIN,
      result_out_of_range = ERANGE,
      state_not_recoverable = ENOTRECOVERABLE,
      stream_timeout = ETIME,
      text_file_busy = ETXTBSY,
      timed_out = ETIMEDOUT,
      too_many_files_open_in_system = ENFILE,
      too_many_open_files = EMFILE,
      too_many_links = EMLINK,
      too_many_symbolic_link_levels = ELOOP,
      value_too_large = EOVERFLOW,
      wrong_protocol_type = EPROTOTYPE,
      last_error = ELAST
      };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // is_error_condition_enum struct
  template<> struct is_error_condition_enum<errc> : true_type {
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // make_error_code function
  error_code make_error_code(errc e) noexcept;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // make_error_condition function
  error_code make_error_condition(errc e) noexcept;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Comparison operators
  bool operator==(const error_code& lhs, const error_code& rhs) noexcept;
  bool operator==(const error_code& lhs, const error_condition& rhs) noexcept;
  bool operator==(const error_condition& lhs, const error_code& rhs) noexcept;
  bool operator==(
		  const error_condition& lhs,
		  const error_condition& rhs
                  ) noexcept;
  bool operator!=(const error_code& lhs, const error_code& rhs) noexcept;
  bool operator!=(const error_code& lhs, const error_condition& rhs) noexcept;
  bool operator!=(const error_condition& lhs, const error_code& rhs) noexcept;
  bool operator!=(
		  const error_condition& lhs,
		  const error_condition& rhs
                  ) noexcept;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Hash support
  template<> struct hash<error_code> {
    std::size_t operator()(error_code const&) const;
  };
  //----------------------------------------------------------------------------

} /* std */
//==============================================================================

////////////////////////////////////////////////////////////////////////////////
// If compiler uses export, don't include source for templates
#ifdef __SL_COMPILER_USE_EXPORT__
# include <sl/stdcpp/detail/system_error.ipp>
#endif /* __SL_COMPILER_USE_EXPORT__ */
////////////////////////////////////////////////////////////////////////////////

#endif /* !__SL_STDCPP_IMPL_SYSTEM_ERROR_HPP__ */

//-<EOF>
