#ifndef SON8_MATFOURD_VEC_TYPE_HXX
#define SON8_MATFOURD_VEC_TYPE_HXX
// son8
#include <son8/matfourd/core.hxx>
#include <son8/matfourd/layout.hxx>
// std
#include <array>

namespace son8::matfourd {
    // Vec (column vector) class template
    // TODO change Layt template parameter name to RowOrder?
    template< typename Type, unsigned Size, bool Layt = Layout::ColMajor >
    class Vec final {
    public:
        static_assert( 2 <= Size && Size <= 4
            , "son8::matfourd: Vec template size must be in range [2,4]" );
        using ValueType = Type;
        using DataType = std::array< ValueType, Size >;
        using SelfType = Vec< Type, Size, Layt >;
        using SwapType = Vec< Type, Size, not Layt >;
        friend SwapType;
    private:
        DataType data_;
        DataType const &array_data( ) const { return data_; }
    public:
        static constexpr unsigned size( ) noexcept { return Size; }
        static constexpr bool order( ) noexcept { return Layt; }
        SON8_MATFOURD_DISC data( ) -> ValueType * { return data_.data( ); }
        SON8_MATFOURD_FUNC data( ) const -> ValueType const * { return data_.data( ); }
        // constructors
        template< typename Banned >
        Vec( ForsakenInitialist_< Banned > ) {
            static_assert( sizeof( ValueType ) == 0xFA1105
                , "son8::matfourd: Vec constructor requires not forsaken nested initilizer_list-like constructs" );
        }
        Vec( ) = default;
        operator DataType() const { return data_; }
        explicit Vec( DataType const &array )
        : data_( array ) { }
        Vec( ValueType const &x, ValueType const &y )
        : data_{ x, y } {
            static_assert( Size == 2
                , "son8::matfourd: Vec constructor requires type with 2 elements" );
        }
        Vec( ValueType const &x, ValueType const &y, ValueType const &z )
        : data_{ x, y, z } {
            static_assert( Size == 3
                , "son8::matfourd: Vec constructor requires type with 3 elements" );
        }
        Vec( ValueType const &x, ValueType const &y, ValueType const &z, ValueType const &w )
        : data_{ x, y, z, w } {
            static_assert( Size == 4
                , "son8::matfourd: Vec constructor requires type with 4 elements" );
        }
        // as row-major operator~
        SON8_MATFOURD_FUNC operator~( ) const -> SwapType {
            return SwapType{ data_ };
        }
        // permit
        SON8_MATFOURD_FUNC operator+( ) const -> SelfType {
            if/*_*/ constexpr ( SelfType::size( ) == 2 ) return SelfType{ +x( ), +y( ) };
            else if constexpr ( SelfType::size( ) == 3 ) return SelfType{ +x( ), +y( ), +z( ) };
            else if constexpr ( SelfType::size( ) == 4 ) return SelfType{ +x( ), +y( ), +z( ), +w( ) };
        }
        // negate
        SON8_MATFOURD_FUNC operator-( ) const -> SelfType {
            if/*_*/ constexpr ( SelfType::size( ) == 2 ) return SelfType{ -x( ), -y( ) };
            else if constexpr ( SelfType::size( ) == 3 ) return SelfType{ -x( ), -y( ), -z( ) };
            else if constexpr ( SelfType::size( ) == 4 ) return SelfType{ -x( ), -y( ), -z( ), -w( ) };
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
            static_assert( Size > 2
                , "son8::matfourd: Vec accessor z requires larger array type" );
            return data_[2];
        }
        SON8_MATFOURD_FUNC w( ) -> ValueType & {
            static_assert( Size > 3
                , "son8::matfourd: Vec accessor w requires larger array type" );
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
            static_assert( Size > 2
                , "son8::matfourd: Vec const accessor z requires larger array type" );
            return data_[2];
        }
        SON8_MATFOURD_FUNC w( ) const -> ValueType const & {
            static_assert( Size > 3
                , "son8::matfourd: Vec const accessor w requires larger array type" );
            return data_[3];
        }
    }; // class Vec

} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_TYPE_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
