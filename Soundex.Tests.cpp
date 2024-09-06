#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}
 
TEST(SoundexTest, HandlesSingleCharacter) {
    for (char c = 'A'; c <= 'Z'; ++c) {
        std::string expected = std::string(1, c) + "000";
        EXPECT_EQ(generateSoundex(std::string(1, c)), expected);
    }
}
 
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
TEST(SoundexTest, HandlesLongNames) {
    EXPECT_EQ(generateSoundex("Soundex"), "S532");
    EXPECT_EQ(generateSoundex("Generate"), "G563");
    EXPECT_EQ(generateSoundex("Function"), "F523");
}

TEST(SoundexTest, HandlesHyphensAndSpaces) {
    EXPECT_EQ(generateSoundex("Soundex-Code"), "S532");
    EXPECT_EQ(generateSoundex("Generate Function"), "G563");
}

TEST(SoundexTest, HandlesNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("Func@123"), "F520");
    EXPECT_EQ(generateSoundex("Gen#erate"), "G563");
}
