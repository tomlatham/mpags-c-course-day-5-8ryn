#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

//Standard library includes
#include <string>

//Our project headers
#include "CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher interface
 */

/**
 * \interface Cipher
 * \brief Encrypt or decrypt text using the implmented cipher with the given key
 */ 
class Cipher {
  public:
    /// Default constructor
    Cipher() = default;

    /// Copy constructor
    Cipher(const Cipher& rhs) = default;

    /// Move constructor
    Cipher(Cipher&& rhs) = default;

    /// Copy assignment operator
    Cipher& operator=(const Cipher& rhs) = default;

    /// Move assignment operator
    Cipher& operator=(Cipher&& rhs) = default;

    /// Destructor
    virtual ~Cipher() = default;



  /**
   * \brief Apply the cipher to the provided text
   *
   * \param inputText the text to encrypt or decrypt
   * \param cipherMode whether to encrypt or decrypt the input text
   * \return the result of applying the cipher to the input text
   */
    virtual std::string applyCipher( const std::string& inputText,
		const CipherMode cipherMode ) const = 0;
  
  

};


#endif
