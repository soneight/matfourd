#ifndef SON8_MATFOURD_VEC_SWIZZLES_HXX
#define SON8_MATFOURD_VEC_SWIZZLES_HXX

#include <son8/matfourd/core.hxx>
#include <son8/matfourd/vec/type.hxx>

#define SON8_MATFOURD_SWIZZLES_COORDS swizzles::Coord Crd1, swizzles::Coord Crd2, swizzles::Coord Crd3, swizzles::Coord Crd4

namespace son8::matfourd {
    // opengl-like Vec swizzles
    namespace swizzles {
        // enum helper
        enum class Coord : unsigned { o, x, y, z, w };
        // implementation
        template< unsigned Size, unsigned ReqS, Coord Crd1, Coord Crd2, Coord Crd3 = Coord::o, Coord Crd4 = Coord::o >
        class Impl_ {
            static_assert( 2 <= Size && Size <= 4
                , "son8::matfourd: swizzle implementaion requires size to be in range [2,4]" );
            static_assert( Crd1 != Coord::o && Crd2 != Coord::o
                , "son8::matfourd: swizzle implementaion requires first two coords to be non-zero" );
            template< Coord Crd, typename Type >
            SON8_MATFOURD_FUNC
            static constexpr coord( Type const &vec ) {
                static_assert( Crd != Coord::o, "son8::matfourd: swizzle with incorrect o Coord" );
                if constexpr ( Crd == Coord::x ) return vec.x( );
                if constexpr ( Crd == Coord::y ) return vec.y( );
                if constexpr ( Crd == Coord::z ) return vec.z( );
                if constexpr ( Crd == Coord::w ) return vec.w( );
            }
        public:
            template< typename Type >
            SON8_MATFOURD_FUNC
            static constexpr c1( Type const &vec ) { return coord< Crd1 >( vec ); }
            template< typename Type >
            SON8_MATFOURD_FUNC
            static constexpr c2( Type const &vec ) { return coord< Crd2 >( vec ); }
            template< typename Type >
            SON8_MATFOURD_FUNC
            static constexpr c3( Type const &vec ) { return coord< Crd3 >( vec ); }
            template< typename Type >
            SON8_MATFOURD_FUNC
            static constexpr c4( Type const &vec ) { return coord< Crd4 >( vec ); }
        }; // class Impl_
        // aliases
        using xx_ = Impl_< 2, 2, Coord::x, Coord::x >;
        using xy_ = Impl_< 2, 2, Coord::x, Coord::y >;
        using xz_ = Impl_< 2, 3, Coord::x, Coord::z >;
        using xw_ = Impl_< 2, 4, Coord::x, Coord::w >;
        using yx_ = Impl_< 2, 2, Coord::y, Coord::x >;
        using yy_ = Impl_< 2, 2, Coord::y, Coord::y >;
        using yz_ = Impl_< 2, 3, Coord::y, Coord::z >;
        using yw_ = Impl_< 2, 4, Coord::y, Coord::w >;
        using zx_ = Impl_< 2, 3, Coord::z, Coord::x >;
        using zy_ = Impl_< 2, 3, Coord::z, Coord::y >;
        using zz_ = Impl_< 2, 3, Coord::z, Coord::z >;
        using zw_ = Impl_< 2, 4, Coord::z, Coord::w >;
        using wx_ = Impl_< 2, 4, Coord::w, Coord::x >;
        using wy_ = Impl_< 2, 4, Coord::w, Coord::y >;
        using wz_ = Impl_< 2, 4, Coord::w, Coord::z >;
        using ww_ = Impl_< 2, 4, Coord::w, Coord::w >;

