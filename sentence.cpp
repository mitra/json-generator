//
//  main.cpp
//  nouns
//
//  Created by Noah Eisen on 10/28/14.
//  Copyright (c) 2014 Noah Eisen. All rights reserved.
//

#include <iostream>
#include <random>
#include <fstream>
#include <ctime>
#include <map>
#include "json_gen.h"

using namespace std;

string get_from_file(string filename);

string get_noun();

string get_article();

string get_adjective();

string get_relative_pronoun();

string get_preposition();

string get_verb();

string get_adverb();

string get_ornate_noun();

string get_fancy_noun();

string get_ornate_verb();

string get_sentence();

std::map<std::string, std::shared_ptr<RandomLine>> file_cache;

string get_from_file(string filename)
{
    ifstream infile;
	std::shared_ptr<RandomLine> random_line;
	std::string file = "../files/" + filename;
	auto itr = file_cache.find(file);
	if (itr == file_cache.end()) {
		auto lines = std::make_shared<RandomLine>(file);
		file_cache[file] = lines;
		random_line = lines;
	} else {
		random_line = itr->second;
	}
	return random_line->GetWord();

}

string get_noun()
{
    return get_from_file("nouns.txt");
}

string get_article()
{
    return "the";
}

string get_adjective()
{
    return get_from_file("adjectives.txt");
}

string get_relative_pronoun()
{
    return get_from_file("relative_pronouns.txt");
}

string get_preposition()
{
    return get_from_file("prepositions.txt");
}

string get_verb()
{
    return get_from_file("verbs.txt");
}

string get_subject()
{
    return get_from_file("subjects.txt");
}

string get_adverb()
{
    return get_from_file("adverbs.txt");
}

string get_ornate_noun()
{
    string result;
    
    result += get_article() + " ";
    
    if (rand() % 2)
        result += get_adjective() + " ";
    
    if (rand() % 4)
        result += get_adjective() + " ";
    
    result += get_noun();
    
    return result;
}

string get_fancy_noun()
{
    string result;
    
    result += get_ornate_noun();
    
    if (rand() % 3)
        return result;
    
    if (rand() % 3)
        return result + " " + get_preposition() + " " + get_fancy_noun();
    
    result += " " + get_relative_pronoun() + " ";
    
    if (rand() % 2)
        result += get_verb() + " " + get_fancy_noun();
    
    else
        result += get_fancy_noun() + " " + get_verb();
    
    return result;
}

string get_ornate_verb()
{
    return get_adverb() + " " + get_verb();
}

string get_sentence()
{
    return get_subject() + " " + get_ornate_verb() + " " + get_fancy_noun();
}
