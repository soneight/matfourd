#ifndef SON8_MATFOURD_VEC_HXX
#define SON8_MATFOURD_VEC_HXX

#include <son8/matfourd/core.hxx>
#include <son8/matfourd/layout.hxx>

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
        // compound only works with same value type
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

} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
