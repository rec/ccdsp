// Copyright (c) 2006-2008 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef __CCDSP_BASE__
#define __CCDSP_BASE__

// Macros to disallow various class methods that C++ unfortunately creates
// automatically.  Place either one of these in the private: section of your
// class.

// A macro to disallow the copy constructor and operator= functions.
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

// A macro to disallow the default constructor, copy constructor and operator=
// functions.
#define DISALLOW_COPY_ASSIGN_AND_EMPTY(TypeName) \
  TypeName();                                    \
  DISALLOW_COPY_AND_ASSIGN(TypeName)


// Shorthands for built-in C++ types.

namespace ccdsp {

typedef signed char schar;
typedef signed char int8;
typedef short int16;
typedef int int32;
typedef long long int64;

typedef unsigned char uchar;
typedef unsigned char uint8;
typedef unsigned char byte;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

}  // namespace ccdsp

#endif  // __CCDSP_BASE__
