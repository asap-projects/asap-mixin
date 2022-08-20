//===----------------------------------------------------------------------===//
// Distributed under the 3-Clause BSD License.See accompanying file LICENSE or
// copy at https://opensource.org/licenses/BSD-3-Clause).
// SPDX-License-Identifier: BSD-3-Clause
//===----------------------------------------------------------------------===//

#include "mixin/mixin.h"

#include <sstream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::Eq;

namespace asap::mixin {

namespace {

//! [Mixin calls other mixin]
template <typename Base> struct WithLogging : Base {
  void Log(const std::string &message) const {
    out << message;
  }
  auto LoggerOutput() -> std::string {
    return out.str();
  }

private:
  mutable std::stringstream out;
};

template <typename Base> struct Persistence : Base {
  void Store() const {
    // self() is provided by Base, so we need to mark it dependent.
    // this->self() is short and obvious.
    this->self().Log("storing...");
  }
};
//! [Mixin calls other mixin]

// NOLINTNEXTLINE
TEST(MixinSelf, UseSelfToAccessOtherMixinInterfaces) {
  struct Concrete : asap::mixin::Mixin<Concrete, Persistence, WithLogging> {};

  Concrete concrete;
  concrete.Store();
  EXPECT_THAT(concrete.LoggerOutput(), Eq("storing..."));
}

// NOLINTNEXTLINE
TEST(MixinSelf, CompositionOrderDoesNotMatter) {
  //! [Composition order does not matter]
  struct Concrete1 : Mixin<Concrete1, Persistence, WithLogging> {};
  struct Concrete2 : Mixin<Concrete2, WithLogging, Persistence> {};
  //! [Composition order does not matter]

  [[maybe_unused]] Concrete1 concrete_1;
  [[maybe_unused]] Concrete2 concrete_2;
}

} // namespace

} // namespace asap::mixin
