Question:
    Given a string,find the length of the longest substring without repeating characters
    example
        abcabcbb    3
        bbbb        1
        pwwkew      3

Solution:
    Time complexity O(n)
    'vec' store the characters's index.if it no appear,its equal -1
    'length' is the substring length of end in s[i],so have two recursion expression
    if(s[i] does't appear or s[i] appear but it does't belong to the range of longest-substring)
        length++;
    else
        length = i sub i's last time appear index
