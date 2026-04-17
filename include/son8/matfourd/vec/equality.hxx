#ifndef SON8_MATFOURD_VEC_EQUALITY_HXX
#define SON8_MATFOURD_VEC_EQUALITY_HXX

#include <son8/matfourd/vec/type.hxx>

namespace son8::matfourd {
    // Vec (column vector) equality: (any)v == (any)v = bool
    template< typename Type, unsigned Size, bool RowMajorL, bool RowMajorR >
    SON8_MATFOURD_FUNC operator==( Vec< Type, Size, RowMajorL > const &vecL, Vec< Type, Size, RowMajorR > const &vecR ) {
        using r = bool;
        if/*_*/ constexpr ( Size == 2 ) {
            return r { vecL.x( ) == vecR.x( )
                    && vecL.y( ) == vecR.y( ) };
        }
        else if constexpr ( Size == 3 ) {
            return r { vecL.x( ) == vecR.x( )
                    && vecL.y( ) == vecR.y( )
                    && vecL.z( ) == vecR.z( ) };
        }
        else if constexpr ( Size == 4 ) {
            return r { vecL.x( ) == vecR.x( )
                    && vecL.y( ) == vecR.y( )
                    && vecL.z( ) == vecR.z( )
                    && vecL.w( ) == vecR.w( ) };
        }
    }
    // Vec (column vector) inequality: (any)v != (any)v = bool
    template< typename Type, unsigned Size, bool RowMajorL, bool RowMajorR >
    SON8_MATFOURD_FUNC operator!=( Vec< Type, Size, RowMajorL > const &vecL, Vec< Type, Size, RowMajorR > const &vecR )
    -> bool {
        return not (vecL == vecR);
    }
} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_EQUALITY_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
// Apache License 2.0
// NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
// SPDX-License-Identifier: Apache-2.0
// lib: `matfourd` C++17 Four Dimensional Matrices
// Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ
