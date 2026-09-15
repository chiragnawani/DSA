class Solution(object):
    def groupAnagrams(self, strs):
        dict1 = {}

        for word in strs:
            sortedword = "".join(sorted(word))
            if sortedword not in dict1:
                dict1[sortedword] = [word]
            else:
                dict1[sortedword].append(word)
        result = []
        for item in dict1.values():
            result.append(item)
        return result