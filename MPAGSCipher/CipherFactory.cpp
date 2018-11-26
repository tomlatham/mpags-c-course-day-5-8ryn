//Standard Library headers
#include <iostream>

//Our project headers
#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

std::unique_ptr<Cipher> cipherFactory( const CipherType type, const std::string & key){

  switch (type){

  case CipherType::Caesar :
    return std::make_unique<CaesarCipher>(key);

  case CipherType::Playfair :
    return std::make_unique<PlayfairCipher>(key);

  case CipherType::Vigenere :
    return std::make_unique<VigenereCipher>(key);

  }

  //This case should never happen but added to keep compiler happy
  std::cerr << "[error] Unrecognised CipherType passed to cipherFactory" << std::endl;
  return std::unique_ptr<Cipher>();

}
