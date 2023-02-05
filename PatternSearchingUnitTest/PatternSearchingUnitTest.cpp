#include <gtest/gtest.h>
#include <../PatternSearchingLib/PatternSearchingLib.h>

namespace PatternSearchingUnitTest {
    TEST(PatternSearchingUnitTest, simpleNaive) {
        std::vector<int> excpected = {0, 4, 8};
        std::string text = "abcdabcdabcd";
        std::string pattern = "abcd";
        std::vector<int> outcome = NaiveSearch(pattern, text);
        ASSERT_EQ(excpected, outcome);
    }
    TEST(PatternSearchingUnitTest, simpleKMP) {
        std::vector<int> excpected = {0, 4, 8};
        std::string text = "abcdabcdabcd";
        std::string pattern = "abcd";
        std::vector<int> outcome = KMPSearch(pattern, text);
        ASSERT_EQ(excpected, outcome);
    }

    TEST(PatternSearchingUnitTest, simpleRK) {
        std::vector<int> excpected = {0, 4, 8};
        std::string text = "abcdabcdabcd";
        std::string pattern = "abcd";
        std::vector<int> outcome = RKSearch(pattern, text, 13);
        ASSERT_EQ(excpected, outcome);
    }

    TEST(PatternSearchingUnitTest, emptyNaive) {
        std::vector<int> excpected = {};
        std::string text = "";
        std::string pattern = "abcd";
        std::vector<int> outcome = NaiveSearch(pattern, text);
        ASSERT_EQ(excpected, outcome);
    }
    TEST(PatternSearchingUnitTest, emptyKMP) {
        std::vector<int> excpected = {};
        std::string text = "";
        std::string pattern = "abcd";
        std::vector<int> outcome = KMPSearch(pattern, text);
        ASSERT_EQ(excpected, outcome);
    }

    TEST(PatternSearchingUnitTest, emptyRK) {
        std::vector<int> excpected = {};
        std::string text = "";
        std::string pattern = "abcd";
        std::vector<int> outcome = RKSearch(pattern, text, 13);
        ASSERT_EQ(excpected, outcome);
    }

    TEST(PatternSearchingUnitTest, doubleemptyNaive) {
        std::vector<int> excpected = {};
        std::string text = "";
        std::string pattern = "";
        std::vector<int> outcome = NaiveSearch(pattern, text);
        ASSERT_EQ(excpected, outcome);
    }
    TEST(PatternSearchingUnitTest, doubleemptyKMP) {
        std::vector<int> excpected = {};
        std::string text = "";
        std::string pattern = "";
        std::vector<int> outcome = KMPSearch(pattern, text);
        ASSERT_EQ(excpected, outcome);
    }

    TEST(PatternSearchingUnitTest, doubleemptyRK) {
        std::vector<int> excpected = {};
        std::string text = "";
        std::string pattern = "";
        std::vector<int> outcome = RKSearch(pattern, text, 13);
        ASSERT_EQ(excpected, outcome);
    }

    TEST(PatternSearchingUnitTest, exactNaive) {
        std::vector<int> excpected = {0};
        std::string text = "abcabc123";
        std::string pattern = "abcabc123";
        std::vector<int> outcome = NaiveSearch(pattern, text);
        ASSERT_EQ(excpected, outcome);
    }
    TEST(PatternSearchingUnitTest, exactKMP) {
        std::vector<int> excpected = {0};
        std::string text = "abcabc123";
        std::string pattern = "abcabc123";;
        std::vector<int> outcome = KMPSearch(pattern, text);
        ASSERT_EQ(excpected, outcome);
    }

    TEST(PatternSearchingUnitTest, exactRK) {
        std::vector<int> excpected = {0};
        std::string text = "abcabc123";
        std::string pattern = "abcabc123";
        std::vector<int> outcome = RKSearch(pattern, text, 13);
        ASSERT_EQ(excpected, outcome);
    }

    TEST(PatternSearchingUnitTest, patternLongerNaive) {
        std::vector<int> excpected = {};
        std::string text = "abcabc123";
        std::string pattern = "abcabc1sadasx23";
        std::vector<int> outcome = NaiveSearch(pattern, text);
        ASSERT_EQ(excpected, outcome);
    }
    TEST(PatternSearchingUnitTest, patternLongerKMP) {
        std::vector<int> excpected = {};
        std::string text = "abcabc123";
        std::string pattern = "abcabc12sadasx3";;
        std::vector<int> outcome = KMPSearch(pattern, text);
        ASSERT_EQ(excpected, outcome);
    }

    TEST(PatternSearchingUnitTest, patternLongerRK) {
        std::vector<int> excpected = {};
        std::string text = "abcabc123";
        std::string pattern = "abcabc123123";
        std::vector<int> outcome = RKSearch(pattern, text, 13);
        ASSERT_EQ(excpected, outcome);
    }

    TEST(PatternSearchingUnitTest, patternNotInTextNaive) {
        std::vector<int> excpected = {};
        std::string text = "abcabc123";
        std::string pattern = "dx2";
        std::vector<int> outcome = NaiveSearch(pattern, text);
        ASSERT_EQ(excpected, outcome);
    }
    TEST(PatternSearchingUnitTest, patternNotInTextKMP) {
        std::vector<int> excpected = {};
        std::string text = "abcabc123";
        std::string pattern = "dx2";;
        std::vector<int> outcome = KMPSearch(pattern, text);
        ASSERT_EQ(excpected, outcome);
    }

    TEST(PatternSearchingUnitTest, patternNotInTextRK) {
        std::vector<int> excpected = {};
        std::string text = "abcabc123";
        std::string pattern = "sx2";
        std::vector<int> outcome = RKSearch(pattern, text, 13);
        ASSERT_EQ(excpected, outcome);
    }


}
