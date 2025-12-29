#ifndef SON8_MATFOURD_MAT_MULTIPLY_HXX
#define SON8_MATFOURD_MAT_MULTIPLY_HXX

#include <son8/matfourd/order.hxx>
#include <son8/matfourd/mat/type.hxx>
#include <son8/matfourd/vec/multiply.hxx>

namespace son8::matfourd {
    // Layout aware operations (operator^)
    // Mat (column matrix) layout-aware vector outer product: Vec ^ ~Vec = Mat
    template< typename Type, unsigned Size >
    SON8_MATFOURD_FUNC operator^( Vec< Type, Size, Order::ColMajor > const &vecL, Vec< Type, Size, Order::RowMajor > const &vecR ) {
        using r = Mat< Type, Size, Size >;
        if/*___*/ constexpr ( r::vecs( ) == 2 ) {
            return r{ { vecL.x( ) * vecR.x( ), vecL.y( ) * vecR.x( ) }
                    , { vecL.x( ) * vecR.y( ), vecL.y( ) * vecR.y( ) } };
        } else if constexpr ( r::vecs( ) == 3 ) {
            return r{ { vecL.x( ) * vecR.x( ), vecL.y( ) * vecR.x( ), vecL.z( ) * vecR.x( ) }
                    , { vecL.x( ) * vecR.y( ), vecL.y( ) * vecR.y( ), vecL.z( ) * vecR.y( ) }
                    , { vecL.x( ) * vecR.z( ), vecL.y( ) * vecR.z( ), vecL.z( ) * vecR.z( ) } };
        } else if constexpr ( r::vecs( ) == 4 ) {
            return r{ { vecL.x( ) * vecR.x( ), vecL.y( ) * vecR.x( ), vecL.z( ) * vecR.x( ), vecL.w( ) * vecR.x( ) }
                    , { vecL.x( ) * vecR.y( ), vecL.y( ) * vecR.y( ), vecL.z( ) * vecR.y( ), vecL.w( ) * vecR.y( ) }
                    , { vecL.x( ) * vecR.z( ), vecL.y( ) * vecR.z( ), vecL.z( ) * vecR.z( ), vecL.w( ) * vecR.z( ) }
                    , { vecL.x( ) * vecR.w( ), vecL.y( ) * vecR.w( ), vecL.z( ) * vecR.w( ), vecL.w( ) * vecR.w( ) } };
        }
    }
    // Mat (column matrix) layout-aware: ~Vec ^ Mat = ~Vec
    template< typename Type, unsigned Cols, unsigned Rows >
    SON8_MATFOURD_FUNC operator^( Vec< Type, Rows, Order::RowMajor > const &vecRow, Mat< Type, Cols, Rows, Order::ColMajor > const &matCol ) {
        using r = Vec< Type, Cols, Order::RowMajor >;
        if/*___*/ constexpr ( r::size( ) == 2 ) {
            return r{ vecRow ^ matCol.v1( )
                    , vecRow ^ matCol.v2( ) };
        } else if constexpr ( r::size( ) == 3 ) {
            return r{ vecRow ^ matCol.v1( )
                    , vecRow ^ matCol.v2( )
                    , vecRow ^ matCol.v3( ) };
        } else if constexpr ( r::size( ) == 4 ) {
            return r{ vecRow ^ matCol.v1( )
                    , vecRow ^ matCol.v2( )
                    , vecRow ^ matCol.v3( )
                    , vecRow ^ matCol.v4( ) };
        }
    }
    // Mat (column matrix) layout-aware: ~Mat ^ Vec = Vec
    template< typename Type, unsigned Cols, unsigned Rows >
    SON8_MATFOURD_FUNC operator^( Mat< Type, Cols, Rows, Order::RowMajor > const &matRow, Vec< Type, Cols, Order::ColMajor > const &vecCol ) {
        using r = Vec< Type, Rows >;
        if/*___*/ constexpr ( r::size( ) == 2 ) {
            return r{ matRow.v1( ) ^ vecCol
                    , matRow.v2( ) ^ vecCol };
        } else if constexpr ( r::size( ) == 3 ) {
            return r{ matRow.v1( ) ^ vecCol
                    , matRow.v2( ) ^ vecCol
                    , matRow.v3( ) ^ vecCol };
        } else if constexpr ( r::size( ) == 4 ) {
            return r{ matRow.v1( ) ^ vecCol
                    , matRow.v2( ) ^ vecCol
                    , matRow.v3( ) ^ vecCol
                    , matRow.v4( ) ^ vecCol };
        }
    }
    // Mat (column matrix) layout-aware: ~Mat ^ Mat = Mat
    template< typename Type, unsigned ColsLRowsR, unsigned RowsL, unsigned ColsR >
    SON8_MATFOURD_FUNC operator^( Mat< Type, ColsLRowsR, RowsL, Order::RowMajor > const &matRow, Mat< Type, ColsR, ColsLRowsR, Order::ColMajor > const &matCol ) {
        using r = Mat< Type, ColsR, RowsL >;
        if/*___*/ constexpr ( r::vecs( ) == 2 ) {
            return r{ matRow ^ matCol.v1( )
                    , matRow ^ matCol.v2( ) };
        } else if constexpr ( r::vecs( ) == 3 ) {
            return r{ matRow ^ matCol.v1( )
                    , matRow ^ matCol.v2( )
                    , matRow ^ matCol.v3( ) };
        } else if constexpr ( r::vecs( ) == 4 ) {
            return r{ matRow ^ matCol.v1( )
                    , matRow ^ matCol.v2( )
                    , matRow ^ matCol.v3( )
                    , matRow ^ matCol.v4( ) };
        }
    }
    // Generic operations (operator*)
    // Mat (column matrix) generic: (any)Mat * scalar = Mat
    template< typename Type, unsigned Cols, unsigned Rows, bool RowMajor >
    SON8_MATFOURD_FUNC operator*( Mat< Type, Cols, Rows, RowMajor > const &mat, Type const &scalar )  {
        using r = Mat< Type, Cols, Rows, RowMajor >;
        if/*___*/ constexpr ( r::vecs( ) == 2 ) {
            return r{ mat.v1( ) * scalar
                    , mat.v2( ) * scalar };
        } else if constexpr ( r::vecs( ) == 3 ) {
            return r{ mat.v1( ) * scalar
                    , mat.v2( ) * scalar
                    , mat.v3( ) * scalar };
        } else if constexpr ( r::vecs( ) == 4 ) {
            return r{ mat.v1( ) * scalar
                    , mat.v2( ) * scalar
                    , mat.v3( ) * scalar
                    , mat.v4( ) * scalar };
        }
    }
    // Mat (column matrix) generic: scalar * (any)Mat = Mat
    template< typename Type, unsigned Cols, unsigned Rows, bool RowMajor >
    SON8_MATFOURD_FUNC operator*( Type const &scalar, Mat< Type, Cols, Rows, RowMajor > const &mat )
    -> Mat< Type, Cols, Rows, RowMajor > {
        return mat * scalar;
    }
    // Mat (column matrix) generic: (any)Vec * (any)Mat = ~Vec
    template< typename Type, unsigned Cols, unsigned Rows, bool RowMajorL, bool RowMajorR >
    SON8_MATFOURD_FUNC operator*( Vec< Type, Rows, RowMajorL > const &vecL, Mat< Type, Cols, Rows, RowMajorR > const &matR ) {
        using r = Vec< Type, Cols, Order::RowMajor >;
        Vec< Type, Rows, Order::RowMajor > const vecRow{ vecL };
        Mat< Type, Cols, Rows, Order::ColMajor > const matCol{ matR };
        return r{ vecRow ^ matCol };
    }
    // Mat (column matrix) generic: (any)Mat * (any)Vec = Vec
    template< typename Type, unsigned Cols, unsigned Rows, bool RowMajorL, bool RowMajorR >
    SON8_MATFOURD_FUNC operator*( Mat< Type, Cols, Rows, RowMajorL > const &matL, Vec< Type, Cols, RowMajorR > const &vecR ) {
        using r = Vec< Type, Rows >;
        Mat< Type, Cols, Rows, Order::RowMajor > const matRow{ matL };
        Vec< Type, Cols, Order::ColMajor > const vecCol{ vecR };
        return r{ matRow ^ vecCol };
    }
    // Mat (column matrix) generic: (any)Mat * (any)Mat = Mat
    template< typename Type, unsigned ColsLRowsR, unsigned RowsL, unsigned ColsR, bool RowMajorL, bool RowMajorR >
    SON8_MATFOURD_FUNC operator*( Mat< Type, ColsLRowsR, RowsL, RowMajorL > const &matL, Mat< Type, ColsR, ColsLRowsR, RowMajorR > const &matR ) {
        using r = Mat< Type, ColsR, RowsL >;
        Mat< Type, ColsLRowsR, RowsL, Order::RowMajor > const matRow{ matL };
        Mat< Type, ColsR, ColsLRowsR, Order::ColMajor > const matCol{ matR };
        return r{ matRow ^ matCol };
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_MULTIPLY_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
