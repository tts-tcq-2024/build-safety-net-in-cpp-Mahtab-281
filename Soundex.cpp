#include <string>
#include <cctype>
#include <unordered_map>
#include <algorithm>
 
// Function to map characters to their corresponding Soundex codes
char mapToSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, 
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'}, {'L', '4'}, {'M', '5'}, 
        {'N', '5'}, {'R', '6'}
    };
    c = toupper(c);
    auto it = soundexMap.find(c);
    return (it != soundexMap.end()) ? it->second : '0';
}
 
void appendSoundex(std::string& soundex, char code, char& prevCode) {
    if (code != '0' && code != prevCode) {
        soundex += code;
        prevCode = code;
    }
}
 
std::string paddingSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    paddedSoundex.resize(4, '0');
    return paddedSoundex;
}
// Helper function to build the Soundex code
std::string buildSoundex(const std::string& name, char firstLetter, char prevCode, std::string soundex, size_t index) {
   if (index >= name.length() || soundex.length() == 4) {
        return paddingSoundex(soundex);
    }
 
    char code = mapToSoundexCode(name[index]);
    appendSoundex(soundex, code, prevCode);
 
    return buildSoundex(name, firstLetter, prevCode, soundex, index + 1);
}
 
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";  // Handle empty input
 
    return buildSoundex(name, toupper(name[0]), mapToSoundexCode(name[0]), std::string(1, toupper(name[0])), 1);
}
