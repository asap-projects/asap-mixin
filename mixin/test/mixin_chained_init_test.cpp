//===----------------------------------------------------------------------===//
// Distributed under the 3-Clause BSD License.See accompanying file LICENSE or
// copy at https://opensource.org/licenses/BSD-3-Clause).
// SPDX-License-Identifier: BSD-3-Clause
//===----------------------------------------------------------------------===//

#include "mixin/mixin.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::Eq;

namespace asap::mixin {

namespace {
struct Argument1 {
  int a1;
};
struct Argument2 {
  int a2;
};

template <typename Base> struct Fragment1 : Base {
  template <typename... Args>
  Fragment1(Argument1 arg1, int foo, Args &&...args)
      : Base(std::forward<Args>(args)...), x_{arg1.a1}, y_{foo} {
  }
  int x_;
  int y_;
};

template <typename Base> struct Fragment2 : Base {
  template <typename... Args>
  explicit Fragment2(Argument2 arg2, Args &&...args)
      : Base(std::forward<Args>(args)...), z_{arg2.a2} {
  }
  int z_;
};

// NOLINTNEXTLINE
TEST(MixinChainedInit, MixinConstructorForwardsUnusedArgumentsToBase) {
  struct Composite : Mixin<Composite, Fragment1, Fragment2> {
    constexpr Composite(Argument1 arg1, int foo, Argument2 arg2)
        : Mixin(arg1, foo, arg2) {
    }
  };

  Composite composite{Argument1{1}, 2, Argument2{3}};
  EXPECT_THAT(composite.x_ + composite.y_ + composite.z_, Eq(1 + 2 + 3));
}

} // namespace

} // namespace asap::mixin
