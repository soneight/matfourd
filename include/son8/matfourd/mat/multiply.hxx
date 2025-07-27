#ifndef SON8_MATFOURD_MAT_MULTIPLY_HXX
#define SON8_MATFOURD_MAT_MULTIPLY_HXX

#include <son8/matfourd/mat.hxx>
#include <son8/matfourd/vec/multiply.hxx>

namespace son8::matfourd {
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

} // namespace son8::matfourd



#endif//SON8_MATFOURD_MAT_MULTIPLY_HXX
