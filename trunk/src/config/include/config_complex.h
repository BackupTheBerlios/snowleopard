/*==============================================================================
  Snow Leopard Compiler Project
  
  Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
  
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
// config_complex.h
//------------------------------------------------------------------------------
// Configuration applicable to all complex number C code.
//    - slci
//    - libslstdc
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_CONFIG_COMPLEX_H__
#define __SL_CONFIG_CONFIG_COMPLEX_H__

//------------------------------------------------------------------------------
// Complex/imaginary type
#define __SL_COMPLEX_T _Complex
#define __SL_COMPLEX_I 1
#define __SL_IMAGINARY_T _Imaginary
#define __SL_IMAGINARY_I SL_COMPLEX_I
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// CX_LIMITED_RANGE pragma
#define __SL_CX_LIMITED_RANGE DEFAULT
//------------------------------------------------------------------------------

#endif /* !__SL_CONFIG_CONFIG_COMPLEX_H__ */

//-<EOF>

