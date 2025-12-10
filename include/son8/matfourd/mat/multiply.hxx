#ifndef SON8_MATFOURD_MAT_MULTIPLY_HXX
#define SON8_MATFOURD_MAT_MULTIPLY_HXX

#include <son8/matfourd/layout.hxx>
#include <son8/matfourd/mat/type.hxx>
#include <son8/matfourd/vec/multiply.hxx>

namespace son8::matfourd {
    // Layout aware operations (operator^)
    // Mat (column matrix) layout-aware vector outer product: Vec ^ ~Vec = Mat
    template< typename Type, unsigned Size >
    SON8_MATFOURD_FUNC operator^( Vec< Type, Size, Layout::ColMajor > const &vecL, Vec< Type, Size, Layout::RowMajor > const &vecR ) {
        using Ret = Mat< Type, Size, Size >;
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
    template< typename Type, unsigned Cols, unsigned Rows >
    SON8_MATFOURD_FUNC operator^( Vec< Type, Rows, Layout::RowMajor > const &vecRow, Mat< Type, Cols, Rows, Layout::ColMajor > const &matCol ) {
        using Ret = Vec< Type, Cols, Layout::RowMajor >;
        Ret ret;
        ret.x( ) = vecRow ^ matCol.v1( );
        ret.y( ) = vecRow ^ matCol.v2( );
        if constexpr ( Ret::size( ) > 2 ) ret.z( ) = vecRow ^ matCol.v3( );
        if constexpr ( Ret::size( ) > 3 ) ret.w( ) = vecRow ^ matCol.v4( );
        return ret;
    }
    // Mat (column matrix) layout-aware: ~Mat ^ Vec = Vec
    template< typename Type, unsigned Cols, unsigned Rows >
    SON8_MATFOURD_FUNC operator^( Mat< Type, Cols, Rows, Layout::RowMajor > const &matRow, Vec< Type, Cols, Layout::ColMajor > const &vecCol ) {
        using Ret = Vec< Type, Rows >;
        Ret ret;
        ret.x( ) = matRow.v1( ) ^ vecCol;
        ret.y( ) = matRow.v2( ) ^ vecCol;
        if constexpr ( Ret::size( ) > 2 ) ret.z( ) = matRow.v3( ) ^ vecCol;
        if constexpr ( Ret::size( ) > 3 ) ret.w( ) = matRow.v4( ) ^ vecCol;
        return ret;
    }
    // Mat (column matrix) layout-aware: ~Mat ^ Mat = Mat
    template< typename Type, unsigned ColsLRowsR, unsigned RowsL, unsigned ColsR >
    SON8_MATFOURD_FUNC operator^( Mat< Type, ColsLRowsR, RowsL, Layout::RowMajor > const &matRow, Mat< Type, ColsR, ColsLRowsR, Layout::ColMajor > const &matCol ) {
        using Ret = Mat< Type, ColsR, RowsL >;
        Ret ret;
        ret.v1( ) = matRow ^ matCol.v1( );
        ret.v2( ) = matRow ^ matCol.v2( );
        if constexpr ( Ret::vecs( ) > 2 ) ret.v3( ) = matRow ^ matCol.v3( );
        if constexpr ( Ret::vecs( ) > 3 ) ret.v4( ) = matRow ^ matCol.v4( );
        return ret;
    }
    // Generic operations (operator*)
    // Mat (column matrix) generic: scalar * (any)Mat = Mat
    template< typename Type, unsigned Cols, unsigned Rows, bool Layt >
    SON8_MATFOURD_FUNC operator*( Type scalar, Mat< Type, Cols, Rows, Layt > const &mat ) {
        using Ret = Mat< Type, Cols, Rows, Layt >;
        Ret ret;
        ret.v1( ) = scalar * mat.v1( );
        ret.v2( ) = scalar * mat.v2( );
        if constexpr ( Ret::vecs( ) > 2 ) ret.v3( ) = scalar * mat.v3( );
        if constexpr ( Ret::vecs( ) > 3 ) ret.v4( ) = scalar * mat.v4( );
        return ret;
    }
    // Mat (column matrix) generic: (any)Mat * scalar = Mat
    template< typename Type, unsigned Cols, unsigned Rows, bool Layt >
    SON8_MATFOURD_FUNC operator*( Mat< Type, Cols, Rows, Layt > const &mat, Type scalar )
    -> Mat< Type, Cols, Rows, Layt > {
        return scalar * mat;
    }
    // Mat (column matrix) generic: (any)Vec * (any)Mat = ~Vec
    template< typename Type, unsigned Cols, unsigned Rows, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator*( Vec< Type, Rows, LaytL > const &vecL, Mat< Type, Cols, Rows, LaytR > const &matR ) {
        using Ret = Vec< Type, Cols, Layout::RowMajor >;
        Ret ret;
        Vec< Type, Rows, Layout::RowMajor > const vecRow{ vecL };
        Mat< Type, Cols, Rows, Layout::ColMajor > const matCol{ matR };
        ret.x( ) = vecRow ^ matCol.v1( );
        ret.y( ) = vecRow ^ matCol.v2( );
        if constexpr ( Ret::size( ) > 2 ) ret.z( ) = vecRow ^ matCol.v3( );
        if constexpr ( Ret::size( ) > 3 ) ret.w( ) = vecRow ^ matCol.v4( );
        return ret;
    }
    // Mat (column matrix) generic: (any)Mat * (any)Vec = Vec
    template< typename Type, unsigned Cols, unsigned Rows, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator*( Mat< Type, Cols, Rows, LaytL > const &matL, Vec< Type, Cols, LaytR > const &vecR ) {
        using Ret = Vec< Type, Rows >;
        Ret ret;
        Mat< Type, Cols, Rows, Layout::RowMajor > const matRow{ matL };
        Vec< Type, Cols, Layout::ColMajor > const vecCol{ vecR };
        ret.x( ) = matRow.v1( ) ^ vecCol;
        ret.y( ) = matRow.v2( ) ^ vecCol;
        if constexpr ( Ret::size( ) > 2 ) ret.z( ) = matRow.v3( ) ^ vecCol;
        if constexpr ( Ret::size( ) > 3 ) ret.w( ) = matRow.v4( ) ^ vecCol;
        return ret;
    }
    // Mat (column matrix) generic: (any)Mat * (any)Mat = Mat
    template< typename Type, unsigned ColsLRowsR, unsigned RowsL, unsigned ColsR, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator*( Mat< Type, ColsLRowsR, RowsL, LaytL > const &matL, Mat< Type, ColsR, ColsLRowsR, LaytR > const &matR ) {
        using Ret = Mat< Type, ColsR, RowsL >;
        Ret ret;
        Mat< Type, ColsLRowsR, RowsL, Layout::RowMajor > const matRow{ matL };
        Mat< Type, ColsR, ColsLRowsR, Layout::ColMajor > const matCol{ matR };
        ret.v1( ) = matRow ^ matCol.v1( );
        ret.v2( ) = matRow ^ matCol.v2( );
        if constexpr ( Ret::vecs( ) > 2 ) ret.v3( ) = matRow ^ matCol.v3( );
        if constexpr ( Ret::vecs( ) > 3 ) ret.v4( ) = matRow ^ matCol.v4( );
        return ret;
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_MULTIPLY_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
