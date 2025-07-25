#ifndef SON8_MATFOURD_MAT_HXX
#define SON8_MATFOURD_MAT_HXX

#include "core.hxx"
#include "layout.hxx"
#include "vec.hxx"

#include <algorithm>
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
        Mat( SwapType const &other ) : data_{ (~other).data( ) } { }
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
    // Layout aware operations (operator^)
    // Mat (column matrix) layout-aware vector outer product: Vec ^ ~Vec = Mat
    template< typename TypeL, typename TypeR, unsigned Size >
    SON8_MATFOURD_FUNC operator^( Vec< TypeL, Size, Layout::ColMajor > const &vecL, Vec< TypeR, Size, Layout::RowMajor > const &vecR )
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
    // Mat (column matrix) layout-aware: ~Vec ^ Mat = ~Vec
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols >
    SON8_MATFOURD_FUNC operator^( Vec< TypeL, Rows, Layout::RowMajor > const &vecRow, Mat< TypeR, Rows, Cols, Layout::ColMajor > const &matCol )
    -> Vec< decltype( vecRow.x( ) * matCol.v1( ).x( ) ), Cols, Layout::RowMajor > {
        using Ret = Vec< decltype( vecRow.x( ) * matCol.v1( ).x( ) ), Cols, Layout::RowMajor >;
        Ret ret;
        ret.x( ) = vecRow ^ matCol.v1( );
        ret.y( ) = vecRow ^ matCol.v2( );
        if constexpr ( Cols > 2 ) ret.z( ) = vecRow ^ matCol.v3( );
        if constexpr ( Cols > 3 ) ret.w( ) = vecRow ^ matCol.v4( );
        return ret;
    }
    // Mat (column matrix) layout-aware: ~Mat ^ Vec = Vec
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols >
    SON8_MATFOURD_FUNC operator^( Mat< TypeL, Rows, Cols, Layout::RowMajor > const &matRow, Vec< TypeR, Cols, Layout::ColMajor > const &vecCol )
    -> Vec< decltype( matRow.v1( ).x( ) * vecCol.x( ) ), Rows > {
        using Ret = Vec< decltype( matRow.v1( ).x( ) * vecCol.x( ) ), Rows >;
        Ret ret;
        ret.x( ) = matRow.v1( ) ^ vecCol;
        ret.y( ) = matRow.v2( ) ^ vecCol;
        if constexpr ( Rows > 2 ) ret.z( ) = matRow.v3( ) ^ vecCol;
        if constexpr ( Rows > 3 ) ret.w( ) = matRow.v4( ) ^ vecCol;
        return ret;
    }
    // Mat (column matrix) layout-aware: ~Mat ^ Mat = Mat
    template< typename TypeL, typename TypeR, unsigned RowsL, unsigned ColsL, unsigned RowsR, unsigned ColsR >
    SON8_MATFOURD_FUNC operator^( Mat< TypeL, RowsL, ColsL, Layout::RowMajor > const &matRow, Mat< TypeR, RowsR, ColsR, Layout::ColMajor > const &matCol )
    -> Mat< decltype( matRow.v1( ).x( ) * matCol.v1( ).x( ) ), RowsL, ColsR > {
        static_assert( ColsL == RowsR, "Mat (column matrix) " "columns of left matrix must match rows of right matrix" );
        using Ret = Mat< decltype( matRow.v1( ).x( ) * matCol.v1( ).x( ) ), RowsL, ColsR >;
        Ret ret;
        ret.v1( ) = matRow ^ matCol.v1( );
        ret.v2( ) = matRow ^ matCol.v2( );
        if constexpr ( ColsR > 2 ) ret.v3( ) = matRow ^ matCol.v3( );
        if constexpr ( ColsR > 3 ) ret.v4( ) = matRow ^ matCol.v4( );
        return ret;
    }
    // Generic operations (operator*)
    // Mat (column matrix) generic: scalar * (any)Mat = Mat
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols, bool Layt >
    SON8_MATFOURD_FUNC operator*( TypeL scalar, Mat< TypeR, Rows, Cols, Layt > const &mat )
    -> Mat< decltype( scalar * mat.v1( ).x( ) ), Rows, Cols, Layt > {
        static_assert( std::is_arithmetic_v< TypeL >, "Mat (column matrix) " " matrix scalar multiplicator requires to be arithmetic type" );
        using Ret = Mat< decltype( scalar * mat.v1( ).x( ) ), Rows, Cols, Layt >;
        Ret ret;
        ret.v1( ) = scalar * mat.v1( );
        ret.v2( ) = scalar * mat.v2( );
        if constexpr ( Cols > 2 ) ret.v3( ) = scalar * mat.v3( );
        if constexpr ( Cols > 3 ) ret.v4( ) = scalar * mat.v4( );
        return ret;
    }
    // Mat (column matrix) generic: (any)Mat * scalar = Mat
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols, bool Layt >
    SON8_MATFOURD_FUNC operator*( Mat< TypeL, Rows, Cols, Layt > const &mat, TypeR scalar )
    -> Mat< decltype( mat.v1( ).x( ) * scalar ), Rows, Cols, Layt > {
        return scalar * mat;
    }
    // Mat (column matrix) generic: (any)Vec * (any)Mat = Vec
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator*( Vec< TypeL, Rows, LaytL > const &vecL, Mat< TypeR, Rows, Cols, LaytR > const &matR )
    -> Vec< decltype( vecL.x( ) * matR.v1( ).x( ) ), Cols, Layout::RowMajor > {
        using Ret = Vec< decltype( vecL.x( ) * matR.v1( ).x( ) ), Cols, Layout::RowMajor >;
        Ret ret;
        Vec< TypeL, Rows, Layout::RowMajor > const vecRow{ vecL };
        Mat< TypeR, Rows, Cols, Layout::ColMajor > const matCol{ matR };
        ret.x( ) = vecRow ^ matCol.v1( );
        ret.y( ) = vecRow ^ matCol.v2( );
        if constexpr ( Cols > 2 ) ret.z( ) = vecRow ^ matCol.v3( );
        if constexpr ( Cols > 3 ) ret.w( ) = vecRow ^ matCol.v4( );
        return ret;
    }
    // Mat (column matrix) generic: (any)Mat * (any)Vec = Vec
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator*( Mat< TypeL, Rows, Cols, LaytL > const &matL, Vec< TypeR, Cols, LaytR > const &vecR )
    -> Vec< decltype( matL.v1( ).x( ) * vecR.x( ) ), Rows > {
        using Ret = Vec< decltype( matL.v1( ).x( ) * vecR.x( ) ), Rows >;
        Ret ret;
        Mat< TypeL, Rows, Cols, Layout::RowMajor > const matRow{ matL };
        Vec< TypeR, Cols, Layout::ColMajor > const vecCol{ vecR };
        ret.x( ) = matRow.v1( ) ^ vecCol;
        ret.y( ) = matRow.v2( ) ^ vecCol;
        if constexpr ( Rows > 2 ) ret.z( ) = matRow.v3( ) ^ vecCol;
        if constexpr ( Rows > 3 ) ret.w( ) = matRow.v4( ) ^ vecCol;
        return ret;
    }
    // Mat (column matrix) generic: (any)Mat * (any)Mat = Mat
    template< typename TypeL, typename TypeR, unsigned RowsL, unsigned ColsL, unsigned RowsR, unsigned ColsR, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator*( Mat< TypeL, RowsL, ColsL, LaytL > const &matL, Mat< TypeR, RowsR, ColsR, LaytR > const &matR )
    -> Mat< decltype( matL.v1( ).x( ) * matR.v1( ).x( ) ), RowsL, ColsR > {
        static_assert( ColsL == RowsR, "Mat (column matrix) " "columns of left matrix must match rows of right matrix" );
        using Ret = Mat< decltype( matL.v1( ).x( ) * matR.v1( ).x( ) ), RowsL, ColsR >;
        Ret ret;
        Mat< TypeL, RowsL, ColsL, Layout::RowMajor > const matRow{ matL };
        Mat< TypeR, RowsR, ColsR, Layout::ColMajor > const matCol{ matR };
        ret.v1( ) = matRow ^ matCol.v1( );
        ret.v2( ) = matRow ^ matCol.v2( );
        if constexpr ( ColsR > 2 ) ret.v3( ) = matRow ^ matCol.v3( );
        if constexpr ( ColsR > 3 ) ret.v4( ) = matRow ^ matCol.v4( );
        return ret;
    }
    // Mat (column matrix) layout-aware addition: (same)Mat + (same)Mat = Mat
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols, bool Layt >
    SON8_MATFOURD_FUNC operator+( Mat< TypeL, Rows, Cols, Layt > const &matL, Mat< TypeR, Rows, Cols, Layt > const &matR )
    -> Mat< decltype( matL.v1( ).x( ) + matR.v1( ).x( ) ), Rows, Cols, Layt > {
        using Ret = Mat< decltype( matL.v1( ).x( ) + matR.v1( ).x( ) ), Rows, Cols, Layt >;
        Ret ret;
        ret.v1( ) = matL.v1( ) + matR.v1( );
        ret.v2( ) = matL.v2( ) + matR.v2( );
        if constexpr ( Cols > 2 ) ret.v3( ) = matL.v3( ) + matR.v3( );
        if constexpr ( Cols > 3 ) ret.v4( ) = matL.v4( ) + matR.v4( );
        return ret;
    }
    // Mat (column matrix) layout-aware equality: (same)Mat == (same)Mat = bool
    template< typename Type, unsigned Rows, unsigned Cols, bool Layt >
    SON8_MATFOURD_FUNC operator==( Mat< Type, Rows, Cols, Layt > const &matL, Mat< Type, Rows, Cols, Layt > const &matR )
    -> bool {
        bool ret = matL.v1( ) == matR.v1( ) and matL.v2( ) == matR.v2( );
        if ( !ret ) return false;
        if constexpr ( Cols > 2 ) ret = matL.v3( ) == matR.v3( );
        if ( !ret ) return false;
        if constexpr ( Cols > 3 ) ret = matL.v4( ) == matR.v4( );
        return ret;
    }
    // Mat (column matrix) layout-aware inequality: (same)Mat != (same)Mat = bool
    template< typename Type, unsigned Rows, unsigned Cols, bool Layt >
    SON8_MATFOURD_FUNC operator!=( Mat< Type, Rows, Cols, Layt > const &matL, Mat< Type, Rows, Cols, Layt > const &matR )
    -> bool {
        return not ( matL == matR );
    }
    // Mat (column matrix) generic addition: (any)Mat + (any)Mat = Mat
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator+( Mat< TypeL, Rows, Cols, LaytL > const &matL, Mat< TypeR, Rows, Cols, LaytR > const &matR )
    -> Mat< decltype( matL.v1( ).x( ) + matR.v1( ).x( ) ), Rows, Cols > {
        using Ret = Mat< decltype( matL.v1( ).x( ) + matR.v1( ).x( ) ), Rows, Cols >;
        Ret ret;
        Mat< TypeL, Rows, Cols, Layout::ColMajor > const matColL{ matL };
        Mat< TypeR, Rows, Cols, Layout::ColMajor > const matColR{ matR };
        ret.v1( ) = matColL.v1( ) + matColR.v1( );
        ret.v2( ) = matColL.v2( ) + matColR.v2( );
        if constexpr ( Cols > 2 ) ret.v3( ) = matColL.v3( ) + matColR.v3( );
        if constexpr ( Cols > 3 ) ret.v4( ) = matColL.v4( ) + matColR.v4( );
        return ret;
    }
    // Mat (column matrix) generic subtraction: (any)Mat - (any)Mat = Mat
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator-( Mat< TypeL, Rows, Cols, LaytL > const &matL, Mat< TypeR, Rows, Cols, LaytR > const &matR )
    -> Mat< decltype( matL.v1( ).x( ) - matR.v1( ).x( ) ), Rows, Cols > {
        return matL + ( -matR );
    }
    // Mat (column matrix) generic equality: (any)Mat == (any)Mat = bool
    template< typename Type, unsigned Rows, unsigned Cols, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator==( Mat< Type, Rows, Cols, LaytL > const &matL, Mat< Type, Rows, Cols, LaytR > const &matR )
    -> bool {
        Mat< Type, Rows, Cols, Layout::ColMajor > const matColL{ matL };
        Mat< Type, Rows, Cols, Layout::ColMajor > const matColR{ matR };
        bool ret = matColL.v1( ) == matColR.v1( ) and matColL.v2( ) == matColR.v2( );
        if ( !ret ) return false;
        if constexpr ( Cols > 2 ) ret = matColL.v3( ) == matColR.v3( );
        if ( !ret ) return false;
        if constexpr ( Cols > 3 ) ret = matColL.v4( ) == matColR.v4( );
        return ret;
    }
    // Mat (column matrix) generic inequality: (any)Mat != (any)Mat = bool
    template< typename Type, unsigned Rows, unsigned Cols, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator!=( Mat< Type, Rows, Cols, LaytL > const &matL, Mat< Type, Rows, Cols, LaytR > const &matR )
    -> bool {
        return not ( matL == matR );
    }
    // Mat (column matrix) transpose
    template< typename Type, unsigned Rows, unsigned Cols, bool Layt >
    SON8_MATFOURD_FUNC transpose( Mat< Type, Rows, Cols, Layt > const &mat )
    -> Mat< Type, Cols, Rows, Layt > {
        using Ret = Mat< Type, Cols, Rows, not Layt >;
        Ret ret;
        ret.v1( ) = mat.v1( );
        ret.v2( ) = mat.v2( );
        if constexpr ( Cols > 2 ) ret.v3( ) = mat.v3( );
        if constexpr ( Cols > 3 ) ret.v4( ) = mat.v4( );
        return ~ret;
    };

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
