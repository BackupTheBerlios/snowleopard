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
// config_io.h
//------------------------------------------------------------------------------
// Configuration applicable to all input/output C code.
//    - slci
//    - libslstdc
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_CONFIG_IO_H__
#define __SL_CONFIG_CONFIG_IO_H__

//------------------------------------------------------------------------------
// File position type
typedef sl_size_t sl_file_position_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Stream/buffer macros
//
// Macros for buffers and streams do not overlap.
//
// Buffer macros 
#define __SL__IOFIXEDBUF 01
#define __SL__IOLINEBUF  02
#define __SL__IOUNBUF    04
#define __SL_BUFFER_SIZE __SL_UINT_MAX
// Stream macros
#define __SL__IOREAD       010
#define __SL__IOWRITE      020
#define __SL__IOREADAHEAD  040
#define __SL__IOUNGETC     0100
#define __SL__IODIRTYBLOCK 0200
#define __SL__IOEOF        0400
#define __SL__IOERROR      01000
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// File maxima
//
// EOF macros
#define __SL_EOF ((int)(-1))
#define __SL_WEOF ((sl_wint_t)(-1))
// Open files
#define __SL_FOPEN_MAX __SL_UINT_MAX
#define __SL_TMP_MAX __SL_FOPEN_MAX
#define __SL_TMP_MAX_S __SL_TMP_MAX
// Filenames
#define __SL_FILENAME_MAX __SL_CHAR_MAX
#define __SL_L_tmpnam __SL_CHAR_MAX
#define __SL_L_tmpnam_s __SL_L_tmpnam
// Seek directives
#define __SL_SEEK_CUR 1
#define __SL_SEEK_END 2
#define __SL_SEEK_SET 3
//------------------------------------------------------------------------------

#endif /* !__SL_CONFIG_CONFIG_IO_H__ */

//-<EOF>

