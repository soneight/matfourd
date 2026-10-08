# `MATFOURD`
> C++17 Four Dimensional Matrices

- **dimensions and order:**
  - `Vec*` and `Mat*` support dimensions from 2 to 4 only
  - GLSL dimension naming: `Mat<Type, Cols, Rows>` (`Mat2x4` = 2 columns, 4 rows)

- **memory**:
  - **IMPORTANT**: local variables for `Vec*` and `Mat*` classes are uninitialized, so contains garbage
  - `ColMajor.data()` is contiguous column-by-column
  - `RowMajor.data()` is contiguous row-by-row

- **order representation:**
  - Order is controlled via `bool` using `Order::ColMajor` (`false`) and `Order::RowMajor` (`true`)
  - Default order is always `Order::ColMajor`

- **operator roles (`*` vs `^` vs `~`):**
  - most of multiplication internally implemented by using order-aware `^` operator
  - **`^` (strict order-aware multiplication):** generally expect `RowMajor` left operand and `ColMajor` right operand
  - **`*` (generic order-agnostic multiplication):** automatically converts left operand to `RowMajor` and right operand to `ColMajor`, then calls `^`, that means using `*` for any multiplication between `Vec*` results in dot product
  - **`~` (order toggle):** reverses storage/vector orientation without changing dimensions (`ColMajor <-> RowMajor`)
  - **`transpose(mat)` vs `~mat`:**
    - `transpose`: swaps dimensions (Cols <-> Rows) and preserves order
    - `~M`: preserves dimensions and swaps storage order

- **return types (defaults to `ColMajor` except for):**
  - `vecAny * matAny -> ~Vec` (Row vector)
  - `vecRow ^ matCol -> ~Vec` (Row vector)
  - scalar multiplications and swizzles preserve the operand's original order

- **`Vec*` operations (assuming `ColMajor` by default):**
  - cross product: `vec3Col ^ vec3Col -> vec3Col`
  - dot product (any of):
    - `~vecCol ^ vecCol -> scalar`
    - `vecRow ^ vecCol -> scalar`
    - `vecAny * vecAny -> scalar`
  - outer product by either:
    - `vecCol ^ vecRow -> matCol`
    - `vecCol ^ ~vecCol -> matCol`

- **aliases:**
  - `Vec*`: `Col2` (`=Vec2`), `Col3` (`=Vec3`), `Col4` (`=Vec4`), `Row2`, `Row3`, `Row4`
  - `Mat*`: `Col2x2` (`=Mat2`), `Col3x3` (`=Mat3`), `Col4x4` (`=Mat4`), `Col2x4` (`=Mat2x4`), etc., and matching `Row*` aliases

- **language quirks:**
  - nested `std::initializer_list` construction is banned via `static_assert` to prevent ambiguous braces
  - swizzling is supported via `operator/` on `Vec*` (e.g., `vec4 / zxx -> vec3`) by `using namespace son8::matfourd::swizzles`

## Usage
> TODO: good short example somehow related to computer graphics

```cxx

namespace m4d = son8::matfourd;

m4d::Col4< float > vectorGarbage; // IMPORTANT: garbage, uninitialized vector variable
m4d::Col4x4< float > matrixGarbage; // IMPORTANT: garbage, uninitialized matrix variable

m4d::Col2x4< float > matrixColMajor{ // `.f` is necessary, because of no auto conversion
    { 1.f, 2.f, 3.f, 4.f }, // 1st column
    { 5.f, 6.f, 7.f, 8.f }  // 2nd column
}; // in-memory: 1-2-3-4-5-6-7-8

m4d::Row2x4< float > matrixRowMajor{
    { 1.f, 2.f }, // 1st row
    { 3.f, 4.f }, // 2nd row
    { 5.f, 6.f }, // 3rd row
    { 7.f, 8.f }  // 4th row
}; // in-memory: 1-2-3-4-5-6-7-8

m4d::Vec4< float > vecColMajor{ 1, 2, 3, 4 };
m4d::Row4< float > vecRowMajor{ 5, 6, 7, 8 };

using namespace m4d::swizzles;
m4d::Row2x4< float > matrixRow{
    ~vecColMajor / xy, // `~` is necessary, auto conversion is
    ~vecColMajor / zw, // \ not supported, need to be explicit
    vecRowMajor / xy,
    vecRowMajor / zw
}; // in-memory: 1-2-3-4-5-6-7-8

auto /* m4d::Col4x2< float > */ matrix = ~matrixRow; // in-memory: 1-5-2-6-3-7-4-8

```

### Install
> `CMake` install target and find package would be added on release `v1.0.0`

### Fetch

```cmake
if( NOT TARGET son8__matfourd )
   include( FetchContent )
   message( STATUS "${SON8_APP}: FetchContent `soneight/matfourd`" )
   fetchcontent_declare(
      son8__matfourd
      GIT_REPOSITORY https://github.com/soneight/matfourd.git
      GIT_TAG        83f979910bfe4c1cc4c815031cb74b0599438b0a # v0.0.1
   )
   fetchcontent_makeavailable( son8__matfourd )
endif( )
message( STATUS "${SON8_APP}: target `son8__matfourd` found" )
```

## [CONTRIBUTING](./CONTRIBUTING.md)
> Project Contribution Rules

## [LICENSE](./LICENSE) [Apache-2.0](./LICENSE.Apache-2.0.md) [NOTICE](./NOTICE)
> Project Copying Rules with attribution notice

###### each folder MAY contain README with additional materials
