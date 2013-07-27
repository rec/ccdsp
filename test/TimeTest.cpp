#include "ccdsp/Time.h"

using namespace ccdsp;

// #define FAILURE

int main(int, char**) {
  RealTime r1, r2(1.0), r3(1.0f);
  RealTime rt(100000, 44100);
  RealTime rt2(100000, 44100.0);

  SampleTime s1, s2(0), s3(static_cast<uint64>(23));
  SampleTime st1(1.0, 44100);
  SampleTime st2(1.0, 44100.0);

  r2 += 2.0;
}

#ifdef FAILURE

void fail() {
  RealTime r(0);

  RealTime rt(100000.0, 44100);
  RealTime rt2(100000.0, 44100.0);

  SampleTime s1(0.0);
  SampleTime s2(0.0f);
  SampleTime st1(1, 44100);
  SampleTime st2(1, 44100.0);

  rt += 2;
}

#endif

