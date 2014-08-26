
// Please read ByteStream.h for information about the liscence and authors

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "ByteStream.h"

#define MAXLENGTH 128

ByteStream::ByteStream() {
	
	
}

uint8_t ByteStream::available() {
    
  while ( Serial.available() ) {
    
    uint8_t data = Serial.read();
    
    if ( data & B10000000 ) { // START+LENGTH B1LLLLLLL
       
		in_int = 0;
        in_index = 0;
        expected_bytes = data & B01111111;
        if ( expected_bytes == 0 ) expected_bytes = 128; //in 8bit bytes
        //Serial.print("Bytes expected : ");
        //Serial.println(expected_bytes);
	    in_bits = 0;
 
    } else { // 7 BIT DATA B0XXXXXXX
       
       in_int = ((data & B01111111) << in_bits) | in_int;
       in_bits = in_bits + 7;
	
		while ( in_bits > 7 ) {
		
			in[in_index] = ((unsigned char)(in_int & 0xFF));	
			
			in_index++;
			in_bits = in_bits - 8;
			in_int = in_int >> 8;
		}
			
		// CHECK LENGTH
	   
		if ( in_index  >= expected_bytes ) {
		  
		    in_length = in_index;
		    in_index = 0;
			read_index = 0;
		  
			return  1;
		  
		}

	    return 0;
		}
		
		
	}
  
  return 0;
  
}

uint8_t ByteStream::length() {
	return in_length;
}
/*
uint8_t ByteStream::read() {
    
    if ( read_index < MAXLENGTH ) {
	    uint8_t b = in[read_index];
	    read_index++;
		return b;
	}
	return 0;
}
*/