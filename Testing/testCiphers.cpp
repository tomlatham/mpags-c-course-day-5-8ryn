//! Test of ciphers encryption/decryption
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Cipher.hpp"
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "CipherFactory.hpp"
#include "CipherType.hpp"
#include <vector>


bool testCipher( const Cipher& cipher, const CipherMode mode,
		 const std::string& inputText, const std::string& outputText){
  return (cipher.applyCipher( inputText, mode) == outputText);
}

/*Given that each cipher will have a different input and expected output I can't see how a for loop could be used
 *and hence this method (or certainly my implementation) just seems more cumbersome and less clear than my original code below
 */
TEST_CASE("Cipher encryption and decryption", "[cipher]"){
  std::vector<std::unique_ptr<Cipher>> ciphers;
  ciphers.push_back( cipherFactory( CipherType::Caesar, "10"));
  ciphers.push_back( cipherFactory( CipherType::Playfair, "hello"));
  ciphers.push_back( cipherFactory( CipherType::Vigenere, "testingthisabcdefghijklmnopqrstuvwxyz"));

  SECTION( "Encryption"){
    REQUIRE(testCipher( *ciphers[0], CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN"));
    REQUIRE(testCipher( *ciphers[1], CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"));
    REQUIRE(testCipher(*ciphers[2], CipherMode::Encrypt, "INCREDIBLERESULTTHEREABCDEFGHIJKLMNOPQRSTUVWXYZ", "BRUKMQOUSMJETWOXYNLZNKMOQSUWYACEGIKMOJVKMCICQFH"));
    }

  SECTION( "Decryption"){
    REQUIRE(testCipher( *ciphers[0], CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD"));
    REQUIRE(testCipher(*ciphers[1], CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"));
    REQUIRE(testCipher(*ciphers[2], CipherMode::Decrypt, "BRUKMQOUSMJETWOXYNLZNKMOQSUWYACEGIKMOJVKMCICQFH", "INCREDIBLERESULTTHEREABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    

  }
  
}



/* Old test code
  
TEST_CASE("Caesar Cipher encryption", "[caesar]"){
  CaesarCipher cc{10};
  REQUIRE(testCipher( cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN"));
}

TEST_CASE("Caesar Cipher decyrption", "[caesar]"){
  CaesarCipher cc{10};
  REQUIRE(testCipher( cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD"));
}
TEST_CASE("Playfair Cipher encryption", "[playfair]"){
  PlayfairCipher pc{"hello"};
  REQUIRE(testCipher( pc, CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"));
}

TEST_CASE("Playfair Cipher decryption", "[playfair]"){
  PlayfairCipher pc{"hello"};
  REQUIRE(testCipher(pc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"));
}

TEST_CASE("Vigenere Cipher encryption", "[vigenere]"){
  VigenereCipher vc{"testingthisabcdefghijklmnopqrstuvwxyz"};
  REQUIRE(testCipher(vc, CipherMode::Encrypt, "INCREDIBLERESULTTHEREABCDEFGHIJKLMNOPQRSTUVWXYZ", "BRUKMQOUSMJETWOXYNLZNKMOQSUWYACEGIKMOJVKMCICQFH"));
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]"){
  VigenereCipher vc{"testingthisabcdefghijklmnopqrstuvwxyz"};
  REQUIRE(testCipher(vc, CipherMode::Decrypt, "BRUKMQOUSMJETWOXYNLZNKMOQSUWYACEGIKMOJVKMCICQFH", "INCREDIBLERESULTTHEREABCDEFGHIJKLMNOPQRSTUVWXYZ"));

}

*/
