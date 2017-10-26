class Freeform{
  public:
  Card12 card12;
  optional< std::vector<Card13> > card13;

  template< typename Istream >
  Freeform( Istream& is )
  try:
    card12( is ),
    card13( readCard13List( is, this->card12.nform.value ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating Freeform cards (12 & 13)." );
    throw e;
  }
};
