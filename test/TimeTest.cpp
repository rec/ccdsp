#include "ccdsp/Time.h"

using namespace ccdsp;

// #define FAILURE

int main(int, char**) {
  RealTime r1, r2(1.0), r3(1.0f);
  RealTime rt(100000, 44100);
  RealTime rt2(100000, 44100.0);

  rt += 2.0;
  rt -= 2.0;
  rt *= 2;
  rt *= 2.0;
  rt /= 2;
  rt /= 2.0;

  rt = rt2 + 2.0;
  rt = rt2 - 2.0;

  rt = 2.0 + rt2;
  rt = 2.0 - rt2;

  rt = rt2 * 2;
  rt = rt2 * 2.0;
  rt = 2 * rt2;
  rt = 2.0 * rt2;

  rt = rt2 / 2;
  rt = rt2 / 2.0;

  double ratio = r2 / r3;
  rt = r2 / 2.0;
  rt = rt / 2;

  SampleTime st, s2(0), s3(static_cast<uint64>(23));
  SampleTime st1(1.0, 44100);
  SampleTime st2(1.0, 44100.0);

  st += 2;
  st -= 2;
  st *= 2;
  st *= 2.0;
  st /= 2;
  st /= 2.0;

  st = st2 + 2;
  st = st2 - 2;

  st = 2 + st2;
  st = 2 - st2;

  st = st2 * 2;
  st = st2 * 2.0;
  st = 2 * st2;
  st = 2.0 * st2;

  st = st2 / 2;
  st = st2 / 2.0;

  ratio = r2 / r3;
  rt = r2 / 2.0;
  rt = rt / 2;

  st++;
  ++st;
}

void fail() {
#ifdef FAILURE
  RealTime r(0);

  RealTime rt(100000.0, 44100);
  RealTime rt2(100000.0, 44100.0);

  rt += 2;
  rt -= 2;

  rt = rt2 + 2;
  rt = rt2 - 2;
  rt = 2 + rt2;
  rt = 2 - rt2;

  rt = 2 / rt2;
  rt = 2.0 / rt2;  // This will give a link-time error.

  rt++;
  ++rt;

  SampleTime s1(0.0);
  SampleTime s2(0.0f);
  SampleTime st1(1, 44100);
  SampleTime st2(1, 44100.0);

  st += 2.0;
  st -= 2.0;

  st = st2 + 2.0;
  st = st2 - 2.0;
  st = 2.0 + st2;
  st = 2.0 - st2;

  st = 2 / st2;  // This will give a link-time error.
  st = 2.0 / st2;
#endif
}


