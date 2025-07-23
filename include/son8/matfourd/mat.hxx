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
        static constexpr unsigned vals( ) { return ( Layt == Layout::ColMajor ) ? Rows : Cols; }
        static constexpr unsigned rows( ) { return Rows; }
        static constexpr unsigned cols( ) { return Cols; }
        static constexpr unsigned size( ) { return Rows * Cols; }
        DataType const &data( ) const { return data_; }
        // constructors
        Mat( ) = default;
        Mat( Mat< Type, Rows, Cols, not Layt > const &other ) : data_{ (~other).data( ) } { }
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
        // as row-major operator~
        SON8_MATFOURD_FUNC operator~( ) const -> Mat< ValueType, Rows, Cols, not Layt > {
            Mat< ValueType, Rows, Cols, not Layt > ret;

            /*_*/if constexpr ( vecs( ) == 2 ) ret.v1() = { data_[0].x(), data_[1].x() };
            else if constexpr ( vecs( ) == 3 ) ret.v1() = { data_[0].x(), data_[1].x(), data_[2].x() };
            else if constexpr ( vecs( ) == 4 ) ret.v1() = { data_[0].x(), data_[1].x(), data_[2].x(), data_[3].x() };

            /*_*/if constexpr ( vecs( ) == 2 ) ret.v2() = { data_[0].y(), data_[1].y() };
            else if constexpr ( vecs( ) == 3 ) ret.v2() = { data_[0].y(), data_[1].y(), data_[2].y() };
            else if constexpr ( vecs( ) == 4 ) ret.v2() = { data_[0].y(), data_[1].y(), data_[2].y(), data_[3].y() };

            if constexpr ( vals( ) > 2 ) {
                /*_*/if constexpr ( vecs( ) == 2 ) ret.v3() = { data_[0].z(), data_[1].z() };
                else if constexpr ( vecs( ) == 3 ) ret.v3() = { data_[0].z(), data_[1].z(), data_[2].z() };
                else if constexpr ( vecs( ) == 4 ) ret.v3() = { data_[0].z(), data_[1].z(), data_[2].z(), data_[3].z() };
            }
            if constexpr ( vals( ) > 3 ) {
                /*_*/if constexpr ( vecs( ) == 2 ) ret.v4() = { data_[0].w(), data_[1].w() };
                else if constexpr ( vecs( ) == 3 ) ret.v4() = { data_[0].w(), data_[1].w(), data_[2].w() };
                else if constexpr ( vecs( ) == 4 ) ret.v4() = { data_[0].w(), data_[1].w(), data_[2].w(), data_[3].w() };
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
    // inner product (vec * Vec)
    template< typename TypeL, typename TypeR, unsigned Size >
    SON8_MATFOURD_FUNC operator*( Vec< TypeL, Size > const &vecL, Vec< TypeR, Size, Layout::RowMajor > const &vecR )
    -> Mat< decltype( vecL.x( ) * vecR.x( ) ), Size, Size > {
        using Ret = Mat< decltype( vecL.x( ) * vecR.x( ) ), Size, Size >;
        Ret ret;
        if constexpr ( Size == 2 ) {
            ret.v1( ) = { vecL.x( ) * vecR.x( ), vecL.y( ) * vecR.x( ) };
            ret.v2( ) = { vecL.x( ) * vecR.y( ), vecL.y( ) * vecR.y( ) };
        } else if constexpr ( Size == 3 ) {
            ret.v1( ) = { vecL.x( ) * vecR.x( ), vecL.y( ) * vecR.x( ), vecL.z( ) * vecR.x( ) };
            ret.v2( ) = { vecL.x( ) * vecR.y( ), vecL.y( ) * vecR.y( ), vecL.z( ) * vecR.y( ) };
            ret.v3( ) = { vecL.x( ) * vecR.z( ), vecL.y( ) * vecR.z( ), vecL.z( ) * vecR.z( ) };
        } else if constexpr ( Size == 4 ) {
            ret.v1( ) = { vecL.x( ) * vecR.x( ), vecL.y( ) * vecR.x( ), vecL.z( ) * vecR.x( ), vecL.w( ) * vecR.x( ) };
            ret.v2( ) = { vecL.x( ) * vecR.y( ), vecL.y( ) * vecR.y( ), vecL.z( ) * vecR.y( ), vecL.w( ) * vecR.y( ) };
            ret.v3( ) = { vecL.x( ) * vecR.z( ), vecL.y( ) * vecR.z( ), vecL.z( ) * vecR.z( ), vecL.w( ) * vecR.z( ) };
            ret.v4( ) = { vecL.x( ) * vecR.w( ), vecL.y( ) * vecR.w( ), vecL.z( ) * vecR.w( ), vecL.w( ) * vecR.w( ) };
        }
        return ret;
    }
    // Vec * Mat
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols, bool LaytL >
    SON8_MATFOURD_FUNC operator*( Vec< TypeL, Rows, LaytL > const &vecL, Mat< TypeR, Rows, Cols > const &matR )
    -> Vec< decltype( vecL.x( ) * matR.v1( ).x( ) ), Cols, Layout::RowMajor > {
        using Ret = Vec< decltype( vecL.x( ) * matR.v1( ).x( ) ), Cols, Layout::RowMajor >;
        Ret ret;
        ret.x( ) = vecL * matR.v1( );
        ret.y( ) = vecL * matR.v2( );
        if constexpr ( Cols > 2 ) ret.z( ) = vecL * matR.v3( );
        if constexpr ( Cols > 3 ) ret.w( ) = vecL * matR.v4( );
        return ret;
    }
    // Mat * Vec
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols, bool LaytL >
    SON8_MATFOURD_FUNC operator*( Mat< TypeL, Rows, Cols, LaytL > const &matL, Vec< TypeR, Cols > const &vecR )
    -> Vec< decltype( matL.v1( ).x( ) * vecR.x( ) ), Rows > {
        using Ret = Vec< decltype( matL.v1( ).x( ) * vecR.x( ) ), Rows >;
        Ret ret;
        Mat< TypeL, Rows, Cols, Layout::RowMajor > const mat { matL };
        ret.x( ) = mat.v1( ) * vecR;
        ret.y( ) = mat.v2( ) * vecR;
        if constexpr ( Rows > 2 ) ret.z( ) = mat.v3( ) * vecR;
        if constexpr ( Rows > 3 ) ret.w( ) = mat.v4( ) * vecR;
        return ret;
    }
    // Mat * Mat
    template< typename TypeL, typename TypeR, unsigned RowsL, unsigned ColsL, unsigned RowsR, unsigned ColsR, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator*( Mat< TypeL, RowsL, ColsL, LaytL > const &matL, Mat< TypeR, RowsR, ColsR, LaytR > const &matR )
    -> Mat< decltype( matL.v1( ).x( ) * matR.v1( ).x( ) ), RowsL, ColsR > {
        static_assert( ColsL == RowsR, "Mat (column matrix) " "columns of left matrix must match rows of right matrix" );
        using Ret = Mat< decltype( matL.v1( ).x( ) * matR.v1( ).x( ) ), RowsL, ColsR >;
        Ret ret;
        Mat< TypeL, RowsL, ColsL, Layout::RowMajor > const matRow{ matL };
        Mat< TypeR, RowsR, ColsR, Layout::ColMajor > const matCol{ matR };
        ret.v1( ) = matRow * matCol.v1( );
        ret.v2( ) = matRow * matCol.v2( );
        if constexpr ( ColsR > 2 ) ret.v3( ) = matRow * matCol.v3( );
        if constexpr ( ColsR > 3 ) ret.v4( ) = matRow * matCol.v4( );
        return ret;
    }

}

#endif//SON8_MATFOURD_MAT_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
