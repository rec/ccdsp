all: TimeTest

TimeTest:\
 test/TimeTest.cpp\
 src/ccdsp/SampleRate.h\
 src/ccdsp/SampleTime.h\
 src/ccdsp/RealTime.h
	g++ test/TimeTest.cpp -o test/TimeTest -I src
