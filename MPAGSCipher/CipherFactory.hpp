#ifndef CIPHERFACTORY_HPP
#define CIPHERFACTORY_HPP

//Standard Library includes
#include <memory>

//Our project headers
#include "Cipher.hpp"
#include "CipherType.hpp"

/**
 * \file CipherFactory.hpp
 * \brief Contains the decleration of the cipherFactory function for creating smart pointers to ciphers
 */

/**
 * \brief Returns a smart pointer to a cipher of the specified type using the key
 *
 * \param type the type of Cipher to be created
 * \param key the key to be used in the creation of the Cipher
 * \return a unique smart pointer to the created Cipher object
 */


std::unique_ptr<Cipher> cipherFactory( const CipherType type, const std::string& key); 



#endif


