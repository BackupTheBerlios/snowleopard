/*==============================================================================
  Snow Leopard C++ Tools
  
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
// iostream.cpp
//------------------------------------------------------------------------------
// Standard iostream implementation
//------------------------------------------------------------------------------

#include <sl/config/config.hpp>

#include <iostream>

//------------------------------------------------------------------------------
// Define character stream objects
std::istream cin;
std::ostream cout;
std::ostream cerr;
std::ostream clog;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Define wide-character stream objects
std::wistream wcin;
std::wostream wcout;
std::wostream wcerr;
std::wostream wclog;
//------------------------------------------------------------------------------

namespace std {

  namespace {

    //--------------------------------------------------------------------------
    // Make sure objects are initialized before they can ever be used
    class io_initializer
    {
    private:
      static sl::config::sl_size_t counter_;

    public:
      io_initializer ()
      {
	if (counter_++ == 0)
	  {
	    // Initialize streams
	    std::cin = std::istream (0);
	    std::cout = std::ostream (0);
	    std::cerr = std::ostream (0);
	    std::clog = std::ostream (0);

	    // Tie cout to cin
	    std::cin.tie (std::cout);

	    // Only perform unit buffering on cerr
	    std::cerr.setf (std::ios_base::unitbuf);

	  }
      }

      ~io_initializer ()
      {
	if (--counter_ == 0)
	  {
	    // Sync objects
	    std::cout.flush ();
	    std::cerr.flush ();
	    std::clog.flush ();

	    // Close streams
	    std::cin.close ();
	    std::cout.close ();
	    std::cerr.close ();
	    std::clog.close ();

	  }
      }

    };

    static io_initializer io_init;
    //--------------------------------------------------------------------------

  } /* std::<unnamed> */
  //============================================================================

} /* std */
//==============================================================================

//-<EOF>
