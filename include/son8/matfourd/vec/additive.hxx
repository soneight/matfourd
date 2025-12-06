#ifndef SON8_MATFOURD_VEC_ADDITIVE_HXX
#define SON8_MATFOURD_VEC_ADDITIVE_HXX

#include <son8/matfourd/vec/type.hxx>

namespace son8::matfourd {
    // Vec (column vector) addition: (any)v + (any)v = v
    template< typename TypeL, typename TypeR, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator+( Vec< TypeL, Size, LaytL > const &vecL, Vec< TypeR, Size, LaytR > const &vecR )
    -> Vec< decltype( vecL.x( ) + vecR.x( ) ), Size, Layout::ColMajor > {
        using Ret = Vec< decltype( vecL.x( ) + vecR.x( ) ), Size, Layout::ColMajor >;
        Ret ret;
        ret.x( ) = vecL.x( ) + vecR.x( );
        ret.y( ) = vecL.y( ) + vecR.y( );
        if constexpr ( Ret::size( ) > 2 ) { ret.z( ) = vecL.z( ) + vecR.z( ); }
        if constexpr ( Ret::size( ) > 3 ) { ret.w( ) = vecL.w( ) + vecR.w( ); }
        return ret;
    }
    // Vec (column vector) subtraction: (any)v - (any)v = v
    template< typename TypeL, typename TypeR, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator-( Vec< TypeL, Size, LaytL > const &vecL, Vec< TypeR, Size, LaytR > const &vecR )
    -> Vec< decltype( vecL.x( ) - vecR.x( ) ), Size, Layout::ColMajor > {
        return vecL + (-vecR);
    }
} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_ADDITIVE_HXX
