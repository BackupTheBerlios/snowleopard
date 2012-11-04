/*==============================================================================
  Snow Leopard C++ Compiler Front End
  
  Copyright (C) 2009, 2010, 2011, 2012 Roel Sergeant
  
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
// strings.c
//------------------------------------------------------------------------------
// Managed string for the compiler front end.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "strings.h"
#include "types.h"

#include "char_functions.h"

//------------------------------------------------------------------------------
// Private variables
//
const size_t InitialStringSize = 256;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_new function
//
// Initialize a new string object.
//
slcc_string* str_new () 
{
  slcc_string* s = malloc (sizeof (slcc_string));

  s->size = 0;
  s->reserved = InitialStringSize;
  
  s->value = malloc (sizeof (char[InitialStringSize]));
  s->value[0] = '\0';

  return s;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_new_with_data function
//
// Initialize a string object with data.
//
slcc_string* str_new_with_data (const char* data) 
{
  size_t i;
  slcc_string* s  = str_new ();

  for (i = 0; data[i] != '\0'; ++i)
    str_append (s, data[i]);

  return s;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_new_16 function
//
// Initialize a new string16 object.
//
slcc_string16* str_new_16 () 
{
  slcc_string16* s = malloc (sizeof (slcc_string16));

  s->size = 0;
  s->reserved = InitialStringSize;

  s->value = malloc (sizeof (char16_t[InitialStringSize]));
  s->value[0] = '\0';

  return s;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_new_32 function
//
// Initialize a new string32 object.
//
slcc_string32* str_new_32 () 
{
  slcc_string32* s = malloc (sizeof (slcc_string32));

  s->size = 0;
  s->reserved = InitialStringSize;

  s->value = malloc (sizeof (char32_t[InitialStringSize]));
  s->value[0] = '\0';

  return s;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_new_w function
//
// Initialize a new wstring object.
//
slcc_wstring* str_new_w () 
{
  slcc_wstring* s = malloc (sizeof (slcc_wstring));

  s->size = 0;
  s->reserved = InitialStringSize;

  s->value = malloc (sizeof (wchar_t[InitialStringSize]));
  s->value[0] = '\0';

  return s;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_delete function
//
// Destroy string object.
//
void str_delete (slcc_string* s) 
{
  free (s->value);

  free (s);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_delete_16 function
//
// Destroy string16 object.
//
void str_delete_16 (slcc_string16* s) 
{
  free (s->value);

  free (s);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_delete_32 function
//
// Destroy string32 object.
//
void str_delete_32 (slcc_string32* s) 
{
  free (s->value);

  free (s);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_delete_w function
//
// Destroy wstring object.
//
void str_delete_w (slcc_wstring* s) 
{
  free (s->value);

  free (s);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_append function
//
// Append character to the string.
//
bool str_append (slcc_string* s, char c) 
{
  /* Check if string needs to be extended */
  if ((s->size + 1) > s->reserved)
    {
      char* old = s->value;
      s->reserved += InitialStringSize;
      s->value = malloc (sizeof (char[s->reserved]));
      if (s->value != 0)
	{
	  if (old != 0)
	    memcpy (s->value, old, s->size);
	  else
	    s->value[0] = '\0';

	  free (old);
	}
      else
	s->value[0] = '\0';
    }

  s->value[s->size] = c;
  s->value[++s->size] = '\0';

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_append_16 function
//
// Append character to the string16.
//
bool str_append_16 (slcc_string16* s, char16_t c) 
{
  /* Check if string needs to be extended */
  if ((s->size + 1) > s->reserved)
    {
      char16_t* old = s->value;
      s->reserved += InitialStringSize;
      s->value = malloc (sizeof (char16_t[s->reserved]));
      if (s->value != 0)
	{
	  if (old != 0)
	    memcpy (s->value, old, s->size * sizeof(char16_t));
	  else
	    s->value[0] = '\0';

	  free (old);
	}
      else
	s->value[0] = '\0';
    }

  s->value[s->size] = c;
  s->value[++s->size] = '\0';

  return true;
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// str_append_32 function
//
// Append character to the string32.
//
bool str_append_32 (slcc_string32* s, char32_t c) 
{
  /* Check if string needs to be extended */
  if ((s->size + 1) > s->reserved)
    {
      char32_t* old = s->value;
      s->reserved += InitialStringSize;
      s->value = malloc (sizeof (char32_t[s->reserved]));
      if (s->value != 0)
	{
	  if (old != 0)
	    memcpy (s->value, old, s->size * sizeof(char32_t));
	  else
	    s->value[0] = '\0';

	  free (old);
	}
      else
	s->value[0] = '\0';
    }

  s->value[s->size] = c;
  s->value[++s->size] = '\0';

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_append_w function
//
// Append wchar_t to the wstring.
bool str_append_w (slcc_wstring* s, wchar_t c) {
  /* Check if wstring needs to be extended */
  if ((s->size + 1) > s->reserved)
    {
      wchar_t* old = s->value;
      s->reserved += InitialStringSize;
      s->value = malloc (sizeof (wchar_t[s->reserved]));
      if (s->value != 0)
	{
	  if (old != 0)
	    memcpy (s->value, old, s->size * sizeof(wchar_t));
	  else
	    s->value[0] = '\0';

	  free (old);
	}
      else
	s->value[0] = '\0';
    }

  s->value[s->size] = c;
  s->value[++s->size] = '\0';

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_get_char_from_string function
//
// Get the character at position from the string.
char str_get_char_from_string(const slcc_string* s, size_t pos) {
  if (pos > s->size)
    return '\0';

  return s->value[pos];
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_get_c_string function
//
// Returns a copy of the string as C string.
//
char* str_get_c_string(const slcc_string* s) 
{
  char* cstr = malloc (sizeof (char[s->size + 1]));

  memcpy (cstr, s->value, s->size + 1);

  return cstr;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_get_c_string_after function
//
// Returns the whitespace terminated string that appears after the given string.
//
char* str_get_c_string_after (const slcc_string* s, const char* after) 
{
  char* cstr;
  size_t i;
  size_t bpos;
  size_t epos;
  size_t size = strlen (after);
	
  /* Search end of after */
  for (bpos = 0, i = 0; bpos != s->size; ++bpos)
    {
      if (i == size)
	/* String is found */
	break;
      if (s->value[bpos] == after[i])
	i++;
    }

  /* Skip whitespace */
  for (;;)
    if (tc_is_whitespace (s->value[bpos]))
      bpos++;
    else
      break;

  /* Search end of name */
  for (epos = bpos + 1; epos != s->size; ++epos)
    if (tc_is_alpha_or_underscore (s->value[epos]) 
	|| tc_is_decimal_digit (s->value[epos]))
      /* epos is already incremented by loop */ ;
    else
      break;

  if (bpos == s->size)
    return "";
	
  cstr = malloc (sizeof (char[epos - bpos + 1]));

  strncpy (cstr, s->value + bpos, epos - bpos);
  cstr[epos - bpos] = '\0';

  return cstr;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_get_c_string_all_after function
//
// Returns the remainder of the string given that is after the search string.
// It returns the empty string if the search string is not found.
//
char* str_get_c_string_all_after (const slcc_string* s, const char* after) 
{
  char* cstr;
  size_t i;
  size_t bpos;
  size_t size = strlen (after);
	
  /* Search end of after */
  for (bpos = 0, i = 0; bpos != s->size; ++bpos)
    {
      if (i == size)
	/* String is found */
	break;
      if (s->value[bpos] == after[i])
	i++;
    }

  /* Skip whitespace */
  for (;;)
    if (tc_is_whitespace (s->value[bpos]))
      bpos++;
    else
      break;

  if (bpos == s->size)
    return "";

  cstr = malloc (sizeof (char[s->size - bpos + 1]));

  strncpy (cstr, s->value + bpos, s->size - bpos);
  cstr[s->size - bpos] = '\0';

  return cstr;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_get_c_string_between function
//
// Returns a copy of the part of the string between the two delimiters as C
// string.
//
char* str_get_c_string_between (const slcc_string* s, char d_begin, char d_end) 
{
  size_t bpos;
  size_t epos;

  for (bpos = epos = 0; epos != s->size; ++epos)
    {
      if (bpos == 0 && s->value[epos] == d_begin)
	bpos = epos + 1;
      else if (bpos != 0 && s->value[epos] == d_end)
	{
	  break;
	}
    }

  if (bpos == 0 || epos == s->size)
    return 0;
	
  char* cstr = malloc (sizeof (char[epos - bpos + 1]));

  strncpy (cstr, s->value + bpos, epos - bpos);
  cstr[epos - bpos] = '\0';
	    
  return cstr;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_get_c16_string function
//
// Returns a copy of the string16 as C16 string.
//
char16_t* str_get_c16_string(const slcc_string16* s) 
{
  char16_t* cstr = malloc (sizeof (char16_t[s->size + 1]));

  memcpy (cstr, s->value, (s->size + 1) * sizeof (char16_t));

  return cstr;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_get_c32_string function
//
// Returns a copy of the string32 as C32 string.
//
char32_t* str_get_c32_string(const slcc_string32* s) 
{
  char32_t* cstr = malloc (sizeof (char32_t[s->size + 1]));

  memcpy (cstr, s->value, (s->size + 1) * sizeof (char32_t));

  return cstr;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_get_first_none_whitespace function
//
// Returns position of the first none whitespace character after the given
// position.
//
size_t str_get_first_none_whitespace (const slcc_string* s, size_t after_pos) 
{
  for (/* No initializer needed */ ; after_pos != s->size; ++after_pos)
    if (!tc_is_whitespace (s->value[after_pos]))
      return after_pos;

  return MaxSizeT;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_get_last_word_in_string function
//
// Returns the last part of the input string that doesn't contain whitespace
// characters.
//
char* str_get_last_word_in_string (const slcc_string* s) 
{
  size_t i;
  size_t size;
  char* w;

  /* Search last position that is not a whitespace */
  for (i = s->size; i != 0; --i)
    if (!tc_is_whitespace (s->value[i]))
      break;
	
  /* If only whitespace, return empty string */
  if (i == 0)
    return "";
	
  /* Search first position of the string */
  for (i = i, size = 0; i != 0; --i, ++size)
    if (tc_is_whitespace (s->value[i]))
      break;
	
  i++;
	
  w = malloc (sizeof (char[size + 1]));
       
  strncpy (w, s->value + i, size);
  w[size] = '\0';

  return w;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_get_wc_string function
//
// Returns a copy of the wstring as wide character string.
//
wchar_t* str_get_wc_string (const slcc_wstring* s) 
{
  wchar_t* wcstr = malloc (sizeof (wchar_t[s->size + 1]));

  memcpy (wcstr, s->value, (s->size + 1) * sizeof (wchar_t));

  return wcstr;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_reset function
//
// Reset the string to an empty string.
//
bool str_reset (slcc_string* s) 
{
  if (s->size != 0)
    {
      s->value[0] = '\0';
      s->size = 0;
    }

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_reset_16 function
//
// Reset the string16 to an empty string.
//
bool str_reset_16 (slcc_string16* s) 
{
  if (s->size != 0)
    {
      s->value[0] = '\0';
      s->size = 0;
    }

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_reset_32 function
//
// Reset the string32 to an empty string.
//
bool str_reset_32 (slcc_string32* s) 
{
  if (s->size != 0)
    {
      s->value[0] = '\0';
      s->size = 0;
    }

  return true;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// str_reset_w function
//
// Reset the wstring to an empty wstring.
//
bool str_reset_w (slcc_wstring* s) 
{
  if (s->size != 0)
    {
      s->value[0] = '\0';
      s->size = 0;
    }

  return true;
}
//------------------------------------------------------------------------------

//-<EOF>
