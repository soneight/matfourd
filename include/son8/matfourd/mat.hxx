#ifndef SON8_MATFOURD_MAT_HXX
#define SON8_MATFOURD_MAT_HXX

#include <son8/matfourd/core.hxx>
#include <son8/matfourd/layout.hxx>
#include <son8/matfourd/vec.hxx>

#include <array>
#include <type_traits>

namespace son8::matfourd {
    // Mat (column matrix) class template
    template< typename Type, unsigned Rows, unsigned Cols, bool Layt = Layout::ColMajor >
    class Mat final {
    public:
        static constexpr unsigned const Dims_Min = 2;
        static constexpr unsigned const Dims_Max = 4;
        static_assert( Dims_Min <= Rows && Rows <= Dims_Max && Dims_Min <= Cols && Cols <= Dims_Max, "Mat (column matrix) " "dimensions must be in range [2,4]" );
        using ValueType = Type;
        using VectorType = std::conditional_t< Layt,
            Vec< ValueType, Cols, Layt >,
            Vec< ValueType, Rows, Layt >
        >;
        using DataType = std::conditional_t< Layt,
            std::array< VectorType, Rows >,
            std::array< VectorType, Cols >
        >;
        using SelfType = Mat< Type, Rows, Cols, Layt >;
        using SwapType = Mat< Type, Rows, Cols, not Layt >;
        friend SwapType;
    private:
        DataType data_;
        DataType const &array_data( ) const { return data_; }
    public:
        static constexpr unsigned vecs( ) { return ( Layt == Layout::ColMajor ) ? Cols : Rows; }
        static constexpr unsigned vals( ) { return ( Layt == Layout::ColMajor ) ? Rows : Cols; }
        static constexpr unsigned rows( ) { return Rows; }
        static constexpr unsigned cols( ) { return Cols; }
        static constexpr unsigned size( ) { return Rows * Cols; }
        SON8_MATFOURD_DISC data( ) -> ValueType * { return data_.data( )->data( ); }
        SON8_MATFOURD_FUNC data( ) const -> ValueType const * { return data_.data( )->data( ); }
        // constructors
        Mat( ) = default;
        Mat( SwapType const &other ) : data_{ (~other).array_data( ) } { }
        Mat( DataType const &array ) : data_( array ) { }
        Mat( VectorType const &v1, VectorType const &v2 )
        : data_{ v1, v2 } {
            static_assert( SelfType::vecs( ) == 2, "Mat (column matrix) " "constructor requires 2 vectors" );
        }
        Mat( VectorType const &v1, VectorType const &v2, VectorType const &v3 )
        : data_{ v1, v2, v3 } {
            static_assert( SelfType::vecs( ) == 3, "Mat (column matrix) " "constructor requires 3 vectors" );
        }
        Mat( VectorType const &v1, VectorType const &v2, VectorType const &v3, VectorType const &v4 )
        : data_{ v1, v2, v3, v4 } {
            static_assert( SelfType::vecs( ) == 4, "Mat (column matrix) " "constructor requires 4 vectors" );
        }
        // as row-major operator~
        SON8_MATFOURD_FUNC operator~( ) const -> SwapType {
            SwapType ret;

            /*_*/if constexpr ( SwapType::vals( ) == 2 ) ret.v1() = { data_[0].x(), data_[1].x() };
            else if constexpr ( SwapType::vals( ) == 3 ) ret.v1() = { data_[0].x(), data_[1].x(), data_[2].x() };
            else if constexpr ( SwapType::vals( ) == 4 ) ret.v1() = { data_[0].x(), data_[1].x(), data_[2].x(), data_[3].x() };

            /*_*/if constexpr ( SwapType::vals( ) == 2 ) ret.v2() = { data_[0].y(), data_[1].y() };
            else if constexpr ( SwapType::vals( ) == 3 ) ret.v2() = { data_[0].y(), data_[1].y(), data_[2].y() };
            else if constexpr ( SwapType::vals( ) == 4 ) ret.v2() = { data_[0].y(), data_[1].y(), data_[2].y(), data_[3].y() };

            if constexpr ( SwapType::vecs( ) > 2 ) {
                /*_*/if constexpr ( SwapType::vals( ) == 2 ) ret.v3() = { data_[0].z(), data_[1].z() };
                else if constexpr ( SwapType::vals( ) == 3 ) ret.v3() = { data_[0].z(), data_[1].z(), data_[2].z() };
                else if constexpr ( SwapType::vals( ) == 4 ) ret.v3() = { data_[0].z(), data_[1].z(), data_[2].z(), data_[3].z() };
            }
            if constexpr ( SwapType::vecs( ) > 3 ) {
                /*_*/if constexpr ( SwapType::vals( ) == 2 ) ret.v4() = { data_[0].w(), data_[1].w() };
                else if constexpr ( SwapType::vals( ) == 3 ) ret.v4() = { data_[0].w(), data_[1].w(), data_[2].w() };
                else if constexpr ( SwapType::vals( ) == 4 ) ret.v4() = { data_[0].w(), data_[1].w(), data_[2].w(), data_[3].w() };
            }

            return ret;
        }
        // permit
        SON8_MATFOURD_FUNC operator+( ) const -> SelfType {
            SelfType ret;
            ret.v1( ) = +v1( );
            ret.v2( ) = +v2( );
            if constexpr ( SelfType::vecs( ) > 2 ) ret.v3( ) = +v3( );
            if constexpr ( SelfType::vecs( ) > 3 ) ret.v4( ) = +v4( );
            return ret;
        }
        // negate
        SON8_MATFOURD_FUNC operator-( ) const -> SelfType {
            SelfType ret;
            ret.v1( ) = -v1( );
            ret.v2( ) = -v2( );
            if constexpr ( SelfType::vecs( ) > 2 ) ret.v3( ) = -v3( );
            if constexpr ( SelfType::vecs( ) > 3 ) ret.v4( ) = -v4( );
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
        SON8_MATFOURD_DISC operator*=( SelfType const &other ) -> SelfType & {
            static_assert( SelfType::rows( ) == SelfType::cols( ), "Mat (column matrix) " " compound operator* requires square matrix" );
            *this = *this * other;
            return *this;
        }
        SON8_MATFOURD_DISC operator*=( SwapType const &other ) -> SelfType & {
            *this *= ~other;
            return *this;
        }
        template< typename TypeR, unsigned RowsR, unsigned ColsR, bool LaytR >
        SON8_MATFOURD_DISC operator*=( Mat< TypeR, RowsR, ColsR, LaytR > const &other ) -> SelfType & {
            static_assert( false, "Mat (column matrix) " "compound operator* requires compatible matrix types" );
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
    };
    // Mat (column matrix) aliases
    template< typename Type, bool Layt = Layout::ColMajor > using Mat2 = Mat< Type, 2, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat3 = Mat< Type, 3, 3, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat4 = Mat< Type, 4, 4, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat2x3 = Mat< Type, 2, 3, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat2x4 = Mat< Type, 2, 4, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat3x2 = Mat< Type, 3, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat3x4 = Mat< Type, 3, 4, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat4x2 = Mat< Type, 4, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat4x3 = Mat< Type, 4, 3, Layt >;

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
