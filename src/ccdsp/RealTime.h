#ifndef __CCDSP_REALTIME__
#define __CCDSP_REALTIME__

#include "ccdsp/Base.h"

namespace ccdsp {

struct SampleRate;
struct SampleTime;

struct RealTime {
  RealTime() {}
  RealTime(double p) : time_(p) {}
  RealTime(float p) : time_(p) {}

  double operator*() const { return time_; }

  // If you want to
  // This constructor is implemented in SampleTime.h.
  RealTime(const SampleTime&, const SampleRate&);

  RealTime& operator+=(const RealTime& t) { time_ += *t; return *this; }
  RealTime& operator-=(const RealTime& t) { time_ -= *t; return *this; }

  template <typename T> RealTime& operator+=(T t) { time_ += t; return *this; }
  template <typename T> RealTime& operator-=(T t) { time_ -= t; return *this; }

  template <typename T> RealTime& operator*=(T t) { time_ *= t; return *this; }
  template <typename T> RealTime& operator/=(T t) { time_ /= t; return *this; }

 private:
  double time_;

  // Disallow all integer constructors.
  RealTime(int8 time);
  RealTime(int16 time);
  RealTime(int32 time);
  RealTime(int64 time);

  RealTime(uint8 time);
  RealTime(uint16 time);
  RealTime(uint32 time);
  RealTime(uint64 time);
};

inline const RealTime operator+(const RealTime& x, const RealTime& y) {
  return *x + *y;
}

inline const RealTime operator-(const RealTime& x, const RealTime& y) {
  return *x - *y;
}

inline const RealTime operator*(double x, const RealTime& y) {
  return x * (*y);
}

inline const RealTime operator*(const RealTime& x, double y) {
  return (*x) * y;
}

inline const RealTime operator/(const RealTime& x, double y) {
  return (*x) / y;
}

inline const double operator/(const RealTime& x, const RealTime& y) {
  return (*x) / (*y);
}

}  // namespace ccdsp

#endif  // __CCDSP_REALTIME__
