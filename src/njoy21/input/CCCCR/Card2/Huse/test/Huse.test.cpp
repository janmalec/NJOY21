#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card2, Huse",
          "[CCCCR] [Card2] [Huse]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( std::string s : {"'12' /", "'1234' /", "'123456789012' /"} ){
        iRecordStream<char> iss( std::istringstream( s ) );

        THEN( "the value can be verified" ){
          REQUIRE( s == argument::extract< CCCCR::Card2::Huse >( iss ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is verified" ){
        REQUIRE( "" == argument::extract< CCCCR::Card2::Huse >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid input is provided" ){
      iRecordStream<char> iss( std::istringstream( "'1234567890123' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::Card2::Huse >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
