
/*
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */



/*  * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 Code by Thomas O Fredericks (tof@t-o-f.info)
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef AStream_h
#define AStream_h

#include <inttypes.h>

class AStream
{

public:
  
  AStream(void* array ,  uint8_t arrayLength, uint8_t sizeofvalue ); 
  
  uint8_t available();
  uint8_t length();
  
protected:
  uint8_t* in;
  int in_int;
  uint8_t in_bits, in_index, expected_bytes, in_length, maxLength,sizeofvalue;
 
};

#endif


