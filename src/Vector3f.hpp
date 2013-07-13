/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#ifndef Vector3f_h
#define Vector3f_h


#include <iosfwd>




#include "hxa7241_graphics.hpp"
namespace hxa7241_graphics
{


/**
 * Yes, its the 3D vector class!.<br/><br/>
 *
 * ...mostly the usual sort of stuff.<br/><br/>
 *
 * (Unused methods are commented out. They do work fine though.)<br/><br/>
 *
 * Constant.
 */
class Vector3f
{
/// standard object services ---------------------------------------------------
public:
            Vector3f();
            Vector3f( real64 x,
                      real64 y,
                      real64 z );
// explicit Vector3f( const real64 xyz[3] );

// use defaults
//         ~Vector3f();
//          Vector3f( const Vector3f& );
// Vector3f& operator=( const Vector3f& );


/// commands -------------------------------------------------------------------
//         Vector3f& set( real64 x,
//                        real64 y,
//                        real64 z );
//         Vector3f& set( const real64 xyz[3] );

//         Vector3f& negateEq ();
//         Vector3f& absEq    ();
//         Vector3f& unitizeEq();
//         Vector3f& crossEq  ( const Vector3f& );

//         Vector3f& operator+=( const Vector3f& );
//         Vector3f& operator-=( const Vector3f& );
//         Vector3f& operator*=( const Vector3f& );
//         Vector3f& operator/=( const Vector3f& );
//         Vector3f& operator*=( real64 );
//         Vector3f& operator/=( real64 );

//         Vector3f& clampMin( const Vector3f& );
//         Vector3f& clampMax( const Vector3f& );
//         Vector3f& clamp   ( const Vector3f& min,
//                             const Vector3f& max );
//         /**
//          * 0 to almost 1, ie: [0,1).
//          */
//         Vector3f& clamp01();


/// queries --------------------------------------------------------------------
//         void      get( real64& x_o,
//                        real64& y_o,
//                        real64& z_o )                                   const;
//         void      get( real64 xyz[3] )                                 const;

//         real64    getX()                                               const;
//         real64    getY()                                               const;
//         real64    getZ()                                               const;
           real64    operator[]( int )                                    const;
                                                                          
//         real64    sum()                                                const;
//         real64    average()                                            const;
//         real64    smallest()                                           const;
//         real64    largest()                                            const;
                                                                          
//         real64    length()                                             const;
           real64    dot( const Vector3f& )                               const;
//         real64    distance( const Vector3f& )                          const;

           Vector3f  operator-()                                          const;
//         Vector3f  abs()                                                const;
           Vector3f  unitize()                                            const;
           Vector3f  cross( const Vector3f& )                             const;

           Vector3f  operator+( const Vector3f& )                         const;
           Vector3f  operator-( const Vector3f& )                         const;
           Vector3f  operator*( const Vector3f& )                         const;
//         Vector3f  operator/( const Vector3f& )                         const;
           Vector3f  operator*( real64 )                                  const;
           Vector3f  operator/( real64 )                                  const;

//         bool      operator==( const Vector3f& )                        const;
//         bool      operator!=( const Vector3f& )                        const;
           bool      isZero()                                             const;

//         // returning vectors of -1.0 or 0.0 or +1.0
//         Vector3f  sign   ()                                            const;
//         Vector3f  compare( const Vector3f& )                           const;
//
//         // returning vectors of static_cast<real64>(bool)
//         Vector3f  equal     ( const Vector3f& )                        const;
//         Vector3f  operator> ( const Vector3f& )                        const;
//         Vector3f  operator>=( const Vector3f& )                        const;
//         Vector3f  operator< ( const Vector3f& )                        const;
//         Vector3f  operator<=( const Vector3f& )                        const;

//         /**
//          * 0 to almost 1, ie: [0,1).
//          */
//         void      getClamped01( Vector3f& result_o )                   const;
           Vector3f  getClamped  ( const Vector3f& min,
                                   const Vector3f& max )                  const;


/// friends --------------------------------------------------------------------
// friend  Vector3f  operator*( real64, const Vector3f& );
// friend  Vector3f  operator/( real64, const Vector3f& );


/// constants ------------------------------------------------------------------
   static const Vector3f& ZERO();
// static const Vector3f& HALF();
   static const Vector3f& ONE();
// static const Vector3f& EPSILON();
// static const Vector3f& ALMOST_ONE();
   static const Vector3f& MIN();
   static const Vector3f& MAX();
// static const Vector3f& SMALL();
// static const Vector3f& LARGE();
// static const Vector3f& X();
// static const Vector3f& Y();
// static const Vector3f& Z();


/// fields ---------------------------------------------------------------------
private:
   real64 xyz_m[3];
};








/// friends

//Vector3f operator*( real64, const Vector3f& );
//Vector3f operator/( real64, const Vector3f& );




/// streaming

//std::ostream& operator<<( std::ostream&, const Vector3f& );
std::istream& operator>>( std::istream&,       Vector3f& );




/// INLINES ///


/// standard object services ---------------------------------------------------

//inline
//Vector3f::Vector3f
//(
//   const real64 xyz[3]
//)
//{
//   Vector3f::set( xyz );
//}


//inline
//Vector3f::~Vector3f()
//{
//}
//
//
//inline
//Vector3f::Vector3f
//(
//   const Vector3f& other
//)
//{
//   Vector3f::operator=( other );
//}




/// queries --------------------------------------------------------------------

//inline
//real64 Vector3f::getX() const
//{
//   return xyz_m[0];
//}
//
//
//inline
//real64 Vector3f::getY() const
//{
//   return xyz_m[1];
//}
//
//
//inline
//real64 Vector3f::getZ() const
//{
//   return xyz_m[2];
//}


inline
real64 Vector3f::operator[]
(
   const int i
) const
{
   return xyz_m[i];
}


}//namespace




#endif//Vector3f_h
