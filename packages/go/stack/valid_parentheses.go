package stack

// IsValidParentheses checks if a given string of parentheses is valid.
func IsValidParentheses(s string) bool {
	st := New[rune]()
	pairs := map[rune]rune{
		')': '(',
		'}': '{',
		']': '[',
	}

	for _, char := range s {
		if char == '(' || char == '{' || char == '[' {
			st.Push(char)
		} else if char == ')' || char == '}' || char == ']' {
			top, err := st.Pop()
			if err != nil || top != pairs[char] {
				return false
			}
		}
	}
	return st.IsEmpty()
}
