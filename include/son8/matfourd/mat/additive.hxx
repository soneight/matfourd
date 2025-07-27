#ifndef SON8_MATFOURD_MAT_ADDITIVE_HXX
#define SON8_MATFOURD_MAT_ADDITIVE_HXX

#include <son8/matfourd/mat.hxx>
#include <son8/matfourd/vec/additive.hxx>

namespace son8::matfourd {
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
    // Mat (column matrix) generic addition: (any)Mat + (any)Mat = Mat
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator+( Mat< TypeL, Rows, Cols, LaytL > const &matL, Mat< TypeR, Rows, Cols, LaytR > const &matR )
    -> Mat< decltype( matL.v1( ).x( ) + matR.v1( ).x( ) ), Rows, Cols > {
        using Ret = Mat< decltype( matL.v1( ).x( ) + matR.v1( ).x( ) ), Rows, Cols >;
        Ret ret;
        Mat< TypeL, Rows, Cols, Layout::ColMajor > const matColL{ matL };
        Mat< TypeR, Rows, Cols, Layout::ColMajor > const matColR{ matR };
        return matColL + matColR;
    }
    // Mat (column matrix) generic subtraction: (any)Mat - (any)Mat = Mat
    template< typename TypeL, typename TypeR, unsigned Rows, unsigned Cols, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator-( Mat< TypeL, Rows, Cols, LaytL > const &matL, Mat< TypeR, Rows, Cols, LaytR > const &matR )
    -> Mat< decltype( matL.v1( ).x( ) - matR.v1( ).x( ) ), Rows, Cols > {
        return matL + ( -matR );
    }

} // namespace son8::matfourd



#endif//SON8_MATFOURD_MAT_ADDITIVE_HXX
