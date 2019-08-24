#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::string transformNsort(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {return tolower(c);});
    std::sort(text.begin(), text.end());
    return text;
}

int main() {
    std::vector<std::string> words;
    std::map<std::string, int> sortedWords;
    std::map<std::string, int> sortedOutput;
    std::vector<std::string> output;

    std::string text;
    while(std::cin >> text) {
        if(text == "#")
            break;
        words.push_back(text);
        sortedWords[transformNsort(text)]++;
    }

    for(auto & sortedWord : sortedWords) {
        if(sortedWord.second == 1)
            sortedOutput[sortedWord.first]++;
    }

    for(auto & word : words) {
        for(auto & it : sortedOutput) {
            if(transformNsort(word) == it.first)
                output.push_back(word);
        }
    }

    std::sort(std::begin(output), std::end(output));

    for(std::string & out : output)
        std::cout << out << std::endl;

    return 0;
}
