#line 1 "Src\\Token.cpp"
#line 1 "Src\\Token.h"
#line 1 "Src\\datatypes.h"



#line 1 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"
 
 





 

 








#line 1 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     












      namespace std {

          extern "C" {








 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;


#line 247 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

#line 266 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"


         }   
      }   





      using ::std::int8_t;
      using ::std::int16_t;
      using ::std::int32_t;
      using ::std::int64_t;
      using ::std::uint8_t;
      using ::std::uint16_t;
      using ::std::uint32_t;
      using ::std::uint64_t;
      using ::std::int_least8_t;
      using ::std::int_least16_t;
      using ::std::int_least32_t;
      using ::std::int_least64_t;
      using ::std::uint_least8_t;
      using ::std::uint_least16_t;
      using ::std::uint_least32_t;
      using ::std::uint_least64_t;
      using ::std::int_fast8_t;
      using ::std::int_fast16_t;
      using ::std::int_fast32_t;
      using ::std::int_fast64_t;
      using ::std::uint_fast8_t;
      using ::std::uint_fast16_t;
      using ::std::uint_fast32_t;
      using ::std::uint_fast64_t;
      using ::std::intptr_t;
      using ::std::uintptr_t;
      using ::std::intmax_t;
      using ::std::uintmax_t;








 
#line 20 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 203 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

#line 221 "C:\\Bin\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\inttypes.h"

typedef struct imaxdiv_t { intmax_t quot, rem; } imaxdiv_t;
    


extern "C" {


__declspec(__nothrow) intmax_t strtoimax(const char * __restrict  ,
                   char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
     
__declspec(__nothrow) uintmax_t strtoumax(const char * __restrict  ,
                    char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
     

__declspec(__nothrow) intmax_t wcstoimax(const wchar_t * __restrict  ,
                   wchar_t ** __restrict  , int  ) __attribute__((__nonnull__(1)));
__declspec(__nothrow) uintmax_t wcstoumax(const wchar_t * __restrict  ,
                    wchar_t ** __restrict  , int  ) __attribute__((__nonnull__(1)));

extern __declspec(__nothrow) __attribute__((const)) intmax_t imaxabs(intmax_t  );
   



 
extern __declspec(__nothrow) __attribute__((const)) imaxdiv_t imaxdiv(intmax_t  , intmax_t  );
   











 


}




 

#line 5 "Src\\datatypes.h"

typedef struct coordinates {
	uint16_t x;
	uint16_t y;
	uint8_t player;
} Coordinates;

#line 4 "Src\\Token.h"

class Token
{
	public:
		const Coordinates coordinates;
		const short player;
		Token(Coordinates, short);
};

#line 2 "Src\\Token.cpp"

Token::Token(Coordinates coordinates, short player):coordinates(coordinates),player(player){};
