def isPalindrome(s):
    return s == s[::-1]

print("Welcome to Palindrome Checker")
text = input('Enter text : ')
ans = isPalindrome(text)

if ans:
    print("Yes, it's Palindrome")
else:
    print("No, it's not Palindrome")
