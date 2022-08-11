# Changelog

All notable changes to this project will be documented in this file. See
[standard-version](https://github.com/conventional-changelog/standard-version)
for commit guidelines.

## [1.1.0](http://github.com/abdes/asap/compare/v1.0.5...v1.1.0) (2022-08-11)

Merge features/updates/fixes from upstream [asap](http://github.com/abdes/asap).

## [1.0.5](http://github.com/abdes/asap/compare/v1.0.4...v1.0.5) (2022-03-15)

- chore: remove duplicate RPATH settings

## [1.0.4](http://github.com/abdes/asap/compare/v1.0.3...v1.0.4) (2022-03-15)

### Features

- refactor build to use CPM for cmake dependencies and speedup build with ccache.

### Bug Fixes

- missing intersphinx config for submodule
  ([dc2df5b](http://github.com/abdes/asap/commit/dc2df5bf299d65789f0d3054ac049d9108e9d2b8))
- remove non-existing directory from library include dirs
  ([2f38810](http://github.com/abdes/asap/commit/2f38810813d6eb0b0a5059ecc3970314874815d9))
- require c++-17
  ([049d34c](http://github.com/abdes/asap/commit/049d34c73a02b23ca9dc776465d6029e940f7b23))
- this library has no dependencies
  ([ada7303](http://github.com/abdes/asap/commit/ada730355b750514b04ac37190d5ab2f891db572))

## [1.0.3](http://github.com/abdes/asap/compare/v1.0.2...v1.0.3) (2022-03-06)

### Bug Fixes

- cleanup dependencies and docs for mixin module
  ([69a9014](http://github.com/abdes/asap/commit/69a90147a92114ac20d2c9913359aaec3963ffdb))

## [1.0.2](http://github.com/abdes/asap/compare/v1.0.1...v1.0.2) (2022-03-06)

### Bug Fixes

- missing inter-sphinx config for submodule
  ([72af6d0](http://github.com/abdes/asap/commit/72af6d0b7506678317fbaa22b36dbd109793fd3d))

## [1.0.1](http://github.com/abdes/asap/compare/v1.0.0...v1.0.1) (2022-03-06)

docs: update docs to match the project

## 1.0.0 (2022-03-06)

Initial version of the mixin support library for C++-17. This is a
lightweight library that simplifies the implementation of mixins in C++. See
the documentation and examples for more information.
