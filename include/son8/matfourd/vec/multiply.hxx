#ifndef SON8_MATFOURD_VEC_MULTIPLY_HXX
#define SON8_MATFOURD_VEC_MULTIPLY_HXX

#include <son8/matfourd/vec/type.hxx>

namespace son8::matfourd {
    // Layout aware operations (operator^)
    // Vec (column vector) layout aware dot product: ~v ^ v = scalar (for library compile time test mainly)
    template< typename Type, unsigned Size >
    SON8_MATFOURD_FUNC operator^( Vec< Type, Size, Order::RowMajor > const &vecRow, Vec< Type, Size, Order::ColMajor > const &vecCol ) {
        using r = Type;
        if/*_*/ constexpr ( Size == 2 ) {
            return r{ vecRow.x( ) * vecCol.x( )
                    + vecRow.y( ) * vecCol.y( ) };
        }
        else if constexpr ( Size == 3 ) {
            return r{ vecRow.x( ) * vecCol.x( )
                    + vecRow.y( ) * vecCol.y( )
                    + vecRow.z( ) * vecCol.z( ) };
        }
        else if constexpr ( Size == 4 ) {
            return r{ vecRow.x( ) * vecCol.x( )
                    + vecRow.y( ) * vecCol.y( )
                    + vecRow.z( ) * vecCol.z( )
                    + vecRow.w( ) * vecCol.w( ) };
        }
    }
    // Vec (column vector) layout-aware cross product: v[3] ^ v[3] = v[3]
    template< typename Type >
    SON8_MATFOURD_FUNC operator^( Vec< Type, 3, Order::ColMajor > const &vecL, Vec< Type, 3, Order::ColMajor > const &vecR ) {
        using r = Vec< Type, 3, Order::ColMajor >;
        return r{
            vecL.y( ) * vecR.z( ) - vecL.z( ) * vecR.y( ),
            vecL.z( ) * vecR.x( ) - vecL.x( ) * vecR.z( ),
            vecL.x( ) * vecR.y( ) - vecL.y( ) * vecR.x( )
        };
    }
    // Generic operations (operator*)
    // Vec (column vector) generic: (any)v * scalar = v
    template< typename Type, unsigned Size, bool RowMajor >
    SON8_MATFOURD_FUNC operator*( Vec< Type, Size, RowMajor > const &vec, Type const &scalar ) {
        using r = Vec< Type, Size, RowMajor >;
        if/*_*/ constexpr ( r::size( ) == 2 ) {
            return r{ vec.x( ) * scalar
                    , vec.y( ) * scalar };
        }
        else if constexpr ( r::size( ) == 3 ) {
            return r{ vec.x( ) * scalar
                    , vec.y( ) * scalar
                    , vec.z( ) * scalar };
        }
        else if constexpr ( r::size( ) == 4 ) {
            return r{ vec.x( ) * scalar
                    , vec.y( ) * scalar
                    , vec.z( ) * scalar
                    , vec.w( ) * scalar };
        }
    }
    // Vec (column vector) generic: scalar * (any)v = v
    template< typename Type, unsigned Size, bool RowMajor >
    SON8_MATFOURD_FUNC operator*( Type const &scalar, Vec< Type, Size, RowMajor > const &vec )
    -> Vec< Type, Size, RowMajor > {
        return vec * scalar;
    }
    // Vec (column vector) generic dot product: (any)v * (any)v = scalar
    template< typename Type, unsigned Size, bool RowMajorL, bool RowMajorR >
    SON8_MATFOURD_FUNC operator*( Vec< Type, Size, RowMajorL > const &vecL, Vec< Type, Size, RowMajorR > const &vecR ) {
        using r = Type;
        if/*___*/ constexpr ( Size == 2 ) {
            return r{ vecL.x( ) * vecR.x( )
                    + vecL.y( ) * vecR.y( ) };
        } else if constexpr ( Size == 3 ) {
            return r{ vecL.x( ) * vecR.x( )
                    + vecL.y( ) * vecR.y( )
                    + vecL.z( ) * vecR.z( ) };
        } else if constexpr ( Size == 4 ) {
            return r{ vecL.x( ) * vecR.x( )
                    + vecL.y( ) * vecR.y( )
                    + vecL.z( ) * vecR.z( )
                    + vecL.w( ) * vecR.w( ) };
        }
    }
}

#endif//SON8_MATFOURD_VEC_MULTIPLY_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
