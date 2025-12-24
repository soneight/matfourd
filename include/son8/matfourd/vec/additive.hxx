#ifndef SON8_MATFOURD_VEC_ADDITIVE_HXX
#define SON8_MATFOURD_VEC_ADDITIVE_HXX

#include <son8/matfourd/vec/type.hxx>

namespace son8::matfourd {
    // Vec (column vector) addition: (any)v + (any)v = v
    template< typename Type, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator+( Vec< Type, Size, LaytL > const &vecL, Vec< Type, Size, LaytR > const &vecR ) {
        using r = Vec< Type, Size, Layout::ColMajor >;
        if/*___*/ constexpr ( r::size( ) == 2 ) {
            return r{ vecL.x( ) + vecR.x( )
                    , vecL.y( ) + vecR.y( ) };
        } else if constexpr ( r::size( ) == 3 ) {
            return r{ vecL.x( ) + vecR.x( )
                    , vecL.y( ) + vecR.y( )
                    , vecL.z( ) + vecR.z( ) };
        } else if constexpr ( r::size( ) == 4 ) {
            return r{ vecL.x( ) + vecR.x( )
                    , vecL.y( ) + vecR.y( )
                    , vecL.z( ) + vecR.z( )
                    , vecL.w( ) + vecR.w( ) };
        }
    }
    // Vec (column vector) subtraction: (any)v - (any)v = v
    template< typename Type, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator-( Vec< Type, Size, LaytL > const &vecL, Vec< Type, Size, LaytR > const &vecR )
    -> Vec< Type, Size, Layout::ColMajor > {
        return vecL + (-vecR);
    }
} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_ADDITIVE_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