        using xxx_ = Impl_< 3, 2, Coord::x, Coord::x, Coord::x >;
        using xxy_ = Impl_< 3, 2, Coord::x, Coord::x, Coord::y >;
        using xxz_ = Impl_< 3, 3, Coord::x, Coord::x, Coord::z >;
        using xxw_ = Impl_< 3, 4, Coord::x, Coord::x, Coord::w >;
        using xyx_ = Impl_< 3, 2, Coord::x, Coord::y, Coord::x >;
        using xyy_ = Impl_< 3, 2, Coord::x, Coord::y, Coord::y >;
        using xyz_ = Impl_< 3, 3, Coord::x, Coord::y, Coord::z >;
        using xyw_ = Impl_< 3, 4, Coord::x, Coord::y, Coord::w >;
        using xzx_ = Impl_< 3, 3, Coord::x, Coord::z, Coord::x >;
        using xzy_ = Impl_< 3, 3, Coord::x, Coord::z, Coord::y >;
        using xzz_ = Impl_< 3, 3, Coord::x, Coord::z, Coord::z >;
        using xzw_ = Impl_< 3, 4, Coord::x, Coord::z, Coord::w >;
        using xwx_ = Impl_< 3, 4, Coord::x, Coord::w, Coord::x >;
        using xwy_ = Impl_< 3, 4, Coord::x, Coord::w, Coord::y >;
        using xwz_ = Impl_< 3, 4, Coord::x, Coord::w, Coord::z >;
        using xww_ = Impl_< 3, 4, Coord::x, Coord::w, Coord::w >;
        using yxx_ = Impl_< 3, 2, Coord::y, Coord::x, Coord::x >;
        using yxy_ = Impl_< 3, 2, Coord::y, Coord::x, Coord::y >;
        using yxz_ = Impl_< 3, 3, Coord::y, Coord::x, Coord::z >;
        using yxw_ = Impl_< 3, 4, Coord::y, Coord::x, Coord::w >;
        using yyx_ = Impl_< 3, 2, Coord::y, Coord::y, Coord::x >;
        using yyy_ = Impl_< 3, 2, Coord::y, Coord::y, Coord::y >;
        using yyz_ = Impl_< 3, 3, Coord::y, Coord::y, Coord::z >;
        using yyw_ = Impl_< 3, 4, Coord::y, Coord::y, Coord::w >;
        using yzx_ = Impl_< 3, 3, Coord::y, Coord::z, Coord::x >;
        using yzy_ = Impl_< 3, 3, Coord::y, Coord::z, Coord::y >;
        using yzz_ = Impl_< 3, 3, Coord::y, Coord::z, Coord::z >;
        using yzw_ = Impl_< 3, 4, Coord::y, Coord::z, Coord::w >;
        using ywx_ = Impl_< 3, 4, Coord::y, Coord::w, Coord::x >;
        using ywy_ = Impl_< 3, 4, Coord::y, Coord::w, Coord::y >;
        using ywz_ = Impl_< 3, 4, Coord::y, Coord::w, Coord::z >;
        using yww_ = Impl_< 3, 4, Coord::y, Coord::w, Coord::w >;
        using zxx_ = Impl_< 3, 3, Coord::z, Coord::x, Coord::x >;
        using zxy_ = Impl_< 3, 3, Coord::z, Coord::x, Coord::y >;
        using zxz_ = Impl_< 3, 3, Coord::z, Coord::x, Coord::z >;
        using zxw_ = Impl_< 3, 4, Coord::z, Coord::x, Coord::w >;
        using zyx_ = Impl_< 3, 3, Coord::z, Coord::y, Coord::x >;
        using zyy_ = Impl_< 3, 3, Coord::z, Coord::y, Coord::y >;
        using zyz_ = Impl_< 3, 3, Coord::z, Coord::y, Coord::z >;
        using zyw_ = Impl_< 3, 4, Coord::z, Coord::y, Coord::w >;
        using zzx_ = Impl_< 3, 3, Coord::z, Coord::z, Coord::x >;
        using zzy_ = Impl_< 3, 3, Coord::z, Coord::z, Coord::y >;
        using zzz_ = Impl_< 3, 3, Coord::z, Coord::z, Coord::z >;
        using zzw_ = Impl_< 3, 4, Coord::z, Coord::z, Coord::w >;
        using zwx_ = Impl_< 3, 4, Coord::z, Coord::w, Coord::x >;
        using zwy_ = Impl_< 3, 4, Coord::z, Coord::w, Coord::y >;
        using zwz_ = Impl_< 3, 4, Coord::z, Coord::w, Coord::z >;
        using zww_ = Impl_< 3, 4, Coord::z, Coord::w, Coord::w >;
        using wxx_ = Impl_< 3, 3, Coord::z, Coord::x, Coord::x >;
        using wxy_ = Impl_< 3, 3, Coord::z, Coord::x, Coord::y >;
        using wxz_ = Impl_< 3, 3, Coord::z, Coord::x, Coord::z >;
        using wxw_ = Impl_< 3, 4, Coord::z, Coord::x, Coord::w >;
        using wyx_ = Impl_< 3, 3, Coord::z, Coord::y, Coord::x >;
        using wyy_ = Impl_< 3, 3, Coord::z, Coord::y, Coord::y >;
        using wyz_ = Impl_< 3, 3, Coord::z, Coord::y, Coord::z >;
        using wyw_ = Impl_< 3, 4, Coord::z, Coord::y, Coord::w >;
        using wzx_ = Impl_< 3, 3, Coord::z, Coord::z, Coord::x >;
        using wzy_ = Impl_< 3, 3, Coord::z, Coord::z, Coord::y >;
        using wzz_ = Impl_< 3, 3, Coord::z, Coord::z, Coord::z >;
        using wzw_ = Impl_< 3, 4, Coord::z, Coord::z, Coord::w >;
        using wwx_ = Impl_< 3, 4, Coord::z, Coord::w, Coord::x >;
        using wwy_ = Impl_< 3, 4, Coord::z, Coord::w, Coord::y >;
        using wwz_ = Impl_< 3, 4, Coord::z, Coord::w, Coord::z >;
        using www_ = Impl_< 3, 4, Coord::z, Coord::w, Coord::w >;

