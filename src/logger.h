#ifndef LOGGER_H
#define LOGGER_H

class logger {

public:
int BUFFER_SIZE = 100; //default maximum number of entries line for the log file, after this it ringbuffers 

logger(String name, String head);     //construct an instance of logger passing it the filename 
void setBufferSize(int newSize); //sets the size of the riungbuffer
void data(String data); //write some data
void read(); //dump the contents of the file to serial


private:
String head;
String name;
String* buffer;
int bufferPos;
};

#endif