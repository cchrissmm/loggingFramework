# loggingFramework
A simple logging framework for Arduino.

This is designed to log variables in real time and then when requested print them on the serial bus in CSV format.

At that point using copy paste the data, can be visualised in your viewer of choice.
This step could be automated at some point.

Any tabular program like excel will work, but I use specific graphing program like Flow CSV viewer.

Note, it can only take strings, so you need to convert whatever you want to log to a string first.

## How to
Create an instance of the class at the top of your sketch.
You need to pass it the name of the file and the header of the file.

So if you wanted to create an object that is called "log01" to log VAR01 - 03 and call it "NAME" you'd do this 

`logger log01("NAME","VAR01,VAR02,VAR03");`

And if you want to set the ringbuffer size you can, this sets it to 1000 lines:

`log01.setBufferSize(1000);`

Then you just make a string of the data adding the delimator that you want, I've used a comma:

`String log = String(var01) + "," + String(var02) + "," + String(var03);`

And pass it to log01:

`log01.data(log);`

To dump the data to the serial bus you would:

`log01.read();`

and you would get something like this on the serial bus:

`*************************filedump requested: NAME
TIME,VAR01,VAR02,VAR03
16847,159,318,477
16947,160,320,480
17047,161,322,483
17147,162,324,486
17247,163,326,489
17347,164,328,492
17447,165,330,495
**************************filedump ended NAME`

Then just copy paste this into your view of choice.