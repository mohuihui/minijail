/* Copyright 2016 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef _SCOPED_MINIJAIL_H_
#define _SCOPED_MINIJAIL_H_

#include <memory>

#include "libminijail.h"

namespace {
struct ScopedMinijailDeleter {
    inline void operator()(minijail *j) const {
        if (j) {
            minijail_destroy(j);
        }
    }
};
}

using ScopedMinijail = std::unique_ptr<minijail, ScopedMinijailDeleter>;

#endif /* _SCOPED_MINIJAIL_H_ */
