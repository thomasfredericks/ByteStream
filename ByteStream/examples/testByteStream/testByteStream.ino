#include <ByteStream.h>

ByteStream byteStream = ByteStream();

void setup() {
  
  Serial.begin(57600);
  
}

void loop() {
  
  while( byteStream.available() > 0 ) {
    Serial.print("Received :");
    for ( byte b = 0; b < byteStream.length(); b++ ) {
	  Serial.print(" ");
      Serial.print(byteStream.in[b]);
      
    }
    Serial.println();
  }
  
}