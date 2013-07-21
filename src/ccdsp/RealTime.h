#ifndef __CCDSP_REALTIME__
#define __CCDSP_REALTIME__

#include "ccdsp/Base.h"

namespace ccdsp {

struct SampleRate;
struct SampleTime;

struct RealTime {
  RealTime() {}

  // You can construct a RealTime from any floating point number.
  RealTime(double p) : time_(p) {}
  RealTime(float p) : time_(p) {}

  const double operator*() const { return time_; }

  // If you want to construct a RealTime from an integer type, you also need a
  // Sample Rate.
  RealTime(const SampleTime&, const SampleRate&);
  // Note: this constructor is actually implemented in SampleTime.h.

  RealTime& operator+=(RealTime t) { time_ += *t; return *this; }
  RealTime& operator-=(RealTime t) { time_ -= *t; return *this; }

  template <typename T> RealTime& operator+=(T t) { time_ += t; return *this; }
  template <typename T> RealTime& operator-=(T t) { time_ -= t; return *this; }

  template <typename T> RealTime& operator*=(T t) { time_ *= t; return *this; }
  template <typename T> RealTime& operator/=(T t) { time_ /= t; return *this; }

 private:
  // Constructing a RealTime from an integer type is not allowed.
  RealTime(int8 time);
  RealTime(int16 time);
  RealTime(int32 time);
  RealTime(int64 time);

  RealTime(uint8 time);
  RealTime(uint16 time);
  RealTime(uint32 time);
  RealTime(uint64 time);

  double time_;
};



inline const RealTime operator+(RealTime x, RealTime y) {
  return (*x) + (*y);
}

inline const RealTime operator-(RealTime x, RealTime y) {
  return (*x) - (*y);
}

template <typename T>
inline const RealTime operator*(T x, RealTime y) {
  return t * (*y);
}

template <typename T>
inline const RealTime operator*(RealTime x, T y) {
  return (*x) * y;
}

const RealTime operator*(RealTime x, RealTime y);
// Disallow this case - but by causing a link error.  TODO: a better way?

// Dividing a RealTime by any number gives you a RealTime.
template <typename T>
const RealTime operator/(RealTime x, T y) {
  return static_cast<double>((*x) / y);
}

// Dividing a RealTime by a RealTime gives you a double.
inline const double operator/(RealTime x, RealTime y) {
  return (*x) / (*y);
}

}  // namespace ccdsp

#endif  // __CCDSP_REALTIME__
