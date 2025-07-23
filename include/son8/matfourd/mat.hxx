#ifndef SON8_MATFOURD_MAT_HXX
#define SON8_MATFOURD_MAT_HXX

#include "core.hxx"
#include "layout.hxx"
#include "vec.hxx"

#include <array>

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
    private:
        DataType data_;
    public:
        static constexpr unsigned vecs( ) { return ( Layt == Layout::ColMajor ) ? Cols : Rows; }
        // constructors
        Mat( ) = default;
        Mat( DataType const &array ) : data_( array ) { }
        Mat( VectorType const &v1, VectorType const &v2 )
        : data_{ v1, v2 } {
            static_assert( vecs( ) == 2, "Mat (column matrix) " "constructor requires 2 vectors" );
        }
        Mat( VectorType const &v1, VectorType const &v2, VectorType const &v3 )
        : data_{ v1, v2, v3 } {
            static_assert( vecs( ) == 3, "Mat (column matrix) " "constructor requires 3 vectors" );
        }
        Mat( VectorType const &v1, VectorType const &v2, VectorType const &v3, VectorType const &v4 )
        : data_{ v1, v2, v3, v4 } {
            static_assert( vecs( ) == 4, "Mat (column matrix) " "constructor requires 4 vectors" );
        }
        // accessors
        SON8_MATFOURD_FUNC v1( ) -> VectorType & {
            return data_[0];
        }
        SON8_MATFOURD_FUNC v2( ) -> VectorType & {
            return data_[1];
        }
        SON8_MATFOURD_FUNC v3( ) -> VectorType & {
            static_assert( vecs( ) > 2, "Mat (column matrix) " "accessor requires more than 2 vectors" );
            return data_[2];
        }
        SON8_MATFOURD_FUNC v4( ) -> VectorType & {
            static_assert( vecs( ) > 3, "Mat (column matrix) " "accessor requires more than 3 vectors" );
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
            static_assert( vecs( ) > 2, "Mat (column matrix) " "accessor requires more than 2 vectors" );
            return data_[2];
        }
        SON8_MATFOURD_FUNC v4( ) const -> VectorType const & {
            static_assert( vecs( ) > 3, "Mat (column matrix) " "accessor requires more than 3 vectors" );
            return data_[3];
        }
        // "transpose" operator~
        SON8_MATFOURD_FUNC operator~( ) const -> Mat< ValueType, Rows, Cols, Layout::RowMajor > {
            static_assert( Layt == Layout::ColMajor, "Mat (column matrix) " "`transpose` requires column-major layout" );
            Mat< ValueType, Rows, Cols, Layout::RowMajor > ret;

            /*_*/if constexpr ( Cols == 2 ) ret.v1() = { data_[0].x(), data_[1].x() };
            else if constexpr ( Cols == 3 ) ret.v1() = { data_[0].x(), data_[1].x(), data_[2].x() };
            else if constexpr ( Cols == 4 ) ret.v1() = { data_[0].x(), data_[1].x(), data_[2].x(), data_[3].x() };

            /*_*/if constexpr ( Cols == 2 ) ret.v2() = { data_[0].y(), data_[1].y() };
            else if constexpr ( Cols == 3 ) ret.v2() = { data_[0].y(), data_[1].y(), data_[2].y() };
            else if constexpr ( Cols == 4 ) ret.v2() = { data_[0].y(), data_[1].y(), data_[2].y(), data_[3].y() };

            if constexpr ( Rows > 2 ) {
                /*_*/if constexpr ( Cols == 2 ) ret.v3() = { data_[0].z(), data_[1].z() };
                else if constexpr ( Cols == 3 ) ret.v3() = { data_[0].z(), data_[1].z(), data_[2].z() };
                else if constexpr ( Cols == 4 ) ret.v3() = { data_[0].z(), data_[1].z(), data_[2].z(), data_[3].z() };
            }
            if constexpr ( Rows > 3 ) {
                /*_*/if constexpr ( Cols == 2 ) ret.v4() = { data_[0].w(), data_[1].w() };
                else if constexpr ( Cols == 3 ) ret.v4() = { data_[0].w(), data_[1].w(), data_[2].w() };
                else if constexpr ( Cols == 4 ) ret.v4() = { data_[0].w(), data_[1].w(), data_[2].w(), data_[3].w() };
            }
            return ret;
        }
    };
    // Mat (column matrix) aliases
    template< typename Type > using Mat2 = Mat< Type, 2, 2 >;
    template< typename Type > using Mat3 = Mat< Type, 3, 3 >;
    template< typename Type > using Mat4 = Mat< Type, 4, 4 >;
    template< typename Type > using Mat2x3 = Mat< Type, 2, 3 >;
    template< typename Type > using Mat2x4 = Mat< Type, 2, 4 >;
    template< typename Type > using Mat3x2 = Mat< Type, 3, 2 >;
    template< typename Type > using Mat3x4 = Mat< Type, 3, 4 >;
    template< typename Type > using Mat4x2 = Mat< Type, 4, 2 >;
    template< typename Type > using Mat4x3 = Mat< Type, 4, 3 >;
}

#endif//SON8_MATFOURD_MAT_HXX
