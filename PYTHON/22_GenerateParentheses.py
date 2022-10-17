# Author: Atharv Patil
# Date: 18.10.22


# Used Bit Mask for creating all possible combinations of the valid parenthesis

def generateParenthesis(self, n: int) -> List[str]:

    l = []
    for i in range(2**(2*n)):               # 2^(2*n) because there will be total
        # 2^(no. of positions) possible combinations
        k = (2*n-(len(bin(i))-2))*"0"+bin(i)[2:]
        cnt = 0
        for i in k:
            if i == "0":
                cnt -= 1
            else:
                cnt += 1
            if cnt < 0:
                break
        else:
            if cnt == 0:
                s = ""
                for i in k:
                    if i == "0":
                        s += ")"
                    else:
                        s += "("
                l.append(s)
    return l


print(generateParenthesis(7))
