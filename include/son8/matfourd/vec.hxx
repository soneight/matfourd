#ifndef SON8_MATFOURD_VEC_HXX
#define SON8_MATFOURD_VEC_HXX

#include <son8/matfourd/core.hxx>
#include <son8/matfourd/layout.hxx>

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
        static_assert( std::is_arithmetic_v< TypeL >, "Vec (column vector) " " scalar multiplicator requires to be arithmetic type" );
        using Ret = Vec< decltype( scalar * vec.x( ) ), Size, Layt >;
        Ret ret;
        ret.x( ) = scalar * vec.x( );
        ret.y( ) = scalar * vec.y( );
        if constexpr ( Size > 2 ) ret.z( ) = scalar * vec.z( );
        if constexpr ( Size > 3 ) ret.w( ) = scalar * vec.w( );
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
    // Vec (column vector) addition: (any)v + (any)v = v
    template< typename TypeL, typename TypeR, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator+( Vec< TypeL, Size, LaytL > const &vecL, Vec< TypeR, Size, LaytR > const &vecR )
    -> Vec< decltype( vecL.x( ) + vecR.x( ) ), Size, Layout::ColMajor > {
        using Ret = Vec< decltype( vecL.x( ) + vecR.x( ) ), Size, Layout::ColMajor >;
        Ret ret;
        ret.x( ) = vecL.x( ) + vecR.x( );
        ret.y( ) = vecL.y( ) + vecR.y( );
        if constexpr ( Size > 2 ) { ret.z( ) = vecL.z( ) + vecR.z( ); }
        if constexpr ( Size > 3 ) { ret.w( ) = vecL.w( ) + vecR.w( ); }
        return ret;
    }
    // Vec (column vector) subtraction: (any)v - (any)v = v
    template< typename TypeL, typename TypeR, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator-( Vec< TypeL, Size, LaytL > const &vecL, Vec< TypeR, Size, LaytR > const &vecR )
    -> Vec< decltype( vecL.x( ) - vecR.x( ) ), Size, Layout::ColMajor > {
        return vecL + (-vecR);
    }
    // Vec (column vector) equality: (any)v == (any)v = bool
    template< typename Type, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator==( Vec< Type, Size, LaytL > const &vecL, Vec< Type, Size, LaytR > const &vecR )
    -> bool {
        bool ret = vecL.x( ) == vecR.x( ) and vecL.y( ) == vecR.y( );
        if ( !ret ) return ret;
        if constexpr ( Size > 2 ) { ret = ret and vecL.z( ) == vecR.z( ); }
        if ( !ret ) return ret;
        if constexpr ( Size > 3 ) { ret = ret and vecL.w( ) == vecR.w( ); }
        return ret;
    }
    // Vec (column vector) inequality: (any)v != (any)v = bool
    template< typename Type, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator!=( Vec< Type, Size, LaytL > const &vecL, Vec< Type, Size, LaytR > const &vecR )
    -> bool {
        return not (vecL == vecR);
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
