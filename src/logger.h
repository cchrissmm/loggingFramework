#ifndef LOGGER_H
#define LOGGER_H

class logger {

public:
static const int BUFFER_SIZE = 10; //maximum number of entries line for the log file, after this it ringbuffers 

logger(String name, String head);     //construct an instance of logger passing it the filename 
void data(String data); //write some data
void read(); //dump the contents of the file to serial

private:
String head;
String name;
String buffer[BUFFER_SIZE];
int bufferPos;
};

#endif