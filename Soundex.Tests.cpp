#include <gtest/gtest.h>
#include "Soundex.h"
 
// Test cases for the empty string check
TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}
 
// Test cases for the single character check
TEST(SoundexTest, HandlesSingleCharacter) {
    for (char c = 'A'; c <= 'Z'; ++c) {
        std::string expected = std::string(1, c) + "000";
        EXPECT_EQ(generateSoundex(std::string(1, c)), expected);
    }
}
 
 
// Test cases for the names with vowels and certain consonants that should be ignored
TEST(SoundexTest, HandlesIgnoredCharacters) {
    std::vector<std::pair<std::string, std::string>> testCases = {
        {"AEIOU", "A000"}, {"EAIOU", "E000"}, {"IAEOU", "I000"}, 
        {"OAEIU", "O000"}, {"UAEIO", "U000"}, {"HW", "H000"}, 
        {"WH", "W000"}
    };
    for (const auto& testCase : testCases) {
        EXPECT_EQ(generateSoundex(testCase.first), testCase.second);
    }
}
 
 
// Test cases for the names with adjacent consonants that should be ignored
TEST(SoundexTest, HandlesAdjacentConsonants) {
    std::map<char, std::string> soundexMapping = {
        {'B', "B100"}, {'C', "C200"}, {'D', "D300"}, {'F', "F100"}, 
        {'G', "G200"}, {'J', "J200"}, {'K', "K200"}, {'L', "L400"}, 
        {'M', "M500"}, {'N', "N500"}, {'P', "P100"}, {'Q', "Q200"}, 
        {'R', "R600"}, {'S', "S200"}, {'T', "T300"}, {'V', "V100"}, 
        {'X', "X200"}, {'Y', "Y000"}, {'Z', "Z200"}
    };
 
    for (const auto& entry : soundexMapping) {
        char consonant = entry.first;
        std::string expected = entry.second;
        EXPECT_EQ(generateSoundex(std::string(2, consonant)), expected);
    }
}
 
 
// Test cases for the longer names that require truncation
TEST(SoundexTest, HandlesLongNames) {
    EXPECT_EQ(generateSoundex("Aeiouhw"), "A000");
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Tymczak"), "T520");
    EXPECT_EQ(generateSoundex("Pfister"), "P123");
    EXPECT_EQ(generateSoundex("Ashworth"), "A263");
    EXPECT_EQ(generateSoundex("Bobby"), "B100");
    EXPECT_EQ(generateSoundex("Hildebrand"), "H431");
    EXPECT_EQ(generateSoundex("Barack"), "B620");
    EXPECT_EQ(generateSoundex("abcdefghijklmnopqrstuvwxyz"), "A123");
    EXPECT_EQ(generateSoundex("RoBErt"), "R163");
    EXPECT_EQ(generateSoundex("0"), "0000");
    EXPECT_EQ(generateSoundex("1234"), "1000");
}
 
// Test cases for the names with hyphens or spaces
TEST(SoundexTest, HandlesHyphensAndSpaces) {
    EXPECT_EQ(generateSoundex("Rohit-Sharma"), "R362");
    EXPECT_EQ(generateSoundex("Hrithik-Roshan"), "D526");
    EXPECT_EQ(generateSoundex("Sachin Tendulkar"), "V632");
    EXPECT_EQ(generateSoundex("Rajkumar Rao"), "A531");
}
 
// Test cases for the names with non-alphabetic characters
TEST(SoundexTest, HandlesNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("J'Sharma"), "J156");
    EXPECT_EQ(generateSoundex("Harish@15"), "H620");
}
