# Changelog

All notable changes to this project will be documented in this file. See [standard-version](https://github.com/conventional-changelog/standard-version) for commit guidelines.

## [4.4.6](http://github.com/abdes/asap/compare/v4.4.5...v4.4.6) (2022-09-18)

### Bug Fixes

* top level install not working properly ([4ac4a31](http://github.com/abdes/asap/commit/4ac4a31001a2ab73764e3d9fe3f279b1e7b25aee))

  `CMAKE_MODULE_PATH` should be reset at the top level project to make sure that
  every sub-project uses its own version of the `cmake` files. Additionally,
  refactor the top-level install code to simplify it and remove the need to call
  a function in the top-level project `cmake` script.

## [4.4.5](http://github.com/abdes/asap/compare/v4.4.4...v4.4.5) (2022-09-18)

### Bug Fixes

* [#20](http://github.com/abdes/asap/issues/20) local install should use CMAKE_INSTALL_PREFIX to set variables ([2e1f1d4](http://github.com/abdes/asap/commit/2e1f1d49baff64dbf47dbbda234886ad2dfdbf1c))
* [#20](http://github.com/abdes/asap/issues/20) use CMAKE_INSTALL_PREFIX to set variables ([2fffd96](http://github.com/abdes/asap/commit/2fffd96392114993bbb72e3f614725f867d61ab1))
* wrong variable used of target name ([04b5343](http://github.com/abdes/asap/commit/04b5343ae541bd6d4f5ae1c1fa2eb85b93e0b5a3))

## [4.4.4](http://github.com/abdes/asap/compare/v4.4.3...v4.4.4) (2022-09-18)

### Bug Fixes

* wrong variable used for target name ([04b5343](http://github.com/abdes/asap/commit/04b5343ae541bd6d4f5ae1c1fa2eb85b93e0b5a3))

## [4.4.3](http://github.com/abdes/asap/compare/v4.4.2...v4.4.3) (2022-09-18)

### Bug Fixes

* [#19](http://github.com/abdes/asap/issues/19) use generator expressions instead of CMAKE_BUILD_TYPE ([857d299](http://github.com/abdes/asap/commit/857d2997d4ec6c879036e10234b8baf907e91089))

  Code that checks CMAKE_BUILD_TYPE to set specific compiler flags or defines is
  problematic. Generator expressions should be used instead to handle
  configuration-specific logic correctly, regardless of the generator used.

* use cmake-format extension default behavior ([a5d5c5e](http://github.com/abdes/asap/commit/a5d5c5eae39e4d3d0094c00848cfe777d331a219))

  No need to force the `cmake-format` config file location as the command is run
  in the workspace root by default and it will look for and find the config file
  named `cmake-format.yaml`.

## [4.4.2](http://github.com/abdes/asap/compare/v4.4.1...v4.4.2) (2022-09-16)

### Bug Fixes

* [#13](http://github.com/abdes/asap/issues/13) move "caexcludepath" to dev-windows and exclude CPM cache ([0571714](http://github.com/abdes/asap/commit/0571714e9436bfec26d6450b5bc37f2a5f478a55))
* [#14](http://github.com/abdes/asap/issues/14) upgrade CPM to 0.35.6
  ([695414b](http://github.com/abdes/asap/commit/695414b8e66d4d42d7ef3aaef3c6a4b8399d16c2))
* [#15](http://github.com/abdes/asap/issues/15) get target type before testing it ([b8bd378](https://github.com/abdes/asap/commit/b8bd378f52bc131b84c13b08cfe70d649e9d9be0))
* [#16](http://github.com/abdes/asap/issues/16) use CMAKE_CURRENT_SOURCE_DIR instead of CMAKE_SOURCE_DIR for cmake includes ([4ac6928](http://github.com/abdes/asap/commit/4ac6928fc2a0bf806bbcaa3bea898b5ff018a164))
* [#17](http://github.com/abdes/asap/issues/17) git should not be required ([2c76104](http://github.com/abdes/asap/commit/2c761046d0801f643aa0215d34f2795ff0093dfc))
* [#18](http://github.com/abdes/asap/issues/18) enforce end of line to LF ([943ae47](http://github.com/abdes/asap/commit/943ae479e09de999c324a9cfe3bbf8d688d255a3))

## [1.1.1](http://github.com/abdes/asap/compare/v1.1.0...v1.1.1) (2022-08-20)

* code cleanup to eliminate compiler/linter warnings and improve code quality.

### Bug Fixes

* [#10](http://github.com/abdes/asap/issues/10) no more template export header
  ([dd8ffd5](http://github.com/abdes/asap/commit/dd8ffd5a8f36340963349c7ebcb7c1713c2f880a))
* [#11](http://github.com/abdes/asap/issues/11) refactor compiler options
  management
  ([78ae493](http://github.com/abdes/asap/commit/78ae4933f2e263a55f6537e66347c6b11a24b961))
* [#12](http://github.com/abdes/asap/issues/12) disable used-but-marked-unused
  ([6d42d83](http://github.com/abdes/asap/commit/6d42d83bfdd16123f05a69726058dc5f103143be))
* [#9](http://github.com/abdes/asap/issues/9) remove no longer used function
  ([5a7416f](http://github.com/abdes/asap/commit/5a7416f9563aae303d68ca2bb878fef97fbb7130))

## [1.1.0](http://github.com/abdes/asap/compare/v1.0.5...v1.1.0) (2022-08-11)

Merge features/updates/fixes from upstream [asap](http://github.com/abdes/asap).

## [1.0.5](http://github.com/abdes/asap/compare/v1.0.4...v1.0.5) (2022-03-15)

* chore: remove duplicate RPATH settings

## [1.0.4](http://github.com/abdes/asap/compare/v1.0.3...v1.0.4) (2022-03-15)

### Features

* refactor build to use CPM for cmake dependencies and speedup build with
  ccache.

### Bug Fixes

* missing intersphinx config for submodule
  ([dc2df5b](http://github.com/abdes/asap/commit/dc2df5bf299d65789f0d3054ac049d9108e9d2b8))
* remove non-existing directory from library include dirs
  ([2f38810](http://github.com/abdes/asap/commit/2f38810813d6eb0b0a5059ecc3970314874815d9))
* require c++-17
  ([049d34c](http://github.com/abdes/asap/commit/049d34c73a02b23ca9dc776465d6029e940f7b23))
* this library has no dependencies
  ([ada7303](http://github.com/abdes/asap/commit/ada730355b750514b04ac37190d5ab2f891db572))

## [1.0.3](http://github.com/abdes/asap/compare/v1.0.2...v1.0.3) (2022-03-06)

### Bug Fixes

* cleanup dependencies and docs for mixin module
  ([69a9014](http://github.com/abdes/asap/commit/69a90147a92114ac20d2c9913359aaec3963ffdb))

## [1.0.2](http://github.com/abdes/asap/compare/v1.0.1...v1.0.2) (2022-03-06)

### Bug Fixes

* missing inter-sphinx config for submodule
  ([72af6d0](http://github.com/abdes/asap/commit/72af6d0b7506678317fbaa22b36dbd109793fd3d))

## [1.0.1](http://github.com/abdes/asap/compare/v1.0.0...v1.0.1) (2022-03-06)

docs: update docs to match the project

## 1.0.0 (2022-03-06)

Initial version of the mixin support library for C++-17. This is a lightweight
library that simplifies the implementation of mixins in C++. See the
documentation and examples for more information.
