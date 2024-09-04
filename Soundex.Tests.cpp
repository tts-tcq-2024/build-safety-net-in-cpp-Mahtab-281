#include <gtest/gtest.h>
#include "Soundex.h"
 
 
TEST(SoundexTest, BasicTest) {
    EXPECT_EQ(generateSoundex("Smith"), "S530");
    EXPECT_EQ(generateSoundex("Smyth"), "S530");
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Ashcroft"), "A261");
}
 
TEST(SoundexTest, EdgeCases) {
    EXPECT_EQ(generateSoundex("Chand"), "C530");
    EXPECT_EQ(generateSoundex("Mehra"), "M600");
    EXPECT_EQ(generateSoundex("Pandey"), "P530");
    EXPECT_EQ(generateSoundex(""), "");
}
 
TEST(SoundexTest, CaseInsensitive) {
    EXPECT_EQ(generateSoundex("Robert"), generateSoundex("robert"));
    EXPECT_EQ(generateSoundex("Smith"), generateSoundex("sMiTh"));
}
 
/* TEST(SoundexTest, RepeatedCharacters) {
//   EXPECT_EQ(generateSoundex("Pfister"), "P236");
    EXPECT_EQ(generateSoundex("Honeyman"), "H555");
}*/
 
TEST(SoundexTest, SingleCharacterName) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("B"), "B000");
}
 
TEST(SoundexTest, AllVowels) {
    EXPECT_EQ(generateSoundex("Aeio"), "A000");
    EXPECT_EQ(generateSoundex("Euio"), "E000");
}
