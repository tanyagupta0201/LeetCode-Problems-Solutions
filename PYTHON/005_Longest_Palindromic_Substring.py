class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
  
        ls = len(s)
        if ls <= 1 or len(set(s)) == 1:
            return s
        # create a new list like this: "abc"->"a#b#c"
        temp_s = '#'.join('{}'.format(s))
        # print temp_s
        tls = len(temp_s)
        seed = range(1, tls - 1)
        # this table stores the max length palindrome
        len_table = [0] * tls
        for step in range(1, tls / 2 + 1):
            final = []
            for pos in seed:
                if pos - step < 0 or pos + step >= tls:
                    continue
                if temp_s[pos - step] != temp_s[pos + step]:
                    continue
                final.append(pos)
                if temp_s[pos - step] == '#':
                    continue
                len_table[pos] = step
            seed = final
        max_pos, max_step = 0, 0
        for i, s in enumerate(len_table):
            if s >= max_step:
                max_step = s
                max_pos = i
        return temp_s[max_pos - max_step:max_pos + max_step + 1].translate(None, '#')


if __name__ == '__main__':
    # begin
    s = Solution()
    print(s.longestPalindrome("abcbe"))
