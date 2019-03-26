# Autocorrect-and-Autocomplete-feature-implementations-in-c-

Autocorrect and Autocomplete feature implementation over a 370110 english word dataset.
NEW_WORD_MAKE file reads words from "words" file and creates a new file with words along with their frequencies in a new file "new_words".
This program is executed only once just to make our words file in suitable format.

If a word in incorrectly typed program displays top 5 words based on previous search history that are at 1 unit levenstein distance from it.
If a word in incompletely typed program displays top 5 words based on previous search history that can be completed from entered prefix.
Users selects correct word out of given options by inputting it and in FREQ map count of that word is increased.
At end the updated frequencies are rewritten to the text file.
Data structures used:
   For Autocorrect:
      B_K Tree
   For Autocomplete:
      Trie
