#ifndef SON8_MATFOURD_MAT_ADDITIVE_HXX
#define SON8_MATFOURD_MAT_ADDITIVE_HXX

#include <son8/matfourd/mat/type.hxx>
#include <son8/matfourd/vec/additive.hxx>

namespace son8::matfourd {
    // Mat (column matrix) layout-aware addition: (same)Mat + (same)Mat = Mat
    template< typename Type, unsigned Cols, unsigned Rows, bool Layt >
    SON8_MATFOURD_FUNC operator+( Mat< Type, Cols, Rows, Layt > const &matL, Mat< Type, Cols, Rows, Layt > const &matR ) {
        using Ret = Mat< Type, Cols, Rows, Layt >;
        Ret ret;
        ret.v1( ) = matL.v1( ) + matR.v1( );
        ret.v2( ) = matL.v2( ) + matR.v2( );
        if constexpr ( Ret::vecs( ) > 2 ) ret.v3( ) = matL.v3( ) + matR.v3( );
        if constexpr ( Ret::vecs( ) > 3 ) ret.v4( ) = matL.v4( ) + matR.v4( );
        return ret;
    }
    // Mat (column matrix) generic addition: (any)Mat + (any)Mat = Mat
    template< typename Type, unsigned Cols, unsigned Rows, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator+( Mat< Type, Cols, Rows, LaytL > const &matL, Mat< Type, Cols, Rows, LaytR > const &matR ) {
        using Ret = Mat< Type, Cols, Rows >;
        Ret ret;
        Mat< Type, Cols, Rows, Layout::ColMajor > const matColL{ matL };
        Mat< Type, Cols, Rows, Layout::ColMajor > const matColR{ matR };
        return matColL + matColR;
    }
    // Mat (column matrix) generic subtraction: (any)Mat - (any)Mat = Mat
    template< typename Type, unsigned Cols, unsigned Rows, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator-( Mat< Type, Cols, Rows, LaytL > const &matL, Mat< Type, Cols, Rows, LaytR > const &matR )
    -> Mat< Type, Cols, Rows > {
        return matL + ( -matR );
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_ADDITIVE_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
