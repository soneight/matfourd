#ifndef SON8_MATFOURD_VEC_MULTIPLY_HXX
#define SON8_MATFOURD_VEC_MULTIPLY_HXX

#include <son8/matfourd/vec/type.hxx>

namespace son8::matfourd {
    // Layout aware operations (operator^)
    // Vec (column vector) layout aware dot product: ~v ^ v = scalar (for library compile time test mainly)
    template< typename TypeL, typename TypeR, unsigned Size >
    SON8_MATFOURD_FUNC operator^( Vec< TypeL, Size, Layout::RowMajor > const &vecRow, Vec< TypeR, Size, Layout::ColMajor > const &vecCol ) {
        using Ret = decltype( vecRow.x( ) * vecCol.x( ) );
        Ret ret = vecRow.x( ) * vecCol.x( ) + vecRow.y( ) * vecCol.y( );
        if constexpr ( Size > 2 ) { ret = ret + vecRow.z( ) * vecCol.z( ); }
        if constexpr ( Size > 3 ) { ret = ret + vecRow.w( ) * vecCol.w( ); }
        return ret;
    }
    // Vec (column vector) layout-aware cross product: v[3] ^ v[3] = v[3]
    template< typename TypeL, typename TypeR >
    SON8_MATFOURD_FUNC operator^( Vec< TypeL, 3, Layout::ColMajor > const &vecL, Vec< TypeR, 3, Layout::ColMajor > const &vecR ) {
        using Ret = Vec< decltype( vecL.x( ) * vecR.y( ) - vecL.y( ) * vecR.x( ) ), 3, Layout::ColMajor >;
        return Ret{
            vecL.y( ) * vecR.z( ) - vecL.z( ) * vecR.y( ),
            vecL.z( ) * vecR.x( ) - vecL.x( ) * vecR.z( ),
            vecL.x( ) * vecR.y( ) - vecL.y( ) * vecR.x( )
        };
    }
    // Generic operations (operator*)
    // Vec (column vector) generic: scalar * (any)v = v
    template< typename TypeL, typename TypeR, unsigned Size, bool Layt >
    SON8_MATFOURD_FUNC operator*( TypeL scalar, Vec< TypeR, Size, Layt > const &vec )
    -> Vec< decltype( scalar * vec.x( ) ), Size, Layt > {
        static_assert( std::is_arithmetic_v< TypeL >, "Vec (column vector) " " scalar multiplier requires to be arithmetic type" );
        using Ret = Vec< decltype( scalar * vec.x( ) ), Size, Layt >;
        Ret ret;
        ret.x( ) = scalar * vec.x( );
        ret.y( ) = scalar * vec.y( );
        if constexpr ( Ret::size( ) > 2 ) ret.z( ) = scalar * vec.z( );
        if constexpr ( Ret::size( ) > 3 ) ret.w( ) = scalar * vec.w( );
        return ret;
    }
    // Vec (column vector) generic: (any)v * scalar = v
    template< typename TypeL, typename TypeR, unsigned Size, bool Layt >
    SON8_MATFOURD_FUNC operator*( Vec< TypeL, Size, Layt > const &vec, TypeR scalar )
    -> Vec< decltype( vec.x( ) * scalar ), Size, Layt > {
        return scalar * vec;
    }
    // Vec (column vector) generic dot product: (any)v * (any)v = scalar
    template< typename TypeL, typename TypeR, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator*( Vec< TypeL, Size, LaytL > const &vecL, Vec< TypeR, Size, LaytR > const &vecR ) {
        using Ret = decltype( vecL.x( ) * vecR.x( ) );
        Ret ret = vecL.x( ) * vecR.x( ) + vecL.y( ) * vecR.y( );
        if constexpr ( Size > 2 ) { ret = ret + vecL.z( ) * vecR.z( ); }
        if constexpr ( Size > 3 ) { ret = ret + vecL.w( ) * vecR.w( ); }
        return ret;
    }
}

#endif//SON8_MATFOURD_VEC_MULTIPLY_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
