#ifndef SON8_MATFOURD_VEC_MULTIPLY_HXX
#define SON8_MATFOURD_VEC_MULTIPLY_HXX

#include <son8/matfourd/vec/type.hxx>

namespace son8::matfourd {
    // Layout aware operations (operator^)
    // Vec (column vector) layout aware dot product: ~v ^ v = scalar (for library compile time test mainly)
    template< typename Type, unsigned Size >
    SON8_MATFOURD_FUNC operator^( Vec< Type, Size, Layout::RowMajor > const &vecRow, Vec< Type, Size, Layout::ColMajor > const &vecCol ) {
        using Ret = Type;
        Ret ret = vecRow.x( ) * vecCol.x( ) + vecRow.y( ) * vecCol.y( );
        if constexpr ( Size > 2 ) ret = ret + vecRow.z( ) * vecCol.z( );
        if constexpr ( Size > 3 ) ret = ret + vecRow.w( ) * vecCol.w( );
        return ret;
    }
    // Vec (column vector) layout-aware cross product: v[3] ^ v[3] = v[3]
    template< typename Type >
    SON8_MATFOURD_FUNC operator^( Vec< Type, 3, Layout::ColMajor > const &vecL, Vec< Type, 3, Layout::ColMajor > const &vecR ) {
        using Ret = Vec< Type, 3, Layout::ColMajor >;
        return Ret{
            vecL.y( ) * vecR.z( ) - vecL.z( ) * vecR.y( ),
            vecL.z( ) * vecR.x( ) - vecL.x( ) * vecR.z( ),
            vecL.x( ) * vecR.y( ) - vecL.y( ) * vecR.x( )
        };
    }
    // Generic operations (operator*)
    // Vec (column vector) generic: (any)v * scalar = v
    template< typename Type, unsigned Size, bool Layt >
    SON8_MATFOURD_FUNC operator*( Vec< Type, Size, Layt > const &vec, Type const &scalar ) {
        using Ret = Vec< Type, Size, Layt >;
        Ret ret;
        ret.x( ) = vec.x( ) * scalar;
        ret.y( ) = vec.y( ) * scalar;
        if constexpr ( Ret::size( ) > 2 ) ret.z( ) = vec.z( ) * scalar;
        if constexpr ( Ret::size( ) > 3 ) ret.w( ) = vec.w( ) * scalar;
        return ret;
    }
    // Vec (column vector) generic: scalar * (any)v = v
    template< typename Type, unsigned Size, bool Layt >
    SON8_MATFOURD_FUNC operator*( Type const &scalar, Vec< Type, Size, Layt > const &vec )
    -> Vec< Type, Size, Layt > {
        return vec * scalar;
    }
    // Vec (column vector) generic dot product: (any)v * (any)v = scalar
    template< typename Type, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator*( Vec< Type, Size, LaytL > const &vecL, Vec< Type, Size, LaytR > const &vecR ) {
        using Ret = Type;
        Ret ret = vecL.x( ) * vecR.x( ) + vecL.y( ) * vecR.y( );
        if constexpr ( Size > 2 ) ret = ret + vecL.z( ) * vecR.z( );
        if constexpr ( Size > 3 ) ret = ret + vecL.w( ) * vecR.w( );
        return ret;
    }
}

#endif//SON8_MATFOURD_VEC_MULTIPLY_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
