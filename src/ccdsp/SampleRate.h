#ifndef __CCDSP_SAMPLERATE__
#define __CCDSP_SAMPLERATE__

#include "ccdsp/Base.h"

namespace ccdsp {

struct SampleRate {
  SampleRate() {}

  SampleRate(double r) : rate_(r) {}
  double operator*() const { return rate_; }

 private:
  const double rate_;
};

}  // namespace ccdsp

#endif  // __CCDSP_SAMPLERATE__
