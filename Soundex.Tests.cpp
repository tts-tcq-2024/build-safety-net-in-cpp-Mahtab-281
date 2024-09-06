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
        {"AEIOU", "A000"}, {"HW", "H000"}, {"YHW", "Y000"}, {"XHW", "X200"}
    };
    for (const auto& testCase : testCases) {
        EXPECT_EQ(generateSoundex(testCase.first), testCase.second);
    }
}

TEST(SoundexTest, HandlesAdjacentConsonants) {
    std::map<char, std::string> soundexMapping = {
        {'B', "B100"}, {'C', "C200"}, {'D', "D300"}, {'L', "L400"}, 
        {'M', "M500"}, {'R', "R600"}
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
