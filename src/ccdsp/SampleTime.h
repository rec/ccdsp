#ifndef __CCDSP_SAMPLETIME__
#define __CCDSP_SAMPLETIME__

#include "ccdsp/Base.h"
#include "ccdsp/RealTime.h"
#include "ccdsp/SampleRate.h"

namespace ccdsp {

struct SampleTime {
  SampleTime() {}

  // Allow automatic constructions from all integer types.
  SampleTime(int64 t) : time_(t) {}
  SampleTime(uint64 t) : time_(static_cast<int64>(t)) {}
  SampleTime(int t) : time_(t) {}
  SampleTime(uint t) : time_(t) {}
  SampleTime(short t) : time_(t) {}

  // And you can construct a SampleTime from a RealTime if you have a SampleRate.
  SampleTime(RealTime t, SampleRate r) : time_(static_cast<int64>(t * r)) {}

  SampleTime& operator++() { ++time_; return *this; }
  SampleTime& operator--() { --time_; return *this; }

  SampleTime operator++(int) { return time_++; }
  SampleTime operator--(int) { return time_--; }

  SampleTime& operator-=(SampleTime t) { time_ -= t; return *this; }
  SampleTime& operator+=(SampleTime t) { time_ += t; return *this; }

#if 0
  const SampleTime operator+(SampleTime t) { return time_ + t; }
  const SampleTime operator-(SampleTime t) { return time_ - t; }
  const SampleTime operator+(int t) { return time_ + t; }
  const SampleTime operator+(int64 t) { return time_ + t; }
  const SampleTime operator+(uint t) { return time_ + t; }
  const SampleTime operator+(uint64 t) { return time_ + t; }
  const SampleTime operator-(int t) { return time_ - t; }
  const SampleTime operator-(int64 t) { return time_ - t; }
  const SampleTime operator-(uint t) { return time_ - t; }
  const SampleTime operator-(uint64 t) { return time_ - t; }
  const SampleTime operator-() { return -time_; }

  operator int64() const { return time_; }
#endif

  int64 get() { return time_; }

 private:
  // Disallow these constructors.
  SampleTime(RealTime time);
  SampleTime(double time);

  int64 time_;
};

inline const SampleTime operator+(int p, SampleTime q) { return SampleTime(p) + q; }
inline const SampleTime operator+(int64 p, SampleTime q) { return SampleTime(p) + q; }
inline const SampleTime operator+(uint p, SampleTime q) { return SampleTime(p) + q; }
inline const SampleTime operator+(uint64 p, SampleTime q) { return SampleTime(p) + q; }
inline const SampleTime operator-(int p, SampleTime q) { return SampleTime(p) - q; }
inline const SampleTime operator-(int64 p, SampleTime q) { return SampleTime(p) - q; }
inline const SampleTime operator-(uint p, SampleTime q) { return SampleTime(p) - q; }
inline const SampleTime operator-(uint64 p, SampleTime q) { return SampleTime(p) - q; }

inline RealTime::RealTime(const SampleTime& t, SampleRate r) : time_(t / r) {}

}  // namespace ccdsp

#endif  // __CCDSP_SAMPLETIME__
