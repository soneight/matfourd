#ifndef SON8_MATFOURD_MAT_EQUALITY_HXX
#define SON8_MATFOURD_MAT_EQUALITY_HXX

#include <son8/matfourd/mat.hxx>
#include <son8/matfourd/vec/equality.hxx>

namespace son8::matfourd {
    // Mat (column matrix) layout-aware equality: (any)Mat == (any)Mat = bool
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
    // Mat (column matrix) generic equality: (any)Mat == (any)Mat = bool
    template< typename Type, unsigned Rows, unsigned Cols, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator==( Mat< Type, Rows, Cols, LaytL > const &matL, Mat< Type, Rows, Cols, LaytR > const &matR )
    -> bool {
        Mat< Type, Rows, Cols, Layout::ColMajor > const matColL{ matL };
        Mat< Type, Rows, Cols, Layout::ColMajor > const matColR{ matR };
        return matColL == matColR;
    }
    // Mat (column matrix) generic inequality: (any)Mat != (any)Mat = bool
    template< typename Type, unsigned Rows, unsigned Cols, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator!=( Mat< Type, Rows, Cols, LaytL > const &matL, Mat< Type, Rows, Cols, LaytR > const &matR )
    -> bool {
        return not ( matL == matR );
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_EQUALITY_HXX
