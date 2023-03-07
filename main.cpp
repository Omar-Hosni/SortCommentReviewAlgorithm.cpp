#include <iostream>
#include <set>
#include <queue>
#include <climits>
#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>

vector<string> getWords(string sentence)
{
	vector<string> words;
	sentence += ' ';
	string word = "";
	for (auto c : sentence)
	{
		if (c == ' ')
		{
			if (word.size())
			{
				words.push_back(word);
				word = "";
			}
		}
		else {
			word += c;
		}
	}
	return words;
}

vector<string> sortSentencesByReview(const vector<string>& sentences, const vector<string> &ListOfAllGoodWords)
{
	unordered_set<string> goodWordsInSentence;
	vector<pair<int, int>> score_idx;

	for (string gw : ListOfAllGoodWords)
	{
		goodWordsInSentence.insert(gw);
	}

	for (int i=0; i < sentences.size(); i++)
	{
		vector<string> words = getWords(sentences[i]);
		
		int score = 0;
		for (string w : words)
		{
			if (goodWordsInSentence.count(w))
			{
				score++;
			}
		}
		score_idx.push_back({ score, -i});
	}
	sort(score_idx.rbegin(), score_idx.rend());

	vector<string> res;

	for (auto s_i : score_idx)
	{
		res.push_back(sentences[-s_i.second]);
	}

	return res;
}
