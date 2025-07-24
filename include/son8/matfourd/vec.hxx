#ifndef SON8_MATFOURD_VEC_HXX
#define SON8_MATFOURD_VEC_HXX

#include "core.hxx"
#include "layout.hxx"

#include <array>

namespace son8::matfourd {
    // Vec (column vector) class template
    template< typename Type, unsigned Size, bool Layt = Layout::ColMajor >
    class Vec final {
        static constexpr unsigned const Size_Min = 2;
        static constexpr unsigned const Size_Max = 4;
        static_assert( Size_Min <= Size && Size <= Size_Max, "Vec (column vector) " "size must be in range [2,4]" );
        using ValueType = Type;
        using DataType = std::array< ValueType, Size >;
        using SelfType = Vec< Type, Size, Layt >;
        using SwapType = Vec< Type, Size, not Layt >;
    private:
        DataType data_;
    public:
        static constexpr unsigned size( ) { return Size; }
        DataType const &data( ) const { return data_; }
        // constructors
        Vec( ) = default;
        Vec( SwapType const &other ) : data_{ other.data( ) } { }
        Vec( DataType const &array )
        : data_( array ) { }
        Vec( ValueType const &x, ValueType const &y )
        : data_{ x, y } {
            static_assert( Size == 2, "Vec (column vector) " "size must be 2 for this constructor" );
        }
        Vec( ValueType const &x, ValueType const &y, ValueType const &z )
        : data_{ x, y, z } {
            static_assert( Size == 3, "Vec (column vector) " "size must be 3 for this constructor" );
        }
        Vec( ValueType const &x, ValueType const &y, ValueType const &z, ValueType const &w ) : data_{ x, y, z, w } {
            static_assert( Size == 4, "Vec (column vector) " "size must be 4 for this constructor" );
        }
        // as row-major operator~
        SON8_MATFOURD_FUNC operator~( ) const -> SwapType {
            return SwapType{ data_ };
        }
        // permit
        SON8_MATFOURD_FUNC operator+( ) const -> SelfType {
            SelfType ret;
            ret.x( ) = +x( );
            ret.y( ) = +y( );
            if constexpr ( Size > 2 ) { ret.z( ) = +z( ); }
            if constexpr ( Size > 3 ) { ret.w( ) = +w( ); }
            return ret;
        }
        // negate
        SON8_MATFOURD_FUNC operator-( ) const -> SelfType {
            SelfType ret;
            ret.x( ) = -x( );
            ret.y( ) = -y( );
            if constexpr ( Size > 2 ) { ret.z( ) = -z( ); }
            if constexpr ( Size > 3 ) { ret.w( ) = -w( ); }
            return ret;
        }
        // compound only works with same value type (for now)
        SON8_MATFOURD_DISC operator+=( SelfType const &other ) -> SelfType & {
            *this = *this + other;
            return *this;
        }
        SON8_MATFOURD_DISC operator+=( SwapType const &other ) -> SelfType & {
            *this += ~other;
            return *this;
        }
        SON8_MATFOURD_DISC operator-=( SelfType const &other ) -> SelfType & {
            *this = *this - other;
            return *this;
        }
        SON8_MATFOURD_DISC operator-=( SwapType const &other ) -> SelfType & {
            *this -= ~other;
            return *this;
        }
        // accessors
        SON8_MATFOURD_FUNC x( ) -> ValueType & {
            return data_[0];
        }
        SON8_MATFOURD_FUNC y( ) -> ValueType & {
            return data_[1];
        }
        SON8_MATFOURD_FUNC z( ) -> ValueType & {
            static_assert( Size > 2, "Vec (column vector) " "size must be greater than 2 for this accessor" );
            return data_[2];
        }
        SON8_MATFOURD_FUNC w( ) -> ValueType & {
            static_assert( Size > 3, "Vec (column vector) " "size must be greater than 3 for this accessor" );
            return data_[3];
        }
        // const accessors
        SON8_MATFOURD_FUNC x( ) const -> ValueType const & {
            return data_[0];
        }
        SON8_MATFOURD_FUNC y( ) const -> ValueType const & {
            return data_[1];
        }
        SON8_MATFOURD_FUNC z( ) const -> ValueType const & {
            static_assert( Size > 2, "Vec (column vector) " "size must be greater than 2 for this accessor" );
            return data_[2];
        }
        SON8_MATFOURD_FUNC w( ) const -> ValueType const & {
            static_assert( Size > 3, "Vec (column vector) " "size must be greater than 3 for this accessor" );
            return data_[3];
        }
    };
    // Vec (column vector) aliases
    template< typename Type, bool Layt = Layout::ColMajor > using Vec2 = Vec< Type, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Vec3 = Vec< Type, 3, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Vec4 = Vec< Type, 4, Layt >;
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

} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
