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
// platform/x86_64/jmp_buf.h
//------------------------------------------------------------------------------
// Include for platform dependent headers
//------------------------------------------------------------------------------

#ifndef __SL_STDC_PLATFORM_x86_64_JMP_BUF_H__
#define __SL_STDC_PLATFORM_x86_64_JMP_BUF_H__

//------------------------------------------------------------------------------
// jmp_buf structure
struct jmp_buf {
  unsigned long r1;
  unsigned long r2;
  /* TODO: Add x86_64 specific registers */
};
//------------------------------------------------------------------------------

#endif /* __SL_STDC_PLATFORM_x86_64_JMP_BUF_H__ */

//-<EOF>

