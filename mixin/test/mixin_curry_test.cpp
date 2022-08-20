//===----------------------------------------------------------------------===//
// Distributed under the 3-Clause BSD License.See accompanying file LICENSE or
// copy at https://opensource.org/licenses/BSD-3-Clause).
// SPDX-License-Identifier: BSD-3-Clause
//===----------------------------------------------------------------------===//

#include "mixin/mixin.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace asap::mixin {

namespace {

//! [Curry mixin with multiple parameters]
template <typename Arg1, typename Arg2, typename Base> struct MyMixin : Base {
  /// Forwarding constructor
  template <typename... Args>
  constexpr explicit MyMixin(Arg1 field_1, Arg2 field_2, Args &&...args)
      : Base(static_cast<decltype(args)>(args)...), field_1_{field_1},
        field_2_{field_2} {
  }

private:
  Arg1 field_1_;
  Arg2 field_2_;
};

struct MyClass : Mixin<MyClass, mixin::Curry<MyMixin, int, float>::mixin> {
  template <typename... Args>
  constexpr explicit MyClass(Args &&...args)
      : Mixin(static_cast<decltype(args)>(args)...) {
  }
};
//! [Curry mixin with multiple parameters]

// NOLINTNEXTLINE
TEST(MixinCurry, MultipleTemplateParameters) {
  [[maybe_unused]] MyClass composite{0, 0.0F};
}

} // namespace

} // namespace asap::mixin
