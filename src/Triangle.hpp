/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#ifndef Triangle_h
#define Triangle_h


#include <iosfwd>

#include "Vector3f.hpp"




#include "hxa7241_minilight.hpp"
namespace hxa7241_minilight
{


/**
 * Simple, explicit/non-vertex-shared triangle.<br/><br/>
 *
 * Includes geometry and quality.<br/><br/>
 *
 * Constant.<br/><br/>
 *
 * @implementation
 * Adapts ray intersection code from:
 * <cite>'Fast, Minimum Storage Ray-Triangle Intersection'
 * Moller, Trumbore;
 * Journal of Graphics Tools, v2 n1 p21, 1997.
 * http://www.acm.org/jgt/papers/MollerTrumbore97/</cite>
 *
 * @invariants
 * * reflectivity_m >= 0 and <= 1
 * * emitivity_m    >= 0
 */
class Triangle
{
/// standard object services ---------------------------------------------------
public:
   explicit Triangle( std::istream& );

// use defaults
//         ~Triangle();
//          Triangle( const Triangle& );
// Triangle& operator=( const Triangle& );


/// commands -------------------------------------------------------------------


/// queries --------------------------------------------------------------------
           void     getBound( real64 bound[6] )                           const;
           bool     getIntersection( const Vector3f& rayOrigin,
                                     const Vector3f& rayDirection,
                                     real64&         hitDistance_o )      const;
           Vector3f getSamplePoint( const Random&    random )             const;

           Vector3f getNormal()                                           const;
           Vector3f getTangent()                                          const;
           real64   getArea()                                             const;

           Vector3f getReflectivity()                                     const;
           Vector3f getEmitivity()                                        const;


/// constants ------------------------------------------------------------------
   static  real64 TOLERANCE();


/// fields ---------------------------------------------------------------------
private:
   // geometry
   Vector3f vertexs_m[3];

   // quality
   Vector3f reflectivity_m;
   Vector3f emitivity_m;
};


}//namespace




#endif//Triangle_h
