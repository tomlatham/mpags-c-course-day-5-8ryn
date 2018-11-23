//Standard library headers
#include <string>
#include <iostream>
#include <algorithm>

//Our project headers
#include "VigenereCipher.hpp"
#include "Alphabet.hpp"
#include "CaesarCipher.hpp"

VigenereCipher::VigenereCipher ( const std::string& key )
{
  setKey(key);
}


void VigenereCipher::setKey(const std::string& key ){

  // Store the key
  key_ = key;
  
  // Make sure the key is uppercase
  std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );
  
  // Remove non-alphabet characters
  key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ), std::end(key_) );
  
  // Check if the key is empty and replace with default if so
  if(key_ ==""){
    std::cout << "No key has been provided and so key has been set to \"A\" meaning no encryption" << std::endl;
    key_ = "A";
  }

  // loop over the key
  for( size_t i{0}; i<key_.length(); ++i){
  
    // Find the letter position in the alphabet
    size_t pos = Alphabet::alphabet.find(key_[i]);
    
    // Create a CaesarCipher using this position as a key
    CaesarCipher cipher{pos};
    
    // Insert a std::pair of the letter and CaesarCipher into the lookup
    charLookup_.insert( std::make_pair( key_[i], cipher) );
    
  }
}

std::string VigenereCipher::applyCipher( const std::string& inputText, \
					 const CipherMode cipherMode ) const
{

  std::string output = "";

  // For each letter in input:
  for(size_t i{0}; i<inputText.length() ; ++i){

    // Find the corresponding letter in the key,
    // repeating/truncating as required
    char keyChar = key_[i%key_.length()];
    
    // Find the Caesar cipher from the lookup
    auto posIt = charLookup_.find(keyChar);
    CaesarCipher cipher = (*posIt).second;
    
    // Run the (de)encryption
    // Add the result to the output
    output += cipher.applyCipher( std::string{inputText[i]}, cipherMode);
    
  }

  return output;
}
