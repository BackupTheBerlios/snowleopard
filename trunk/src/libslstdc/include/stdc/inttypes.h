/*==============================================================================
  Snow Leopard Standard C Library
  
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
// inttypes.h
//------------------------------------------------------------------------------
// Standard integer types implementation
//------------------------------------------------------------------------------

#ifndef _SL_STDC_IMPL_INTTYPES_H_
#define _SL_STDC_IMPL_INTTYPES_H_

#include <sl/config/config.h>

#include <stddef.h>
#include <stdint.h>

//------------------------------------------------------------------------------
// imaxdiv_t struct
struct imaxdiv_t {
  intmax_t quot;
  intmax_t rem;
};

typedef struct imaxdiv_t imaxdiv_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Greatest width integer functions
intmax_t imaxabs(intmax_t j);
imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator);
intmax_t strtoimax(const char* restrict nptr, char** restrict endptr, int base);
uintmax_t strtoumax(
    const char* restrict nptr,
    char** restrict endptr,
    int base
                    );
intmax_t wcstoimax(
    const wchar_t* retrict nptr,
    wchar_t** restrict endptr,
    int base
                   );
uintmax_t wcstoumax(
    const wchar_t* restrict nptr,
    wchar_t** restrict endptr,
    int base
                    );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// PRI 8 macros
#define PRId8 "%hhd"
#define PRIi8 "%hhi"
#define PRIo8 "%hho"
#define PRIu8 "%hhu"
#define PRIx8 "%hhx"
#define PRIX8 "%hhX"
// PRI LEAST8 macros
#define PRIdLEAST8 PRId8
#define PRIiLEAST8 PRIi8
#define PRIoLEAST8 PRIo8
#define PRIuLEAST8 PRIu8
#define PRIxLEAST8 PRIx8
#define PRIXLEAST8 PRIX8
// PRI FAST8 macros
#define PRIdFAST8 SL_PRI_FAST_MACRO_d
#define PRIiFAST8 SL_PRI_FAST_MACRO_i
#define PRIoFAST8 SL_PRI_FAST_MACRO_o
#define PRIuFAST8 SL_PRI_FAST_MACRO_u
#define PRIxFAST8 SL_PRI_FAST_MACRO_x
#define PRIXFAST8 SL_PRI_FAST_MACRO_X
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// PRI 16 macros
#define PRId16 "%hd"
#define PRIi16 "%hi"
#define PRIo16 "%ho"
#define PRIu16 "%hu"
#define PRIx16 "%hx"
#define PRIX16 "%hX"
// PRI LEAST16 macros
#define PRIdLEAST16 PRId16
#define PRIiLEAST16 PRIi16
#define PRIoLEAST16 PRIo16
#define PRIuLEAST16 PRIu16
#define PRIxLEAST16 PRIx16
#define PRIXLEAST16 PRIX16
// PRI FAST16 macros
#define PRIdFAST16 SL_PRI_FAST_MACRO_d
#define PRIiFAST16 SL_PRI_FAST_MACRO_i
#define PRIoFAST16 SL_PRI_FAST_MACRO_o
#define PRIuFAST16 SL_PRI_FAST_MACRO_u
#define PRIxFAST16 SL_PRI_FAST_MACRO_x
#define PRIXFAST16 SL_PRI_FAST_MACRO_X
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// PRI 32 macros
#define PRId32 "%ld"
#define PRIi32 "%li"
#define PRIo32 "%lo"
#define PRIu32 "%lu"
#define PRIx32 "%lx"
#define PRIX32 "%lX"
// PRI LEAST32 macros
#define PRIdLEAST32 PRId32
#define PRIiLEAST32 PRIi32
#define PRIoLEAST32 PRIo32
#define PRIuLEAST32 PRIu32
#define PRIxLEAST32 PRIx32
#define PRIXLEAST32 PRIX32
// PRI FAST32 macros
#define PRIdFAST32 SL_PRI_FAST_MACRO_d
#define PRIiFAST32 SL_PRI_FAST_MACRO_i
#define PRIoFAST32 SL_PRI_FAST_MACRO_o
#define PRIuFAST32 SL_PRI_FAST_MACRO_u
#define PRIxFAST32 SL_PRI_FAST_MACRO_x
#define PRIXFAST32 SL_PRI_FAST_MACRO_X
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// PRI 64 macros
#define PRId64 "%lld"
#define PRIi64 "%lli"
#define PRIo64 "%llo"
#define PRIu64 "%llu"
#define PRIx64 "%llx"
#define PRIX64 "%llX"
// PRI LEAST64 macros
#define PRIdLEAST64 PRId64
#define PRIiLEAST64 PRIi64
#define PRIoLEAST64 PRIo64
#define PRIuLEAST64 PRIu64
#define PRIxLEAST64 PRIx64
#define PRIXLEAST64 PRIX64
// PRI FAST64 macros
#define PRIdFAST64 SL_PRI_FAST_MACRO_d
#define PRIiFAST64 SL_PRI_FAST_MACRO_i
#define PRIoFAST64 SL_PRI_FAST_MACRO_o
#define PRIuFAST64 SL_PRI_FAST_MACRO_u
#define PRIxFAST64 SL_PRI_FAST_MACRO_x
#define PRIXFAST64 SL_PRI_FAST_MACRO_X
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// PRI MAX macros
#define PRIdMAX PRId64
#define PRIiMAX PRIi64
#define PRIoMAX PRIo64
#define PRIuMAX PRIu64
#define PRIxMAX PRIx64
#define PRIXMAX PRIX64
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// PRI PTR macros
#define PRIdPTR SL_PRI_PTR_MACRO_d
#define PRIiPTR SL_PRI_PTR_MACRO_i
#define PRIoPTR SL_PRI_PTR_MACRO_o
#define PRIuPTR SL_PRI_PTR_MACRO_u
#define PRIxPTR SL_PRI_PTR_MACRO_x
#define PRIXPTR SL_PRI_PTR_MACRO_X
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// SCN 8 macros
#define SCNd8 "%hhd"
#define SCNi8 "%hhi"
#define SCNo8 "%hho"
#define SCNu8 "%hhu"
#define SCNx8 "%hhx"
#define SCNX8 "%hhX"
// SCN LEAST8 macros
#define SCNdLEAST8 SCNd8
#define SCNiLEAST8 SCNi8
#define SCNoLEAST8 SCNo8
#define SCNuLEAST8 SCNu8
#define SCNxLEAST8 SCNx8
#define SCNXLEAST8 SCNX8
// SCN FAST8 macros
#define SCNdFAST8 SL_SCN_FAST_MACRO_d
#define SCNiFAST8 SL_SCN_FAST_MACRO_i
#define SCNoFAST8 SL_SCN_FAST_MACRO_o
#define SCNuFAST8 SL_SCN_FAST_MACRO_u
#define SCNxFAST8 SL_SCN_FAST_MACRO_x
#define SCNXFAST8 SL_SCN_FAST_MACRO_X
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// SCN 16 macros
#define SCNd16 "%hd"
#define SCNi16 "%hi"
#define SCNo16 "%ho"
#define SCNu16 "%hu"
#define SCNx16 "%hx"
#define SCNX16 "%hX"
// SCN LEAST16 macros
#define SCNdLEAST16 SCNd16
#define SCNiLEAST16 SCNi16
#define SCNoLEAST16 SCNo16
#define SCNuLEAST16 SCNu16
#define SCNxLEAST16 SCNx16
#define SCNXLEAST16 SCNX16
// SCN FAST16 macros
#define SCNdFAST16 SL_SCN_FAST_MACRO_d
#define SCNiFAST16 SL_SCN_FAST_MACRO_i
#define SCNoFAST16 SL_SCN_FAST_MACRO_o
#define SCNuFAST16 SL_SCN_FAST_MACRO_u
#define SCNxFAST16 SL_SCN_FAST_MACRO_x
#define SCNXFAST16 SL_SCN_FAST_MACRO_X
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// SCN 32 macros
#define SCNd32 "%ld"
#define SCNi32 "%li"
#define SCNo32 "%lo"
#define SCNu32 "%lu"
#define SCNx32 "%lx"
#define SCNX32 "%lX"
// SCN LEAST32 macros
#define SCNdLEAST32 SCNd32
#define SCNiLEAST32 SCNi32
#define SCNoLEAST32 SCNo32
#define SCNuLEAST32 SCNu32
#define SCNxLEAST32 SCNx32
#define SCNXLEAST32 SCNX32
// SCN FAST32 macros
#define SCNdFAST32 SL_SCN_FAST_MACRO_d
#define SCNiFAST32 SL_SCN_FAST_MACRO_i
#define SCNoFAST32 SL_SCN_FAST_MACRO_o
#define SCNuFAST32 SL_SCN_FAST_MACRO_u
#define SCNxFAST32 SL_SCN_FAST_MACRO_x
#define SCNXFAST32 SL_SCN_FAST_MACRO_X
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// SCN 64 macros
#define SCNd64 "%lld"
#define SCNi64 "%lli"
#define SCNo64 "%llo"
#define SCNu64 "%llu"
#define SCNx64 "%llx"
#define SCNX64 "%llX"
// SCN LEAST64 macros
#define SCNdLEAST64 SCNd64
#define SCNiLEAST64 SCNi64
#define SCNoLEAST64 SCNo64
#define SCNuLEAST64 SCNu64
#define SCNxLEAST64 SCNx64
#define SCNXLEAST64 SCNX64
// SCN FAST64 macros
#define SCNdFAST64 SL_SCN_FAST_MACRO_d
#define SCNiFAST64 SL_SCN_FAST_MACRO_i
#define SCNoFAST64 SL_SCN_FAST_MACRO_o
#define SCNuFAST64 SL_SCN_FAST_MACRO_u
#define SCNxFAST64 SL_SCN_FAST_MACRO_x
#define SCNXFAST64 SL_SCN_FAST_MACRO_X
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// SCN MAX macros
#define SCNdMAX SCNd64
#define SCNiMAX SCNi64
#define SCNoMAX SCNo64
#define SCNuMAX SCNu64
#define SCNxMAX SCNx64
#define SCNXMAX SCNX64
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// SCN PTR macros
#define SCNdPTR SL_SCN_PTR_MACRO_d
#define SCNiPTR SL_SCN_PTR_MACRO_i
#define SCNoPTR SL_SCN_PTR_MACRO_o
#define SCNuPTR SL_SCN_PTR_MACRO_u
#define SCNxPTR SL_SCN_PTR_MACRO_x
#define SCNXPTR SL_SCN_PTR_MACRO_X
//------------------------------------------------------------------------------

#endif /* !_SL_STDC_IMPL_INTTYPES_H_ */

//-<EOF>
