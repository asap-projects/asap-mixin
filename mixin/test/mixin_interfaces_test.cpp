//===----------------------------------------------------------------------===//
// Distributed under the 3-Clause BSD License.See accompanying file LICENSE or
// copy at https://opensource.org/licenses/BSD-3-Clause).
// SPDX-License-Identifier: BSD-3-Clause
//===----------------------------------------------------------------------===//

#include "mixin/mixin.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::NotNull;

namespace asap::mixin {

namespace {
//! [Virtual interface]
struct Interface {
  virtual ~Interface() = default;

  Interface() = default;
  Interface(const Interface &) = default;
  Interface(Interface &&) noexcept = default;
  auto operator=(const Interface &) -> Interface & = default;
  auto operator=(Interface &&) noexcept -> Interface & = default;

  [[maybe_unused]] virtual void foo() = 0;
};
//! [Virtual interface]

//! [Mixin implements interface]
template <typename Base> struct ImplementsInterface : Base, Interface {
  template <typename... Args>
  constexpr explicit ImplementsInterface(Args &&...args)
      : Base(static_cast<decltype(args)>(args)...) {
  }

  void foo() override {
    // Implement foo interface in the mixin
  }
};
//! [Mixin implements interface]

// NOLINTNEXTLINE
TEST(MixinInterfaces, MixinCanImplementInterface) {
  struct Composite : Mixin<Composite, ImplementsInterface> {};
  // This code compiles and defines the `foo()` method
  Composite composite{};
  EXPECT_THAT(dynamic_cast<Interface *>(&composite), NotNull());
  composite.foo();
}

// NOLINTNEXTLINE
TEST(MixinInterfaces, MixinCanProvideInterface) {
  //! [Mixin provides interface]
  using asap::mixins::Provides;
  struct Composite final : Mixin<Composite, Provides<Interface>::mixin> {
    void foo() override {
      // Implement foo interface in the composite
    }
  };
  //! [Mixin provides interface]
  // This code compiles and defines the `foo()` method
  Composite composite{};
  EXPECT_THAT(dynamic_cast<Interface *>(&composite), NotNull());
  composite.foo();
}

} // namespace

} // namespace asap::mixin
