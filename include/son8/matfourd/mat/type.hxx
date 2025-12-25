#ifndef SON8_MATFOURD_MAT_TYPE_HXX
#define SON8_MATFOURD_MAT_TYPE_HXX
// son8
#include <son8/matfourd/core.hxx>
#include <son8/matfourd/layout.hxx>
#include <son8/matfourd/vec/type.hxx>
// std
#include <array>
#include <type_traits>

namespace son8::matfourd {
    // Mat (column matrix) class template
    template< typename Type, unsigned Cols, unsigned Rows, bool Layt = Layout::ColMajor >
    class Mat final {
    public:
        static_assert( 2 <= Rows && Rows <= 4 && 2 <= Cols && Cols <= 4, "son8::matfourd: Mat template cols and rows must be in range [2,4]" );
        using ValueType = Type;
        using VectorType = std::conditional_t< Layt,
            Vec< ValueType, Cols, Layt >,
            Vec< ValueType, Rows, Layt >
        >;
        using DataType = std::conditional_t< Layt,
            std::array< VectorType, Rows >,
            std::array< VectorType, Cols >
        >;
        using SelfType = Mat< Type, Cols, Rows, Layt >;
        using SwapType = Mat< Type, Cols, Rows, not Layt >;
        friend SwapType;
    private:
        DataType data_;
        DataType const &array_data( ) const { return data_; }
    public:
        static constexpr unsigned vecs( ) noexcept { return ( Layt == Layout::ColMajor ) ? Cols : Rows; }
        static constexpr unsigned vals( ) noexcept { return ( Layt == Layout::ColMajor ) ? Rows : Cols; }
        static constexpr unsigned rows( ) noexcept { return Rows; }
        static constexpr unsigned cols( ) noexcept { return Cols; }
        static constexpr unsigned size( ) noexcept { return Rows * Cols; }
        static constexpr bool order( ) noexcept { return Layt; }
        SON8_MATFOURD_DISC data( ) -> ValueType * { return data_.data( )->data( ); }
        SON8_MATFOURD_FUNC data( ) const -> ValueType const * { return data_.data( )->data( ); }
        // constructors
        Mat( ) = default;
        Mat( SwapType const &other ) : data_{ (~other).array_data( ) } { }
        Mat( DataType const &array ) : data_( array ) { }
        Mat( VectorType const &v1, VectorType const &v2 )
        : data_{ v1, v2 } {
            static_assert( SelfType::vecs( ) == 2, "son8::matfourd: Mat constructor requires type with 2 vectors" );
        }
        Mat( VectorType const &v1, VectorType const &v2, VectorType const &v3 )
        : data_{ v1, v2, v3 } {
            static_assert( SelfType::vecs( ) == 3, "son8::matfourd: Mat constructor requires type with 3 vectors" );
        }
        Mat( VectorType const &v1, VectorType const &v2, VectorType const &v3, VectorType const &v4 )
        : data_{ v1, v2, v3, v4 } {
            static_assert( SelfType::vecs( ) == 4, "son8::matfourd: Mat constructor requires type with 4 vectors" );
        }
        // as swap order operator~
        SON8_MATFOURD_FUNC operator~( ) const -> SwapType {
            if/*___*/ constexpr ( SwapType::vecs( ) == 2 ) {
                if/*___*/ constexpr ( SwapType::vals( ) == 2 ) {
                    return SwapType { { v1( ).x( ), v2( ).x( ) }
                                    , { v1( ).y( ), v2( ).y( ) } };
                } else if constexpr ( SwapType::vals( ) == 3 ) {
                    return SwapType { { v1( ).x( ), v2( ).x( ), v3( ).x( ) }
                                    , { v1( ).y( ), v2( ).y( ), v3( ).y( ) } };
                } else if constexpr ( SwapType::vals( ) == 4 ) {
                    return SwapType { { v1( ).x( ), v2( ).x( ), v3( ).x( ), v4( ).x( ) }
                                    , { v1( ).y( ), v2( ).y( ), v3( ).y( ), v4( ).y( ) } };
                }
            } else if constexpr ( SwapType::vecs( ) == 3 ) {
                if/*___*/ constexpr ( SwapType::vals( ) == 2 ) {
                    return SwapType { { v1( ).x( ), v2( ).x( ) }
                                    , { v1( ).y( ), v2( ).y( ) }
                                    , { v1( ).z( ), v2( ).z( ) } };
                } else if constexpr ( SwapType::vals( ) == 3 ) {
                    return SwapType { { v1( ).x( ), v2( ).x( ), v3( ).x( ) }
                                    , { v1( ).y( ), v2( ).y( ), v3( ).y( ) }
                                    , { v1( ).z( ), v2( ).z( ), v3( ).z( ) } };
                } else if constexpr ( SwapType::vals( ) == 4 ) {
                    return SwapType { { v1( ).x( ), v2( ).x( ), v3( ).x( ), v4( ).x( ) }
                                    , { v1( ).y( ), v2( ).y( ), v3( ).y( ), v4( ).y( ) }
                                    , { v1( ).z( ), v2( ).z( ), v3( ).z( ), v4( ).z( ) } };
                }
            } else if constexpr ( SwapType::vecs( ) == 4 ) {
                if/*___*/ constexpr ( SwapType::vals( ) == 2 ) {
                    return SwapType { { v1( ).x( ), v2( ).x( ) }
                                    , { v1( ).y( ), v2( ).y( ) }
                                    , { v1( ).z( ), v2( ).z( ) }
                                    , { v1( ).w( ), v2( ).w( ) } };
                } else if constexpr ( SwapType::vals( ) == 3 ) {
                    return SwapType { { v1( ).x( ), v2( ).x( ), v3( ).x( ) }
                                    , { v1( ).y( ), v2( ).y( ), v3( ).y( ) }
                                    , { v1( ).z( ), v2( ).z( ), v3( ).z( ) }
                                    , { v1( ).w( ), v2( ).w( ), v3( ).w( ) } };
                } else if constexpr ( SwapType::vals( ) == 4 ) {
                    return SwapType { { v1( ).x( ), v2( ).x( ), v3( ).x( ), v4( ).x( ) }
                                    , { v1( ).y( ), v2( ).y( ), v3( ).y( ), v4( ).y( ) }
                                    , { v1( ).z( ), v2( ).z( ), v3( ).z( ), v4( ).z( ) }
                                    , { v1( ).w( ), v2( ).w( ), v3( ).w( ), v4( ).w( ) } };
                }
            }
        }
        // permit
        SON8_MATFOURD_FUNC operator+( ) const -> SelfType {
            if/*_*/ constexpr ( SelfType::vecs( ) == 2 ) return SelfType{ +v1( ), +v2( ) };
            else if constexpr ( SelfType::vecs( ) == 3 ) return SelfType{ +v1( ), +v2( ), +v3( ) };
            else if constexpr ( SelfType::vecs( ) == 4 ) return SelfType{ +v1( ), +v2( ), +v3( ), +v4( ) };
        }
        // negate
        SON8_MATFOURD_FUNC operator-( ) const -> SelfType {
            if/*_*/ constexpr ( SelfType::vecs( ) == 2 ) return SelfType{ -v1( ), -v2( ) };
            else if constexpr ( SelfType::vecs( ) == 3 ) return SelfType{ -v1( ), -v2( ), -v3( ) };
            else if constexpr ( SelfType::vecs( ) == 4 ) return SelfType{ -v1( ), -v2( ), -v3( ), -v4( ) };
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
        SON8_MATFOURD_DISC operator*=( SelfType const &other ) -> SelfType & {
            static_assert( SelfType::rows( ) == SelfType::cols( ), "son8::matfourd: Mat operator*= requires square matrix" );
            *this = *this * other;
            return *this;
        }
        SON8_MATFOURD_DISC operator*=( SwapType const &other ) -> SelfType & {
            *this *= ~other;
            return *this;
        }
        // accessors
        SON8_MATFOURD_FUNC v1( ) -> VectorType & {
            return data_[0];
        }
        SON8_MATFOURD_FUNC v2( ) -> VectorType & {
            return data_[1];
        }
        SON8_MATFOURD_FUNC v3( ) -> VectorType & {
            static_assert( SelfType::vecs( ) > 2, "Mat (column matrix) " "accessor requires more than 2 vectors" );
            return data_[2];
        }
        SON8_MATFOURD_FUNC v4( ) -> VectorType & {
            static_assert( SelfType::vecs( ) > 3, "Mat (column matrix) " "accessor requires more than 3 vectors" );
            return data_[3];
        }
        // const accessors
        SON8_MATFOURD_FUNC v1( ) const -> VectorType const & {
            return data_[0];
        }
        SON8_MATFOURD_FUNC v2( ) const -> VectorType const & {
            return data_[1];
        }
        SON8_MATFOURD_FUNC v3( ) const -> VectorType const & {
            static_assert( SelfType::vecs( ) > 2, "Mat (column matrix) " "accessor requires more than 2 vectors" );
            return data_[2];
        }
        SON8_MATFOURD_FUNC v4( ) const -> VectorType const & {
            static_assert( SelfType::vecs( ) > 3, "Mat (column matrix) " "accessor requires more than 3 vectors" );
            return data_[3];
        }
    }; // class Mat

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_TYPE_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
