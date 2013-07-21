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

  const int64 operator*() const { return time_; }

 private:
  // Disallow these constructors.
  SampleTime(RealTime time);
  SampleTime(double time);

  int64 time_;
};

inline const SampleTime operator+(SampleTime x, SampleTime y) {
  return (*x) + (*y);
}

inline const SampleTime operator-(SampleTime x, SampleTime y) {
  return (*x) - (*y);
}

template <typename T>
inline const SampleTime operator*(T x, SampleTime y) {
  return t * (*y);
}

template <typename T>
inline const SampleTime operator*(SampleTime x, T y) {
  return (*x) * y;
}

template <typename T>
const SampleTime operator*(SampleTime x, SampleTime y);
// Disallow this case - but by causing a link error.  TODO: a better way?

// Dividing a SampleTime by a number gives you a SampleTime.
template <typename T>
const SampleTime operator/(SampleTime x, T y) {
  return static_cast<int64>((*x) / y);
}

// Dividing a SampleTime by a SampleTime gives you a double.
inline const double operator/(SampleTime x, SampleTime y) {
  return (1.0 * (*x)) / (*y);
}

}  // namespace ccdsp

#endif  // __CCDSP_SAMPLETIME__
