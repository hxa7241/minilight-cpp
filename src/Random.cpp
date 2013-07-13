/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#include <time.h>
#include <stdio.h>

#include "Random.hpp"


using namespace hxa7241_general;




/// constants ------------------------------------------------------------------

namespace
{
   // default seed
   const int32u SEED = 987654321;

   // minimum seeds
   //const int32u SEED_MINS[4] = { 2, 8, 16, 128 };
}




/// standard object services ---------------------------------------------------

/*Random::Random()
{
   // try to get 'non-determinate' seed
   int32u seed = 0;
   {
      // probably Unix time -- signed 32-bit, seconds since 1970
      const time_t t = ::time(0);

      // check time sufficient (probably) and available
      if( (sizeof(time_t) >= 4) && (t != -1) )
      {
         // rotate to make frequently changing bits more significant
         seed = (static_cast<int32u>(t) << 8) | (static_cast<int32u>(t) >> 24);
      }
   }

   // init state from seed
   // *** VERY IMPORTANT ***
      The initial seeds z1, z2, z3, z4  MUST be larger
      than 1, 7, 15, and 127 respectively. //
   for( int i = 4;  i--;  z_m[i] = (seed >= SEED_MINS[i]) ? seed : SEED ) {}

   // store seed/id as 8 digit hex number string
   ::sprintf( id_m, "%08X", z_m[3] & 0xFFFFFFFFu );
}*/


Random::Random()
{
   /* *** VERY IMPORTANT ***
      The initial seeds z1, z2, z3, z4  MUST be larger
      than 1, 7, 15, and 127 respectively. */

   z_m[0] = z_m[1] = z_m[2] = z_m[3] = SEED;
}




/// queries --------------------------------------------------------------------

int32u Random::getInt32u() const
{
   z_m[0] = ((z_m[0] & 0xFFFFFFFEu) << 18) ^ (((z_m[0] <<  6) ^ z_m[0]) >> 13);
   z_m[1] = ((z_m[1] & 0xFFFFFFF8u) <<  2) ^ (((z_m[1] <<  2) ^ z_m[1]) >> 27);
   z_m[2] = ((z_m[2] & 0xFFFFFFF0u) <<  7) ^ (((z_m[2] << 13) ^ z_m[2]) >> 21);
   z_m[3] = ((z_m[3] & 0xFFFFFF80u) << 13) ^ (((z_m[3] <<  3) ^ z_m[3]) >> 12);

   return z_m[0] ^ z_m[1] ^ z_m[2] ^ z_m[3];
}


/*real32 Random::getReal32() const
{
   return static_cast<real32>(static_cast<int32>(getInt32u() & 0xFFFFFF00u)) *
      (1.0f / 4294967296.0f) + 0.5f;
}*/


real64 Random::getReal64() const
{
   return static_cast<real64>(static_cast<int32>(getInt32u())) *
      (1.0 / 4294967296.0) + 0.5 +
      static_cast<real64>(static_cast<int32>(getInt32u() & 0x001FFFFFu)) *
      (1.0 / 9007199254740992.0);
}


/*real64 Random::getReal64_() const
{
   return static_cast<real64>(static_cast<int32>(getInt32u())) *
      (1.0 / 4294967296.0) +
      (0.5 + (1.0  / 4503599627370496.0) * 0.5) +
      static_cast<real64>(static_cast<int32>(getInt32u() & 0x000FFFFFu)) *
      (1.0  / 4503599627370496.0);
}*/


/*const char* Random::getId() const
{
   return id_m;
}*/
