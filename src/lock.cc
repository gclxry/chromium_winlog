// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is used for debugging assertion support.  The Lock class
// is functionally a wrapper around the LockImpl class, so the only
// real intelligence in the class is in the debugging logic.
#include "stdafx.h"
#if !defined(NDEBUG)

#include "lock.h"
#include <cassert>

namespace base {

Lock::Lock() : lock_() {
}

Lock::~Lock() {
  assert(owning_thread_ref_.is_null());
}

void Lock::AssertAcquired() const {
  assert(owning_thread_ref_ == PlatformThreadRef(GetCurrentThreadId()));
}

void Lock::CheckHeldAndUnmark() {
  assert(owning_thread_ref_ == PlatformThreadRef(GetCurrentThreadId()));
  owning_thread_ref_ = PlatformThreadRef();
}

void Lock::CheckUnheldAndMark() {
  assert(owning_thread_ref_.is_null());
  owning_thread_ref_ = PlatformThreadRef(GetCurrentThreadId());
}

}  // namespace base

#endif  // NDEBUG
