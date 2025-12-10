#ifndef SON8_MATFOURD_STATIC_HXX
#define SON8_MATFOURD_STATIC_HXX
// son8
#include <son8/matfourd/vec/swizzles.hxx>
#include <son8/matfourd/vec/additive.hxx>
#include <son8/matfourd/vec/equality.hxx>
#include <son8/matfourd/vec/multiply.hxx>
#include <son8/matfourd/vec/additive.hxx>
#include <son8/matfourd/mat/equality.hxx>
#include <son8/matfourd/mat/multiply.hxx>
// std
#include <type_traits>

namespace son8::matfourd {
    // helper to force compiler error if for some reason static assertion was incorrect
    template< typename Type >
    struct Un {
        static void reachable( ) { Type::son8_matfourd_force_compiler_error( ); }
    };
    // vec swizzles
    template< typename Type, bool Layt, unsigned SizeL, unsigned SizeR, unsigned ReqS, SON8_MATFOURD_SWIZZLES_COORDS >
    void operator/( Vec< Type, SizeL, Layt >, swizzles::Impl_< SizeR, ReqS, Crd1, Crd2, Crd3, Crd4 > ) {
        static_assert( SizeL >= ReqS
            , "son8::matfourd: operator/ swizzles requires correct coords" );
        Un< Type >::reachable( );
    }
    // vec equality
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    void operator==( Vec< TypeL, SizeL, LaytL >, Vec< TypeR, SizeR, LaytR > ) {
        static_assert( SizeL == SizeR
            , "son8::matfourd: operator== requires two Vec with same size" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator== requires two Vec with same value type" );
        Un< TypeL >::reachable( );
    }
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    void operator!=( Vec< TypeL, SizeL, LaytL >, Vec< TypeR, SizeR, LaytR > ) {
        static_assert( SizeL == SizeR
            , "son8::matfourd: operator!= requires two Vec with same size" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator!= requires two Vec with same value type" );
        Un< TypeL >::reachable( );
    }
    // vec additive plus
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    void operator+( Vec< TypeL, SizeL, LaytL >, Vec< TypeR, SizeR, LaytR > ) {
        static_assert( SizeL == SizeR
            , "son8::matfourd: operator+ requires two Vec with same size" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator+ requires two Vec with same value type" );
        Un< TypeL >::reachable( );
    }
    // vec additive minus
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    void operator-( Vec< TypeL, SizeL, LaytL >, Vec< TypeR, SizeR, LaytR > ) {
        static_assert( SizeL == SizeR
            , "son8::matfourd: operator- requires two Vec with same size" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator- requires two Vec with same value type" );
        Un< TypeL >::reachable( );
    }
    // vec multiply scalar left
    template< typename TypeL, typename TypeR, unsigned Size, bool Layt >
    void operator*( TypeL, Vec< TypeR, Size, Layt > ) {
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator* requires scalar and Vec with same value type" );
        Un< TypeL >::reachable( );
    }
    // vec multiply scalar right
    template< typename TypeL, typename TypeR, unsigned Size, bool Layt >
    void operator*( Vec< TypeL, Size, Layt >, TypeR  ) {
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator* requires Vec and scalar with same value type" );
        Un< TypeL >::reachable( );
    }
    // vec multiply (layout-aware)
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    void operator^( Vec< TypeL, SizeL, LaytL >, Vec< TypeR, SizeR, LaytR > ) {
        static_assert( SizeL == SizeR
            , "son8::matfourd: operator^ layout-aware multiply requires two Vec with same size" );
        static_assert( not ( LaytL && LaytR )
            , "son8::matfourd: operator^ layout-aware multiply does not work when both Vec are row-major, unknown operation" );
        static_assert( SizeL == 3
            , "son8::matfourd: operator^ layout-aware cross product requires both Vec to be col-major of size 3" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator^ layout-aware multiply requires two Vec with same value type" );
        Un< TypeL >::reachable( );
    }
    // vec multiply
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    void operator*( Vec< TypeL, SizeL, LaytL >, Vec< TypeR, SizeR, LaytR > ) {
        static_assert( SizeL == SizeR
            , "son8::matfourd: operator* dot product requires two Vec with same size" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator* dot product requires two Vec with same value type" );
        Un< TypeL >::reachable( );
    }
    // mat equality
    template< typename TypeL, typename TypeR, unsigned ColsL, unsigned RowsL, unsigned ColsR, unsigned RowsR, bool LaytL, bool LaytR >
    void operator==( Mat< TypeL, ColsL, RowsL, LaytL >, Mat< TypeR, ColsR, RowsR, LaytR > ) {
        static_assert( ColsL == ColsR && RowsL == RowsR
            , "son8::matfourd: operator== requires two Mat with same dimension" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator== requires two Vec with same value type" );
        Un< TypeL >::reachable( );
    }
    // mat inequality
    template< typename TypeL, typename TypeR, unsigned ColsL, unsigned RowsL, unsigned ColsR, unsigned RowsR, bool LaytL, bool LaytR >
    void operator!=( Mat< TypeL, ColsL, RowsL, LaytL >, Mat< TypeR, ColsR, RowsR, LaytR > ) {
        static_assert( ColsL == ColsR && RowsL == RowsR
            , "son8::matfourd: operator!= requires two Mat with same dimension" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator!= requires two Vec with same value type" );
        Un< TypeL >::reachable( );
    }
    // mat additive plus
    template< typename TypeL, typename TypeR, unsigned ColsL, unsigned RowsL, unsigned ColsR, unsigned RowsR, bool LaytL, bool LaytR >
    void operator+( Mat< TypeL, ColsL, RowsL, LaytL >, Mat< TypeR, ColsR, RowsR, LaytR > ) {
        static_assert( ColsL == ColsR && RowsL == RowsR
            , "son8::matfourd: operator+ requires two Mat with same dimension" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator+ requires two Mat with same value type" );
        Un< TypeL >::reachable( );
    }
    // mat additive minus
    template< typename TypeL, typename TypeR, unsigned ColsL, unsigned RowsL, unsigned ColsR, unsigned RowsR, bool LaytL, bool LaytR >
    void operator-( Mat< TypeL, ColsL, RowsL, LaytL >, Mat< TypeR, ColsR, RowsR, LaytR > ) {
        static_assert( ColsL == ColsR && RowsL == RowsR
            , "son8::matfourd: operator- requires two Mat with same dimension" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator- requires two Mat with same value type" );
        Un< TypeL >::reachable( );
    }
    // mat multiply scalar left
    template< typename TypeL, typename Type, unsigned Cols, unsigned Rows, bool Layt >
    void operator*( TypeL, Mat< Type, Cols, Rows, Layt > ) {
        static_assert( std::is_same_v< TypeL, Type >
            , "son8::matfourd: operator* requires scalar and Mat with same value type" );
        Un< Type >::reachable( );
    }
    // mat multiply scalar right
    template< typename TypeR, typename Type, unsigned Cols, unsigned Rows, bool Layt >
    void operator*( Mat< Type, Cols, Rows, Layt >, TypeR ) {
        static_assert( std::is_same_v< Type, TypeR >
            , "son8::matfourd: operator* requires Mat and scalar with same value type" );
        Un< Type >::reachable( );
    }
    // mat multiply vec left (layout-aware)
    template< typename TypeL, typename TypeR, unsigned Size, unsigned Cols, unsigned Rows, bool LaytL, bool LaytR >
    void operator^( Vec< TypeL, Size, LaytL >, Mat< TypeR, Cols, Rows, LaytR > ) {
        static_assert( LaytL == Layout::RowMajor && LaytR == Layout::ColMajor
            , "son8::matfourd: operator^ layout-aware multiply requires row-major Vec and col-major Mat" );
        static_assert( Size == Rows
            , "son8::matfourd: operator^ layout-aware multiply requires Vec size and Mat rows to be equal" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator^ layout-aware multiply requires Vec and Mat with same value type" );
        Un< TypeL >::reachable( );
    }
    // mat multiply vec right (layout-aware)
    template< typename TypeL, typename TypeR, unsigned Size, unsigned Cols, unsigned Rows, bool LaytL, bool LaytR >
    void operator^( Mat< TypeL, Cols, Rows, LaytL >, Vec< TypeR, Size, LaytR > ) {
        static_assert( LaytL == Layout::RowMajor && LaytR == Layout::ColMajor
            , "son8::matfourd: operator^ layout-aware multiply requires row-major Mat and col-major Vec" );
        static_assert( Cols == Size
            , "son8::matfourd: operator^ layout-aware multiply requires Mat cols and Vec size to be equal" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator^ layout-aware multiply requires Mat and Vec with same value type" );
        Un< TypeL >::reachable( );
    }
    // mat multiply vec left
    template< typename TypeL, typename TypeR, unsigned Size, unsigned Cols, unsigned Rows, bool LaytL, bool LaytR >
    void operator*( Vec< TypeL, Size, LaytL >, Mat< TypeR, Cols, Rows, LaytR > ) {
        static_assert( Size == Rows
            , "son8::matfourd: operator* requires Vec size and Mat rows to be equal" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator* requires Vec and Mat with same value type" );
        Un< TypeL >::reachable( );
    }
    // mat multiply vec right
    template< typename TypeL, typename TypeR, unsigned Size, unsigned Cols, unsigned Rows, bool LaytL, bool LaytR >
    void operator*( Mat< TypeL, Cols, Rows, LaytL >, Vec< TypeR, Size, LaytR > ) {
        static_assert( Cols == Size
            , "son8::matfourd: operator* requires Mat cols and Vec size to be equal" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator* requires Mat and Vec with same value type" );
        Un< TypeL >::reachable( );
    }
    // mat multiply (layout-aware)
    template< typename TypeL, typename TypeR, unsigned ColsL, unsigned RowsL, unsigned ColsR, unsigned RowsR, bool LaytL, bool LaytR >
    void operator^( Mat< TypeL, ColsL, RowsL, LaytL >, Mat< TypeR, ColsR, RowsR, LaytR > ) {
        static_assert( LaytL == Layout::RowMajor && LaytR == Layout::ColMajor
            , "son8::matfourd: operator^ layout-aware two Mat multiply requires row-major left Mat and col-major right Mat" );
        static_assert( ColsL == RowsR
            , "son8::matfourd: operator^ layout-aware two Mat multiply requires match columns of left matrix to rows of right matrix" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator^ requires two Mat with same value type" );
        Un< TypeL >::reachable( );
    }
    // mat multiply
    template< typename TypeL, typename TypeR, unsigned ColsL, unsigned RowsL, unsigned ColsR, unsigned RowsR, bool LaytL, bool LaytR >
    void operator*( Mat< TypeL, ColsL, RowsL, LaytL >, Mat< TypeR, ColsR, RowsR, LaytR > ) {
        static_assert( ColsL == RowsR
            , "son8::matfourd: operator* two Mat multiply requires match columns of left matrix to rows of right matrix" );
        static_assert( std::is_same_v< TypeL, TypeR >
            , "son8::matfourd: operator* requires two Mat with same value type" );
        Un< TypeL >::reachable( );
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_STATIC_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
