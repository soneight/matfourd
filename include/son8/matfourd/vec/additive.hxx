#ifndef SON8_MATFOURD_VEC_ADDITIVE_HXX
#define SON8_MATFOURD_VEC_ADDITIVE_HXX

#include <son8/matfourd/vec/type.hxx>

namespace son8::matfourd {
    // Vec (column vector) addition: (any)v + (any)v = v
    template< typename Type, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator+( Vec< Type, Size, LaytL > const &vecL, Vec< Type, Size, LaytR > const &vecR ) {
        using Ret = Vec< Type, Size, Layout::ColMajor >;
        Ret ret;
        ret.x( ) = vecL.x( ) + vecR.x( );
        ret.y( ) = vecL.y( ) + vecR.y( );
        if constexpr ( Ret::size( ) > 2 ) ret.z( ) = vecL.z( ) + vecR.z( );
        if constexpr ( Ret::size( ) > 3 ) ret.w( ) = vecL.w( ) + vecR.w( );
        return ret;
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