        using xyzw_ = Impl_< 4, 4, Coord::x, Coord::y, Coord::z, Coord::w >;

        // variables
        constexpr xx_ xx;
        constexpr xy_ xy;
        constexpr xz_ xz;
        constexpr xw_ xw;
        constexpr yx_ yx;
        constexpr yy_ yy;
        constexpr yz_ yz;
        constexpr yw_ yw;
        constexpr zx_ zx;
        constexpr zy_ zy;
        constexpr zz_ zz;
        constexpr zw_ zw;
        constexpr wx_ wx;
        constexpr wy_ wy;
        constexpr wz_ wz;
        constexpr ww_ ww;

        constexpr xxx_ xxx;
        constexpr xxy_ xxy;
        constexpr xxz_ xxz;
        constexpr xxw_ xxw;
        constexpr xyx_ xyx;
        constexpr xyy_ xyy;
        constexpr xyz_ xyz;
        constexpr xyw_ xyw;
        constexpr xzx_ xzx;
        constexpr xzy_ xzy;
        constexpr xzz_ xzz;
        constexpr xzw_ xzw;
        constexpr xwx_ xwx;
        constexpr xwy_ xwy;
        constexpr xwz_ xwz;
        constexpr xww_ xww;
        constexpr yxx_ yxx;
        constexpr yxy_ yxy;
        constexpr yxz_ yxz;
        constexpr yxw_ yxw;
        constexpr yyx_ yyx;
        constexpr yyy_ yyy;
        constexpr yyz_ yyz;
        constexpr yyw_ yyw;
        constexpr yzx_ yzx;
        constexpr yzy_ yzy;
        constexpr yzz_ yzz;
        constexpr yzw_ yzw;
        constexpr ywx_ ywx;
        constexpr ywy_ ywy;
        constexpr ywz_ ywz;
        constexpr yww_ yww;
        constexpr zxx_ zxx;
        constexpr zxy_ zxy;
        constexpr zxz_ zxz;
        constexpr zxw_ zxw;
        constexpr zyx_ zyx;
        constexpr zyy_ zyy;
        constexpr zyz_ zyz;
        constexpr zyw_ zyw;
        constexpr zzx_ zzx;
        constexpr zzy_ zzy;
        constexpr zzz_ zzz;
        constexpr zzw_ zzw;
        constexpr zwx_ zwx;
        constexpr zwy_ zwy;
        constexpr zwz_ zwz;
        constexpr zww_ zww;
        constexpr wxx_ wxx;
        constexpr wxy_ wxy;
        constexpr wxz_ wxz;
        constexpr wxw_ wxw;
        constexpr wyx_ wyx;
        constexpr wyy_ wyy;
        constexpr wyz_ wyz;
        constexpr wyw_ wyw;
        constexpr wzx_ wzx;
        constexpr wzy_ wzy;
        constexpr wzz_ wzz;
        constexpr wzw_ wzw;
        constexpr wwx_ wwx;
        constexpr wwy_ wwy;
        constexpr wwz_ wwz;
        constexpr www_ www;

        constexpr xyzw_ xyzw;
    } // namespace swizzles
    // TODO too much repeat, maybe find a better implementation of restricting swizzle requirements
    //      IMORTANT not forget about static header with asserts)
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 2, Layt > const &vec, swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 > ) {
        using Ret = Vec< Type, Size, Layt >;
        using Swiz = swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 >;
        if constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };
        if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };
        if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) };
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 3, Layt > const &vec, swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 > ) {
        using Ret = Vec< Type, Size, Layt >;
        using Swiz = swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 >;
        if constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };
        if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };
        if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) };
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 3, Layt > const &vec, swizzles::Impl_< Size, 3, Crd1, Crd2, Crd3, Crd4 > ) {
        using Ret = Vec< Type, Size, Layt >;
        using Swiz = swizzles::Impl_< Size, 3, Crd1, Crd2, Crd3, Crd4 >;
        if constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };
        if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };
        if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) };
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 4, Layt > const &vec, swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 > ) {
        using Ret = Vec< Type, Size, Layt >;
        using Swiz = swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 >;
        if constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };
        if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };
        if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) };
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 4, Layt > const &vec, swizzles::Impl_< Size, 3, Crd1, Crd2, Crd3, Crd4 > ) {
        using Ret = Vec< Type, Size, Layt >;
        using Swiz = swizzles::Impl_< Size, 3, Crd1, Crd2, Crd3, Crd4 >;
        if constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };
        if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };
        if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) };
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 4, Layt > const &vec, swizzles::Impl_< Size, 4, Crd1, Crd2, Crd3, Crd4 > ) {
        using Ret = Vec< Type, Size, Layt >;
        using Swiz = swizzles::Impl_< Size, 4, Crd1, Crd2, Crd3, Crd4 >;
        if constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };
        if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };
        if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) };
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_SWIZZLES_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
