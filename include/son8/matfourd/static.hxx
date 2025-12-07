#ifndef SON8_MATFOURD_STATIC_HXX
#define SON8_MATFOURD_STATIC_HXX

#include <son8/matfourd/vec/additive.hxx>
#include <son8/matfourd/vec/equality.hxx>
#include <son8/matfourd/vec/multiply.hxx>

namespace son8::matfourd {
    // helper to force compiler error if for some reason static assertion was incorrect
    template< typename Type >
    struct Un {
        static void reachable( ) { Type::son8_matfourd_force_compiler_error( ); }
    };
    // vec additive
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    void operator+( Vec< TypeL, SizeL, LaytL > const &vecL, Vec< TypeR, SizeR, LaytR > const &vecR ) {
        static_assert( SizeL == SizeR, "son8::matfourd: operator+ cannot add two Vec with different sizes" );
        Un< TypeL >::reachable( );
    }
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    void operator-( Vec< TypeL, SizeL, LaytL > const &vecL, Vec< TypeR, SizeR, LaytR > const &vecR ) {
        static_assert( SizeL == SizeR, "son8::matfourd: operator- cannot subtract two Vec with different sizes" );
        Un< TypeL >::reachable( );
    }
    // vec equality
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    void operator==( Vec< TypeL, SizeL, LaytL > const &vecL, Vec< TypeR, SizeR, LaytR > const &vecR ) {
        static_assert( SizeL == SizeR, "son8::matfourd: operator== cannot compare two Vec with different sizes" );
        Un< TypeL >::reachable( );
    }
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    void operator!=( Vec< TypeL, SizeL, LaytL > const &vecL, Vec< TypeR, SizeR, LaytR > const &vecR ) {
        static_assert( SizeL == SizeR, "son8::matfourd: operator== cannot compare two Vec with different sizes" );
        Un< TypeL >::reachable( );
    }
    // vec multiply (layout-aware)
    template< typename TypeL, typename TypeR, unsigned SizeL, unsigned SizeR, bool LaytL, bool LaytR >
    void operator^( Vec< TypeL, SizeL, LaytL > const &vecL, Vec< TypeR, SizeR, LaytR > const &vecR ) {
        static_assert( SizeL == SizeR        , "son8::matfourd: operator^ layout-aware multiply of two Vec with different sizes" );
        static_assert( not ( LaytL && LaytR ), "son8::matfourd: operator^ layout-aware multiply does not work when both Vec are row-major, unknown operation" );
        static_assert( SizeL == 3            , "son8::matfourd: operator^ layout-aware cross product requires both Vec to be col-major of size 3" );
        Un< TypeL >::reachable( );
    }
    // TODO mat
} // namespace son8::matfourd

#endif//SON8_MATFOURD_STATIC_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
