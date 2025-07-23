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
    private:
        DataType data_;
    public:
        // constructors
        Vec( ) = default;
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
        // "transpose" operator~
        SON8_MATFOURD_FUNC operator~( ) const {
            static_assert( Layt == Layout::ColMajor, "Vec (column vector) " "layout is already row-major" );
            return Vec< ValueType, Size, Layout::RowMajor >{ data_ };
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
    // Vec (column ) aliases
    template< typename Type > using Vec2 = Vec< Type, 2 >;
    template< typename Type > using Vec3 = Vec< Type, 3 >;
    template< typename Type > using Vec4 = Vec< Type, 4 >;
    // Vec (column vector) inner product (dot/scalar product)
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator*( Vec< TypeL, SizeL, LaytL > const vecL, Vec< TypeR, SizeR, LaytR > const vecR ) {
        static_assert( SizeL == SizeR, "Vec (column vector) " "dot product " "sizes must match" );
        static_assert( LaytR == Layout::ColMajor, "Vec (column vector) " "dot product " "right operand must be column-major vector" );
        using Ret = decltype( vecL.x( ) * vecR.x( ) );
        Ret ret = vecL.x( ) * vecR.x( ) + vecL.y( ) * vecR.y( );
        if constexpr ( SizeL > 2 ) { ret = ret + vecL.z( ) * vecR.z( ); }
        if constexpr ( SizeL > 3 ) { ret = ret + vecL.w( ) * vecR.w( ); }
        return ret;
    }
    // Vec (column vector) cross product
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator^( Vec< TypeL, SizeL, LaytL > const vecL, Vec< TypeR, SizeR, LaytR > const vecR ) {
        static_assert( SizeL == 3 && SizeR == 3, "Vec (column vector) " "cross product is only defined for 3D vectors" );
        static_assert( LaytL == Layout::ColMajor && LaytR == Layout::ColMajor, "Vec (column vector) " "cross product ^ " "both operands must be column-major vectors" );
        using Ret = Vec< decltype( vecL.x( ) * vecR.y( ) - vecL.y( ) * vecR.x( ) ), 3 >;
        return Ret{
            vecL.y( ) * vecR.z( ) - vecL.z( ) * vecR.y( ),
            vecL.z( ) * vecR.x( ) - vecL.x( ) * vecR.z( ),
            vecL.x( ) * vecR.y( ) - vecL.y( ) * vecR.x( )
        };
    }
} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
