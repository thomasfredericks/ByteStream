#include <AStream.h>

byte array[32];

AStream byteStream = AStream(array,32,sizeof(byte));

void setup() {
  
  Serial.begin(57600);
  
}

void loop() {
  
  while( byteStream.available() > 0 ) {
    Serial.print("Received : ");
    for ( byte b = 0; b < byteStream.length(); b++ ) {
      Serial.print(array[b]);
      Serial.print(" ");
    }
    Serial.println();
  }
  
}
