class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        space_pos = sentence.find(" ")

        while space_pos != -1:
            if sentence[space_pos - 1] != sentence[space_pos + 1]:
                return False

            space_pos = sentence.find(" ", space_pos + 1)

        return sentence[0] == sentence[-1]
